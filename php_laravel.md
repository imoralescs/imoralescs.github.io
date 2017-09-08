
## Local Enviroment Notes

* **No application encryption key has been specified. New Laravel app**

```
$ php artisan key:generate
```

* **Permission denied**

```
$ sudo chmod -R 777 /path/to/directory
```

* **Restart, Start, Stop MySQL from the Command Line Linux**

On Linux start/stop/restart from the command line:

```
 /etc/init.d/mysqld start
 /etc/init.d/mysqld stop
 /etc/init.d/mysqld restart
```

Some Linux flavours offer the service command too

```
 service mysqld start
 service mysqld stop
 service mysqld restart
```

or

```
service mysql start
service mysql stop
service mysql restart
```

* **Requested PHP extension dom is missing from your system**

Installing xml-extension (php7.0-xml in my case) solved the problem

```
sudo apt-get install php-xml
```

Managed to fix it with a php version 5.6*

```
$ sudo apt-get install php5.6-xml
```

* **Requested PHP extension mbstring is missing from your system**

```
sudo apt-get install php-mbstring 
```

* **Laravel 5 Failed opening required bootstrap/../vendor/autoload.php**

```
composer update --no-scripts
```

## Directory Structure

### `.env` 

This file contain configuration based on the environment of the application.

### `artisan`

It is end point for artisan command which is used for various tasks and function in Laravel.

### `composer.json`

Dependency and all list for composer installation

### `package.json`

This file contain node related dependency, for example compiling SASS or LESS.

### app

App directory contains the main code for any application. Almost all of the classes in your app will be in the directory. It is further divided in following sub directory:

* **app -> Console**

Place you can extend Artisan command. This contain custom artisan commands for the application

* **app -> Http**

This directory contain controllers & middleware. They are placed in their respective directories. Before on Laravel 5.2 route file is placed in this directory too, but after Laravel 5.2 they create a routes directory outside of app directory.

* **app -> Providers**

Contain services provider, help to boot you app. This directory contains service provider for your application. For example by default Laravel comes with Authentication provider which when enabled, is used for authentication purposes.

* **app -> User.php**

Is a example file for a Model.

* **Other directory**

These directories come in each new version of Laravel prior to 5.3 but are often not used, so all new installs won't have them. Here's the list of folders that are going away: **Events**, **Jobs**, **Listeners**, **Policies**.

### bootstrap

This directory contains files that load the framework and compose auto loading. This directory also builds a cache directory which holds framework generated files for functionality development such as the route and services cache files.

### config

The config directory, as the name implies, holds all of your application’s configuration files.

### database

This directory comprises your database migration and seeds. Developers may also use this directory to grip a SQLite database.

* **database -> migration**

Laravel migrations provide mechanisms for creating and modifying database tables. Migrations are database agnostic. This means you do not have to worry about the specific SQL syntax for the database engine that you are creating tables for. Migrations also allow you to roll back the most recent changes that you made to a database.

### public

This directory contains the index.php file, which is the initial point for all requests arriving in your application and also houses your assets such as images, JavaScript, and CSS.

### resources

This directory contains raw, uncompiled assets such as LESS, SASS or JS. It also contain template and language files for the application.

### routes

This directory contain the route files, i.e. something like pretty URL for your application and its corresponding views. It will get more clear in upcoming posts.

* **routes -> wep.php**

Route for normal wep app, when you need to render view.

* **routes -> api.php**

Help us to create RESTful enpoint.

### storage

Storage directory holds your compiled Blade templates, sessions, caches, and other files developed by the framework.

### test

It contain automated test for your php application. PHPUnit is provided out of the box.

### vendor

It contain various supporting frameworks, codes and dependencies to make application working.

## Artisan

Artisan is the command-line interface included with Laravel. It provides a number of helpful commands that can assist you while you build your application.
