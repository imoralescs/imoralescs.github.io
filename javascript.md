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

## Array

