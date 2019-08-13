# Projects Setup

Usually we have a mobile and/or web applications and a GraphQL server. Here we are going to see the steps to setup a brand new project

Install our CLI astroman for easiness to create new projects

## Repositories & Notifications Webhooks

1. Create empty repositories in our github organization. The pattern is `nameproject-app` for mobile `nameproject-webapp` for a web application `nameproject-landing` for a landing page `nameproject-graphql` if we just consume API REST and `nameproject-server` when we do all the server features
2. Create the Pivotal Tracker
3. Create the tags in pivotal: scene/page/component/graphql/app/webapp/landing.
4. Create the Epics for abroad user stories & setup
5. Create channels in our discord: projectname and projectname-bots
6. Setup the pivotal webhooks by going to https://pivotal-to-discord-webhook.now.sh and set webhooklink from discord **don't forget to add token is necessary not optional like it's saying in the UI**. Now go to pivotal tracker and add https://pivotal-to-discord-webhook.now.sh/hook on the webhooks settings https://www.pivotaltracker.com/projects/project-number/webhooks
7. Setup the github webhooks by going to the project repositories and set the webhooklink/github link https://github.com/Astrocoders/nameproject/settings/hooks, set application/json, set "Send me everything". to test the notifications star the project
8. Add the basic stories below on the pivotal tracker

## Initial Setup (for each repository/project item this is about running astroman to generate the app/webapp/server structure)

in the case of app projects

- Gradient
- Docz
- Theme hookup
- Modal hookup
- Share to Apps/Social hookup
- Camera & Album hookup
- Push notifications
- [SplashScreen](https://github.com/Astrocoders/guidelines/blob/master/splashscreen.md)
- [Fastlane - Circleci APK build and deploy to Beta & slack/discord](https://github.com/Astrocoders/guidelines/blob/master/setup-fastlane-mobile-app.md)
- Fastlane - Circleci IPA build and deploy to Testflight
- Detox

in case of webapp

- Docz
- Theme hookup
- Modal hookup
- Netlify setup
- Circleci CI/CD
- Jest
- Cypress

in case of server/graphql

- Circleci CI/CD
- Jest

## Initial setup

If everything is updated and you installed astroman then you should:

1. run `astroman new projectname app-reason` | addendum: options that I see (app-js, app-reason, webapp-js, webapp-reason, landing-cra, landing-gatsby, server-js, server-ts, server-reason, graphql-js)
2. `astroman push astrocoders/nameproject` | addendum: this command doesn't exists but would be nice. It would run: git init && git commit -m "Initial commit" && git remote add origin git@github.com:param1.git && git push -u origin master
3. sip a coffee ;)

IMPORTANT Addendum:

The 8. step contain the tasks that the command `astroman new` should automate. We are just adding this time to our customers view to give us more "time" to sharpen our tools and always make it better and fresh.

Alright! You made it! 🚀🚀🚀