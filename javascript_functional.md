# Javascript Functional

Is the process of building software by composing pure functions, avoiding shared state, mutable data, and side-effects. Functional programming is declarative rather than imperative, and application state flows through pure functions. Contrast with object oriented programming, where application state is usually shared and colocated with methods in objects.

Is all about decomposing a problem into a set of functions. Often, functions are chained together, nested within each other, passed around, and treated as first-class citizens.

## Pure Function

### What is a Function?

A function is a process which takes some input, called arguments, and produces some output called a return value. Functions may serve the following purposes:

* **Mapping:** Produce some output based on given inputs. A function maps input values to output values.
* **Procedures:** A function may be called to perform a sequence of steps. The sequence is known as a procedure, and programming in this style is known as procedural programming.
* **I/O:** Some functions exist to communicate with other parts of the system, such as the screen, storage, system logs, or network.

Pure functions are all about mapping. Functions map input arguments to return values, meaning that for each set of inputs, there exists an output. A function will take the inputs and return the corresponding output.

### What is Pure Functions?

Pure functions take some input and return some output based on that input. Pure functions are completely independent of outside state, and as such, they are immune to entire classes of bugs that have to do with shared mutable state. Pure functions are also extremely independent, can be easy to move around, refactor, and reorganize in your code, making your programs more flexible and adaptable to future changes.

Pure Functions will always produce the same output given the same inputs.

## Anonymous functions

Are functions without names. But they are more than that. What they allow is the ability to define ad-hoc logic, on-the-spot and as needed. The standard way to write anonymous functions:

```javascript
function anonymous_01() {
  console.log("hello world")
}
```

Anonymous function assigned to variable:

```javascript
var anonymous_02 = function(x,y) {
  return x + y;
}
```

Anonymous function used in place of a named callback function, this is one of the more common uses of anonymous functions.

```javascript
setInterval(function(){
	console.log(new Date().getTime())
}, 1000);
```

## First Class Function and Higher Order Function

JavaScript has first class functions, which allows us to treat functions as data, we can assign them to variables, pass them to other functions as parameters, return them from functions, etc…

A higher order function is any function which takes a function as an argument, returns a function, or both. Higher order functions are often used to:

* Abstract or isolate actions, effects, or async flow control using callback functions, promises, monads, etc…
* Create utilities which can act on a wide variety of data types
* Partially apply a function to its arguments or create a curried function for the purpose of reuse or function composition
* Take a list of functions and return some composition of those input functions

## Function Composition

Is the process of combining two or more functions in order to produce a new function or perform some computation. Composing functions together is like snapping together a series of pipes for our data to flow through.

Put simply, a composition of functions `f` and `g` can be defined as `f(g(x))`, which evaluates from the inside out — right to left. In other words, the evaluation order is:

1. `x`
2. `g`
3. `f`

```javascript
// Function To Compose
const length = x => x.length;
const trim = x => x.trim();

const trimLen_01 = x => length(trim(x));
const result_01 = trimLen_01("  blah  ");
console.log(result_01); //-> 4

// Compose Function
const compose = (f,g) => x => f(g(x));

// Compose ES5
const composeES5 = function(f,g) {
	return function(x) {
  	return f(g(x))
  }
}

const trimLen_02 = compose(length, trim);
const result_02 = trimLen_02("  blah  ");
console.log(result_02); //-> 4
```

Composition is associative, is not important how we group our composition, if they are always on same order.

```javascript
// Function To Compose
const length = x => x.length;
const trim = x => x.trim();
const inc = x => x + 1;

// Compose Function
const compose = (f,g) => x => f(g(x));

const trimLenInc_01 = compose(inc, compose(length, trim));
const trimLenInc_02 = compose(compose(inc, length), trim);

const result_01 = trimLenInc_01("  blah  ");
console.log(result_01); //-> 5

const result_02 = trimLenInc_02("  blah  ");
console.log(result_02); //-> 5
```

Composition come from category theory, category theory is the study of how you compose. Example we have category like: String, Int, Boolean, ect. And Morph allow us to tranform from one category to another.

```javascript
// Function To Compose
const length = x => x.length;
const trim = x => x.trim();
const greated = x => x > 5;

// Compose Function
const compose = (f,g) => x => f(g(x));

// String -g-> Int -f-> Boolean
// Object -Morph -> Object -Morph-> Object
// We can cut out middle one and we can 
// String -(f.g)-> Boolean

const trimLenGreated5 = compose(greated, compose(length, trim));
console.log(trimLenGreated5("  blah  ")); //-> false
```

## Curry or Partial Application

### Arity and Arguments

Refers to the number of arguments a function can accept. The value arguments inside of javascript function is a variable they contains all the arguments passed in the function call, regardless of how many are defined.

```javascript
const showArgs = function(a,b){
  console.log(arguments);
}

showArgs('one', 'two'); //-> ["one", "two"
```

Arguments variable alse has a ‘.length’ property. The ‘.length’ of a function never changes it always matches the number of declared arguments for the function.

```javascript
const argsLen = function() {
  console.log(arguments.length);
}
argsLen('a', 'e', 'i', 'o', 'u'); //-> 5
```

We can represent the arguments variable as array by using a built-in array method called slice. Because arguments isn’t is a real array.

### Curry

Take a function and turns it into a function. Currying refers to the process of transforming a function with multiple arity into the same function with less arity. This help us on case we have a function with multiple argument, on functional programming we only can apply one input to the function and one output. Curry allow us to create our Compose function.

```javascript
const compose = (f,g) => x => f(g(x));
```

## Functional Programming Challenges

Functional Programming is a style of writing programs by simply composing a set of functions. Let create a example how we can translate imperative way of programming to a functional programming.

```javascript
const nextCharForNumberString = str => {
  const trimmed = str.trim();
  const number = parseInt(trimmed);
  const nextNumber = number + 1;
  return String.fromCharCode(nextNumber);
}

const result = nextCharForNumberString(` 64 `);
console.log(result); //-> "A"
```
To compose in one mini workflow, instead separate line with data assignment. The way we can do this is:

```javascript
const nextCharForNumberString = str =>
  [str]
  .map(t => t.trim())
  .map(n => parseInt(n))
  .map(nN => nN + 1)
  .map(nN => String.fromCharCode(nN));

const result = nextCharForNumberString(` 64 `);
console.log(result); //-> ["A"]
```

Essentially, Functional Programming asks us to wrap virtually everything in functions or object, write lots of small reusable functions and simply call them one after the other to get the result or in a compose fashion. But in order to actually write programs in this style, functions need to follow some rules.

### Box "Functor, Identity"

```javascript
const Box = x => ({
  map: f => Box(f(x)),
  inspect: () => `Box(${x})`,
});

const nextCharForNumberString = str =>
  Box(str)
  .map(t => t.trim())
  .map(n => parseInt(n))
  .map(nN => nN + 1)
  .map(nN => String.fromCharCode(nN));

const result = nextCharForNumberString(` 64 `);
console.log(result.inspect()); //-> Box(A)
```

Map allow us to composing left to right.

**Fold**

Also known variously as reduce, accumulate, compress, or inject, is a family of higher-order functions that iterate an arbitrary function over a data structure in some order and build up a return value. Typically, a fold deals with two things: a combining function and a list of elements of some data structure.

Fold (or catamorphisms) are a fundamental part of the structure of functional programs. Intuitively, they provide a way to summarize or reduce a data container down to a single value.

The folding of the list [1,2,3,4,5] with the addition operator would result in 15, the sum of the elements of the list [1,2,3,4,5]. To a rough approximation, one can think of this fold as replacing the commas in the list with the + operation, giving 1 + 2 + 3 + 4 + 5.

```javascript
const Box = x => ({
  map: f => Box(f(x)),
	fold: f => f(x),
  inspect: () => `Box(${x})`,
});

const nextCharForNumberString = str =>
  Box(str)
  .map(t => t.trim())
  .map(n => parseInt(n))
  .map(nN => nN + 1)
  .map(nN => String.fromCharCode(nN))
  .fold(c => c.toLowerCase());

const result = nextCharForNumberString(` 64 `);
console.log(result); //-> "a"
```

Simple we using fold to removing value from the box, is exactly like map without return Box, is a same way to remove value from the Box.

**Functor**

We are working with a Functor, Box is a Functor, Functor is something that can be mapped over. In other words, it’s a container which has an interface which can be used to iterate over the values inside it. When you see the word functor, you should think “mappable”.
