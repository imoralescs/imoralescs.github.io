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

### Install Windows

* Navigate to `https://docs.haskellstack.org/en/stable/install_and_upgrade/#windows`
* Install Windows XX-bit Installer
* On command prompt:

```
> stack setup
```

* Restart shell command prompt, to run Prelude type:

```
> stack ghci
```


### Install Linux Ubuntu

```
$ sudo apt-get install haskell-platform
```

### Start using Haskell on prompt

```
$ ghci
```

## Access Docker Postgrel

```
$ docker exec -it container-id /bin/bash
```

### access tonight data

```
$ ps flax

$ psql gotonight
```

try example of postgrel

```
SELECT email FROM members
```

see all table

```
\dt
```

other

```
SELECT id, email FROM members;
```

Quit from terminal postgrel

```
\q
```


## Postgrel


* Create Table

```
CREATE TABLE directors (
  id SERIAL PRIMARY KEY,
  name VARCHAR(200)
);

SELECT * FROM directors;

CREATE TABLE movies (
  id SERIAL PRIMARY KEY,
  title VARCHAR(100) NOT NULL,
  release_date DATE,
  count_stars INTEGER,
  director_id INTEGER
);

SELECT * FROM movies;
```

* Insert to Table

```
INSERT INTO directors (name) VALUES ('Quentin Tarantino');

SELECT * FROM directors;

INSERT INTO directors (name) VALUES ('Judd Apatow'), ('Mel Brooks');

SELECT * FROM directors;

INSERT INTO movies (title, release_date, count_stars, director_id)
VALUES ('Kill Bill', '10-10-2003', 3, 1);

SELECT * FROM movies;
```
