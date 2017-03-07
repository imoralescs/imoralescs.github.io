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

With no argument, they just make a default comparisons.

* **callback is a comparator:** it should return either a number either < 0, 0, or > 0
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
var result = [2,4,6].map(n => n * n);
console.log(result); //-> [4, 16, 36]
```

**Filter** 

Call function on each element, keeps only the results that pass the test. Return new array, does not modify original array.

```javascript
const isEven = n => n % 2 == 0; 
const result = [1,2,3,4,5,6].filter(isEven);

console.log(result); //-> [2, 4, 6]
```

**Reduce “fold”** 

Take a function and started value, Each time, passes accumulated result and next array element through function, until a single value is left.

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
