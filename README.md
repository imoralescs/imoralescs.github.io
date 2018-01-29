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

## Setup PC HG Mercurial SSH with Bitbucket

* Generate SSH Key on your pc

```
$ ssh-keygen
```

* Add passphrase
* Save on default directory
* Verify key on directory

```
$ ls ~/.ssh
```

* Add your key on bitbucket, go to bitbucket account -> ssh key, and add you key.

```
$ cat ~/.ssh/id_rsa.pub
```

* Test you connection with you passphrase

```
$ ssh -T hg@bitbucket.org
```

## Create my Dev Env

### Screen Resolution Problem resize

After create you machine, log in and install:

 ```
 sudo apt-get install virtualbox-guest-dkms
 ```

## Bug Dropbox
```

17
down vote
accepted
Lubuntu 14.04 ....I have a few machines, all the same OS. One by one Dropbox icon dissappeared.

I have struggled for months. Couldn't recover icon. Got it now!

In terminal type ... dropbox stop && dbus-launch dropbox start
Follow the prompts, if any. Two of my machines responded "Dropbox not installed".
sudo apt-get install dropbox
Repeat line 1. Icon appeared. Didn't stay after re-boot.
Repeat line 1, to get icon.
Go to Preferences ...General, (Dropbox icon) and un-tick 'Start Dropbox on system startup'.
Now to 'Default applications for LXSession' (menu ...Preferences)
Under Autostart, un-tick any previous Dropbox attempts (these can be deleted later).
Add dbus-launch dropbox start
Re-boot.
```

## Mercurial

### Problem on checkout branch with dashes on name.

Used tag branch.

```
hg branches
```

this produce a list of branches with id tag.

```
hg update TAG
```

verify branch

```
hg branch
```

## G

```

after install dependecy on the same dir change to root used
```
```
sudo mkdir Dropbox
ls
> Dropbox
sudo mount -t vboxsf dir dir
cd dir
ls
sudo usermod -aG vboxsf username
```


```
sudo chmod -R 777  client
```

## Django

Access to postgrel database

```
$ docker exec -it container-id /bin/bash
```

them

```
psql -U postgres
```

check

```
\dt
```
