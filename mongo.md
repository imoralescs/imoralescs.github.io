# Mongo

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
