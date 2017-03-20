# Javascript

Javascript was developed by Netscape in 1995 to create product and application that run in the browser, its is primarily client-side. To work with JavaScript, they are some term, you need to understand.

## Script Tag

Everything start with where we write the Javascript code to be execute. The script tag is used for specifying JavaScript which should run in a web page. A script tag can either include the JavaScript directly, or it can point to a URL where the script should be loaded from. Script tags are executed in the order they appear.

```html
<script>
  var x = 3;
  alert(x);
</script>

// External resource
<script src="https://example.com/example-framework.js"></script>
```

This mean you can significantly slow down your site if you have slow script loading early in the page. Also means script which appear later on the page can depend on things scripts which appear earlier have done.

Elements on the page won't render until all script tags preceding them have loaded and executed. This means you can do all sorts of tweak to performance the page.

### Where to place the script tag

Script position in the DOM affect when they run.

```html
<html>
  <head>
    <script>
      // document.head is available
      // document.body is not!
    </script>
  </head>
  <body>
    <script>
      // document.head is available
      // document.body is available
    </script>
  </body>
</html>
```

### Using attribute on script tag for external call

* **Script:** Without any attribute, HTML file will parsed until script file hit. At that point parsing will stop and a request will made to fetch the file external.

* **Async:** Download the file during HTML parsing and will pause the HTML parser to execute it when it has finish download. Will start running before the load event gets fired.

* **Defer:** Download the file during HTML parsing and will only execute it after the parser has completed. Before DOMContentLoaded event get fired.

### Encoding and tag META

When you try save file, you may encounter a problem. To all was well, you need to:

1. Make sure that the HEAD there is a line `<meta charset="utf-8">`.
2. Make sure that the editor retains the file is in UTF-8.

### Integrity Attribute

The integrity attribute is a part of the new Subresource Integrity spec. It allows you to provide a hash for the contents which a script file should contain. It’s meant to prevent a nefarious actor from messing with the contents of a script tag over the wire. In a world with SSL, this is only really valuable if you’re loading a script from some external source you don’t control like jquery

```html
<script
  src="//code.jquery.com/jquery.js"
  integrity="sha384-oqVuAfXRKap7fdgcCY5uykM6+R9GqQ8K/uxy9rx7HNQlGYl1kPzQho1wx4JwY8wC">
</script>
```

## Variable

Variable consists of a name and a dedicated memory, which corresponds to it. The value is an individual program entities in the programming process can recreate mathematical expression, this expression creates a new value from existing values. This is where the variable represents something important variables allows us to store and retrieve data or mathematical expression in our program.

To declare or, in other words, to create a variable keyword is used var:

```javascript
var message;
```

After that we can write in the variable data:

```javascript
var message;
message = "Hello Worlds!";
```

### Variable Names and Constants

Only have two restriction:

1. Name can consist of letters, number, symbols, $, and _
2. The first character must not be a digit.
3. Good practices of name constant is all letter on uppercase.

### Constants

Is like a variable that we can create and can be read-only. We create this with `const` keyword.

```javascript
const AREA_CODE = 787;
```

## Data Type

### Types

On Javascript we no have the concepts of classes, they only have two kind of types. Primitive and reference. Primitive types are stored as simple data type (Number, String, Boolean, Null, Undefined) and Reference or Complex type are stored as objects, which are really just reference to locations in memory.

#### Primitives

**Number**

A single type of number used for both integer and fractional numbers for. 

```javascript
var n = 123;
n = 12.345;
```

**String**

In Javascript single and double quotes are equal, you can use either one or the other. 

```javascript
var str = "Hello Worlds!"; 
str = 'New Sentences'; 
```

**Boolean**

He has only two meanings: true (the truth), and false (false).

```javascript
var checked = true;
```

**Special Value Null and Undefined**

The value null is not related to any of the above types, and forms a separate type, consisting of a single value of null:

```javascript
var age = null; 
```

In the JavaScript null is not a "reference to a null object" or "null pointer" in some other languages. It is simply a special value that is worth "nothing" or "value unknown".

The value undefined , is null , forms his own style, consisting of one of this value. It has the meaning of "no value".

If the variable is declared, but it is nothing recorded, its value is precisely undefined :

```javascript
var x; 
console.log( x );
```

#### Reference or Complex

**Objects**

The first five types are called "primitive". Is a container for a collection of value. It is used for data collection and for the announcement of more complex entities.

**Object Structure**

```javascript
Object {
  properties/key : properties/value
}
```

Declare objects using the curly braces {...} , for example:

```javascript
var user = { name: "Jack" };
```

### Typeof Operator

To identify primitive type is with the typeof operator. Operator typeof returns the type of the argument. He has two syntax: with and without brackets:

1. Syntax: `typeof x`.
2. Its syntax is: `typeof(x)`.

They work the same way, but the first syntax is shorter.

## Operator With Primitive Types

### Arithmetics

```javascript
// Assignment 
var x = 10;
var y = 10;
```

```javascript
// Multiply, Divide, Add
const x = 7;
const result = x * 2;
console.log(result); //-> 14
```

```javascript
// Short assingment and avoid duplication.
y += 5;
console.log(y);
```

```javascript
// Remainder
const x = 7;
const result = x % 6;
console.log(result); //-> 1
```

```javascript
// Increment (add one to)
let x = 7;
x++;
console.log(x); //-> 8
```

```javascript
// String Concatenation
let s = "Hello";
const result = s + ", Worlds!"
console.log(result); //-> Hello, Worlds!
```

```javascript
// Test Equal
let x = 7;
console.log(x == 7); //-> true
console.log(x == 8); //-> false
```

```javascript
// Conditionals
let x = 7;
console.log(x < 8); //-> true
```

### Boolean Operator 

Common used on conditional statement.

```javascript
// == Equality, != Inequality 
let x = 2;
if(x == 2) {
  console.log("Execute 1");
}
//-> Execute 1

if(x != 2) {
  console.log("Execute 1");
}
else {
  console.log("Execute 2");
}
//-> Execute 2

// === Equality Object Identical
let x = 2;
if(x == "2") {
  console.log("Execute 1");
}
//-> Execute 1

if(x === "2") {
  console.log("Execute 1");
}
else {
  console.log("Execute 2");
}
//-> Execute 2
```

### Comparing Without Coercion

Triple equal operator instead of the double equal operator. The reason is that triple equals does the comparison without coercing the variable to another type.

```javascript
console.log("5" == 5); //-> true
console.log("5" === 5); //-> false
console.log(undefined == null); //-> true
console.log(undefined === null); //-> false
```

## Statements

### If

The operator if is a condition in the example above.

```javascript
var year = 2011;
if(year != 2011) { 
  console.log( 'year is 2011..' ); 
  console.log( '..this condition is true!' ); 
} 
```

Operator Question Mark "?" Is a shorted way to if. It has the form of: 

```javascript
condition ? value-if-true : value-if-false 
```

Think of the ? as "then" and : as "else"

```javascript
var age = 11;
age > 18 ? console.log("true") : console.log("false"); //-> false

var age = 20;
age > 18 ? console.log("true") : console.log("false"); //-> true
```

### If...Else

```javascript
var data = 6;

if(data < 5) {
  result = 'Block Code 1';
  console.log(result);
}
else {
  result = 'Block Code 2';
  console.log(result);
}

var message;
var login = "Jack";

if(login == 'John') {
  message = 'Hello John';
  console.log(message);
} 
else if(login == 'Jack') {
  message = 'Hello Jack!';
  console.log(message);
} 
else if(login === '') {
  message = 'Please type login!';
  console.log(message);
} 
else {
  message = 'Hmmm!';
  console.log(message);
}
```

### Switch

It is a more intuitive way to compare an expression with several options.

```javascript
switch(x) {
  case 'value1':  
    // if (x === 'value1')
    // Block Code
    break;
  case 'value2':  
    // if (x === 'value2')
    // Block Code
    break;
  default:
    // Block Code
    break;
}
```

### Throw

Allow us to create a costume error with `throw 'Custom Error'`.

```javascript
if(x === 9) {
  console.log('x is ' + x);
}
else {
  throw 'Error: x should contain the value of 10';
}
```

### Try Catch & Finally

Allow us to define a block of code to be test for error while be executing.

```javascript
let age = 10;

try {
  if( age < 12) {
    throw "Children are not allowed";
  }
  if(age > 95) {
    throw "Maximum age allowed is 95";
  }
}
catch(err) {
  console.log("Error: " + err);
}
finally {
  console.log('Test Completed');
}
//-> Error: Children are not allowed
//-> Test Completed
```

## Loops

### While

```javascript
var i = 0; 

while(i < 3) { 
  console.log(i); 
  i++; 
}
```

### Do While

```javascript
var i = 0; 

do { 
  console.log( i ); 
  i++; 
} 
while(i < 3); 
```

### For

```javascript
var i; 
for(i = 0; i < 3; i++) { 
  console.log( i ); 
} 
```

* **Start:** `i = 0`
* **Conditions:** `i < 3` 
* **Step:** `i++` 
* **Body:** `console.log( i )`

In the code within the curly braces (they are not mandatory unless a single operation)

## Function

Function are the pieces where you will wrap all your code, is a process which takes some input, called arguments or parameters, and produces some output called a return value. They are the primary unit of execution. Functions may serve the following purposes:

* **Mapping:** Produce some output based on given inputs. A function maps input values to output values.
* **Procedures:** A function may be called to perform a sequence of steps. The sequence is known as a procedure, and programming in this style is known as procedural programming.
* **I/O:** Some functions exist to communicate with other parts of the system, such as the screen, storage, system logs, or network.

Function can be see it as function declaration or function expession(named & anonymous). Function can be declared using the `function` keyword and a name.

```javascript
var square = function(x){
  return x * x;
}

console.log(square(12));
// 144
```
The `return` statement determines the value the function returns. Function without return statement always return a default value, which is `undefined`. The only exception is when a new object is created calling a constructor function using `new` keyword. In this case default return value will be the value `this`.

```javascript
function Intro() {
  console.log(this);
}

Intro();
// Window

var intro = new Intro();  
// Intro {}
intro;
```

Functions can also be treated as values, meaning you can assign them to variables and pass and return them to and from functions as well. These are referred to as first-class functions and lead to higher-order functions when working in a more declarative, functional style of programming.

### Function as Data

```javascript
var validateDataForAge = function(data) {
  person = data();
  console.log(person);
  
  if (person.age <1 || person.age > 99) {
    return true;
  }
  else {
    return false;
 }
};

var errorHandlerForAge = function(error) {
  console.log("Error while processing age");
};

function parseRequest(data, validateData, errorHandler) {
  var error = validateData(data);

  if (!error) {
    console.log("no errors");
  } 
  else {
    errorHandler();
  }
}

var generateDataForScientist = function() {
  return {
    name: "Albert Einstein",
    age : Math.floor(Math.random() * (100 - 1)) + 1,
  };
};

var generateDataForComposer = function() {
  return {
    name: "J S Bach",
    age : Math.floor(Math.random() * (100 - 1)) + 1,
  };
};

// Parse Request
parseRequest(generateDataForScientist, validateDataForAge, errorHandlerForAge);
// -> {name: "Albert Einstein", age: 42} no errors
parseRequest(generateDataForComposer, validateDataForAge, errorHandlerForAge);
// -> {name: "J S Bach", age: 87} no errors
```

### Function Input

Functions need input, sometimes hear people refer to them as "arguments" and sometimes as "parameters". Parameters to a function behave like regular variables. But their initial values are giving by the caller of the function. Arguments are the values you pass in, and parameters are the named variables inside the function that receive those passed in values.

**Counting Inputs**

Function arguments or arity of a function refers to the number of arguments a function expects. Every function scope in JavaScript can access the special variable `arguments`. This variable holds a list of all the arguments that were passed to the function.

The `arguments` object is not an Array. While it has some of the semantics of an array namely the `length` property it does not inherit from `Array.prototype` and is in fact an `Object`.

Due to this, it is not possible to use standard array methods like `push`, `pop` or `slice` on arguments. While iteration with a plain `for` loop works just fine, it is necessary to convert it to a real `Array` in order to use the standard Array methods on it.

```javascript
function foo(x,y,z) {
  // ..
}

foo.length; //-> 3	
```

**Converting to an Array** 

```javascript
function has() {  
  let args = [].slice.call(arguments);
  args.forEach((arg) => console.log(arg));
}
has(1,2,3,4); 
```

or 

```javascript
function has() {  
  let args = Array.prototype.slice.call(arguments);
  args.forEach((arg) => console.log(arg));
}
has(1,2,3,4); 
```

### Invoking functions

Invoking a function is done using the () operator on the function name or variable holding the function expression. 

```javascript
var foo(){ /* do foo */ }   // declaration  
foo();   // invoke

(function baz() {           // IIFE
   console.log("baz!");
})();
// "baz!"

var bar = function(){ /* do bar */ };  // expression  
bar();   // invoke  
```

### Immediately-Invoked Function Expression (IIFE)

An IIFE is an anonymous function that is created and then immediately invoked. It’s not called from anywhere else (hence why it’s anonymous), but runs just after being created.

```javascript
var x = (function calc() {
  return 2 * 2;
})();

console.log(x); //-> 4 
```

## Scope

Scope is a set of variable you have access to, we have global scope, the main scope of you app, is where any variable can be access. 

### Lexical Scope

Every scope is a lexical scope on javascript. 

```javascript
var getSponsor = function(info) {
  // This is a new Lexical Scope
}
```

To explain lexical scope, we have rules, every variable define in the global scope is accessible in any other part of you program, however if this variable are define in a new lexical scope, like inside of function. You can not access to variable inside of function if you try get that variable from parent scope. 

### Closure

A closure is an inner function that has access to the outer variables scope chain. The closure has three scope chains: it has access to its own scope (variables defined between its curly brackets), it has access to the outer variables, and it has access to the global variables.

```javascript

var closureFunction = function(name){
  var text = 'Hello ' + name;
  return function(){
    console.log(text);
  };
};

closureFunction('John');
// Nothing happens

var runClosure = closureFunction('John');
runClosure();

// Only way to call only the closure is using another parentheses.
closureFunction('Jack')();
```

## This Keyword

On right theory is a value who decided when an execution context is created. When the original context where this is declared changes, what this refers to also changes. 

### Execution context

Refers to the environment or what is around in which a piece of JavaScript code execute. It is test, check into one of three environment.

Note to remember:

* **Invocation:** Execution the code that makes the body of a function.
* **Context:** of an invocation is the value of this within function body.
* **Scope:** of a function is a set of variable, object, function accessible within a function body.

### Global execution context

The default, implicit environment, where your code is not part of any function.

```javascript
this === window; // true
```

### Function execution context

Context that is created in order to run the code within function, the destroyed after the function execution. There are four rules of precedence that can be used to determine what this gets bound to. First let's review a function:

```javascript
// Function declaration
var baz = function(){
  // Function body
};

// Invocation of function
baz();
```

### They are 5 pattern for knowing, what this special variable is bound to in call time

**Pattern 1:** Global

```javascript
console.log(this);// Window{..}
```

**Pattern 2:** Function invocation(Default binding)

When you invoke a function declaration or a function expression the `this` keyword will be bound to the global object, which in the browser is the window object. ES6 this get the value undefined.

```javascript
// Function declaration
var baz = function(){
  // Function body
  console.log(this);
};

// Invocation of function
baz(); //-> window/global
```

**Pattern 3:** Method invocation(Implicit binding)

When you invoke a method the `this` value will be bound to that object.

```javascript
var baz = {
  foo : function() {
    console.log(this); 
  }
};

baz.foo(); //-> baz{}
```

**Pattern 4:** Constructor invocation(New binding)

When a function invocation processed by the new keyword `this` will be bound to the newly created object.

```javascript
var Person = function(){
  this.name = 'Some Name';
}

var person = new Person();
console.log(person.name); //-> 'Some Name'

person.name = 'Other Name';
console.log(person.name); //-> 'Other Name'
```

**Pattern 5:** Explicit binding

Allow to reference to who apply `this` key. We can explicitly set what `this` keyword will be bound to using one of the following: .call() .apply() .bind().

```javascript
var logger = function() {
  console.log(this);
}

var user1 = {
  logMessage: logger
};

var user2 = {
  logMessage: logger
}

user1.logMessage(); // user1
user2.logMessage(); // user2

// Call or Apply : Allow to reference to who apply this 
user1.logMessage.call(user2); //-> user2
```

## Call & Apply

The `.call()` and `.apply()` methods they allows you to pass or apply function to array of argument, into another function. Instead of individual arguments.

```javascript
// Example 1:
var sayHi = function(who){
  return "Hello" + (who ? ", " + who : "") + "!";
};

console.log(sayHi()); //-> Hello!
console.log(sayHi('World')); //-> Hello, World!
console.log(sayHi.apply(null,["Jack"])); //-> Hello, Jack!

// On this case first argument is null, this target to global object.
var alien = {
  sayHi: function(who){
    return "Hello" + (who ? ", " + who : "") + "!";
  }
};

console.log(alien.sayHi("Alien")); //-> Hello, Alien!
console.log(sayHi.apply(alien,["John"])); //-> Hello, John!
console.log(sayHi.call(alien,"Peter")); //-> Hello, Peter!

// Example 2:
name = 'Default';
var person1 = {name: 'Marvin'};
var person2 = {name: 'Zaphod'};

var sayHello = function(){
  console.log('Hello, ' + this.name);
};

var sayGoodbye = function(){
  console.log('Goodbye, ' + this.name);
};

sayHello(); //-> Hello, Default
sayGoodbye(); //-> Goodbye, Default

sayHello.call(person1); //-> Hello, Marvin
sayGoodbye.call(person2); //-> Goodbye, Zaphod

sayHello.apply(person1); //-> Hello, Marvin
sayGoodbye.apply(person2); //-> Goodbye, Zaphod
```

## Bind

Similar to Call and Apply we using Bind to manipulate the Execution Content of an object or function. When you call bind you are really passing one Execution Context to another Execution Context.

```javascript
var obj = {
  objName: 'John Doe',
  getObjName: function(){
    return this.objName;
  }
} 

var greetObj = function(){
  console.log("Hello " + this.getObjName());
}

var newObj = greetObj.bind(obj);
newObj();
```

## Array Data Structure

Are list of values, They are used to store multiple values written as a list between square brackets, separated by commas.

### Array Allocation

```javascript
let primes = [2,3,5,7,11,13];
let names = ["Joe", "Jane", "John", "Juan"];
```

### Array Allocation

```javascript
console.log(primes[1]); //-> 3
console.log(names[2]); //-> John
```

### Know Length Property

```javascript
const result = names.length;
console.log(result); //-> 4
```

Javascript offers several way to add, remove and replace items in an array, some of these way mutate the array and other non-mutating.

### Add Element To Array

The mutating method for adding element to an array are:
	
* **array.push():** Adds an item to the end of the array.
* **array.unshift():** Adds an item to the beginning of the array.

```javascript
var mutatingAdd = ['a', 'b', 'c', 'd', 'e'];

mutatingAdd.push('f');
console.log(mutatingAdd); //-> ["a", "b", "c", "d", "e", "f"]

mutatingAdd.unshift('z');
console.log(mutatingAdd); //-> ["z", "a", "b", "c", "d", "e", "f"]
```

Non-mutating have two way to add new items to an array without mutating the original array. The first one is with the .concat() and using the spread operator.

```javascript
const arr1 = ['a', 'b', 'c', 'd', 'e'];

const arr2 = arr1.concat('f');

console.log(arr1); //-> ["a", "b", "c", "d", "e"]
console.log(arr2); //-> ["a", "b", "c", "d", "e", "f"]

const arr1 = ['a', 'b', 'c', 'd', 'e'];

const arr2 = [...arr1, 'f'];
console.log(arr2); //-> ["a", "b", "c", "d", "e", "f"]

const arr3 = ['z', ...arr1];
console.log(arr3); //-> ["z", "a", "b", "c", "d", "e"]
```

### Remove Element To Array

Remove method with mutation for removing from an array are:

* **array.pop():** Removes an items at the end of the array.
* **array.shift():** Removes an items at the beginning of the array.

```javascript
let mutatingRemove = ['a', 'b', 'c', 'd', 'e']; 

mutatingRemove.pop(); 
console.log(mutatingRemove); //-> ["a", "b", "c", "d"]

mutatingRemove.shift(); 
console.log(mutatingRemove); //-> ["b", "c", "d"]
```

In this case you can catch the delete item in a variable.

```javascript
const returnedValue = mutatingRemove.pop();  
console.log(returnedValue); //-> d
```

Array.splice also removing items from array, they take two parameter.

```javascript
let mutatingRemove = ['a', 'b', 'c', 'd', 'e'];  
mutatingRemove.splice(0, 2); 
console.log(mutatingRemove); //-> ["c", "d", "e"]
```

* **Param 1:** Is the starting point of the splice.
* **Param 2:** Number of the items to remove from array.

Non-mutation remove element can be done  with filter and slice:

```javascript
const arr1 = ['a', 'b', 'c', 'd', 'e'];
const arr2 = arr1.filter(a => a !== 'e');
console.log(arr2); //-> ["a", "b", "c", "d"]

const arr1 = ['a', 'b', 'c', 'd', 'e'];
const arr2 = arr1.slice(1, 5);
console.log(arr2); //-> ["b", "c", "d", "e"]
```

### Replace Element From Array

You can replace element from array with mutation, with array.splice.

```javascript
let mutatingReplace = ['a', 'b', 'c', 'd', 'e'];  
mutatingReplace.splice(2, 1, 'z');
console.log(mutatingReplace); //-> ["a", "b", "z", "d", "e"]
```

* **Param 1:** Is the index to start replacing.
* **Param 2:** Is the number of item to remove.
* **Param 3:** Will be inserted into the array.

```javascript
mutatingReplace.splice(2, 1, 'z','y','x');
console.log(mutatingReplace); //-> ["a", "b", "z", "y", "x", "d", "e"]
```

You can replace element from array without mutation.

```javascript
const replace = (list, index, newElement) => {
  return [
    ...list.slice(0, index),
    newElement,
    ...list.slice(index + 1)
  ]
};

const arr1 = ['a', 'b', 'c', 'd', 'e'];  
const arr2 = replace(arr1, 2, 'z');

console.log(arr1); //-> ["a", "b", "c", "d", "e"]
console.log(arr2); //-> ["a", "b", "z", "d", "e"]
```

### String

This data structure lets you work with a series of characters. String has methods.

```javascript
let s = "this is a test";

console.log(s.charAt(0)); //-> t

// Return the first character of string 
console.log(s.indexOf("i")); //-> 2

// Return the last character of string 
console.log(s.lastIndexOf("i")); //-> 5

// Return specific
console.log(s.substring(1,4)); //-> his

// Param 1: Starting index
// Param 2: Ending index

// Return string at lowercase
console.log(s.toLowerCase()); //-> this is a test

// Return string at uppercase
console.log(s.toUpperCase()); //-> THIS IS A TEST

Regular Expressions String

Regular expressions are a way to describe patterns in string data.

let g = "aaxbbxxccxxxddXXXee";

// Replace - Replace all place that match the regular expression with a replacement string.
console.log(g.replace(/x/g, "q"));

// Match - Return array of part string that match the regular expression.
console.log(g.match(/x+/g));

// Testing - Return boolean value if match value.
console.log(/abc/.test("abcde")); //-> true

// Split - Return array with all part of the string that are between the regular expression.
console.log(g.split(/x+/));

// Search - Return the position of the first place that match the regular expression.
console.log(g.search(/x+/));
```

### Other Important Methods We Can Used With Array

JavaScript Arrays have lots of built in methods. All array methods iterate in what is traditionally called "left to right" from index 0, to index length - 1, also called "start" to "end". 

reduceRight is an exception in that it iterates in reverse from end to start.

**Sort** 

With no argument, they just make a default comparisons. Callback is a comparator, it should return either a number either < 0, 0, or > 0.

* **callback answers:** how do the two items compare with each other
* **callback gets these arguments:** oneElement, theOtherElement
* **final return value:** number < 0, if oneElement should preceed theOtherElement, 0 to keep the relative order, > 0 to place oneElement at a later index than theOtherElement

```javascript
var arr1 = ['hi', 'bye', 'hola', 'adios'];
console.log(arr1.sort()); //-> ["adios", "bye", "hi", "hola"]

var arr2 = [1, -1, 10, 11, 9, 8];
console.log(arr2.sort()); //-> [-1, 1, 10, 11, 8, 9]
```

With function as argument.

```javascript
var nums = [1, -1, -2, 10, 11, 9, 8];
var difference = (n1,n2) => {return(n1 - n2)};

console.log(nums.sort(difference)); //-> [-2, -1, 1, 8, 9, 10, 11]
```

**forEach** 

Call function on each element of array.

* **callback answers:** here’s an item. do something nutty with it, i don't care what.
* **callback gets these arguments:** item, index, list
* **final return value:** nothing - in other words, undefined

```javascript
var nums = [1,2,3];
var sum = 0;

[1, 2, 3].forEach((item, index) => {
  console.log(item);
  console.log(index);
  sum += item;
});

console.log(sum); //-> 6
```

**Map** 

Call function on each element, then accumulates result array of the output. Return new array, does not modify original array.

* **callback answers:** here’s an item. what should i put in the new list in its place?
* **callback gets these arguments:** item, index, list
* **final return value:** list of new items

```javascript
var result = [2,4,6].map(item => item * item);
console.log(result); //-> [4, 16, 36]
```

**Filter** 

Call function on each element, keeps only the results that pass the test. Return new array, does not modify original array. Callback is a predicate, it should return a truthy or falsy value.

* **callback answers:** should i keep this item?
* **callback gets these arguments:** item, index, list
* **final return value:** list of kept items

```javascript
const isEven = n => n % 2 == 0; 
const result = [1,2,3,4,5,6].filter(isEven);

console.log(result); //-> [2, 4, 6]
```

**Reduce “fold”** 

Take a function and started value, Each time, passes accumulated result and next array element through function, until a single value is left.

* **callback answers:** here’s the result from the previous iteration. what should i pass to the next iteration?
* **callback gets these arguments:** result, item, index, list
* **final return value:** result of last iteration

```javascript
const nums = [1,2,3,4];

const add = (x,y) => x + y;
const mult = (x,y) => x * y;
const bigger = (x,y) => x > y ? x : y;

const sum = nums.reduce(add, 0);
const product = nums.reduce(mult, 1);
const max = nums.reduce(bigger, -Number.MAX_VALUE);

console.log(sum); //-> 10
console.log(product); //-> 24
console.log(max); //-> 4
```

**reduceRight** 

(same as reduce, but in reversed order: last-to-first)

**Find**

Callback is a predicate, it should return a truthy or falsy value.

* **callback answers:** is this item what you’re looking for?
* **callback gets these arguments:** item, index, list
* **final return value:** the item you’re looking for, or undefined

note: stops iterating once it receives a truthy value from your callback.

```javascript
const objects = [{ id: 'a' }, { id: 'b' }, { id: 'c' }];
const found = objects.find(item => {
  return item.id === 'b';
});

console.log(found === objects[1]); //-> true
```

**findIndex**

Callback is a predicate, it should return a truthy or falsy value.

* **callback answers:** is this item what you’re looking for?
* **callback gets these arguments:** item, index, list
* **final return value:** the index of the item you’re looking for, or -1

note: stops iterating once it receives a truthy value from your callback.

```javascript
const objects = [{ id: 'a' }, { id: 'b' }, { id: 'c' }];
const foundIndex = objects.findIndex(function (item) {
  return item.id === 'b';
});
console.log(foundIndex === 1); //-> true
```

**Some**

Callback is a predicate, it should return a truthy or falsy value

* **callback answers:** does this item meet your criteria?
* **callback gets these arguments:** item, index, list
* **final return value:** true after the first item that meets your criteria, else false

note: stops iterating once it receives a truthy value from your callback.

```javascript
const hasNegativeNumbers = [1, 2, 3, -1, 4].some(item => {
  return  item < 0;
}) 

console.log(hasNegativeNumbers); //-> true
```

**Every**

callback is a predicate, it should return a truthy or falsy value.

* **callback answers:** does this item meet your criteria?
* **callback gets these arguments:** item, index, list
* **final return value:** false after the first item that failed to meet your criteria, else true

note: stops iterating once it receives a falsy value from your callback.
example use case:

```javascript
const allPositiveNumbers = [1, 2, 3].every( item => {
  return item > 0;
});

console.log(allPositiveNumbers); //-> true
```

## Objects

Javascript have five core primitive data type, they are immutable: Number, String, Boolean, Undefined and Null. An Object is an unordered list of primitive data type that is stored as a serie of name value pairs. Each unique keys that correspond to a value we'll call this pair a `property`. 

### Ways to create or instantiate:

Used the new operator with a constructor.

```javascript
let Person = new Object();
Person.name = "John";

console.log(Person.name); //-> John
```

**Object literals**

To create an object with object literal syntax, you can define the properties of a new object inside braces. Properties are made up of an identifier or string, a colon, and value, with multiple properties separated by commas.

```javascript
let Person = {
  name: "John"
};

console.log(Person.name); //-> John
```

**Using `Object.create()`**

```javascript
let Person = Object.create(null);
Person.name = "John";

console.log(typeof Person); //-> Object
console.log(Person.name); //-> John
```

**Using a function**

```javascript
function Person(name) {
  this.name = name;
};

let john = new Person("John");

console.log(typeof Person); //-> Function
console.log(typeof john); //-> Object
console.log(john.name); //-> John
```

### Adding Object Properties

A properties has a name and a value. In addition, a property can be enumerable, configurable and writable.

```javascript
let Person = new Object();

Person.firstName = "Steve";
Person.lastName = "McNiller";

console.log(Person.firstName + " " + Person.lastName); //-> Steve McNiller
```

### Accessing Object Properties

We know properties are name/value pairs that are stored on a object. Dot notation is the most common way to access properties in Javascript (as in many object-oriented languages), but you can also access properties on Javascript objects by using bracket notation with string.

```javascript
console.log(Person.firstName + " " + Person.lastName); //-> Steve McNiller
```

### Adding Object Methods

You can add a method to an object in the same way that you would add a property. The this value object represent the global scope inside of the object.

```javascript
let Person = {
  firstName : "Steve",
  lastName : "McNiller",
  sayName : function() {
    console.log(this.firstName + " " + this.lastName);
  }
}
Person.sayName(); //-> Steve McNiller
```

### Detecting Object Properties

It sometimes necessary to check whether a property exists in the object. We can used if statement.

```javascript
if (Person.firstName) {
  console.log("Properties Exist!");
}
//-> Properties Exist!
```

Second way to detect properties is with the in operator, they looks for a properties with a given name in a specific object and returns true.

```javascript
console.log("firstName" in Person); //-> true
console.log("address" in Person); //-> false
```

Third way to detect properties on object is with the hasOwnProperty() method, which is present on all objects and returns true only if the given property exists and is an own property.

```javascript
console.log(Person.hasOwnProperty("firstName")); //-> true
console.log(Person.hasOwnProperty("address")); //-> false
```

### Removing Object Properties

The delete operator works on a single object property and calls an internal operation named.

```javascript
console.log("firstName" in Person); //-> true
delete Person.firstName;
console.log("firstName" in Person); //-> false
```

### Enumeration

Array are ordered collection of value, but object are an unordered collection of key, value pair. When we are dealing with object, the order of enumeration is not guaranteed, with array it is.  

```javascript
let Phone = {
  screen: "320x480",
  wifi: true,
  price: 99.99
}

let property, prop;

for(property in Phone) {
  console.log("Name: " + property);
  console.log("Value: " + Phone[property]);
}
```

We show how you loop through object properties, but if you just need a list of an object properties to use later in you program, introduce the Object.keys() this method return an array of all enumerable property names defined by a given object.

```javascript
const phoneProperty = Object.keys(Phone);
console.log(phoneProperty); //-> ["screen", "wifi", "price"]

console.log(Phone.propertyIsEnumerable("wifi")); //-> true
console.log(phoneProperty.propertyIsEnumerable("wifi")); //-> false
```

### Type of Object Properties

By default there are two different types of properties: Data Properties and Accessor Properties. Data properties contain a value and Accessor properties do not contain a value but instead define a function to call when the property is read (called a getter), and a function to call when the property is written to (called a setter).

```javascript
let Person = {
  _name:"Michael Chase",
	
  get name() {
    console.log("Reading name");
    return this._name;
  },
	
  set name(value) {
    console.log("Setting name to %s", value);
    this._name = value;
  }
};

console.log(Person.name); //-> "Reading name" then "Michael Chase"

Person.name="Greg Inker";
console.log(Person.name); //-> "Setting name to Greg Inker" then "Greg Inker"
```

### Property Attributes

On past Javascript version there no way to specify whether a property should be enumerable, there was no way to access the internal attribute of property at all, now we have several ways of interacting with property attribute directly.

**Common Attribute**
	
There are two property attribute share between data and accessor properties. We can used .defineProperty() to change property attribute.

1. Enumerable, which determines whether you can iterate over properties. true if and only if this property shows up during enumeration of the properties on the corresponding object. Defaults to false.
2. Configurable, which determine whether the property can be changed. true if and only if the type of this property descriptor may be changed and if the property may be deleted from the corresponding object. Defaults to false.

```javascript
let Person = {
  firstName: "Steven",
  lastName: "Boyd"
};

// Avoiding enumerable "firstName" properties.
Object.defineProperty(Person, "firstName", {
  enumerable: false
});

// Testing
console.log("firstName" in Person); //-> true
console.log(Person.propertyIsEnumerable("firstName")); //-> false

let properties = Object.keys(Person);
console.log(properties.length); // 1, not 2

// Avoiding some can change "firstName" properties.
Object.defineProperty(Person, "firstName", {
  configurable: false
});

// Testing
delete Person.firstName;
delete Person.lastName;

console.log("firstName" in Person); //-> true
console.log("lastName" in Person); //-> false

console.log(Person.firstName); //-> Steven
console.log(Person.lastName); //-> undefined
```

**Data Property Attributes**

Data properties possess two additional attributes that assessors do not. We can used `.defineProperty()` to change property attribute.

1. Value, which holds the property value. This attribute is filled in automatically when you create a property on an object. 
2. Writable, which is a boolean value indicating whether the property can be written to. By default, all properties are writable unless you specify otherwise.

```javascript
let Person = function(firstName, lastName){
  this.firstname = firstName;
  this.lastName = lastName;
}

Object.defineProperty(Person, "species", {
  writable: false,
  value: "Human",
});

console.log("species" in Person); //-> true
console.log(Person.propertyIsEnumerable("species")); //-> false

delete Person.firstName;
console.log("species" in Person); //-> true

Person.species = "fish";
console.log(Person.species); //-> Human
```

### Accessor Property Attribute

Accessor properties alse have two additional attributes. Have [[Get]] and [[Set]], which contain the getter and setter functions, respectively.

```javascript
let Person = {
  _name:"Peterson",
	
  get name() {
    console.log("Reading name");
    return this._name;
  },
	
  set name(value) {
    console.log("Setting name to %s", value);
    this._name=value;
  }
};

console.log(Person.name); //-> Reading name then "Peterson"
```

Also can be written as follow:

```javascript
let Person = {
  _name:"Michael"
};

Object.defineProperty(Person, "name", {
  get: function() {
    console.log("Reading name");
    return this._name;
  },
	
  set: function(value) {
    console.log("Setting name to %s", value);
    this._name=value;
  },
    enumerable:true,
    configurable:true
});

Person.name = "Peterson"; // Setting name to Peterson
console.log(Person.name); //-> Reading name then "Peterson"
```

### Accessor Property Attribute

* `get`, a function which serves as a getter for the property. Whatever the function returns will be used as the value of the property. When it is undefined the getter behaviour is ignored. Defaults to undefined.
* `set`, a function which serves as a setter for the property, or undefined if there is no setter. The function will receive one argument with the new value being assigned to the property. Defaults to undefined.

```javascript
let Person = {};

Object.defineProperties(Person, {
  // data property to store data
  _name: {
    value:"Michelle",
    enumerable:true,
    configurable:true,
    writable:true
  },
	
  // accessor property
  name: {
    get:function() {
      console.log("Reading name");
      return this._name;
    },
		
    set:function(value) {
      console.log("Setting name to %s", value);
      this._name = value;
    },
    enumerable:true,
    configurable:true
  }
});

Person.name = "Peterson"; //-> Setting name to Peterson
console.log(Person.name); //-> Reading name then "Peterson"
```

### Retrieving Property Attributes

```javascript
let Person = {};

Object.defineProperties(Person, {
  // data property to store data
  _name: { 
    value: "Michelle",
    enumerable: true,
    configurable: true,
    writable: true
  },
	
  // accessor property
  name: {
    get:function() {
      console.log("Reading name");
      return this._name;
    },
		
    set:function(value) {
      console.log("Setting name to %s", value);
      this._name = value;
    },
    enumerable:true,
    configurable:true
  }
});

let descriptor = Object.getOwnPropertyDescriptor(Person, "_name");

console.log(descriptor.enumerable); //-> true
console.log(descriptor.value); //-> Michelle
```

### Preventing Object Modification

**Preventing Extensions**
	
By default all object are extensible, means adding new properties and method to an object. `Object.preventExtensions()` method changes the behaviour of the object and don't allow to add new properties and method to an object.

```javascript
let Person = {
  firstName: "John"
};

let Dog = {};

console.log(Object.isExtensible(Person)); //-> true
Object.preventExtensions(Person);

Person.lastName = "Miller";
Dog.name = "Kyle";

console.log(Person.lastName); //-> undefined
console.log(Dog.name); //-> Kyle

console.log(Object.isExtensible(Person)); //-> false
```

**Sealing Object**

We cannot extend the object, also we cannot delete the existing properties, but we can modify the existing properties and methods.

**Frozen Object**

With Frozen object we cannot add new properties and method, also cannot delete or modify the existing properties and methods.

```javascript
let Person = {
  name: "Nicoles"
};

Object.freeze(Person);

Person.name = "Mike";

console.log(Person.name); //-> Nicoles

console.log(Object.isExtensible(Person)); //-> false
console.log(Object.isFrozen(Person)); //-> true
```

### Constructors

A constructor is simply a function that is used with new to create an object.

```javascript
function Person(firstName, lastName) {
  this.firstName = firstName;
  this.lastName = lastName;
  this.sayName = function() {
    console.log(this.firstName + " " + this.lastName);
  };
};

let trey = new Person('Trey', 'Johnson');
trey.sayName(); //-> Trey Johnson

// instanceof to know if objects is created by other.
console.log(trey instanceof Person); //-> true
```

### Classes and Inheritance Prototypes

To understand Javascript Inheritance we need to understand Javascript Prototype.

You can think of a prototype as a recipe for an object. Almost every function (with the exception of some built-in functions) has a prototype property that is used during the creation of new instances. That prototype is shared among all of the object instances, and those instances can access properties of the prototype.

We have two concept of prototype on Javascript:

**Prototype Property**

A Javascript function's has a prototype property.  You can attach properties and methods on this prototype property when you want to implement inheritance. This prototype property is not enumerable; that is, it isn’t accessible in a for loop. 

The prototype property is used primarily for inheritance; you add methods and properties on a function prototype property to make those methods and properties available to instances of that function.

```javascript
function PrintNumber(x) {
  this.x = x;
}

// We can add method to this function by accessing function prototype.
PrintNumber.prototype.print = function() {
  console.log(this.x);
};

// We create a new fresh object with function contructor, allowing inherits all from function.
var objNew = new PrintNumber(22);

// We can used method and values from function on the new object.
objNew.print(); //-> 22
```

**Prototype Attribute**

This is a characteristic of the object, telling us the object parent. In simple terms: An object’s prototype attribute points to the object’s “parent”. The prototype attribute is normally referred to as the prototype object, and it is set automatically when you create a new object.

**Constructor**

Is a function used for initializing new object and you can use the new keyword to call the constructor. Note: Constructor function === Classes

```javascript
function Person() {}
console.log(typeof Person); //-> function

let steve = new Person();
console.log(typeof steve); //-> object

// Constructor property is simply a property (like any variable) that holds or points to the constructor of the object.
let myObject = new Object();
console.log(myObject.constructor); //-> Object()

console.log(steve.constructor); //-> Person()

// All Object created by Object literal and Object constructor inherits from Object.prototype
let peter = new Object();
console.log(peter.constructor); //-> Object()

let jack = {};
console.log(jack.constructor) //-> Object()

let michelle = Object.create(Object.prototype);
console.log(michelle.constructor) //-> Object()
```

Why is Prototype important and when is it used?

* **Prototype property:** prototype-based inheritance.

```javascript
function Plant() {
  this.country = "Mexico";
  this.isOrganic = true;
}

Plant.prototype.showNameAndColor = function() {
  console.log("I am a " + this.name + " and my color is " + this.color);
}

function Fruit(fruitName, fruitColor) {
  this.name = fruitName;
  this.color = fruitColor;
}

// Set the Fruit's prototype to Plant's constructor, thus inheriting all of Plant.prototype methods and properties.
Fruit.prototype = new Plant();

let banana = new Fruit("Banana", "Yellow");

console.log(banana.name); //-> Banana
banana.showNameAndColor(); //-> I am a Banana and my color is Yellow
```

* **Prototype Attribute:** Accessing Properties on Objects, Object.prototype Properties Inherited by all Objects. All objects in JavaScript inherit properties and methods from Object.prototype. 

```javascript
let now = new Date();
let earlier = new Date(2010,1,1);

console.log(now);
console.log(earlier);

.toString() - Method is called as a fallback whenever valueOf() returns a reference value instead of a primitive value. It is also implicitly called on primitive values whenever JavaScript is expecting a string.

let Toyota = {
  model: "Camry",
  year: 2017,
  toString: function() {
    return this.model + " " + this.year;
  }
};

console.log(Toyota.toString()); //-> Camry 2017
```

### Object Pattern, Module Pattern

```javascript
let ModuleObject = (function() {
  // private data variables
	
  return {
    // public methods and properties
  }
}());

let human = (function() {
  let age = 25;
	
  return {
    name: "Nicholas",
		
    getAge: function() {
      return age;
    },
		
    growOlder: function() {
      age++;
    }
  };
}());

console.log(human.name); //-> Nicholas
console.log(human.getAge()); //-> 25

human.age = 100;
console.log(human.getAge()); //-> 25

human.growOlder();
human.growOlder();
human.growOlder();

console.log(human.getAge()); //-> 28
```

### Mixins

Mixins are a way to add the functionality of 1 or more objects to a new object, essentially creating a non-standard means of inheritance.

```javascript
function Cat(name) {
  this.name = name;
}

function Dog(name) {
  this.name = name;
}

let speaker = {
  speak: function() {
    return this.name + " is speaking.";
  }
};

let mover = {
  walk: function() {
    return this.name + " is walking.";
  },
  run: function() {
    return this.name + " is running.";
  }
}

// By jquery function.
// $.extend(Cat.prototype, speaker, mover);
// $.extend(Dog.prototype, speaker, mover);


// ES6 Object.assign Object.assign(target, ...sources)
// Object.assign(Cat.prototype, speaker, mover);
// Object.assign(Dog.prototype, speaker, mover);

// By Javascript

// Implementation 1
/*
function extend(target) {
  if(!arguments[1]) {
    return;
  }
  
  for(let i = 1, j = arguments.length; i < j; i++) {
    let source = arguments[i];
    
    for(let prop in source) {
      if(!target[prop] && source.hasOwnProperty(prop)) {
        target[prop] = source[prop];
      }
    }
  }
}

extend(Cat.prototype, speaker, mover);
extend(Dog.prototype, speaker, mover);

let charlie = new Cat("Charlie");
let daisy = new Dog("Daisy");

console.log(charlie.speak()); //-> Charlie is speaking.
console.log(daisy.speak()); //-> Daisy is speaking.
console.log(charlie.walk()); //-> Charlie is walking.
*/

// Implementation 2
/*
function mixin(source, target) {  
  for (var prop in source) {
    if (source.hasOwnProperty(prop)) {
      target[prop] = source[prop];
    }
  }
}

mixin(speaker, Cat.prototype);

let chole = new Cat("Chole");
console.log(chole.speak()); //-> Chole is speaking.
*/

// Implementation 3
function mixin(receiver, supplier) {
	
  Object.keys(supplier).forEach(function(property) {
    let descriptor = Object.getOwnPropertyDescriptor(supplier, property);
    Object.defineProperty(receiver, property, descriptor);
  });

  return receiver;
}

let charlie = mixin(new Cat(), speaker);
charlie.name = "Charlie";

let daisy = mixin(new Dog(), speaker);
daisy.name = "Daisy";

console.log(charlie.speak()); //-> Charlie is speaking.
console.log(daisy.speak()); //-> Daisy is speaking.
```

## Document Object Model (DOM)

In application is an HTML, XML or SVG document, when a web page is loaded, the browser creates the DOM of the page. Is basically an object they contain every element of the page inside it. The DOM is constructed as a tree of object and each object represents an element of the page. And each element is an object.

### DOM Structure

* DOCUMENT_NODE
* ELEMENT_NODE

```html
<html> <head> <body> <h1> <p>
```

* TEXT_NODE

```html
<p>I am text node</p>
```

* ATTRIBUTE_NODE

```html
<img src="attribute node">
```

### Topology

The DOM objects relate to each other in a certain way, but there are some relationships that will be present in most situations:

* **Parents nodes:** Are nodes that nest further nodes in them. Examples of the nodes that most of the times will contain nested nodes are the `<html>` and `<body>` tags.
* **Child nodes:** Child nodes have something in common, they have a parent. Examples of child nodes can be `<head>`, `<body>` and `<p>`
* **Sibling nodes:** Sibling nodes are nodes that are placed next to another node in the tree. A paragraph (`<p>`)node can be a sibling of a heading (`<h1>`) node.

### DOM nodes

A node is the minimal unit that a DOM tree is made of. Each element in a well formatted HTML will become a node. Nodes have properties and methods attached to them. During the creation of the DOM, the browser attaches the attributes, the HTML itself, the styles and the events to each node.

The browser then provides JavaScript (and other languages) with an API (Application Programming Interface) that will serve to modify, insert, alter or remove any node in the DOM tree. In fact, each node is an interface on its own.

Each node will inherit from the Node interface which contains some basic functionality attached to it. This functionality will be then accessible to the language (JavaScript in this case) to allow it to modify the node properties or read the current state of the node.

You can see a node like a box containing all kind of fun stuff you can play with, including other nodes (the nested nodes). Properties such as `[node].nodeName` or `[node].firstChild` and `[node].nextSibling`. 

### Access To Node

**`getElementsByTagName`**

```html
<div>
  <p>Proin a aliquet</p>
  <p>Nulla placerat</p>
</div>
```

```javascript
// Return all element
var nodeP = document.getElementsByTagName('p');
console.log(nodeP); //-> [p, p]

// Return specify by array position
var nodeP = document.getElementsByTagName('p')[0];
console.log(nodeP); //-> <p>Proin a aliquet</p>
```

**`getElementsByName`**

```html
<div>
  <p>Proin a aliquet</p>
  <p name="node_two">Nulla placerat</p>
</div>
```

```javascript
var nodeP = document.getElementsByName('node_two');
console.log(nodeP); //-> [p], <p>Nulla placerat</p>
```

**`getElementById`**

```html
<div>
  <p>Proin a aliquet</p>
  <p id="node_two">Nulla placerat</p>
</div>
```

```javascript
var nodeP = document.getElementById('node_two');
console.log(nodeP); //-> <p id="node_two">Nulla placerat</p>
```

**`querySelector`**

```html
<div>
  <p class="node_one">Proin a aliquet</p>
  <p id="node_two">Nulla placerat</p>
</div>
```

```javascript
var nodeClass = document.querySelector('#node_two');
console.log(nodeClass); //-> <p id="node_two">Nulla placerat</p>

var nodeId = document.querySelector('.node_one');
console.log(nodeId); //-> <p class="node_one">Proin a aliquet</p>
```

### Create and Delete Node

**Create**

```javascript
var container = document.getElementById('container');
var nodeP = document.createElement('p');
var nodePContext = document.createTextNode('Nulla placerat');

var result = nodeP.appendChild(nodePContext);

container.appendChild(result);
```

**Delete**

```html
<div>
  <div id="text">Nulla placerat</div>
  <div>Proin a aliquet</div>
</div>
```

```javascript
var nodePToDelete = document.getElementById('text');
nodePToDelete.parentNode.removeChild(nodePToDelete);
```

```html
<div>
  <div>Proin a aliquet</div>
</div>
```

### Access To Attribute Node

```html
<div>
  <a href="https://www.acelerisque.com">Acelerisque</a>
  <div id="div" data-name="Nulla placerat">Tristique scelerisque</div>
  <p class="cerat">Sed aliquet leo</p>
</div>
```

```javascript
var nodeA = document.getElementsByTagName('a')[0];
var nodeDiv = document.getElementsByTagName('div')[0];
var nodeDivId = document.getElementById('div');
var nodeP = document.getElementsByTagName('p')[0];

console.log(nodeA.href); //-> https://www.acelerisque.com/

// Access to style of the element.
nodeDiv.style.fontWeight = "900";

// Access by classname
console.log(nodeP.className); //-> cerat

// Access by dataset
console.log(nodeDivId.dataset.name); //-> Nulla placerat
```

## Browser Object Model (BOM)

Is a core object generated by the browser, allow us manipulate or interact with the browser core element.

### Window

The window object (global object), which is at the very top of the browser model hierarchy, can be thought of as the frame of the the browser and include scroll bars, navigator bars, and icons. And inside of the window object is the document object, this can be represented by the html page.

Window have five properties object are history, location, navigator, screen, and document properties.

**History**

The history property keeps track of the pages the user visits. History has a few methods including `back()` and `foward()`, to switch between pages the user has visited. The `go()` method which specifies how far foward or back in the history to go. And a `length()` property that shows how many pages are in the history stack.

```javascript
// This is like back button on browser.
window.history.go(-1);
```

**Location**

The location object displays information about the page’s location. It contains the page’s url, the server, port number of the server connection and the protocal used. This information is made available through the location object’s href, hostname, port, and protocol properties.

```javascript
const url = window.location.href;
console.log(url); //-> https://fiddle.jshell.net/

const protocol = window.location.protocol;
console.log(protocol); //-> https:
```

**Navigator**

Using the navigator method allows you to see information about the browser and the operating system. It’s propeties allow you to find out which browser, version, and operating system the user has. So that you are able to act on that information and make sure your code works only in browsers that support it. An important property of the navigator object is geolocation, which uses the geophysical position of the device or computer. The main method of geolocation is `getCurrentPosition()`. It requires a callback function that executes when `getCurrentPosition()` is done running.

```javascript
const appVersion = window.navigator.appVersion;
console.log(appVersion); //-> 5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36

const appLang = window.navigator.language;
console.log(appLang); //-> en-US
```

**Screen**

The screen property gives information about the display capabilities of the user’s machine, it includes the height and width properties. They display the vertical and horizontal range of the screen.

```javascript
const browserHeight = window.screen.height;
console.log(browserHeight); //-> 1080
```

### Window Method

Like javascript, the browser itself also has methods. Two example methods of the window are `alert()` and `prompt()`.

### Feature Window Detection

An if statement can be used to test if the browser supports a certain feature.

```javascript
if (typeof navigator.geolocation != “undefined”) { 
  // use geolocation
}
```

## Events

Event is something that the browser or user can interact with. One of the most important features of the DOM is that it provides you with event binding functionality out of the box.

Event binding is the act of attaching event listeners that will be triggered based upon actions on certain nodes in the Document Object Model.

With event binding you can listen for events and wait until the event is fired to act accordingly. Each node can listen to multiple events.

### Events Type

* **Browser Events:** a signal that something (an action) has happend in the browser.
* **Document Loading:** an action that takes place when the when the page loads up.
* **Event Handler Attachment:** attaching a handler to an event usually using the `.on` method.
* **Event Object:** is sent to a handler function as an argument.
* **Form Events:** takes place when an event is triggered pertaining to the form, like reset, search, etc.
* **Keyboard Events:** waiting for a press (up/down).
* **Mouse Events:** an event is triggered when the mouse is clicked.

In the following example we have a button, because this button is a node itself we can “attach” event listeners to it. The code will be explained in the comments.

```html
<button id="myButton">Say hi!</button>
```

### Events Handlers

**Inline Events**

Is attach events right into the DOM element. Developers realized that this wasn't a good idea. They started for a better separation of concerns. JavaScript should be moved to a `<script>` tag or .js file. This is generally what’s referred to as unobtrusive JavaScript.

* **Common events:**
* `onload // When the page loads.`
* `onclick // When a user clicks something.`
* `onmouseover // When a user mouses over something.`
* `onfocus // When a user puts the cursor in a form field.`
* `onblur // When a user leaves a form field.`
* `DOMContentLoaded // When your document's DOM has fully loaded.`
* `keydown // When you press down on a key on your keyboard.`
* `scroll // When an element is scrolled around.`

```javascript
<a onclick="console.log('Yay');">Link</a>
```
```javascript
function onload () {
  let button = document.getElementById('myButton')
  function onclick () {
    button.innerHTML = 'Hi!, you clicked me!'
  }
  
  button.addEventListener('click', onclick)
}

window.onload(onload)
```

**Event Listeners**

`addEventListener` function where it binds an element to a particular event. If you want to remove any applied event just call `removeEventListener`.

```javascript
element.addEventListener('click', doSomething, false);
```

Third optional parameter to control event bubbling.

### Event Bubbling

We have this html structure:

```html
<div id="one_a" class="item">
  <div id="two" class="item">
    <div id="three_a" class="item">
      <button id="buttonOne" class="item">one</button>
    </div>
    <div id="three_b" class="item">
      <button id="buttonTwo" class="item">two</button>
      <button id="buttonThree" class="item">three</button>
    </div>
  </div>
</div>
<div id="one_b" class="item"> 
</div>
```

And we attach a event to `buttonOne`, let's say that we click on the `buttonOne` element. When the DOM initiate an event, the event always starts at the root `window`, goes down until it hits the target in this case `buttonOne`, and then goes back up to the root `window`.

This entire journey is very formally defined:

* **Event Capturing Phase:** where you initiate the event and the event barrels down the DOM from the root `window`.
* **Event Bubbling Phase:** where your event bubbles back up to the root `window`.

Why this is important?

Event bubbling work like this. If an element A and that element is contained within element B, and element A is clicked, the click event fires for element A and then it will bubble up and fire for element B. This occurs because technically you are clicking both elements.

Example:

```javascript
// If you click innerDiv, they will fired: two, three_b, buttonThree
innerDiv = document.getElementById("buttonThree");
innerDiv.addEventListener("click",function(){
  console.log("buttonThree");
});

outterDiv = document.getElementById("three_b");
outterDiv.onclick = function() {
  console.log("three_b");
};

containerDiv = document.getElementById("two");
containerDiv.onclick = function() {
  console.log("two");
}
```

To avoid this conflict we need to used `event.stopPropagation();` this function is hiding in the shadows to kill the event on specific point. 

```javascript
innerDiv = document.getElementById("buttonThree");
innerDiv.addEventListener("click",function(event){
  console.log("buttonThree");
  event.stopPropagation();
}); //-> buttonThree
```

This fixing resolve the conflict and allow us to only fired event from specifying an element trigger.

### `event.preventDefault()`

Another function that lives on your event object.  Many HTML elements exhibit a default behavior when you interact with them. For example, clicking in a textbox gives that textbox focus with a little blinking text cursor appearing. Using your mouse wheel in a scrollable area will scroll in the direction you are scrolling. Clicking on a checkbox will toggle the checked state on or off. All of these are examples of built-in reactions to events your browser instinctively knows what to do about.

If you want to turn off this default behavior, you can call the `.preventDefault()` function. 

### Event Arguments and Event Type

Your event handler does more than just get called when an event gets overheard by an event listener. It also provides access to the underlying event object as part of its arguments. To access this event object easily, we need to modify your event handler signature to support this argument.

```javascript
function myEventHandler(e) {
  // e <- event object
  // event handlery stuff
}
```

This event object contains properties that are relevant to the event that was fired. Some of the popular properties from the Event type that you will use are:

* `currentTarget`
* `target`
* `preventDefault`
* `stopPropagation`
* `type`
