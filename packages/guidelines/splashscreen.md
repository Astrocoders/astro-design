## SplashScreen Setup

1. Generate the assets here: https://pgicons.abiro.com

- you can use an image as a background, or simply set a background color
- upload the icon in the best resolution

2. Follow the installation instructions here: https://github.com/crazycodeboy/react-native-splash-screen#installation

### Android

1. Create the drawable-\* folders in `android/app/src/main/res`
2. Place downloaded images in the right folders
3. Add `SplashScreen.hide()` to the root component didMount

### IOS

---

### Tips:

If you're using storybook, be sure to add `SplashScreen.hide()` also in the `storybook/index.js`