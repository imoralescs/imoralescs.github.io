# Nodejs and MongoDB

## Nodejs

Is a single-threaded by design to make asynchronous processing simpler. Node.js is for writing server-side JavaScript applications. It is built on top of the V8 JavaScript runtime and uses an event-driven, non-blocking I/O model that makes it perfect for data-intensive, real-time applications.

### Non-Blocking I/O

Blocking refers to operations that block further execution until that operation finishes. Non-blocking refers to code that doesn't block execution. In the given example, localStorage is a blocking operation as it stalls execution to read. On the other hand, fetch is a non-blocking operation as it does not stall alert(3) from execution.

```
// Blocking: 1,... 2
alert(1);
var value = localStorage.getItem('foo');
alert(2);

// Non-blocking: 1, 3,... 2
alert(1);
fetch('example.com').then(() => alert(2));
alert(3);
```

### `global` Object

Is similar to window object in the browser Javascript.

```
global.require() === require()
global.process === process
global.console === console
```

* **`process` Object**

In Node, interaction with the current Node process takes place via the `process` object. As the `process` object is a global, it is accessible from anywhere in the application source code. Example:

Environmenta variable can be accessed via the env attribute.

```
console.log(process.env)
```

To exit a process, use the exit function.

```
process.exit();
```

### Modules

In the browser `<script>`, CommonJS, AMD (requirejs) and ES6. Module loaders in the browser are SystemJS, RequireJS, Browserify and es6-module-loader. On Nodejs, built-in modules with require a CommonJS notation.

```
var express = require('express');
var app = express();
```

Modules can live different place with Javascript. They can be on local machines, virtual machines, server, remote URI locations, or anywhere really.

* **Loading Node Modules**

These modules can be loaded with module loaders like require or via inversion of control patterns.

```
var filesystem - require('fs');
```

* **Creating a Module with a "Class" example**

```
function UserController() {}

var ctrl = UserController();
ctrl.login("fred", "123456");
```

* **Node Patterns for Module Exports**

```
module.exports = function(ops){}
module.exports = {}
exports.methodA = function(ops){}
exports.obj = {}
```

### NPM (Node Package Manager)

### Nodejs HTTP Server "Hello World"

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

* **`HTTP` Object*

This allows Nodejs to transfer data over the Hyper Text Transfer Protocol (HTTP).

```
var server = http.createServer([requestListener]);
server.listen(port[, hostname][, backlog][, callback]);
```

## Express

Express is a relatively small framework that sits on top of Nodejs web server functionality to simplify its APIs. It makes it easier to organize your application functionality with middleware and routing, it adds helpful utilities to Nodejs HTTP objects, it facilitates the rendering of dynamic HTML views.

* **Installing**

```
$ npm install express --save
```

Example of Express:

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

* **Structure**

```
app.js  - main file, houses the embedded server and application logic.
/public - contains static files to be served by the embedded server.
/routes - houses custom routing for the embedded server.
/views  - contains templates that can be processed by a template engine.
```

* **app.js**

It has five distinct parts. We'll start with imports and instantiations. So we import whatever files we need to import, or modules I should say. Then we configure our Express app. Then we would utilize middleware, apply them, most likely from the imported modules. Then we would create the routes, or we would apply the routes imported from our own modules from the routes folder. And then finally we would boot up our server.

### Configuring Express

Express server need to be configured before it can start. Manage configuration via set method.

```
var express = require('express');
var app = express();

app.set('view engine', 'pug');
```

### Middleware

Middleware pattern is a series of processing units connected together, where the output of one unit is the input for the next one. Middleware receives the request and response objects of an HTTP request/response cycle. It may modify (transform) these objects before passing them to the next middleware function in the chain.

You will use middleware all the time in express and a lot of your logic will live inside of them. Middleware is invoked with a request, a response and next. Request is the request object. It contains really important things like the request headers and the request body (presuming your using body-parser).

The response is the express response method. You use this to send responses back to the client, for example `res.json({‘message’:’hello there’});` Next is something unique to express. You invoke next when you are done in your middleware and you want to move on to the next piece of middleware.

* **Creating Middleware**

```
// As variable
var middleware = function(request, response, next){
  // Modify request or response
  // Execute the callback when done
  next()
}
app.use(middleware);

// As anonymous function
app.use(function(request, response, next){
  // Modify request or response
  // Execute the callback when done
  next()
});
```

Request is always the same object in the lifecycle of a single client request to the Express server.

* **Example**

```
var express = require('express');
var app = express();
var PORT = 8080;

function log(request, response, next){
  console.log(new Date(), request.method, request.url);
  console.log('Now next function:\n');
  next();
}

function greeting(request, response, next){
  response.write('Hello \n' + 'World');
  response.end();
  next();
}

app.get('/', log, greeting);

app.listen(PORT, function(){
  console.log("Express server started on port " + PORT);
});
```

### Template Engine

A template engine enables you to use static template files in your application. At runtime, the template engine replaces variables in a template file with actual values, and transforms the template into an HTML file sent to the client. This approach makes it easier to design an HTML page.

* **Pug**

Pug is a super easy-to-use, high performance template engine built in JavaScript used for building static websites.

```
$ npm install pug
```

Simple Hello World using Express and Pug. Create directory **views** and include the following file:

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

### Launch App

```
$ node app.js
$ nodemon app.js
$ pm2 app.js
```

### Routing

Routing is a way to map requests to specific handlers depending on their URL and HTTP verb.

* **REST**

REpresentational State Transfer (REST) is an architectural pattern for developing network application. REST systems aim to keep things simple when connecting to and exchanging data between machines.

* **HTTP**

* **REST Verbs**

REST verbs can be summarised by the CRUD acronym. CRUD stands for: Create(POST), Read(GET), Update(PUT) and Delete. 

* **Resource**

“The key abstraction of information in REST is a resource. Any information that can be named can be a resource: a document or image, a temporal service (e.g. "today's weather in Los Angeles"), a collection of other resources, a non-virtual object (e.g. a person), and so on. In other words, any concept that might be the target of an author's hypertext reference must fit within the definition of a resource. A resource is a conceptual mapping to a set of entities, not the entity that corresponds to the mapping at any particular point in time.” - Roy Fielding’s dissertation.

* **Route on Express**

```
// GET Route
app. get('/users', function(request, response){
  // Code to retrieve users
  response.send(user);
});

// Accessing URL Parameters
app.get('/users/:id/:another/:segment', function(request, response){
  // These dynamic parameters can then be accessed via the request params object
  request.params.id
});

// POST Route
app.post('/users', function(request, response){
  
});

// PUT Route
app.put('/users/:id', function(request, response){

})

// DELETE Route
app.delete('users/:id', function(request, response){

});

// Query Strings
// Express converts URL query string into JSON
// GET http://localhost:3000/?name=Bruce+Wayne&age=40&occupation=Batman
app.get('/', function(request, response){
  console.log(request.query.name);
  console.log(request.query.occupation);
  console.log(request.query.age);
});
```

REST uses HTTP request and responses to provide representations of resources.

* **Request Body Object - Parsing Request Body**

Let say we want our clients to be able to create records in our database for resources. To do this we need them to supply us with data for that resource object. The POST body is an object of data attached to the incoming request. Express requires additional middleware to be able to process these incoming values. Enter `body-parser`.


```
var bodyParse = require('body-parser');
app.use(bodyParse.json());

// Usage: web forbs with action attribute
// Parse application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({extended: false}));

// Accessing Form Data
// POST name=Bruce+Wayne&age=40&occupation=Businessman
/*
request.body.name
request.body.age
request.body.occupation
*/
```

* **Request Body Object - File Uploads**

https://github.com/expressjs/multer
https://github.com/yahoo/express-busboy
https://github.com/mscdex/busboy
https://github.com/pillarjs/multiparty

* **Request Body Object - Parsing JSON**

```
app.use(bodyParse.json({type: 'application/*+json'}));
```

* **Request Body Object - Parsing Buffer**

```
app.use(bodyParse.raw({type: 'application/vnd.custom-type'}));
```

* **Request Body Object - Parsing HTML**

```
app.use(bodyParse.text({type: 'text/html'}));
```

* **Request Header Shortcuts**

```
request.get(headerKey) - value for the header key.
request.accepts(type) - checks if the type is accepted.
request.acceptsLanguage(language) - checks language.
request.acceptsCharset(charset) - checks charset.
request.is(type) - check the type.
request.ip - IP address.
request.ips - IP addresses with trust-proxy on.
request.path - URL path.
request.host - host without port number.
request.fresh - check freshness.
request.stale - checks staleness.
request.xhr - true for AJAX request.
```

* **Responses Object**

The response object is also accessible via routing handlers in Express, It is second argument in the handler callback. The response object can be used to modify an HTTP response before sending it out.

* **Response Method**

```
response.redirect(status, url) - redirect request.
response.send(status, data) - send response.
response.json(status, data) - send JSON and force proper headers.
response.sendfile(path, options, callback) - send a file.
response.render(templateName, locals, callback) - render a template.
response.locals - pass data to template.
```

## MongoDB

Mongo DB is a non-relational data base. Stored only JSON.

### CAP Theorem

Consistency Availability Partition tolarance

### Install Mongo on local

### Access local or remote mongo shell

By terminal type.

```
$ mongo
```

### Basics command

See all database inside my mongo server.

```
$ show dbs
```

To define database.

```
$ use dbs_name
```

### Create Database

* **MongoDB**:

```
$ use blogs

$ db.articles.insert({title: "Phasellus interdum", text: "Cras luctus libero at convallis viverra", tags: ["news", "sports"]})

$ db.articles.find()
```

### Creating Document and Saving it to Collection

* **MongoDB**:
```
var newArticle = {};
newArticle.title = "Curabitur lobortis";

newArticle.text = "Nulla rutrum risus eu arcu lacinia, vitae fringilla";

db.articles.save(newArticle);
db.articles.find().pretty();
```

* **Output**:

```
{
  "_id" : ObjectId("59aec1901855f5fcdba84649"),
  "title" : "Phasellus interdum",
  "text" : "Cras luctus libero at convallis viverra",
  "tags" : ["news", "sports"]
}
{
  "_id" : ObjectId("59aec5a3c097c653fdea04eb"),
  "title" : "Curabitur lobortis",
  "text" : "Nulla rutrum risus eu arcu lacinia, vitae fringilla"
}
```

### Dropping Database 

* **MongoDB**:
```
$ use blogs

$ db.dropDatabase();
```

### Creating a Collection using `db.createCollection(name, options)`

* `name` - type string. Name of the collection.
* `options` - type document. To specify indexing, memory size, maximum number of documents.

```
> db.createCollection("users", {capped:true, size: 6142800, max: 10000})

> show collections
```

### Drop Collection

```
> db.users.drop()

> show collections
```

### MongoDB CRUD Operations

* **Creating and Insert collection using javascript file**

```
db.studentInfo.insert({
  name: {
    firstName: "John",
    lastName: "Reach"
  },
  class: 6,
  rollNo: 23,
  subjects: [
    "Maths", "Physics", "English"
  ],
  attendance: {
    January: "90%",
    February: "85%",
    March: "98%"
  }
});

db.studentInfo.insert({
  name: {
    firstName: "Sunil",
    lastName: "Gupta"
  },
  class: 6,
  rollNo: 24,
  subjects: [
    "Maths", "Physics", "English", "Chemistry"
  ],
  attendance: {
    January: "97%",
    February: "99%",
    March: "100%"
  }
});
```

```
> load("C:/Users/Israel/Documents/Projects/nodejs-app/students.js")

> db.studentInfo.find().pretty();
```

* **Insert Array**

```
var studentsArray =
[{
  name: {
    firstName: "Peter",
    lastName: "Gates"
  },
  age: 12,
  class: 6,
  rollNo: 26,
  subjects: [
    "Maths", "Physics", "English"
  ],
  attendance: {
    January: "80%",
    February: "95%",
    March: "93%"
  }
},
{
  name: {
    firstName: "Sunil",
    lastName: "Gupta"
  },
  age: 18,
  class: 6,
  rollNo: 24,
  subjects: [
    "Maths", "Physics", "English", "Chemistry"
  ],
  attendance: {
    January: "97%",
    February: "99%",
    March: "100%"
  }
},{
  name: {
    firstName: "John",
    lastName: "Reach"
  },
  age: 17,
  class: 6,
  rollNo: 23,
  subjects: [
    "Maths", "Physics", "English"
  ],
  attendance: {
    January: "90%",
    February: "85%",
    March: "98%"
  }
}];

db.studentInfo.insert(studentsArray);
```

* **Querying**

```
db.studentInfo.find({"name.firstName":"Sunil"}).pretty();
```

```
{
  "_id" : ObjectId("59aef7320786199ef27197a8"),
  "name" : {
    "firstName" : "Sunil",
    "lastName" : "Gupta"
  },
  "class" : 6,
  "rollNo" : 24,
  "subjects" : [
    "Maths",
    "Physics",
    "English",
    "Chemistry"
  ],
  "attendance" : {
    "January" : "97%",
    "February" : "99%",
    "March" : "100%"
  }
}
```

* **Querying with $lt and $gt

`$lt` - Less than.

```
db.studentInfo.find({"age":{$lt:16}}).pretty();
```

```
{
        "_id" : ObjectId("59aefa340786199ef27197a9"),
        "name" : {
                "firstName" : "Peter",
                "lastName" : "Gates"
        },
        "age" : 12,
        "class" : 6,
        "rollNo" : 26,
        "subjects" : [
                "Maths",
                "Physics",
                "English"
        ],
        "attendance" : {
                "January" : "80%",
                "February" : "95%",
                "March" : "93%"
        }
}
```

`$gt` - Greated than.

```
db.studentInfo.find({"age":{$gt:16}}).pretty();
```

* **Updating**

```
db.studentInfo.update({"name.firstName":"Sunil"},{$set:{"age":17}});

db.studentInfo.update({"name.firstName":"Sunil"},{$set:{"subjects.1":"Science"}});

db.studentInfo.find({"name.firstName":"Sunil"}).pretty();
```

```
{
        "_id" : ObjectId("59aefa340786199ef27197aa"),
        "name" : {
                "firstName" : "Sunil",
                "lastName" : "Gupta"
        },
        "age" : 17,
        "class" : 6,
        "rollNo" : 24,
        "subjects" : [
                "Maths",
                "Science",
                "English",
                "Chemistry"
        ],
        "attendance" : {
                "January" : "97%",
                "February" : "99%",
                "March" : "100%"
        }
}
```

* **Deleting**

```
db.studentInfo.remove({"name.firstName":"Sunil"})
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

## Deploy AWS Elastic Beanstalk

First you need to install the Elastic Beanstalk Command Line Interface. The EB CLI is developed in Python and requires Python version 2.7, version 3.4, or newer. Them need a package manager for Python that provides an easy way to install, upgrade, and remove Python packages and their dependencies calling `pip`.

### On Windows:

1. Install Python Latest
2. Modify your PATH variable (Windows):
  * Press the Windows key, and then type environment variables.
  * Choose Edit environment variables for your account.
  * Choose PATH, and then choose Edit.
  * Add paths to the Variable value field, separated by semicolons. For example: `C:\existing\path;C:\new\path`
  * Choose OK twice to apply the new settings.
  * Close any running command prompts and reopen.
  
```
Python 3.6 – %USERPROFILE%\AppData\Roaming\Python\Python36\Scripts
```

3. Install the EB CLI

```
pip install awsebcli --upgrade --user
```

4. Test CLI

```
eb --version
```

Create AWS Access Key
1. By AWS Console access to IAM
2. On IAM, click on Users link on the sidebar on the left.
3. On Users screen, click on Add user button to create a new user.
4. Follow the guide to create user, pick user name and select Programmatic access. Then click on Next:Permissions button.
5. On Set permission for USER, we just want to add permission to used Elastic Beanstalk, click on Attach existing policies directly and on the botton windows search for beanstalk and CHECK AWSElasticBeanstackFullAccess. Scroll to botton and click on Next:review button.
6. Review all and then click on Create user button.
7. After create, AWS will give you important credential information, save this on private file, because you cannot get access to this again.

Add Access Key to Local EB client
1. On terminal type `eb init`, select your AWS region
2. Then add your credentials
3. Select an application to use, select 2 to a new one. Enter App name, answer the following question if you are going to used Docker and select platform in this case 1 (Node.js)
4. Then they ask if you want to continum with CodeCommit, select no on this case.
5. Create a SSH for you instances



## AWS Service for containers

* Elastic Compute Cloud(EC2) - Your private server VM. Is a manual way to deploy your app.
* Elastic Container Service(ECS) - Under the hood prepare everything for you in a VM and deploy your container.
* Elastic Container Registry(ECR) - Is a storage for your Docker Images.
* Elastic Beanstalk Container PaaS

## AWS EC2 Container Service

They have:

* Tasks - Defined what to run and how to runner. Think like this is Docker run command. Task definition has info about images, env vars and network.
* Clusters - Is like an EC2 instance where containers run, multiple container.
* Registries - Is how you start with ECS, where developers store their images. Allows for versioning and tagging.
* Service - Is where we monitoring containers, autoscaling.

## Deployment using ECR and EC2 ECS

### Create a repository and add images

* Required to have AWS CLI

1. On ECS dashboard or console click on the Repositories link on the left sidebar.
2. Add name to the repository. Repository URI is the address of where is your repository located. click on the Next button.
3. At sucessfully message, AWS will provide you some command to build, tag and push docker images.
4. On your local machine from the app root directory test your AWS CLI

```
aws ec2 describe-regions
```

5. To get the login to ECR type the following command

```
aws ecr get-login --no-include-email --region us-east-1
```

6. This last command will give you a string, to copy and paste on the same terminal to login to ECR. 
7. Now we need to build the images, Used the same command AWS provide you after create repository.

```
docker build -t node-app .
```

8. After build let add tag name to image from tag name AWS provide us after create repository.

```
docker tag node-app:latest 055987196794.dkr.ecr.us-east-1.amazonaws.com/node-app:latest
```

9. Now the final command to push our image to AWS

```
docker push 055987196794.dkr.ecr.us-east-1.amazonaws.com/node-app:latest
```

10. You can verify on Repository section we push up ours images.

### Create Task Definition

1. On ECS dashboard click on the Task Definitions link on the left sidebar and click on Create new Task Definition button.
2. Add name, AWS create rules for us, on network we are going to select "bridge".
3. To add container, click on add container:
* Add name to container
* Add URI of the images
* Memory limit select soft limit and 512
* Port mapping 80 to port in container, on this case 80 to 8080
* Add Env Variables is you used
4. After add container click on button create

### Create Cluster

1. On ECS dashboard click on the Clusters link on the left sidebar and click on Create Cluster button.
2. Add name cluster, select instance type, number of instance 1, everything default, only on VPC select Create a new VPC and add or create a new roles
3. click on Create button
4. after create, click on View Cluster, and will see empty cluster on all tabs, go to your tasks sections. Click on your task you and to execute.
5. On action dropdown select task from list by checkbox the task and then click on Create Service, add service name and number of task 1. In here you can configurate your load balance, click on create services
6. After Task service start running sucessfully, go to Clusters area, click on the cluster we create, then click on the tab ECS Instances and click on the container instance. This will give you the public DNS
