# Javascript Asynchronous

First understand what “synchronous”, the opposite, means. In programming, we can simplify the definition of synchronous code as “a bunch of statements in sequence”; so each statement in your code is executed one after the other. This means each statement has to wait for the previous one to finish executing.

```javascript
console.log('First');
console.log('Second');
console.log('Third');
```

The statements above will execute in order, outputting “First”, “Second”, “Third” to the console. That’s because it’s written synchronously.

Asynchronous code takes statements outside of the main program flow, allowing the code after the asynchronous call to be executed immediately without waiting. 

## Event Loop

## Callback

Is the most basic method of asynchronous programming. Callback functions are functions that are passed as arguments into other functions to be executed at a later point in time.

```javascript
//multiplies two numbers
function mult(x,y){ 
  return x * y;  
}

//adds to numbers
function add(x,y){  
   return x + y;
}

//uses a callback to process two numbers
function calculate(x,y,compute){ 
  return compute(x,y);
}

var a = calculate(10,5,add); //uses add callback
console.log(a); // logs 15

var b = calculate(10,5,mult); //uses mult callback
console.log(b); // logs 50
```

## Anonymous Callbacks

Callbacks can be created and used without being bound to a specific function name. Anonymous callbacks are useful when a callback is only needed to be declared once, since they are quicker to write than named callbacks.

```javascript
var c = calculate(10,5,function(x,y){ //uses an anonymous callback
  return x - y; //subtracts y from x
});

console.log(c); // logs 5

var d = calculate(10,5, (x,y) => {return x - y}); //using arrow functions

console.log(d); // logs 5
```

## Chaining Callbacks

The Continuation Passing Style(CPS) is a programming style used to chain callback functions together. In CPS, methods with callback functions as arguments are called within other callback functions. CPS is characterized by having methods that have callback functions as their last argument.

CPS has a tendency to become difficult to manage as more and more callback functions are chained together. 


## Timers

### setTimeout()

The `setTimeout()` method is used to schedule a task to be put on the event queue after a given amount of time. The first parameter to setTimeout() is the callback function that is going to be executed. The second parameter is the amount of time to wait before putting the task on the event queue. setTimeout() is non-blocking and other code may run while the setTimeout() task is waiting to be executed.

```javascript
setTimeout(function(){
  console.log("hello")  
},1000); //waits 1 second
```

### claerTimeout();

The `clearTimeout()` function is used to cancel a timeout that is still pending. The `setTimeout()` method call returns a numeric timerID that is used to identify the timer. This timerID can be passed into the `clearTimeout()` method call to stop the timer.

```javascript
var timeout = setTimeout(function(){
  console.log("hello")  
},1000); //waits 1 second

clearTimeout(timeout); //clears the setTimeout callback from running
```

### SetInterval()

The `setInterval()` method is used to schedule a reoccurring task to be put on the event queue every time a given number of milliseconds elapses. The first parameter to `setInterval()` is the callback function that is going to be executed. The second parameter is the amount of time to wait before the reoccurring task is put back on to the event queue.

```javascript
var count = 0;

var interval = setInterval(function(){
  count++;
  console.log(count);
},1000); //executes callback every second
```

### clearInterval()

The `clearInterval()` method is used to stop an interval timer set by `setInterval()`. The `setInterval()` method call returns a numeric timerID that is used to identify the interval timer. This timerID can be passed into the `clearInterval()` method call to stop the interval timer.


### Asynchronous Code using Timers

Synchronous code is run line by line in the order in which the code occurred. Notice how synchronous code is executed:

```javascript
console.log("first");
console.log("second");
console.log("third");
```

Asynchronous code may be executed in a different order than how it originally occurred. Asynchronous code is non-blocking and will only run when the call stack is empty.

Asynchronous code can be shown by using a `setTimeout()` method call with a timeout value of 0. This will immediately put a task on the event queue.

Notice how "second" is logged asynchronously and occurs out of order:

```javascript
function asyncLog(val){ //logs values asynchronously
  setTimeout(function(){  //setTimeout with a time of 0 will execute asynchronously
    console.log(val);      
  },0)
}

console.log("first");
asyncLog("second");
console.log("third");
```

The output appears out of order because the asynchronous console log task had to wait for the call stack to finish executing the other console logs before it could occur.


## DOM Events

DOM Event Listeners happen in parallel with the JavaScript run time. When an event occurs, the event listener detects the event and executes an event handler to put a task on the event queue. The task will eventually make its way to the call stack to be executed.

If multiple events are detected, multiple tasks will be put on the event queue in the order in which they occurred. When the call stack is empty, the first task on the event queue is pushed onto the call stack. When this task finishes, the cycle continues and the next task on the event queue is pushed onto the call stack. Thus, if a certain task takes a long time to finish, the tasks behind it on the event queue will have to wait.

### Types of HTML DOM Events

Here are some examples of HTML DOM Events:

* **Click Event:** Occurs when a user clicks a DOM element
* **Mouseenter Event:** Occurs when a pointer is moved over an element
* **Mouseleave Event:** Occurs when a pointer is moved out of an element
* **Keypress Event:** Occurs when a key is pressed

### Referencing DOM Elements

DOM elements can be referenced using the `document.getElementById(id)` method call if the DOM element has an id attribute defined.

```javascript
addEventListener()
```

The `addEventListener(eventType,eventHandler)` method call is used to add an event listener to a DOM object. The eventType argument is a string that represents the type of event that is being listened for. The `eventHandler` is a callback function that handles the event once it is detected.

### Event Attributes

DOM elements have event attributes that can be used to handle events. Here are several of the attributes that can act as event attributes:

* onclick - handles click events
* onmouseover - handles mouseover events
* onmouseleave - handles mouseleave events
* onkeypress - handles keypress events

The general format for the name of the event attributes is: "on" + "eventType". Event handler functions can be assigned to the event attributes to handle events.

## Promises

Promises are containers for values that are not yet available yet but may eventually become available. Promises are important, because promises are becoming the standard way to handle asynchronous functions in JavaScript.

```javascript
var promise = new Promise(function(resolve, reject) {
  var isSuccessful = true;
  if (isSuccessful) { 
    // If everything is successful
    resolve("Success!");
  }
  else {              
    // If something went wrong*/
    reject(Error("Failure."));
  }
});

promise.then(function(val){
  // val represents the fulfillment value
  console.log(val);//logs "success!" since promise resolved
})
.catch(function(val){
  // val represents the rejection value
  console.log(val); //doesn't occur since promise never rejected
});
```

### Creating a new Promise

**`new Promise()`**

The `new Promise()` constructor is called to create a new promise. The constructor takes in a callback function with the arguments `resolve` and `reject`.

**`resolve()`**

The `resolve()` function is used to change the status of the promise from pending to fulfilled. The value that is passed inside the `resolve()` function becomes the fulfillment value of the promise. Once the `resolve()` function is called, future `resolve()` and `reject()` calls no longer have any effect.

**`reject()`**

The `reject()` function is used to change the status of the promise from pending to rejected. The value that is passed inside the `reject()` function becomes the rejection value of the promise. Once the `reject()` function is called, future `resolve()` and `reject()` calls no longer have any effect. The resolve function can take in any object as an argument, but one common practice is to pass in a Error object because it provides a more detailed error report. 

### Using Promises with Then() and Catch()

The `then()` and `catch()` methods are used to handle the results of Promises once they have finished pending. The `then()` method is used to handle resolved Promises while the `catch()` method is used to handle rejected Promises. Both of the methods use callback functions. The callback functions should each have one argument representing the Promise result.

### Transforming Value

Promise results can be transformed by calling the return statement within the `then()` callback. This will cause the `then()` method to return a `new Promise` with the transformed result.

```javascript
var promise_01 = Promise.resolve("hello");

var promise_02 = promise_01.then(function(result) { 
  console.log(result); //-> hello
  return result + " world";
}); 

promise_02.then(function(result){
  console.log(result); //-> hello world
});
```

**Chaining Transforms**

Several transforms can be chained together using multiple `then()` method calls.

```javascript
var promise = Promise.resolve([1,2,3,4]);

promise.then(function(result) { 
  console.log(result) //-> [1,2,3,4] 
  return result.map(x => x * x);
})
.then(function(result2){
  console.log(result2) //-> [1,4,9,16]
  return result2.filter( x => x > 10);
})
.then(function(result3){
  console.log(result3) //-> [16]
  return result3.toString() + "!!";
})
.then(function(result4){
  console.log(result4) //-> "16!!"
  return result4;
})
.catch(function(error){
  console.log(error)
});
```

### Handling Multiple Promise

**Promise.all()**

The Promise.all() method is used to process multiple Promises at the same time. The method takes in an array of Promises and then waits for them to all to resolve. Once they have all finished resolving, an array of results can be obtained by using the `then()` method. If any of the Promises reject, then the Promise.all() method will return the first rejected Promise.

```javascript
let promise_01 = Promise.resolve('hello'); 
let promise_02 = Promise.resolve({age:2,height:188}) 
let promise_03 = Promise.resolve('worlds');

let promise = Promise.all([promise_01,promise_02,promise_03])
promise.then(function(result) { 
  console.log(result); //-> ["hello", Object, "worlds"]
}).catch(function(error){
  console.log(error); 
});
```

Rejected case:

```javascript
let promise_01 = Promise.resolve('hello'); 
let promise_02 = Promise.resolve({age:2,height:188}) 
let promise_03 = Promise.reject('worlds');

let promise = Promise.all([promise_01,promise_02,promise_03])
promise.then(function(result) { 
  console.log(result); //-> "worlds"
}).catch(function(error){
  console.log(error); 
});
```

**Promise.Race()**

The Promise.race() method takes in an array of promises and takes the result of the promise that rejects or resolves the fastest. Like normal promises, the `then()` and `catch()` methods are used to retrieve the results of the fastest promise.

The Promise.race() method can be used to choose the quickest source when there are two similar sources of the same data.

```javascript
function delayedResolve(time){
  return new Promise(function(resolve, reject){
    setTimeout(function(){
      resolve("resolved in " + time);
    })
  })
}

function delayedReject(time){
  return new Promise(function(resolve, reject){
    setTimeout(function(){
      reject("reject in " + time);
    })
  })
}

let promise_01 = delayedResolve(500);
let promise_02 = delayedReject(200);
let promise_03 = delayedResolve(100);

let promise = Promise.race([promise_01, promise_02, promise_03]);
promise.then(function(result){
  console.log(result);
})
.catch(function(error){
  console.log(error);
});
```

## Fetch API

The Fetch API is an interface that is used to make network requests. The Fetch API is a much needed improvement over XMLHttpRequest, the old API for making network request. The Fetch API is built into most modern browsers and also returns Promises.

```javascript
fetch("https://jsonplaceholder.typicode.com/todos/1") 
.then(function(result){ 
	console.log(result); 
}); //-> Response {type: "cors", url: "https://jsonplaceholder.typicode.com/todos/1", status: 200, ok: true, statusText: ""…}
```

### Extracting data from a Response object

A Response object has several methods that are used to extract the fetched data. Here are the common extraction methods:

* **`json()`:** is used to extract a json object.
* **`text()`:** is used to extract a text string.
* **`blob()`:** is used to extract a file-like object.

```javascript
fetch("https://jsonplaceholder.typicode.com/todos/1") 
.then(function(result){ 
  return result.json() 
})
.then(function(result){
  console.log(result);
}); //-> Object {userId: 1, id: 1, title: "delectus aut autem", completed: false}
```

### Handling Fetch Responses

Example checking the response status, It is important to check the status of the Response object that is fetched. A status between 200-299 means that the request was somewhat successful while statuses in the 400s or 500s mean that problems have occurred. 

```javascript
fetch("https://jsonplaceholder.typicode.com/todos/1") 
.then(function(result){ 
  console.log(result);
  if(result.ok) { 
    return result.text(); 
  }
  else { 
    console.log(result.status) //logs 404
    return Promise.reject(result.status); 
  } 
})
.then(function(result){
  console.log(result);
}) //-> {"userId": 1,"id": 1,"title": "delectus aut autem","completed": false}
.catch(function(err){
  console.log("Error: " +  err);
}); //-> "Error: 404", handles the rejected promise
```

### Customizing Fetch Setting

The `fetch()` method can also take in an optional init object. This object applies custom settings to the Fetch request.

```javascript
let initObject = {
  method: 'POST',
  headers: new Headers(),
  mode: 'cors',
  body: "{}" 
}

fetch("https://jsonplaceholder.typicode.com/posts", initObject)
.then(function(result){ 
  return result.json() 
})
.then(function(result){
  console.log(result);
})
.catch(function(err){
  console.log(err);
}); //-> Object {id: 101}
```

**Method**

The method attribute is a string that is used to specify the HTTP request method type. Here is a list of some commonly used method types:

* **Get:** used to retrieve an existing data resource.
* **Head:** used to retrieve HTTP headers.
* **Post:** used to create a new data resource.
* **Put:** used to create a new data resource or modify an existing data resource.
* **Delete:** used to delete a data resource.

**Body**

The body attribute is a JSON string used to send data along with a fetch request. If the body value is an object, it is important to stringify the object that is being sent using `JSON.stringify()` or it will not process correctly. Get and Head HTTP requests can not have bodies.

**Headers**

The headers attribute is used to add more information about the resource being fetched or the client doing the fetching. A Headers object can be created using the new `Headers()` constructor and individual headers can be added to the Headers object through the `append()` method.

**Mode**

The mode attribute is a string that is used to determine whether or not the Fetch request can fetch resources from different servers.

In this course we will cover the following two mode types:

* **same-origin:** the Fetch request can only fetch resources from the same server.
* **cors (cross origin HTTP request):** the Fetch request can fetch resources from different servers.

### Using Fetch with Requests

The `fetch()` method can take in a Request object instead of an URL and an init object. The Request constructor takes in the same parameters as the `fetch()` method, an URL and an optional init object. Request objects are used because they make Fetch requests a bit cleaner and also offer a bit more control.

```javascript
var initObject = {
  method: 'POST',
  headers: new Headers(),
  mode: 'cors',
  body: "{}" 
}

var request = new Request("https://jsonplaceholder.typicode.com/posts", initObject)

fetch(request).then(function(result){ 
  return result.json() 
}).then(function(result){
  console.log(result); //-> Object {id: 101}
}).catch(function(err){
  console.log(err);
});
```

**Reusing Request Objects***

Requests with Bodies(POST, PUT)

If a Request object is used more than once in a Fetch request that involves bodies (POST, PUT) it will throw an error.

```javascript
var initObject = {
  method: 'POST',
  headers: new Headers(),
  mode: 'cors',
  body: "{}" 
}

var request = new Request("https://jsonplaceholder.typicode.com/posts",initObject)

fetch(request).then(function(result){  
  return result.json() 
}).then(function(result){
  console.log(result);
}).catch(function(err){
  console.log(err);
});


fetch(request).then(function(result){
  return result.json();
}).catch(function(err){
  console.log(err.message)
  //-> "Failed to execute 'fetch' on 'Window': Cannot construct
  //    a Request with a Request object that has already been used."
});
```

**Requests without Bodies (GET, HEAD)**

However, Request objects can be used more than once in Fetch requests that don't involve bodies(Head,Get).

## Generators

Generators are functions that can be paused and resumed. Generators can send out values when pausing and take in values when resuming.

### Creating a Generator Function

`function*` Keyword, Generator functions look similar to regular functions, except that they have an asterisk (*) after the function keyword. This syntax may look similar to the pointer notation from other languages, but it is unrelated.

```javascript
function* genFunc() {
  yield console.log('lorem');
  yield console.log('ipsum');
  return 'done';
}

const gen = genFunc();

gen.next(); //-> lorem
gen.next(); //-> ipsum
console.log(gen.next().value); //-> done
```

**Yield Keyword**

The `yield` keyword is used to pause the generator. The `yield` keyword may also be used to receive input and send output from the generator.

```javascript
yield console.log('lorem'); // pause the generator ans send out
yield console.log('ipsum'); // pause the generator ans send out
```

**Return Value**

Generator Functions have an optional return value. Omitting the return value is equivalent to returning an undefined value. The return value of Generator functions is often left unused.

### Iterating through a Generator Object

A Generator Object is returned from calling a Generator function. It is important to not confuse Generator Objects with Generator functions. 

Generator Objects conform to the iterator protocol and may be iterated with the `next()` method.

Generator functions are initially paused and the first call to `next()` starts the Generator function. The Generator function then runs until it hits the first yield keyword and then pauses. Subsequent calls to `next()`  will resume the Generator function until the next yield keyword appears.

The `next()` method returns an object with two properties:

* **done:** a boolean indicating whether the Generator function has processed all of the yield statements or has already returned. 
* **value:** the value associated with the most recent yield statement.

After all of the yield statements have been processed with `next()`, the following `next()` call returns an object with a value property equal to the Generator function return value and a done property set to true. If the return statement was omitted from the Generator function then the value property will be undefined. After the the done property is true in one of the returned objects, additional `next()` calls will return objects with an undefined value property and a true done property. Yield statements after the return statement are ignored.

### Throwing Errors from within a Generator Function

If an error is encountered within a Generator function, then the error will be thrown by the `next()` call that encounters the error. The `next()` call that throws the error will return an undefined value and additional yield statements after the error are ignored. Additional `next()` calls after the error will also return undefined values.

```javascript
function* genFunc() {
  yield 'a';
  yield 'b';
  throw new Error("error thrown by genFunc()!");
  yield 'c';
  yield 'd';    
}

var genObject = genFunc();

try {
  console.log(genObject.next().value); //-> a
  console.log(genObject.next().value); //-> b
  console.log(genObject.next().value); //-> error thrown by genFunc()!
  console.log(genObject.next().value); // undefined, other yield statements are ignored after the error
}
catch(e) {
  console.log(e.message);
}
```

### Yielding to other Generators

The `yield*` keyword is used to call another Generator function within a Generator function.

```javascript
function* genFuncA() {
  yield 'a';
  yield 'b';
  yield 'c';
  return "done with genFuncA()!"      
}

function* genFuncB(){
  yield 1;
  yield* genFuncA(); // contains iterable [a,b,c]
  yield 2;
  yield 3;
  return "done with genFuncB()!";
}

var genObject = genFuncB();

console.log(genObject.next().value); //-> 1
console.log(genObject.next().value); //-> a
console.log(genObject.next().value); //-> b
console.log(genObject.next().value); //-> c
console.log(genObject.next().value); //-> 2
console.log(genObject.next().value); //-> 3
console.log(genObject.next().value); //-> done with genFuncB()!
```

The `yield*` statement does not add the return value of the generator function that it calls to its list of iterables. Instead, the return value may be accessed by the return value of the `yield*` statement.

```javascript
function* genFuncA() {
  yield 'a';
  yield 'b';
  return "done with genFuncA()!"      
}

function* genFuncB(){
  yield 1;
  let returnVal = yield* genFuncA(); 
  yield returnVal; 
  yield 2;
  return "done with genFuncB()!";
}

var genObject = genFuncB();

console.log(genObject.next().value); //-> 1
console.log(genObject.next().value); //-> a
console.log(genObject.next().value); //-> b
console.log(genObject.next().value); //-> done with genFuncA()!
console.log(genObject.next().value); //-> 2
console.log(genObject.next().value); //-> done with genFuncB()!
```

The `yield*` statement can be used on any iterable in addition to Generator functions.

```javascript
function* genFunc(){
  yield 1;
  yield* [2,3,4]; 
  yield 5;
}

var genObject = genFunc();

console.log(genObject.next().value); //-> 1
console.log(genObject.next().value); //-> 2
console.log(genObject.next().value); //-> 3
console.log(genObject.next().value); //-> 4
console.log(genObject.next().value); //-> 5
```

### Sending Input to Generator Functions

Sending input using `next()`, In addition to iterating through Generator Objects, `next()` can also be used to send values back into Generator functions. This is accomplished by passing a value into the next() method call as an argument. The value that is passed into the `next()` method call eventually becomes the return value of the most recent yield statement. Since the first `next()` call starts the Generator function, any value that gets passed into it will be ignored.

```javascript
function* genFunc(){
  var a = yield;
  console.log(a);
  var b = yield;  
  console.log(b); 
  var c = yield;
  console.log(c); 
}

var genObject = genFunc();

genObject.next(0); 
genObject.next(1); //-> 1
genObject.next(2); //-> 2
genObject.next(3); //-> 3
```

The `next()` method can also be used to modify the values sent by the yield statement and send them back.

```javascript
function* genFunc(){
  var a = yield 'a';
  console.log(a); // a = 'a!'
  var b = yield 'b';  
  console.log(b); // b = 'B'
  var c = yield 'c';
  console.log(c); // c = 'abc'
}

var genObject = genFunc();

var w = genObject.next(); 
var x = genObject.next(w.value + '!'); //-> a!
var y = genObject.next(x.value.toUpperCase()); //-> B
var z = genObject.next(w.value + x.value + y.value); //-> abc
```

### Other Methods to Iterate

**For Of**

```javascript
function* genFunc(){
  yield 'a';
  yield;  
  yield* [1,2,3];
  yield 123;
  return "finished";
}

for (var x of genFunc()){ //for...of statement
  console.log(x); 
}
//-> a undefined 1 2 3 123
```

**Spread Operator**

```javascript
var arr = [...genFunc()];
console.log(arr); //-> ["a", undefined, 1, 2, 3, 123]
```

**Destructuring**, destructuring assignment

```javascript
var [a,b,c,d,e,f,g] = genFunc();
console.log(a,b,c,d,e,f,g); //-> a undefined 1 2 3 123 undefined
*/
```

### Return()

Generator Objects have a `return()` method that terminates the Generator function. `return()` causes a return statement to be performed at the most recent yield statement. The `return()` method takes in one optional variable that is used as the return value of the Generator function. Calling return(x) will return an object with a value property equal to x and a done property of true. After `return()` is called, subsequent yield statements in the Generator function are ignored. 

### Throw()

Generator Objects have a `throw()` method that causes an error to be thrown at the most recent yield statement. The `throw()` method takes in one argument, which is commonly an `Error object`.

### Generator with Asynchronous Function

```javascript
// API Json Data
/*
{
  "name": "imoralescs",
  "userId": 1,
  "id": 1,
  "title": "sunt aut facere repellat provident occaecati excepturi optio reprehenderit",
  "body": "quia et suscipit\nsuscipit recusandae consequuntur expedita et cum\nreprehenderit molestiae ut ut quas totam\nnostrum rerum est autem sunt rem eveniet architecto"
}
*/

// Generator to get and display avatar
// It yields promises
function* showUserAvatar() {
  // User Page Info
  let userFetch = yield fetch(`https://api.myjson.com/bins/7yj2j`);
  let userInfo = yield userFetch.json();

  // User Github Info
  let githubFetch = yield fetch(`https://api.github.com/users/${userInfo.name}`);
  let githubUserInfo = yield githubFetch.json();

  let img = new Image();
  img.src = githubUserInfo.avatar_url;
  img.className = "promise-avatar-example";
  document.body.appendChild(img);

  yield new Promise(resolve => setTimeout(resolve, 3000));

  img.remove();

  return img.src;
}

// Auxiliary laborer function
// To perform promises from the generator
function execute(generator, yieldValue) {
  let next = generator.next(yieldValue);
  
  if (!next.done) {
    next.value.then(
      result => execute(generator, result),
      err => generator.throw(err)
    );
  } 
  else {
    // process the result return from the generator
    // usually here call callback or something like that
    console.log(next.value);
  }
}
execute(showUserAvatar());
```

## Observables
