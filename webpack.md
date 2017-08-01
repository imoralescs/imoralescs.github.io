# Webpack

## Installation

### Start project with NPM

1. `npm init`
2. Fill all details of the project.

### Install Webpack

1. `yarn add webpack --dev`

 * `--dev` This mean add dependecy on development enviroment.

2. Add script to **package.js** create JS bundle.

```
{
  "name": "webpack-intro",
  "version": "1.0.0",
  "description": "Webpack for newbee",
  "main": "index.js",
  "scripts": {
    "build": "webpack",
  },
  "author": "Israel Morales",
  "license": "ISC",
  "devDependencies": {
    "webpack": "^3.4.1"
  }
}
```

### Add `webpack.config`

Create a file on the root of you project. **webpack.config**. This file need a entry file, is the first piece of code, would be start you entire application.

Second, this file need output file name and path.

**Directory Structure**

```
src
  -- index.js
package.json
webpack.config.js
yarn.lock
```

**index.js**

```
console.log("Hello From Webpack");
```

**webpack.config.js**

```javascript
module.exports = {
  entry: "./src/index.js",
  output: {
    filename: "bundle.js"
  }
}
```

After have all new changes, we can run `yarn build` and next `node bundle.js` to test our bundle.

### Changing your bundle location

**path**

Tell webpack where to put the bundle.js. This property need the tools `path` to accept absolute path. To change this `path: "./build"` to `path: path.join(__dirname, "build")`.


**webpack.config.js**

```javascript
const path = require("path");

module.exports = {
  entry: "./src/index.js",
  output: {
    filename: "bundle.js",
    path: path.join(__dirname, "build"),
  }
}
```

### Dependency Graph

Any time one file depends on another, webpack treats this as a dependency. This allows webpack to take non-code assets, such as images or web fonts, and also provide them as dependencies for your application.

When webpack processes your application, it starts from a list of modules defined on the command line or in its config file. Starting from these entry points, webpack recursively builds a dependency graph that includes every module your application needs, then packages all of those modules into a small number of bundles - often, just one - to be loaded by the browser.

Task runner builder like grunt and gulp they pull large js files and concat all.

### Loaders and Rules

Allow us to manages all assests.

**Loaders**

How loaders look like:

```
const doSomething = require("do-something");

module.exports = function(source) {
 
 const newSource = doSomethingToSource(source);
 
 return newSource;
}
```

Each rules set, is going to be a javascript object and is going to take two important property that are required. **test** tell webpack to map file there are pass his regular expression test and perform a transform on it. **use** is the module to used for transform the file.

Example: **webpack.config.js**

```javascript
const path = require("path");

module.exports = {
  entry: "./src/index.js",
  output: {
    filename: "bundle.js",
    path: path.join(__dirname, "build"),
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        use: "some-loader",
      }
    ]
  }
}
```

The most common module loader is `babel-loader`. Also you can add array of loader, and compose loader from right to left.

Example: **webpack.config.js**

```javascript
const path = require("path");

module.exports = {
  entry: "./src/index.js",
  output: {
    filename: "bundle.js",
    path: path.join(__dirname, "build"),
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        use: "some-loader",
      },
      {
        test: /\.css$/,
        use: [
          "style-loader",
          "css-loader",
        ]
      }
    ]
  }
}
```

Add options to loader:

```javascript
const path = require("path");

module.exports = {
  entry: "./src/index.js",
  output: {
    filename: "bundle.js",
    path: path.join(__dirname, "build"),
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        use: "some-loader",
      },
      {
        test: /\.css$/,
        use: [
          "style-loader",
          "css-loader",
        ]
      },
      {
        test: /\.jpeg$/,
        use: [
          {
            loader: "url-loader", options: {
              limit: 10000
            }
          }
        ]
      }
    ]
  }
}
```

### Plugins

Can perform any functionality that loader cannot. More that only transform file.

How plugin look like:

```
class ExamplePlugin {
  apply(compiler) {
    compiler.plugin("run", (compiler, callback) => {
      console.log(`WEBPACK IS RUNNING`);
      callback();
    });
  }
}

module.exports = ExamplePlugin;
```

Example: **webpack.config.js**

```javascript
const path = require("path");
const ExamplePlugin = require("./ExamplePlugin.js");

module.exports = {
  entry: "./src/index.js",
  output: {
    filename: "bundle.js",
    path: path.join(__dirname, "build"),
  },
  plugins: [
    new ExamplePlugin(),
  ]
}
```

### Leveraging NPM Scripts


**Directory Structure**

```
src
  -- index.js
  -- card.js
package.json
webpack.config.js
yarn.lock
```

**webpack.config.js**

```javascript
const path = require("path");

module.exports = {
  entry: "./src/index.js",
  output: {
    filename: "[chunkhask].bundle.js",
    path: path.join(__dirname, "build"),
  }
}
```

```
{
  "name": "webpack-intro",
  "version": "1.0.0",
  "description": "Webpack for newbee",
  "main": "index.js",
  "scripts": {
    "watch-build": "yarn build -- --watch",
    "watch": "webpack --watch",
    "build": "webpack"
  },
  "author": "Israel Morales",
  "license": "ISC",
  "devDependencies": {
    "webpack": "^3.4.1"
  }
}
```

```
import createCard from "./card";

createCard(
  "Im learning webpack: Web Essentials",
  "This course is made by me."
);
```

```
const createAndAppendCard = (header, body) => {
  const cardFragment = document.createDocumentFragment();
  const cardElement = document.createElement("div");
  const cardHeader = `<h2 class="card-header">${header}</h2>`;
  const cardBody = `<div class="card-body">${body}</div>`;

  cardElement.innerHTML = `
    <div class="card">
      ${cardHeader}
      ${cardBody}
    </div>
  `;

  cardFragment.appendChild(cardElement);

  document.body.appendChild(cardFragment);
};

export default createAndAppendCard
```
