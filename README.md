# Personal Knowledge Wiki

## Resource Web:
* http://javascript.info/

## NPM Package Manager

### Install globally

```

```

### Install a package

```
npm install <package> --save
```

```
npm install express --save
```

## Yarn Package Manager

### Install globally

```
npm install yarn --global
```

### Initial and create package.json

```
yarn init -y
```

### Install a package

```
yarn add <package>
```

```
yarn add express
```

## Delete Node Modules

```
rm -rf node_modules
```

## json-server

https://github.com/typicode/json-server

## Jest Testing Framework

### Jest default test folder

By default Jest searches all the directories named `__tests__` and runs all JS files inside.

### Run Jest

```
jest --watch
```

### How We Test Components

With Snapshots, first on the test we render the components to JSON (JSON tree), to match with a snapshot. The first time this test runs it run just a good components of JSON and then we just put that in a snapshot file in a directory and your test will pass. Them in the next time your test runs again, The test just will take that and it will render the components again to JSON and there are going to compare to the previous snapshot file case of JSON. If they are changes, Jest will say something in your code was changes, then you can decide if that is the change you want and decide to put that to the snapshot, if not want that change you can decide to leave the snapshot as is and let try to fix right.

The main goal is just match Snapshots.

## Start with Flow

First on the root project type:

```
yarn add --dev flow-bin
```

To setup flow on you node_modules, them:

```
yarn flow -- init
```

This create your `.flowconfig` file, for project. Now let install CLI Flow-Typed to bring types from repo to your project with the following command:

```
yarn global add flow-typed
```
Them:
```
flow-typed install
```

This are goign to grab all the types from what you install to you project and install on the project.

To test you app with flow, meanwhile the app if running with webpack, in another command line on the same app root type:

```
yarn flow
```

If everything is good you will see 'No errors!' message.

## Start Haskell

### Install Linux Ubuntu

```
sudo apt-get install haskell-platform
```

### Start using Haskell on prompt

```
$ ghci
```
