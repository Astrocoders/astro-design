const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const outputDir = path.resolve(__dirname, 'build/');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: './src/index.bs.js',
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: 'index.js',
    publicPath: '/'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'src/index.html',
      inject: false
    })
  ],
  module: {
    rules: [
      {
        test: /\.(jpe?g|png|svg|woff|woff2|eot|ttf|otf)$/,
        loader: 'file-loader',
      },
    ],
  },
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true
  }
};