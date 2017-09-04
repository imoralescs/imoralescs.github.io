# Nodejs and MongoDB

## Nodejs

Is a single-threaded by design to make asynchronous processing simpler.

## Non-Blocking I/O

## `global` Object

Is similar to window object in the browser Javascript.

```
global.require() === require()
global.process === process
global.console === console
```

**`process` Object**

In Node, interaction with the current Node process takes place via the `process` object. As the `process` object is a global, it is accessible from anywhere in the application source code. Example:

Environmenta variable can be accessed via the env attribute.

```
console.log(process.env)
```

To exit a process, use the exit function.

```
process.exit();
```

## Modules

In the browser `<script>`, CommonJS, AMD (requirejs) and ES6. Module loaders in the browser are SystemJS, RequireJS, Browserify and es6-module-loader. On Nodejs, built-in modules with require a CommonJS notation.

```
var express = require('express');
var app = express();
```

Modules can live different place with Javascript. They can be on local machines, virtual machines, server, remote URI locations, or anywhere really.

**Loading Node Modules**

These modules can be loaded with module loaders like require or via inversion of control patterns.

```
var filesystem - require('fs');
```

**Creating a Module with a "Class" example**

```
function UserController() {}

var ctrl = UserController();
ctrl.login("fred", "123456");
```

**Node Patterns for Module Exports**

```
module.exports = function(ops){}
module.exports = {}
exports.methodA = function(ops){}
exports.obj = {}
```

## NPM (Node Package Manager)

## Nodejs HTTP Server "Hello World"

Example of the `server`, `request` and `response` object.

```javascript
var http = require('http');
var server = http.createServer(function(request, response) {
  response.writeHead(200, {"Content-Type": "text/plain"});
  response.end("Hello, World\n");
});

server.listen(8000, function(){
  console.log("Server running at http://localhost:8000");
});

```

```
var http = require('http');
var server = http.createServer(function(request, response) {
  console.log('url', request.url);
  console.log('method:', request.method);

  // Auth
  response.writeHead(401, {"Content-Type": "text/plain"});
  response.end("Hello, World\n");
});

server.listen(8000, function(){
	console.log("Server running at http://localhost:8000");
});
```

Run with:

```
$ node server.js
```

Send requests:

```
$ curl http://localhost:8000
$ curl http://localhost:8000 -v
```

## MongoDB

Mongo DB is a non-relational data base. Stored only JSON.

## Install Mongo on local

## Access local or remote mongo shell

By terminal type.

```
$ mongo
```

### Basics command

See all database inside my mongo server.

```
$ show dbs
```

To define or create a new database.

```
$ use dbs_name
```

To add element to a collection `db.collection.insert({property: "value"})` or `db.collection.save({property: "value"})`.

```mongo
db.posts.insert({title:"Sundisse",text:"Nullam ut tortor facilisis sollicitudin."})
```

or 

```mongo
db.posts.save({title:"Suspendisse",text:"Nullam blandit orci ut tortor facilisis sollicitudin."})
```

To find all elements on the collection database

```
db.posts.find()
```

## JSON

## Nodejs

Simple Hello World using Nodejs.

```javascript
var http = require('http');
var server = http.createServer(function(request, response) {
  response.writeHead(200, {"Content-Type": "text/plain"});
  response.end("Hello, World\n");
});

server.listen(8000);
console.log("Server running at http://localhost:8000");
```

## Express

Simple Hello World using Express.

```javascript
var express = require('express');
var app = express();

app.get('/', function(req, res){
  res.send("Hello, World!");
});

app.get('*', function(req, res){
  res.status(404).send("Page not found");
});

app.listen(8080);
console.log("Express server started on port 8080");
```

## Express and Pug

Simple Hello World using Express adn Pug. Create directory **views** adn include the following file:

```pug
html
  head
    title= title
  body
    h1= message
```

```javascript
var express = require('express');
var app = express();

app.set('view engine', 'pug');

app.get('/', function(req, res){
  res.render('index',{
    title: 'Nodejs Express App',
    message: 'Hello there!'
  });
});

app.get('*', function(req, res){
  res.status(404).render('index',{
    title: 'Nodejs Express App',
    message: 'Page not found'
  });
});

app.listen(8080);
console.log("Express server started on port 8080");
```

## Express, Mongo and Pug

`mongodb` is the official MongoDB driver for Nodejs.

* posts.pug

```
html
  head
    title= title
  body
    ul
      each val, index in posts
        li= val.title + ' - ' + val.text
```

```javascript
var express = require('express');
var app = express();

var mongo = require('mongodb');
var url = 'mongodb://localhost:27017/api';

app.set('view engine', 'pug');

app.get('/', function(req, res, next){
  res.render('index',{
    title: 'Nodejs Express App',
    message: 'Helo there!'
  });
});

app.get('/posts', function(req, res, next){
  var resultArray = [];
  mongo.connect(url, function(error, db){
    if(error) return next(error);
    var posts = db.collection('posts').find();
    posts.forEach(function(post, error){
      if(error) return next(error);
      resultArray.push(post);
    },
    function(){
      db.close();
      res.render('posts',{
        title: 'Nodejs Express App',
        posts: resultArray
      });
    });
  });
});

app.get('*', function(req, res){
  res.status(404).render('index',{
    title: 'Nodejs Express App',
    message: 'Page not found'
  });
});

app.listen(8080);
console.log("Express server started on port 8080");
```

## Schemaless

MongoDB is a JSON-style data store. The documents stored in the database can have varying sets of fields, with different types for each field.

```
> db.posts.find().pretty()
{
	"_id" : ObjectId("59ac4169f8e91961ca2870ee"),
	"title" : "Suspendisse",
	"text" : "Nullam blandit orci ut tortor facilisis sollicitudin."
}
{
	"_id" : ObjectId("59acb35bf8e91961ca2870ef"),
	"title" : "Sundisse",
	"text" : "Nullam ut tortor facilisis sollicitudin."
}
```

If we insert a new data with different key values:

```
db.posts.save({title: "Maecenas", text: "Maecenas tincidunt quis arcu non suscipit.", type: "news"})
```

```
> db.posts.find().pretty()
{
	"_id" : ObjectId("59ac4169f8e91961ca2870ee"),
	"title" : "Suspendisse",
	"text" : "Nullam blandit orci ut tortor facilisis sollicitudin."
}
{
	"_id" : ObjectId("59acb35bf8e91961ca2870ef"),
	"title" : "Sundisse",
	"text" : "Nullam ut tortor facilisis sollicitudin."
}
{
	"_id" : ObjectId("59ace7ebf8e91961ca2870f0"),
	"title" : "Maecenas",
	"text" : "Maecenas tincidunt quis arcu non suscipit.",
	"type" : "news"
}
```

We can update old data:

```
> var j = db.posts.findOne({'title':'Sundisse'})
> j
{
	"_id" : ObjectId("59acb35bf8e91961ca2870ef"),
	"title" : "Sundisse",
	"text" : "Nullam ut tortor facilisis sollicitudin."
}
> j.type = "sport"
sport
> j
{
	"_id" : ObjectId("59acb35bf8e91961ca2870ef"),
	"title" : "Sundisse",
	"text" : "Nullam ut tortor facilisis sollicitudin.",
	"type" : "sport"
}
> db.posts.save(j);
WriteResult({ "nMatched" : 1, "nUpserted" : 0, "nModified" : 1 })
> db.posts.find().pretty()
{
	"_id" : ObjectId("59ac4169f8e91961ca2870ee"),
	"title" : "Suspendisse",
	"text" : "Nullam blandit orci ut tortor facilisis sollicitudin."
}
{
	"_id" : ObjectId("59acb35bf8e91961ca2870ef"),
	"title" : "Sundisse",
	"text" : "Nullam ut tortor facilisis sollicitudin.",
	"type" : "sport"
}
{
	"_id" : ObjectId("59ace7ebf8e91961ca2870f0"),
	"title" : "Maecenas",
	"text" : "Maecenas tincidunt quis arcu non suscipit.",
	"type" : "news"
}
```
