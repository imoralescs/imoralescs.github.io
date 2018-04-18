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

## How to Stop PostgreSQL service 

```
sudo /etc/init.d/postgresql stop
```

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

Permission denied when running .sh scripts

```
chmod +x the_file_name
```

* Creating a Super User to Use the Admin

SSH to container:
```
$ docker exec -it container-id /bin/bash
```

Then navigate to app directory and run the following command:

```
python manage.py createsuperuser
```

then follow the step, after create the super user, navigate throug browser to app url /admin


# Composer

When you createing an application in PHP, you dont want to write all of it yoursealf.  doest make sense to re-invent the wheel. Composer is a tool for dependecy management in PHP, allow you to declare the libraries your project depends on and it will manage (install/update) them for you.

## What about a dependecy manager

Is a type of application where you have a focus on getting features that can add to your project, for example a library to create PDF files an MVC framework and so on. A dependency manager has the ability to from a specification of which library or framework you will use and which version will be used, it will automate this download process and you will only need to make a "require" or "include" request for that new dependency on your project.

## What is the need to use a dependency manager?

The need to use a dependency manager, in addition to automating the process to get a new dependency, also helps improve the development in a project that is being developed together, since you will not always need to specify for a new team member which dependency and the version you are using, the vast majority of dependency managers have a certain type of file where you specify which dependency and the version being used in the project. For example, Composer has a file named composer.json where everything is fairly clearly specified.

Another important factor is when we need dependencies that need to be configured prior to their use. When we download and configure this type of dependency manually when sharing this project, it will be very possible to occur certain errors in other machines, because each machine has a specific configuration, even if the operating system is the same and in the end you will have to manually make all the machines that use your project a certain type of configuration.

And one of the great advantages of using a dependency manager is when your project needs a specific version of a particular dependency.

## Composer for Beginners - Installation

Installing Composer on Linux

To install it in Linux, just enter the following commands in the terminal:

```
sudo apt-get update
```

Now, let's install the dependencies. We'll need `curl` in order to download Composer and `php-cli` for installing and running it. The `php-mbstring` package is necessary to provide functions for a library we'll be using. `git` is used by Composer for downloading project dependencies, and `unzip` for extracting zipped packages. Everything can be installed with the following command:

```
sudo apt-get install curl php-cli php-mbstring git unzip
```

Entering the command below `curl` will download the latest version.

```
cd ~
curl -sS https://getcomposer.org/installer -o composer-setup.php
```

To install composer globally, use the following:

```
sudo php composer-setup.php --install-dir=/usr/local/bin --filename=composer
```

Ready! The composer is definitely installed on your machine, if you want to do a test to make sure the installation was successful, open the command prompt or terminal and type:

```
composer
```

## Getting started with composer

Some fo composer more useful command:

- composer help <command> : will show the help page for a giveb command
- composer self update : update composer to latest available version
- composer search : search package
- composer status : show a list of dependencies that have been modified locally

## Managing PHP Dependencies

`composer.json` - This file list the dependencies of your project and usually contains other metadata.  This file describes all the dependencies, and holds some metadata as well. composer init will launch the wizard. The wizard will guide us through the generation of our composer.json file.
`composer.lock` - This file is created/update after installing/updating your project dependecies with the list of the installed packages and versions.
`vendor/` - The default directory where the dependecy packages will be stored

`vendor/` should be add to `.gitignore`

## Package Installation using Composer

Package installation using composer is really easy. You need to write just one line command and it will install the package. Suppose, you need to install monolog logger for your symfony project. Then, you need to write

```
$ sudo composer require monolog/monolog
```

## Packagist

Packagist is main repository of composer packages. Means when we are searching or installing any package or library in our project basically we are hitting Packagist.

Packagist also encourages developers to submit their packages to strengthen the community.


## Autoloading

The autoloading provided by Composer to access the project’s dependencies is very useful, and can also be used to access our own application’s code. To do this, we need to register our code in the composer.json file using the autoload key.

```
{
    "autoload": {
        "psub-4": {"Foo\\": "src/"}
    }
}
```

First, Composer will register a PSUB-4 autoloader for the Foo namespace.

## What is autoloading

Supposing that you are developing an application and you have a long list of libraries that needed to be loaded. We can load all of classes at the beginning of your script and you will be able to use any one of these classes anywhere in your application. Better solution is Whenever I use a class, I go and load it, so my application doesn’t have to load all classes each request, this is called “Autoloading”.

How Composer Does Autoloading
Along with your script index.php add your composer.json:

```
{
  "autoload": {
    "classmap": [
      "Classes/"
    ]
  }
}
```

And update your index.php file to:

```
require __DIR__ . '/vendor/autoload.php';

$a = new A();
```

Using `classmap`, we are telling composer that this is the way to do mapping, and it is a very basic way to map namespaces to paths and if you want more details, just check `vendor/composer/autoload_classmap.php` after you run the composer install:

## Inclusion

- Initialization

1- Initialize composer, on project root directory type:

```
composer init
```
Them follow the following step.

2- Set package name
3- Set description
4- Set the package author
5- Set the package stability
6- Set the package type
7- Set the package license
8- Define package dependecies

List any dependecies that we know of to used.

9- Define development dependencies

Allow us to specify our development dependecies

10- Confirm composer.json generation


## Note

* RuntimeException: Unable to create the cache directory
Posible solution
```
$ chown -R www-data:www-data app/cache

and

$ chown -R www-data:www-data app/log
```

* Getting Error SQLSTATE[HY000] [2002] Connection refused on Docker Env

Used name of container.

## Composer optimize the autoloader

```
composer dump-autoload --optimize
```

```
List of docker-php-ext-install extension names
Possible values for ext-name:

bcmath
bz2
calendar
ctype
curl
dba
dom
enchant
exif
fileinfo
filter
ftp
gd
gettext
gmp
hash
iconv
imap
interbase
intl
json
ldap
mbstring
mcrypt
mysqli
oci8
odbc
opcache
pcntl
pdo
pdo_dblib
pdo_firebird
pdo_mysql
pdo_oci
pdo_odbc
pdo_pgsql
pdo_sqlite
pgsql
phar
posix
pspell
readline
recode
reflection
session
shmop
simplexml
snmp
soap
sockets
spl
standard
sysvmsg
sysvsem
sysvshm
tidy
tokenizer
wddx
xml
xmlreader
xmlrpc
xmlwriter
xsl
zip
```

## Add user ubuntu permission

```
$ sudo chown -R <username> *
$ sudo chgrp -R <grpname> *
```

# Gatsbyjs

* Install Gatsby Global

```
npm install --global getsby-cli
```

* Create a new site

```
gatsby new wp-gatsby
```

* Run client app

```
gatsby develop
```

* In my docker project, npm install on main directory

* `src/` - is the directory for react webpage main code


## StoryBook
1. Get Storybook and install global

```
npm install -g getstorybook
```

2. Now get into you app directory and type

```
getstorybook
```

3. to run storybook type
```
npm run storybook
```
