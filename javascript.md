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
## External Script, Order Of Execution

If the JavaScript code is a lot, it is rendered in a separate file that connects to HTML:

```html
<script src="/path/to/script.js"></script> 
```

Here `/path/to/script.js` is the **absolute path** to the file containing the script (from the root of the site). The browser will download the script and execute it. You can also use the **path relative** to the current page. For example, `src="path/to/script.js"` denotes a file from the current directory.

Typically, in HTML, only the simplest scripts are written, and complex ones are rendered in a separate file. The browser will download it only the first time and in the future, if the server is properly configured, will take it from its **cache**.

Because of this, the same large script containing, for example, a library of functions, can be used on different pages without a full reboot from the server.

### Avoid `src` and code

If the `src` attribute is specified, the contents of the tag are ignored. In one SCRIPT tag, you can not simultaneously connect an external script and specify the code.

This is not how it works:

```html
<script src="file.js"> 
  alert(1);
</script> 
```
It is necessary to choose: either `SCRIPT` comes with `src` , or contains the code. The tag above should be divided into two: one with `src` , another with code.

### Asynchronous Scripts: `defer` / `async`

The browser loads and displays HTML gradually. This is especially noticeable with a slow Internet connection: the browser does not wait for the page to load in its entirety, but it shows the part that it managed to load.

If the browser sees a `<script>` tag, then it must by default execute it, and then show the rest of the page. This behavior is called "synchronous". As a rule, it is quite normal, but there is an important consequence. If the script is external, then while the browser does not execute it, it will not show the part of the page below it. That is, in such a document, until the `big.js` is loaded, the contents of `<body>` will be hidden.

**What to do?**

You can put all such scripts at the bottom of the page and this will reduce the problem, but it will not get rid of it completely if there are several scripts. Let's say there are 3 scripts at the end of the page, and the first one is slowing down, it turns out that the other two will wait for it, it's also not good.

In addition, the browser will reach the scripts located at the end of the page, they will start to load only when the entire page is loaded. And this is not always correct. For example, the visit counter will most likely work if you load it earlier.

Therefore, "placing the scripts at the bottom" is not the best solution. Cardinally solve this problem using the `async` or `defer` :

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

### Variable Names

Only have two restriction:

1. Name can consist of letters, number, symbols, $, and _
2. The first character must not be a digit.
3. Avoid used reserved names, there is a list of reserved words that can not be used for variables, since they are used by the language itself, for example: var, class, return, export , etc. Using reserved names can produces a syntax error.

### Constants

Is like a variable that we can create and can be read-only. We create this with `const` keyword.

```javascript
const AREA_CODE = 787;
```

### Constant Names

Good practices of name constant is all letter on uppercase.

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

## Basic Operator

### The terms "unary", "binary", "operand"

Operators have their own terminology, which is used in all programming languages. Before we move on, there are several terms to understand what this is about.

* **The operand:** Is what the operator applies to. For example: 5 * 2 - operator of multiplication with left and right operands. Another name: "operator argument".
* **Unary:** Is an operator that applies to a single expression. For example, the unary minus operator "-" changes the sign of the number to the opposite:

```javascript
// Assignment 
var x = 10;
var y = 10;
```

* **Binary:** Is an operator that is applied to two operands. The same minus exists in a binary form.

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

### Adding Rows, Binary +

Usually, with the plus sign '+' add up the numbers. But if the binary operator '+' applied to strings, then it unites them into one:

```javascript
// String Concatenation
let s = "Hello";
const result = s + ", Worlds!"
console.log(result); //-> Hello, Worlds!
```

If at least one argument is a string, then the second one will also be converted to a string! And it does not matter, the operand-string is located to the right or left, in any case the non-string argument will be transformed.

```javascript
// String and Number Concatenation
console.log('1' + 2); //-> "12"
console.log(2 + '1'); //-> "21"
```

This reduction to the string is a feature exclusively of the binary operator "+" . The remaining arithmetic operators work only with numbers and always give arguments to the number.

```javascript
// String and Number Concatenation
console.log(1 - '2'); //-> 1
console.log(6 / '2'); //-> 3
```

### Assignment

### Taking The Remainder `%`

The operator of taking the remainder of % interesting in that, despite the designation, nothing to do with interest. Its result a % b is the remainder of dividing a by b .

```javascript
console.log(5 % 2); //-> 1
```

### Increment / Decrement `++` , `--`

One of the most common operations in JavaScript, as in many other programming languages, is to increment or decrement the variable by one. There are even special operators for this:

Increment ++ increases by 1:

```javascript
var i = 2; 
i++;
console.log(i); //-> 3
```

Decrement reduces by 1:

```javascript
var i = 2; 
i--;
console.log(i); //-> 1
```

Is important that increment / decrement can only be applied to a variable. The code 5++ will give an error.

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

### Bitwise operators

Common used on conditional statement. Bitwise operators treat arguments as 32-bit integers and operate at the level of their internal binary representation. These operators are not specific to JavaScript, they are supported in most programming languages. The following bitwise operators are supported:

* **AND** (s) ( & )
* **OR** (or) ( | )
* **XOR** (bitwise exclusive or) ( ^ )
* **NOT** (not) ( ~ )
* **LEFT SHIFT** (left shift) ( << )
* **RIGHT SHIFT** (right shift) ( >> )
* **ZERO-FILL RIGHT SHIFT** (right shift with zeros filling) ( >>> )

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

### The Comma Operator

A comma allows you to list expressions by separating them with a comma ',' . Each of them is calculated and discarded, with the exception of the last one, which is returned.

A comma is the only operator whose priority is lower than the assignment. In the expression `a = (5,6)` , explicit brackets are used to explicitly set the priority, otherwise the operator `=` would be executed before the comma `,` , it would be `(a=5), 6`.

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

It evaluates it, and if the result is true , it executes the command. The operator `if` is a condition in the example above.  

```javascript
var year = 2011;
if(year != 2011) { 
  console.log( 'year is 2011..' ); 
  console.log( '..this condition is true!' ); 
} 
```

Operator Question Mark `?` Is a shorted way to if. It has the form of: 

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

You can use the built-in constructor as an error constructor: `new Error(message)` or any other.

```javascript
var data = '{ "age": 30 }';
try {
  var user = JSON.parse(data); 
  if(!user.name) {
    throw new SyntaxError("The data is incorrect");
  }
  console.log(user.name);
} 
catch (e) {
  console.log(e); //-> SyntaxError: The data is incorrect
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

### Return

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

Scope mean where to look for thing, where that variable exist. Scope is a where a set of variable or function you have access to, we have global scope, the main scope of you app, is where any variable and function can be access.

### Global Scope

In the browser, this object is explicitly available under the name window . The window object is simultaneously a global object and contains a number of properties and methods for working with the browser window, but we are only interested in its role as a global object.

By assigning or reading a global variable, we are actually working with window properties.

```javascript
var a = 5;
console.log(window.a); //-> 5 
```

### Lexical Scope

Every scope is a lexical scope on javascript. 

```javascript
var getSponsor = function(info) {
  // This is a new Lexical Scope
}
```

To explain lexical scope, we have rules, every variable define in the global scope is accessible in any other part of you program, however if this variable are define in a new lexical scope, like inside of function. You can not access to variable inside of function if you try get that variable from parent scope. 

### Closure

Closure is when a function **remember** its lexical scope even when the function is executed outside that lexical scope.

```javascript
function foo() {
  var bar = "bar";
  
  function baz(){
    console.log(bar);
  }
  
  bam(baz);
}

function bam(baz){
  baz();
}

foo(); //-> "bar"
```

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

### Module Patterns

The module pattern makes use of one of the nicer features of JavaScript, **closures** and **IIFE** in order to give you some control of the privacy of your methods so that third party applications cannot access private data or overwrite it.

```javascript
// Classic Module Pattern
var foo = (function(){
  var o = {bar: "bar"};
  
  return {
    bar: function(){
      console.log(o.bar);
    }
  };
})();

foo.bar(); //-> "bar"
```

```javascript
// Modified Module Pattern
var foo = (function(){
  var publicAPI = {
    bar: function(){
      publicAPI.baz();
    },
    baz: function(){
      console.log("baz");
    }
  };
  return publicAPI;
})();

foo.bar();

// Modern Module Pattern AMD
/*
define("foo", function(){
  var o = {bar: "bar"};
  
  return {
    bar: function(){
      console.log(o.bar);
    }
  }
});
*/

// ES6 
/*
var o = {bar: "bar"};

export function bar(){
  return o.bar;
}

import bar from "foo";
bar();
*/
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
