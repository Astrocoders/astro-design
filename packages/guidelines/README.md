# GUIDELINES

Astrocoders current guideline to build apps/systems

# JavaScript 

## React frontend development

Here are some small guidelines that are important to create easy to maintain React components in javascript

1. Use arrow function for stateless components
2. Always assign the arrow function to a const 
3. Destruct the props and add defaults if necessary
4. ALWAYS use PropTypes.  shape, arrayOf can help you.
5. If it's a single styled components use attrs or `` with `props => props` to get the props sent to the component
6. Use `export default class MyComponent extends Component {}` on stateful components
7. Always add the components and all their possible states on docz to document it
8. Above each propType describe if necessary what's for the props with `/** My description */`
9. Create tests with jest and react-test-library for components that has logic & components that aggregate components verifying if the inside components exists. 
10. On tests always use `data-testid="MyComponentName"` to find components in the DOM


Example with Header

`Header.js`

```JSX

import React from 'react'
import PropTypes from 'prop-types'
import styled from 'styled-components'
import { MdApps, MdNotificationsNone } from 'react-icons/md'
import { navigate } from '@reach/router'

import cleanButton from '../polished/cleanButton'
import Avatar from './Avatar'
import Logo from './Logo'
import { logout } from '../api'

const HeaderWrapper = styled.div`
  display: flex;
  justify-content: ${props => (props.isLogged ? 'space-between' : 'center')};
  align-items: center;
  height: 58px;
  padding-left: 1rem;
  padding-right: 1rem;
  background-color: #151a21;
  box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.25);
  &:after {
    content: '';
    background-color: #eceef2;
    display: ${props => (props.isLogged ? 'block' : 'none')};
    height: 96px;
    left: 0;
    position: absolute;
    top: 58px;
    width: 100%;
    z-index: 0;
  }
`

const HeaderMenu = styled.button`
  ${cleanButton()};
`

const HeaderMdApps = styled(MdApps)`
  color: #e1e5ed;
  font-size: 1.5rem;
`

const HeaderInfo = styled.div`
  display: flex;
  justify-content: space-between;
  align-items: center;
`

const HeaderNotification = styled(MdNotificationsNone)`
  color: #e1e5ed;
  font-size: 1.5rem;
  cursor: pointer;
`

const HeaderBadgeWrapper = styled.button`
  ${cleanButton()};
  display: flex;
  margin-right: 1rem;
`

const HeaderBadge = styled.span`
  border-radius: 50%;
  width: 12px;
  height: 12px;
  background-color: #ec3853;
  position: absolute;
  margin-left: 12px;
`

const onClickLogout = async () => {
  await logout()
  navigate('/')
}

const Header = ({ isLogged = false, user: { avatar }, notifications: { hasNew, list } }) => (
  <HeaderWrapper isLogged={isLogged}>
    {isLogged ? (
      <React.Fragment>
        <HeaderMenu onClick={onClickLogout}>
          <HeaderMdApps data-testid="HeaderMdApps" />
        </HeaderMenu>
        <HeaderInfo>
          <HeaderBadgeWrapper>
            <HeaderNotification data-testid="HeaderNotification" />
            {hasNew && <HeaderBadge data-testid="HeaderBadge" />}
          </HeaderBadgeWrapper>
          <Avatar size="1.5rem" img={avatar} data-testid="Avatar" />
        </HeaderInfo>
      </React.Fragment>
    ) : (
      <Logo height="1.5rem" />
    )}
  </HeaderWrapper>
)

Header.propTypes = {
  isLogged: PropTypes.bool.isRequired,
  user: PropTypes.shape({
    avatar: PropTypes.string,
  }),
  notifications: PropTypes.shape({
    hasNew: PropTypes.bool.isRequired,
    list: PropTypes.array.isRequired,
  }),
}

Header.defaultProps = {
  isLogged: false,
  user: {
    avatar: null,
  },
  notifications: {
    hasNew: false,
    list: [],
  },
}

export default Header

```

`Header.mdx`


```JSX

---
name: Header
---

import { Playground, PropsTable } from 'docz'
import Header from './Header'

# Header

<PropsTable of={Header} />

## Basic usage

<Playground>
  <Header isLogged />
</Playground>

## Not Logged

<Playground>
  <Header isLogged={false} />
</Playground>

## With Badge

<Playground>
  <Header isLogged notifications={{
    hasNew: true,
    list: [],
  }}/>
</Playground>
```

`Header.test.js`

```JSX

import React from 'react'
import { render, cleanup } from 'react-testing-library'

import Header from './Header'

afterEach(cleanup)

describe('Header component', () => {
  it('should show the menu button', () => {
    const { queryByTestId } = render(<Header />)

    expect(queryByTestId('HeaderMdApps')).toBeInTheDocument()
  })
  it('should show the notification button', () => {
    const { queryByTestId } = render(<Header />)

    expect(queryByTestId('HeaderNotification')).toBeInTheDocument()
  })
  it('should NOT show the notification badge if no notifications', () => {
    const { queryByTestId } = render(<Header />)

    expect(queryByTestId('HeaderBadge')).not.toBeInTheDocument()
  })
  it('should show the notification badge if there are notifications', () => {
    const notifications = {
      hasNew: true,
      list: [],
    }
    const { queryByTestId } = render(<Header notifications={notifications} />)

    expect(queryByTestId('HeaderBadge')).toBeInTheDocument()
  })
  it('should show the avatar', () => {
    const { queryByTestId } = render(<Header />)

    expect(queryByTestId('Avatar')).toBeInTheDocument()
  })
})

```

## React pure API requests

## React Apollo

## React Native

### Publishing
#### Android
Generate keystore and move to android/app
```
$ keytool -genkey -v -keystore my-release-key.keystore -alias my-key-alias -keyalg RSA -keysize 2048 -validity 10000
$ mv my-release-key.keystore android/app
```
Generate a random password and save it.
Edit android/gradle.properties and add the keystore credentials
```diff
android.useDeprecatedNdk=true
android.enableAapt2=false
+MYAPP_RELEASE_STORE_FILE=my-release-key.keystore
+MYAPP_RELEASE_KEY_ALIAS=my-key-alias
+MYAPP_RELEASE_STORE_PASSWORD=THE_PASSWORD_YOU_USED
+MYAPP_RELEASE_KEY_PASSWORD=THE_PASSWORD_YOU_USED
```
Update android/app/build.gradle with
```diff
android {
    compileSdkVersion 26
    buildToolsVersion "26.0.1"

    defaultConfig {
        applicationId "com.yourapp"
        minSdkVersion 16
        targetSdkVersion 22
        versionCode 1
        versionName "1.0"
        ndk {
            abiFilters "armeabi-v7a", "x86"
        }
        vectorDrawables.useSupportLibrary = true
    }
+    signingConfigs {
+        release {
+            if (project.hasProperty('MYAPP_RELEASE_STORE_FILE')) {
+                storeFile file(MYAPP_RELEASE_STORE_FILE)
+                storePassword MYAPP_RELEASE_STORE_PASSWORD
+                keyAlias MYAPP_RELEASE_KEY_ALIAS
+                keyPassword MYAPP_RELEASE_KEY_PASSWORD
+            }
+        }
+    }
    splits {
        abi {
            reset()
            enable enableSeparateBuildPerCPUArchitecture
            universalApk false  // If true, also generate a universal APK
            include "armeabi-v7a", "x86"

        }
    }
    buildTypes {
        release {
            minifyEnabled enableProguardInReleaseBuilds
            proguardFiles getDefaultProguardFile("proguard-android.txt"), "proguard-rules.pro"
+            signingConfig signingConfigs.release
        }
    }

```

Add useful commands to package.json scripts
```diff
  "scripts": {
    "start": "react-native start",
    "android": "react-native run-android",
+    "android:clean": "cd android && ./gradlew clean",
+    "android:debug:install": "cd android && adb install app/build/outputs/apk/app-debug.apk",
+    "android:install": "adb install android/app/build/outputs/apk/app-release.apk",
+    "android:release:generate": "yarn bs:build && cd android && ./gradlew assembleRelease",
    "android:reverse": "adb reverse tcp:7007 tcp:7007 && adb reverse tcp:8081 tcp:8081 && adb reverse tcp:8000 tcp:8000",

```
To generate a new signed APK run "npm run android:release:generate", you can install it with "android:install"

# Reason

## ReasonReact

## Reason on server

## Reason builds

# Create React App Deployment on Netlify

Everything super easy there. No changes are required in the netlify process to deploy. The only thing necessary is to create a 404 page so netlify can redirect to the right page. In this case we want a 404 to be the index one so we can handle it. so we change the build command to 

```json
...
  "build": "react-scripts build && cp build/index.html build/404.html"
...
```

