# Setup continuous deploy with Fastlane on react native projects

## Setup Fastlane

Create a file Gemfile in the root of your project and put this content in it
```
source "https://rubygems.org"

gem "fastlane"
gem "dotenv"
gem "cocoapods", "~> 1.5.3"
```

Then create a directory fastlane in the root of your project and inside of it crete these files:

Appfile
```
json_key_file("fastlane/googlePlayAPI.json") # Path to the json secret file - Follow https://docs.fastlane.tools/actions/supply/#setup to get one
package_name("BUNDLE_ID")
# apple_id("[[APPLE_ID]]")
app_identifier("BUNDLE_ID")
```

Fastfile
``` 
fastlane_require 'dotenv/load'

# For a list of all available actions, check out
#
#     https://docs.fastlane.tools/actions

ANDROID_DIR = File.expand_path('../android', __dir__)
IOS_DIR = File.expand_path('../ios', __dir__)

def package
  $package_json ||= JSON.parse(
    File.read('../package.json'),
    symbolize_names: true
  )
end

def version_name(args)
  tag = args[:tag] || ''
  version = args[:version] || package[:version]
  version << '-' << tag unless tag.empty?
  version
end

def android_certificate()
  {
    'android.injected.signing.store.file' => ENV['ANDROID_KEYSTORE_FILE'],
    'android.injected.signing.store.password' => ENV['ANDROID_KEYSTORE_PASSWORD'],
    'android.injected.signing.key.alias' => ENV['ANDROID_KEY_ALIAS'],
    'android.injected.signing.key.password' => ENV['ANDROID_KEY_PASSWORD']
  }
end

platform :android do
  BUILD_NUMBER_PATTERN = '(versionCode) ([[:digit:]]*)'
  VERSION_NAME_PATTERN = '(versionName) "(.*)"'

  desc "Bump build and version numbers"
  lane :bump do |args|
    gradle_build = "#{ANDROID_DIR}/app/build.gradle"
    version = version_name args
    build_number = args[:build_number]
    unless build_number
      build_number = sh "awk 'match($0,/#{BUILD_NUMBER_PATTERN}/) {print $2}' #{gradle_build}"
      build_number = build_number.to_i + 1
    end
    # Set extended regex option according to OS
    # http://www.grymoire.com/Unix/Sed.html#uh-4a
    opt = case RUBY_PLATFORM
          when /darwin/i then "Ei ''"
          when /linux|arch/i then 'ri'
          end
    sh %Q{sed -#{opt} 's/#{BUILD_NUMBER_PATTERN}/\\1 #{build_number}/' #{gradle_build}}
    sh %Q{sed -#{opt} 's/#{VERSION_NAME_PATTERN}/\\1 "#{version}"/' #{gradle_build}}
  end

  desc "Build staging apk file"
  lane :buildStaging do |signed: false, bump: false, **options|
    bump options if bump
    build_options = signed ? {print_command: false, properties: android_certificate} : {}
    gradle(
      task: "assemble",
      flavor: "staging",
      build_type: "release",
      project_dir: ANDROID_DIR,
      **build_options
    )
  end

  desc "Build development apk file"
  lane :buildDevelopment do |signed: false, bump: false, **options|
    bump options if bump
    build_options = signed ? {print_command: false, properties: android_certificate} : {}

    gradle(
      task: "assemble",
      flavor: "development",
      build_type: "release",
      project_dir: ANDROID_DIR,
      **build_options
    )
  end

  desc "Build production apk file"
  lane :buildProduction do |signed: false, bump: false, **options|
    bump options if bump
    build_options = signed ? {print_command: false, properties: android_certificate} : {}

    gradle(
      task: "assemble",
      flavor: "production",
      build_type: "release",
      project_dir: ANDROID_DIR,
      **build_options
    )
  end

  desc "Publish beta build"
  lane :beta do
    upload_to_play_store(track: 'beta')
  end

  desc "Publish release build"
  lane :playstore do
    upload_to_play_store
  end

  # Optional
  # Get app build and send to slack channel pointed by these environment variables
  desc "Upload the latest output APK to Slack channel"
  lane :upload_to_slack do |options|
    full_file_path = "../android/app/build/outputs/apk/staging/release/app-staging-release.apk"
    file_name = full_file_path.gsub(/\/.*\//,"")
    sh "echo Uploading " + file_name + " to Slack"
    sh "curl https://slack.com/api/files.upload -F token=\"#{ENV[ "SLACK_TOKEN" ]}\" -F channels=\"#{ENV[ "SLACK_CHANNEL" ]}\" -F title=\"" + file_name + "\" -F filename=\"" + file_name + "\" -F file=@" + full_file_path
  end
end

```

## Setup CircleCI

Create a directory .circleci in your project root and create a file config.yml inside it

Sample config.yml
```` 
version: 2
jobs:
  build-deploy:
    docker:
      - image: circleci/android:api-27-node8-alpha

    working_directory: ~/repo

    steps:
      - checkout

      - run:
          name: Install node deps
          command: yarn install --network-concurrency 1 --ignore-engines

      - run:
          name: Build ReasonML
          command: yarn bs:build

      - run:
          name: Install RubyGems
          command: sudo apt-get install rubygems

      - run:
          name: Install Ruby Headers
          command: sudo apt-get install ruby-all-dev

      - run:
          name: Install Fastlane
          command: sudo gem install bundler && sudo bundle update

      - run:
          name: Bump App Version
          command: bundle exec fastlane android bump ${CIRCLE_BUILD_NUM}

      - run:
          name: Build Staging
          environment:
            ANDROID_KEYSTORE_FILE: staging.keystore
          command: |
            echo ${ANDROID_STAGING_KEYSTORE_FILE} | base64 --decode > android/app/staging.keystore
            echo ${ANDROID_GOOGLE_SERVICES} | base64 --decode > android/app/src/staging/google-services.json
            export ANDROID_KEY_PASSWORD=${ANDROID_STAGING_KEYSTORE_PASSWORD}
            export ANDROID_KEYSTORE_PASSWORD=${ANDROID_STAGING_KEYSTORE_PASSWORD}
            export ANDROID_KEY_ALIAS=${ANDROID_STAGING_KEY_ALIAS}
            yarn rn:android:release-build
            bundle exec fastlane android buildStaging build_number:${CIRCLE_BUILD_NUM}

      #   - run:
      #       name: Init Supply
      #       command: bundle exec fastlane supply init

      #   - run:
      #       name: Deploy Beta
      #       command: |
      #         if [ "${CIRCLE_BRANCH}" == "develop" ]
      #         then
      #           bundle exec fastlane android beta
      #         fi

      - store_artifacts:
          path: ./android/app/build/outputs/apk/staging/release/app-staging-release.apk
          destination: app-staging.apk

      - run:
          name: Send APK to Slack
          command: |
            if [ "${CIRCLE_BRANCH}" == "develop" ]
            then
              bundle exec fastlane android upload_to_slack
            fi

workflows:
  version: 2
  push_staging:
    jobs:
      - build-deploy

````


###
Alright! You made it! 🚀🚀🚀