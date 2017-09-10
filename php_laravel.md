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

### Basic Command

From the root of you project.


* This return all the command available by default.

```
$ php artisan list
```

* Will place you app on maintenance mode.

```
$ php artisan down
```

* Will restore from maintenance mode.

```
$ php artisan up
```

* Show all routes of app and details.

```
$ php artisan route:list
```

## App Key

To generate

```
$ php artisan key:generate
```

## Namespace

By default you Namespace is `App`. If we want to change this.

```
$ php artisan app:name Name
```

Notes: Namespace name always start with uppercase letters.

## Routing

Is our main entry point to our application. The essential function of any web application framework is to take requests from a user and deliver responses, usually via HTTP(S). This means defining an application’s routes is the first and most important project to tackle when learning a web framework; without routes, you have no ability to interact with the end user.

In a Laravel application, you will define your **web** routes in `routes/web.php` and your **API** routes in `routes/api.php`. Web routes are those that will be visited by your end users; API routes are those for your API, if you have one. 

In projects running versions of Laravel prior to 5.3, there will be only one routes file, located at `app/Http/routes.php`.

The simplest way to define a route is to match a path (e.g., /) with a closure:

* **Basic Route**

```
Route::get('/', function(){
  return 'Hello, Worlds!';
});
```

### Closure

Closures are PHP’s version of anonymous functions. A closure is a function that you can pass around as an object, assign to a variable, pass as a parameter to other functions and methods, or even serialize.

### HTTP Methods

Every HTTP request has a **verb,** or action, along with it. Laravel allows you to define your routes based on which verb was used; the most common are `GET` and `POST`, followed by `PUT`, `DELETE`, and `PATCH`.

Each method communicates a different thing to the server, and to your code, about the intentions of the caller.

* **Route Verbs**

`Route::get` in our route definitions means we’re telling Laravel to only match for these routes when the HTTP request
uses the `GET` action. But what if it’s a form `POST`, or maybe some JavaScript sending `PUT` or `DELETE` requests? There are a few other options for methods to call on a route definition.

```
Route::get('/', function () {
  return 'Hello, World!';
});

Route::post('/', function () {});

Route::put('/', function () {});

Route::delete('/', function () {});

Route::any('/', function () {});

Route::match(['get', 'post'], '/', function () {});
```

### Route Parameters

If the route you’re defining has parameters—segments in the URL structure that are variable, it’s simple to define them in your route and pass them to your closure.

```
Route::get('/users/{username}', function($username){
  echo $username;
});

Route::get('/users/{id}/friends', function($id){
  echo $id;
});
```

Testing url on browser:

```
http://localhost/users/joseph_01
http://localhost/users/22/friends
```

Output:

```
joseph_01
22

```

### Route Names

The simplest way to refer to a routes in your application is just by their path. But, there’s a `url()` helper to simplify that linking in your views, if you need it. The helper will prefix your route with the full domain of your site.

Laravel also allows you to name each route, which enables you to refer to it without explicitly referencing the URL. This is helpful because it means you can give simple nicknames to complex routes, and also because linking them by name means you don’t have to rewrite your frontend links if the paths change.

```
// Defining a route with name in routes/web.php:
Route::get('/landing/page', function(){
  echo 'Landing';
})->name('landing');

// Link the route in a view using the route() helper
Route::get('/redirect', function(){
  return redirect()->route('landing');
});
```

```
// Using url() helper
<a href="<?php echo url('/'); ?>">
```

* **Old Laravel Version**

Fluent route definitions don’t exist in Laravel 5.1. You’ll need to instead pass an array to the second parameter of your route definition; check the Laravel docs to see more about how this works.

```
Route::get('members/{id}', [
 'as' => 'members.show',
]);
```

* **Group Route**

```
Route::group(['prefix' => 'account'], function(){
  Route::get('change-password', function(){
    echo 'Change password';
  });

  Route::get('profile', function(){
    echo 'Profile';
  });

  Route::post('profile', function(){
    //
  });
});
```

* **Naming Route**

```
Route::get('/redirect', function(){
  return redirect()->route('landing');
});

Route::get('/landing/page', function(){
  echo 'Landing';
})->name('landing');
```

## Controller

To create our controller, we need to used **Artisan**.

```
php artisan make:controller HomeController
```

After creating, you can finding on App -> Http -> Controller. If you can create his own directory, remember add the directory name on namespace. Now we can add the missing code to the following code.

```
<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class HomeController extends Controller
{
    public function index()
    {
        return 'Home';
    }
}

```

To hook up the controller to route.

```
Route::get('/home',[
  // as mean route name.
  'as' => 'home',
  // uses controller and define as ControllerName@functionInController
  'uses' => 'HomeController@index',
]);

```

### Request Object

Allow us to catch get or post query string data or request body.

```
<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class HomeController extends Controller
{
    public function index(Request $request)
    {
        return $request->name;
    }
}
```

Url on browser:

```
http://localhost/home?name=Alex
```

Output:

```
Alex
```

We can used `get` method from Request Object to return value in case we have empty value on Url query.

```
<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class HomeController extends Controller
{
    public function index(Request $request)
    {
        return $request->get('name', 'No name provide');
    }
}
```

Url on browser:

```
http://localhost/home
```

Output:

```
No name provide
```

### Submit (Simple Example)

```
Route::get('/home',[
  'as' => 'home',
  'uses' => 'HomeController@index',
]);

Route::post('/home',[
  'uses' => 'HomeController@create'
]);
```

```
<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class HomeController extends Controller
{
    public function index()
    {
        return '<form action="' . route('home') . '" method="POST"><input type="text" name="email"><input type="submit"></form>';
    }

    public function create(Request $request)
    {
      dd($request->email);
    }
}
```

And to proper work, Disable Crossover Request on file `VerifyCsrfToken.php` on directory app -> Http -> Middleware

```
<?php

namespace App\Http\Middleware;

use Illuminate\Foundation\Http\Middleware\VerifyCsrfToken as Middleware;

class VerifyCsrfToken extends Middleware
{
    /**
     * The URIs that should be excluded from CSRF verification.
     *
     * @var array
     */
    protected $except = [
        //
        // Disable Crossover Request
        '/home'
    ];
}
```

## Views

They are located on resources -> views. You need to create your template with adding .blade to pick up the blade sintax.

## Security

## Step Develop Tasklist App

### Step 1: Database and Modeling

If is a fresh laravel install, delete migration file on database directory. If not create you own migration files.

```
php artisan make:migration create_tasks_table --create=tasks
```

The `--table` and `--create` options may also be used to indicate the name of the table and whether the migration will be creating a new table.

The purpose of create this migration file, is to define which or what columns we wants and after define we can execute those migration files and create ours database table schema for us.

Add your tables on this new file migration.

```
<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateTasksTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('tasks', function (Blueprint $table) {
            $table->increments('id');
            $table->string('name');
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('tasks');
    }
}
```

After edit you migration file, make sure you have all you mysql configuration data on you `.env` file. If you are using docker on windows make sure you have all php extension enable on you php.ini file. To execute you migration file run:

```
$ php artisan migrate
```

To verify you data, you can connect to you mysql service via mysql client. Now let create our model on the App directory. We can used as base User.php, this file is a model file by default. To create our new model file, we need to type the following command:

```
php artisan make:model Task
```

This following command create this code:

```
<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Task extends Model
{
    //
}
```
