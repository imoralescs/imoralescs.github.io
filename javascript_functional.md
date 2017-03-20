# Javascript Functional

Is the process of building software by composing pure functions, avoiding shared state, mutable data, and side-effects. Functional programming is declarative rather than imperative, and application state flows through pure functions. Contrast with object oriented programming, where application state is usually shared and colocated with methods in objects.

Is all about decomposing a problem into a set of functions. Often, functions are chained together, nested within each other, passed around, and treated as first-class citizens.

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

Function arguments or arity of a function refers to the number of arguments a function expects. This is determined by the number of declared arguments in the function declaration and is available in the function's `.length` property.

```javascript
function foo(x,y,z) {
  // ..
}

foo.length; //-> 3	
```

The arguments object is a local variable available within all functions and it is array-like. This means it is not an instanceof the `Array` type and does not have many of it's methods. `arguments` can be accessed by index, ie `arguments[0]`, `arguments[1]` and it has a `.length` property.

This feature allows Javascript functions to have variable arguments. To work with the arguments as a real array, you can simply convert the arguments object to an array. 

```javascript
function has() {  
  let args = [].slice.call(arguments);
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

## Pure Function

Programming task, start from data input to a function, then enclose a series of computing steps to process data and last data will be the output. One or more of these tasks form a program. Inputs and outputs (collectively refereed to as I/O) are related to keyboards, screens, files, database, etc. The key part of pure function is the middle part of the operation, inside of the function between input and output can not have a external I/O operation, should be pure operation, through pue mathematical operation to evaluate.

Pure functions are completely independent of outside state, and as such, they are immune to entire classes of bugs that have to do with shared mutable state. Pure functions can be easy to move around, refactor, and reorganize in your code, making your programs more flexible and adaptable to future changes.

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

## Partial Application and Curry

Javascript allows us to access all the arguments passed to a function via the arguments variable made available inside a function's scope. This variable contains an array-like list of all the arguments pass to the function when it was called.

I say, array-like, because even though it's a list, it only has a .length and none of the other properties you'd expect of a real Array. You can access it via indexing [], get the `.length` and iterate over it using a loop construct - and that's about it.

But we can convert this into a 'real' array which will make the arguments list much more useful to us:

```javascript
function showArgs() {  
  var args = [].slice.call(arguments);
}
```

The `[].slice.call(arguments)` is a short-handed way of doing `Array.prototype.slice.call(arguments)`, we just take advantage of the use of an array literal.

In ES6 we can access and 'unpack' our arguments even more easily with the help of the spread/gather operator:

```javascript
function howMany(...args) {  
  console.log("args:", args, ", length:", args.length);
}
howMany(1,2,3,4); //-> args: [1,2,3,4], length: 4   (a "real" array)!  
```

### Partial Application

Partial Application is the process of taking an original function of N arguments, and generating a new function that fixes some of the arguments, and takes in a smaller number of arguments.

The `partial(..)` function takes an `fn` for which function we are partially applying. Then, any subsequent arguments passed in are gathered into the presetArgs array and saved for later.

```html
<ul id="result"></ul>
```

```javascript
const ajax = (url, data, callback) => {
  const request = new XMLHttpRequest();
  url = url + data;
  
  request.open('GET', url, true);
  request.onload = () => {
    if (request.status >= 200 && request.status < 400) {
      // Success!
      const json = JSON.parse(request.responseText);
      callback(json);
    } 
    else {
      // We reached our target server, but it returned an error
    }
  };
  
  request.onerror = () => {
    // There was a connection error of some sort
  };
  
  request.send();
};

const renderItems = data => {
  const mount = document.getElementById('result');
  mount.innerHTML = ` `;
  data.forEach(entry => {
    let container = document.createElement('li');
    container.innerHTML = 
    `
       <span>${entry.title}</span>
    `
    mount.appendChild(container)
  })
};

const partial = function(fn /*, args...*/) {
  // A reference to the Array#slice method.
  const slice = Array.prototype.slice;
  // Convert arguments object to an array, removing the first argument.
  const args = slice.call(arguments, 1);

  return function() {
    // Invoke the originally-specified function, passing in all originally-
    // specified arguments, followed by any just-specified arguments.
    return fn.apply(this, args.concat(slice.call(arguments, 0)));
  };
};

/*
const getUrl_01 = partial(ajax, 'https://jsonplaceholder.typicode.com/posts?userId=');
getUrl_01(2, renderItems);
*/

const getUrl_02 = partial(ajax, 'https://jsonplaceholder.typicode.com/posts?userId=');
const getPost_02 = partial(getUrl_02, 2);
getPost_02(renderItems);
```

**With `.bind`**

JavaScript has a built-in utility called `bind(..)`, which is available on all functions. It has two capabilities: presetting the this context and partially applying arguments.

```javascript
/*
const getPost_01 = ajax.bind(null, 'https://jsonplaceholder.typicode.com/posts?userId=');
getPost_01(2, renderItems);
*/

const getUrl_02 = ajax.bind(null, 'https://jsonplaceholder.typicode.com/posts?userId=');
const getPost_02 = getUrl_02.bind(null, 2);
getPost_02(renderItems);
```

**Reversing Arguments**

Recall that the signature for our Ajax function is: ajax( url, data, cb ). What if we wanted to partially apply the cb but wait to specify data and url later? We could create a utility that wraps a function to reverse its argument order:

```javascript
const partialRight = function(fn /*, args...*/) {
  // A reference to the Array#slice method.
  const slice = Array.prototype.slice;
  // Convert arguments object to an array, removing the first argument.
  const args = slice.call(arguments, 1);

  return function() {
    // Invoke the originally-specified function, passing in all just-
    // specified arguments, followed by any originally-specified arguments.
    return fn.apply(this, slice.call(arguments, 0).concat(args));
  };
};

const getUrl = partialRight(ajax, renderItems);
getUrl('https://jsonplaceholder.typicode.com/posts?userId=', 1);
```

### Curry

Currying is the process of taking a function that accepts N arguments and turning it into a chained series of N functions each taking 1 argument.

If we had an `add()` function that accepted 3 arguments and returned the sum,

```javascript
function add(a,b,c) { return a+b+c; }  
```

we can turn it into a curried function as follows:

```javascript
function curriedAdd(a) {  
   return function(b) {
     return function(c) {
       return a+b+c;
     }
   }
}
```

Curry it works by nesting functions for each possible argument, using the natural closure created by the nested functions to retain access to each of the successive arguments.

What we want is a way to easily convert an existing function that takes N arguments into its curried version without having to write-out each curried version of a function as we did with `curriedAdd()`.

```javascript
const add = (a, b, c) => a + b + c;

const argsArray = argsObject => Array.prototype.slice.call(argsObject, 0);

const curry = function(f, n) {
  const args = argsArray(arguments);
  if (typeof n === 'undefined')
    args[1] = f.length;
  if (n === args.length - 2)
    return f(...args.slice(2));
  return function() {
    return curry(...args.concat(argsArray(arguments)));
  };
};

const curriedAdd = curry(add);

const result_01 = curriedAdd(1, 2, 3);
console.log(result_01); //-> 6

const result_02 = curriedAdd(1)(2, 3); 
console.log(result_02); //-> 6

const result_03 = curriedAdd(1)(2)(3) === curriedAdd(1, 2)(3);
console.log(result_03); //-> true
```

## Function Composition

Is a mathematical concept, by which the result of one function becomes the input of the next, and so on. The return value of the final function call is the overall result. It is a key concept in functional programming. Composing functions from several small and simple functions allows for easy code reuse. Combining two or more functions in order to produce a new function or perform some computation, "take the output of program A and put it into program B". Composing functions together is like snapping together a series of pipes for our data to flow through.

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

Let us implement a more flexible compose function which can handle any number of functions as well as any number of arguments. The previous compose only works with two functions and only accepts the first passed in argument. We can rewrite the compose function as follows:

```javascript
const compose = function() {
  const fn = Array.prototype.slice.call(arguments);

  return fn.reduce((f, g) => function() {
    return f(g.apply(this, arguments));
  });
};

const composeES5 = function() {
  const fn = Array.prototype.slice.call(arguments);

  return fn.reduce(function(f,g) {
    return function() {
      return f(g.apply(this, arguments));
    };
  });
};

// Right To Left
const nextCharForNumberString = compose( 
  number => String.fromCharCode(number),
  number => number + 1,
  number => parseInt(number),
  str => str.trim()
);

const result = nextCharForNumberString(" 64 ");
console.log(result); //-> "A"
```

### Pipe

In Unix operating systems, a pipeline is multiple processes that are chained together. Each process takes an input from the previous process's output, and then passes it's output along to the next process.

```unix
process1 | process2 | process3
```

The `|` symbolises the pipe.

This is very much similar to how our compose function works. The only difference is that it evaluates left-to-right instead. Below is an implementation of a pipe function.

```javascript
const pipe = (...fns) => {
  return (initialVal) => {
    return fns.reduce((val, fn) => {
      return fn(val);
    }, initialVal);
  }
}

// Right To Left
const nextCharForNumberString = pipe(
  str => str.trim(),
  number => parseInt(number),
  number => number + 1,
  number => String.fromCharCode(number)
);

const result = nextCharForNumberString(" 64 ");
console.log(result); //-> "A"
```

## Accumulators (Recursion)

Useful tool to aid in building up a single result by iterating over a collection. Recursion is popular within functional programming languages and many of them actually offer an optimization called "tail call optimization". The problem with for loops is that the control flow through the loop is mutable. Instead we can make use of an accumulator, a tool for combining multiple values from a collection into a single value.

An accumulator is an additional argument added to a function. As the function that has an accumulator is continually called upon, the result of the computation so far is stored in the accumulator. After the recursion is done, the value of the accumulator itself is often returned unless further manipulation of the data is needed.

### Recursion

Recursion is most famous functional programming technique. A recursive function is a function that calls itself. When a functions calls itself, something strange happens. It acts both as a loop, in that it executes the same code multiple times, and as a function stack.

## Memoization

Is an optimization technique where expensive function calls are cached such that the result can be immediately returned the next time the function is called with the same arguments. This method of optimization is not unique to JavaScript and is quite common in many programming languages. It is especially useful in recursive functions as calls are more likely to call with the same arguments while recursing.

```javascript
// Function without Memoization
function factorial_01(num) {
  console.log('working for factorial(' + num + ')');
  if(num === 1) { return 1 };
  return num * factorial_01(num - 1);
}

console.log(factorial_01(3)); 
//-> working for factorial(3)
//-> working for factorial(2)
//-> working for factorial(1)
//-> 6

console.log(factorial_01(3)); 
//-> working for factorial(3)
//-> working for factorial(2)
//-> working for factorial(1)
//-> 6

console.log(factorial_01(3)); 
//-> working for factorial(3)
//-> working for factorial(2)
//-> working for factorial(1)
//-> 6

let memoize = fn => { // line 1
  let cache = {}; // line 2
  return (...args) => { // line 3
    let stringifiedArgs = JSON.stringify(args); // line 4
    let result = cache[stringifiedArgs] = cache[stringifiedArgs] || fn(...args); // line 5
    return result;// line 6
  };
};

var factorial_02 = memoize(function(num) {
  console.log('working for factorial(' + num + ')');
  if(num === 1) { return 1 };
  return num * factorial_02(num - 1);
});

// First Call
console.log(factorial_02(3));
//-> working for factorial(3)
//-> working for factorial(2)
//-> working for factorial(1)
//-> 6

// Successive Calls
console.log(factorial_02(3)); //-> 6
console.log(factorial_02(3)); //-> 6

// Short Circuit Higher Factorial Calls
console.log(factorial_02(4));
//-> working for factorial(4)
//-> 24
```

**Memoization Function**

Line:

1. Our memoize function accepts a fn to be memoized.
2. We initialize a new cache for the fn passed in utilizing the, ever so powerful, closure scope.
3. We return the memoized fn which accepts some number of args.
4. We stringify the arguments passed to our memoized fn to be used as a “key” to our cache.
5. We then check the cache for the value associated with that key.  If the value associated with that key exists in the cache we assign it to result otherwise we call fn with the arguments passed to the memoized function and assign its value to the cache.
6. Finally, we return the result.

### Where can I use memoization? 

Not all functions can be memoized. In particular, pure functions can be memoized. A function is said to be pure when it behaves in a predictable way, in the sense that for each x, the function will always return the same associated y value.

## Immutability

Variables can be assigned only once. This is known as immutability. ECMAScript 2015 supports a new keyword, `const`. The `const` keyword can be used in the same way as `var` except that variables assigned with const will be immutable.

If we using an older browser without support, then const won't be available to you. A possible workaround is to make use of the `Object.freeze` functionality which is more widely adopted:

```javascript
let consts = Object.freeze({ pi : 3.141});
consts.pi = 7;
console.log(consts.pi);//outputs 3.141
```

## Category Theory
Category theory is the theoretical concept that empowers function composition. Allow us to write entire libraries helpers and APIs to programming on functional way.

### Category theory

**Categories** 

Are just sets with the same type. In JavaScript, they're arrays or objects that contain variables that are explicitly
declared as numbers, strings, Booleans, dates, nodes, and so on.

**Morphisms**

Are pure functions that, when given a specific set of inputs, always return the same output. 

**Homomorphic** 

Operations are restricted to a single category. 

**Polymorphic**

Operations can operate on multiple categories. For example, the homomorphic function multiplication only works on numbers, 

```javascript
console.log(5 * 5); //-> 25
console.log('acb' * 'def'); //-> NaN
```

but the polymorphic function addition can work on strings too.

```javascript
console.log(5 + 5); //-> 10
console.log('acb' + 'def'); //-> 'acbdef'
```

Category theory tells us that, when we have two morphisms where the category of the first one is the expected input of the other, then they can be composed.

### Type Safety

Categories contain two things:

1. **Objects:**  (in JavaScript, types), In category theory are more like variables with an explicit data type and not collections of properties and values like in the JavaScript definition of objects.
2. **Morphisms:** (in JavaScript, pure functions that only work on types), are just pure functions that use those types.

Using category theory in JavaScript means working with one certain data type per category. Data types are numbers, strings, arrays, dates, objects, Booleans, and so on. But, with no strict type system in JavaScript, things can go awry. So we'll have to implement our own method of ensuring that the data is correct.

There are four primitive data types in JavaScript: numbers, strings, Booleans, and functions. We can create type safety functions that either return the variable or throw an error. This fulfils the object axiom of categories.

```javascript
var typeOf = function(type) {
  return function(x) {
    if(typeof x === type) {
      return x;
    }
    else {
      throw new TypeError("Error: " + type + " expected, " + typeof x + " given.");
    }
  }
}

var str = typeOf('string'),
    num = typeOf('number'),
    func = typeOf('function'),
    bool = typeOf('boolean');

// timestampLength :: String -> Int
function timestampLength(t) { 
  return num(str(t).length); 
}

// const result_01 = timestampLength(Date.parse('12/31/1999')); 
// console.log(result_01); //-> Uncaught TypeError: Error: string expected, number given.

const result_02 = timestampLength(Date.parse('12/31/1999').toString());
console.log(result_02); //-> 12
```

Functions like this `.toString()` that explicitly transform one type to another (or to the same type) are called morphisms.

This fulfils the morphism axiom of category theory. These forced type declarations via the type safety functions and the morphisms that use them are everything we need to represent the notion of a category in JavaScript.

### Category and Containers

We can think of "Category" as a container, with contains two things. Value and the deformation of the value, that is the function.

```javascript
// Implementation 1
class Category_01 {
  constructor(val) {
    this.val = val;
  }
	
  add(x) {
    return x + this.val;
  }
}

const category = new Category_01(1);
console.log(category.add(3)); //-> 4

// Implementation 2
const Category_02 = x => ({
  add: (y) => y + x 
});

const result_01 = Category_02(1).add(3);
console.log(result_01); //-> 4
```

### Box "Functor"

While morphisms are mappings between types, functors are mappings between categories. They can be thought of as functions that lift values out of a container, morph them, and then put them into a new container. 

```javascript
class Functor {
  constructor(val) { 
    this.val = val; 
  }

  map(f) {
    return new Functor(f(this.val));
  }

  inspect() {
    return `Functor(${this.val})`;
  }
}

const nextCharForNumberString = str =>
  new Functor(str)
  .map(t => t.trim())
  .map(n => parseInt(n))
  .map(nN => nN + 1)
  .map(nN => String.fromCharCode(nN));

const result = nextCharForNumberString(` 64 `);
console.log(result.inspect()); //-> Functor(A)
```

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

Map on this Box functos allow us to composing left to right.

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

We defined functors as something that takes a value from a container and applies a function to it. When that container is a function, we just call it to get its inner value, Box is a Functor, Functor is something that can be mapped over. In other words, it’s a container which has an interface which can be used to iterate over the values inside it. When you see the word functor, you should think “mappable”.

Function compositions are associative. If your high school algebra teacher was like mine, she taught you what the property is but not what it can do. In practice, compose is what the associative property can do.

This is not to be confused with the commutative property. ƒ o g does not always equal g o ƒ. In other words, the reverse of the first word of a string is not the same as the first word of the reverse of a string.

What this all means is that it doesn't matter which functions are applied and in what order, as long as the input of each functions comes from the output of the previous function. 

Any type with map method, and is determined by few laws:

* Law 1:  

Functor must distribute over morphism composition, if you have object a to --> b to --> c, always must exist a arrow(morphism) to composite all from a to --> c. And both path are identical. Compose arrow must exist.

F(f) ∘ F(g) === F(f ∘ g)

```javascript
const Box = x => ({
  map: f => Box(f(x)),
  fold: f => f(x),
  inspect: () => `Box(${x})`,
});


const result_01 = Box('squirrels')
  .map(s => s.substr(5))
  .fold(s => s.toUpperCase());

const result_02 = Box('squirrels')
  .fold(s => s.substr(5).toUpperCase());

console.log(result_01, result_02); //-> "RELS RELS"
console.log(result_01 === result_02); //-> true
```

* Law 2: 

Functor must map identity of an object to that of mapped object.

F(id A) === id F(A)

```javascript
const Box = x => ({
  map: f => Box(f(x)),
  fold: f => f(x),
  inspect: () => `Box(${x})`,
});

const id = x => x;

const result_01 = Box('crayons').map(id);
const result_02 = id(Box('crayons'));

console.log(result_01.inspect() === result_02.inspect()); //-> true
```

**`.of`**

`new` command was used when the `new` functor was created . This is really not like a functional programming, because the `new` command is an object-oriented programming. `.of` Is a interface to put or place a value into the type. And we called lifting a value into a type. 

We are use the `of` method to replace the `new`.

```javascript
class Functor {
  constructor(val) { 
    this.val = val; 
  }

  map(f) {
    return new Functor(f(this.val));
  }
	
  inspect() {
    return `Functor(${this.val})`;
  }
}

Functor.of = val => new Functor(val);

const nextCharForNumberString = str =>
  Functor.of(str)
  .map(t => t.trim())
  .map(n => parseInt(n))
  .map(nN => nN + 1)
  .map(nN => String.fromCharCode(nN));

const result = nextCharForNumberString(` 64 `);
console.log(result.inspect()); //-> Functor(A)
```

```javascript
const Box = x => ({
  map: f => Box(f(x)),
  fold: f => f(x),
  inspect: () => `Box(${x})`,
});

Box.of = (x) => Box(x);
const result = Box.of(100);
console.log(result.inspect()); //-> Box(100)
```

### Either and "Maybe" Functor

With Either we can solve challenge like how we handle If-Else Condition and Null Exception.

```javascript
const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  inspect: () => `Right(${x})`
})

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  inspect: () => `Left(${x})`
})

Left("hi")
  .map(s => s.toUpperCase())
  .fold(x => console.log(x + ', I am Left!'),
	y => console.log(y + ', Wooo, I am Right!'));
//-> hi, I am Left!

Right("Hi")
  .map(s => s.toUpperCase())
  .fold(x => console.log(x + ', I am Left!'),
        y => console.log(y + ', Wooo, I am Right!'));
//-> HI, Wooo, I am Right!
```

Right Box take a value and map, through another function and continuum mapping if need it. Left Box is different in the case, when take a value they are not going to run any function. Left refuse to run any request.

This is useful, to refactor fold method inside "Box" with (f, g) => g(x) for right box case and (f, g) => f(x) for left box case. 

This allow us to do pure functional error handling, if-else case, code branching, null check, or other case than capture disjunction concept of OR.

**If/Else**

```javascript
const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  inspect: () => `Right(${x})`
})

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  inspect: () => `Left(${x})`
})

// Looking for premium member.
const jack = {
  "premium":true,
  "preferences":[{
    "name":"Jack Smith",
    "address":"1420 Seagull Dr Apt. 203",
  }],
};

const maria = {
  "premium":false,
  "preferences":[{
    "name":"Maria Hillary",
    "address":"Elon Cres 408",
  }],
};

function loadPrefs(data){
  console.log("User " + data[0].name + " is premium member.");
}

const getUser = user =>
  (user.premium ? Right(user) : Left('not premium'))
    .map(u => u.preferences)
    .fold(() => console.log("User is not premium member."),
          prefs => loadPrefs(prefs))

getUser(jack); //-> "User Jack Smith is premium member."
getUser(maria); //-> “User is not premium member."
```

**Try/Catch**

```javascript
const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  inspect: () => `Right(${x})`
})

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  inspect: () => `Left(${x})`
})

const tryCatch = fn => {
  try {
    return Right(fn())
  }
  catch(e) {
    return Left(e)
  }
}

var data = '{"serve": "nginx","port": "8000" }';
const readFile = (x) => x

const getPort = () =>
  tryCatch(() => readFile(data))
    .map(p => tryCatch(() => JSON.parse(p)))
    .fold(e => 3000,
          p => p);

const result = getPort();
console.log(result.inspect()); //-> Right(Right([object Object]))
```

We have a problem with previous code, on the Try/Catch we have the case of two Box are catching our value or testing our value from null. So we have a Box inside another Box. To solve this we can fold two time. But what if the case we have more that two level of deep Box.

### Monads Functor

Box have `.of` method to lift the value, to place value into the type and we add `.chain` method to create the monad interface, other way to call are (flatMap, bind, >>=)

Chain is like map, only difference is they unboxing back up a value. Chain is a method which, wait for it, allows a chain of operations in sequence. It also takes care of handling invalid or nothing values while it’s at it to make sure our code doesn’t crash and burn if users start sending wrong data through an email field for example. The chain is actually called bind in monadic nomenclature. But since the word is already in javascript’s dictionary for an entirely different purpose than what we used chain for, it was rechristened. Monads allow us to nest computation.

* Law 1:

join(monad.map(join)) === join(join(monad))

```javascript
const Box = x => ({
  map: f => Box(f(x)),
  inspect: () => `Box(${x})`,
  chain: f => f(x),
});

Box.of = (x) => Box(x);

const join = monad =>
  monad.chain(x => x);

const monad = Box(Box(Box(3)));
console.log(monad.inspect()); //-> Box(Box(Box(3)))

const result_01 = join(monad.chain(x => x));
const result_02 = join(monad.map(join));
const result_03 = join(join(monad))

// Flatmap
console.log(result_01.inspect()); //-> Box(3)
console.log(result_02.inspect() === result_03.inspect()); //-> true
```

* Law 2:

join(Box.of(monad)) === join(monad.map(Box.of))

```javascript
const Box = x => ({
  map: f => Box(f(x)),
  inspect: () => `Box(${x})`,
  chain: f => f(x),
});

Box.of = (x) => Box(x);

const join = monad =>
  monad.chain(x => x);

const monad = Box('wonder');

const result_01 = join(Box.of(monad));
const result_02 = join(monad.map(Box.of));
console.log(result_01.inspect() === result_02.inspect()); //-> true
```

**Try/Catch with Chain**

```javascript
const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  chain: f => f(x),
  inspect: () => `Right(${x})`
})

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  chain: f => Left(x),
  inspect: () => `Left(${x})`
})

const tryCatch = fn => {
  try {
    return Right(fn())
  }
  catch(e) {
    return Left(e)
  }
}

var data = '{"serve": "nginx","port": "8000" }';
const readFile = (x) => x

const getPort = (data) =>
  tryCatch(() => readFile(data))
    .chain(p => tryCatch(() => JSON.parse(p)))
    .fold(e => 3000,
          p => p.port);

const result_01 = getPort(data);
console.log(result_01); //-> "8000"

const result_02 = getPort();
console.log(result_02); //-> "3000"
```

**If/Else/If**

```javascript
console.clear();

const curry = R.curry;
const is = R.is;

const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  chain: f => f(x),
  inspect: () => `Right(${x})`
})

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  chain: f => Left(x),
  inspect: () => `Left(${x})`
})

const tax = curry((tax, price) => {
  return (!is(Number, price)) ? 
    Left(new Error("Price must be numeric")) :
    Right(price + (tax * price));
});

const discount = curry((dis, price) => {
  return (!is(Number, price)) ?
    Left(new Error("Price must be numeric")) :
    (price < 10) ?
      Left(new Error("discount cant be applied for items priced below 10")) :
      Right(price - (price * dis))			
});

const result_01 = discount(0.1, 11);
console.log(result_01.inspect()); //-> Right(9.9)

const result_02 = discount(0.1, '11');
console.log(result_02.inspect()); //-> Left(Error: Price must be numeric)

const result_03 = discount(0.1, 9);
console.log(result_03.inspect()); //-> Left(Error: discount cant be applied for items priced below 10)

const result_04 = tax(0.1, 11);
console.log(result_04.inspect()); //-> Right(12.1)

const result_05 = tax(0.1, '11');
console.log(result_05.inspect()); //-> Left(Error: Price must be numeric)

const addTax = (tax(0.1));
const apply25Disc = (discount(0.25));
const getItemPrice = (item) => Right(item.price);

const showTotalPrice = (item) =>
  getItemPrice(item)
    .chain(apply25Disc)
    .chain(addTax)
    .fold(error => error,
          price => price);

const result_06 = showTotalPrice({ name: 't-shirt', price: 11 });
console.log(result_06); //=> 9.075

const result_07 = showTotalPrice({ name: 't-shirt', price: '10 dollars' });
console.log(result_07); //=> Error: Price must be numeric

const result_08 = showTotalPrice({ name: 't-shirt', price: 5 });
console.log(result_08); //=> Error: discount cant be applied for items priced below 10
```

```javascript
const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  chain: f => f(x),
  inspect: () => `Right(${x})`
})

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  chain: f => Left(x),
  inspect: () => `Left(${x})`
})

const jack = {
  "premium":true,
  "preferences":[{
    "name":"Jack Smith",
    "address":"1420 Seagull Dr Apt. 203",
  }],
};

const maria = {
  "premium":false,
  "preferences":[{
    "name":"Maria Hillary",
    "address":"Elon Cres 408",
  }],
};

function loadPrefs(data){
  console.log("User " + data[0].name + " is premium member.");
}

const getUser = user =>
  (user.premium ? Right(user) : Left('not premium'))
    .map(u => u.preferences)
    .fold(() => console.log("User is not premium member."),
          prefs => loadPrefs(prefs))
					
getUser(jack); //-> "User Jack Smith is premium member."
getUser(maria); //-> “User is not premium member."
```

**fromNullable** 

Is a helper to check null value before execute code.

```javascript
const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  chain: f => f(x),
  inspect: () => `Right(${x})`
})

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  chain: f => Left(x),
  inspect: () => `Left(${x})`
})

const fromNullable = x => 
  x != null ? Right(x) : Left(null);
	
const jonh = {
  "premium":true,
  "name":"Jonh Walk",
  "address":{
    "street":{
      "name":"Seagull Drive"
    },
  },
};

const steph = {
  "premium":true,
  "name":"Steph Walk",
  "address":{
    "street":null,
  },
};

const maria = {
  "premium":true,
  "name":"Steph Walk",
  "address":null,
};

const getStreetName = user =>
  fromNullable(user.address)
    .chain(a => fromNullable(a.street))
    .map(s => s.name)
    .fold(e => console.log("street don't exist"),
				  n => console.log(n));

getStreetName(jonh); //-> "Seagull Drive"
getStreetName(steph); //-> "street don't exist"
getStreetName(maria); //-> "street don't exist"
```

```javascript
const curry = R.curry;
const is = R.is;
const prop = R.prop;

const getProp = (obj, key) =>
  key.split('.').reduce( (o, x) =>
    (typeof o == "undefined" || o === null) ? o : o[x], obj);
		
const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  chain: f => f(x),
  inspect: () => `Right(${x})`
})

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  chain: f => Left(x),
  inspect: () => `Left(${x})`
})

const fromNullable = x => 
  x != null ? Right(x) : Left(null);
	
let joeUser = {
  name: 'joe',
  email: 'joe@example.com',
  prefs: {
    languages: {
      primary: 'sp',
      secondary: 'en'
    }
  }
};

let indexURLs = {
  'en': 'http://mysite.com/en',  
  'sp': 'http://mysite.com/sp', 
  'jp': 'http://mysite.com/jp'   
}

const getUrl = R.curry(function(allUrls, language){
  return fromNullable(allUrls[language])
    .fold(() => "Language not found",
          url => url);
})(indexURLs);

const getURLForUser = (user) => 
  fromNullable(user)//wrap user in a Maybe object 
    .map(x => getProp(x, 'prefs.languages.primary')) //to grab primary language
    .fold(() => "User not found",
          user => getUrl(user));

const result_01 = getURLForUser(joeUser);
console.log(result_01);
```

```javascript
const curry = R.curry;
const is = R.is;
const prop = R.prop;

const getProp = (obj, key) =>
  key.split('.').reduce( (o, x) =>
    (typeof o == "undefined" || o === null) ? o : o[x], obj);
		
const Right = x => 
({
  fold: (f, g) => g(x),
  map: f => Right(f(x)),
  chain: f => f(x),
  inspect: () => `Right(${x})`
})

Right.of = (x) => Right(x);

const Left = x =>
({
  fold: (f, g) => f(x),
  map: f => Left(x),
  chain: f => Left(x),
  inspect: () => `Left(${x})`
})

const fromNullable = x => 
  x != null ? Right(x) : Left(null);
	
const data = { host: 'localhost', port: 80,};

Right.of(data)
  .map(prop('host'))
  .fold(() => console.log("Properties don't found"),
        x => console.log("Properties: " + x));
//-> Properties: localhost
```

### Lazy Evaluation Monad

Lazy evaluation, also known as non-strict evaluation, call-by-need and deffered execution, is strategy which delays the evaluation or execution of an expression until its value is needed. Typically they wrap a function. IO Monad, Task, Promise, Observable, all are Lazy Evaluation Monad.

```javascript
const LazyBox = g => ({
  map: f => LazyBox(() => f(g())),
  fold: f => f(g()),
});

const result = LazyBox(() => ' 64 ')
  .map(a => a.trim())
  .map(trimmed => new Number(trimmed))
  .map(number => number + 1)
  .map(x => String.fromCharCode(x));

console.log(result.fold(x => x.toLowerCase()));
```

**IO Monad**

```html
<div id="text-html">Lorem ipsum dolor sit amet.</div> 
```

```javascript
/*
// Convert function argument to array.
const argsToArray = (args) => {
  return Array.prototype.slice.call(args, 0);
}

// Partial function helper.
const partial = function() {
  let args = argsToArray(arguments);
  let fn = args.shift();

  return function() {
    let remainingArgs = Array.from(arguments);
    return fn.apply(this, args.concat(remainingArgs));
  }
}
*/

const partial = function(fn, ...outerArgs){
  return function(...innerArgs) {
    return fn(...outerArgs, ...innerArgs)
  }
}

const IO = g => ({
  map: f => IO(() => f(g())),
  inspect: () => `IO(${g()})`,
  chain: f => f(g),
  fold: f => f(g()),
  run: () => g()
});

// Helper functions
const read = function (document, id) {
  return function () {
    return document.querySelector(`${id}`);
  };
};

const write = function(document, id) {
  return function(val) {
    return document.querySelector(`${id}`).innerHTML = val;
  };
};

// Partial Method - Add function to partial apply and add first param.
const readDom = partial(read, document); 
const writeDom = partial(write, document); 

// Run program
const changeToStartCase =
  IO(readDom('#text-html'))
    .map(x => x.innerHTML.toUpperCase())
    .map(writeDom('#text-html'));

// this will start case the content within the DOM element
changeToStartCase.run();
```

**Task Monad**

The Task(a, b) structure represents values that depend on time. This allows one to model time-based effects explicitly, such that one can have full knowledge of when they're dealing with delayed computations, latency, or anything that can not be computed immediately. Need .fork() to execute.

```javascript
// Library Task
// https://github.com/folktale/data.task

// Success Case
Task.of(1)
  .map(x => x + 1)
  .chain(x => Task.of(x + 1))
  .fork(e => console.log('Err', e),
        s => console.log('Success', s)); //-> Success 3
				
// Error Case, like Left
Task.rejected(1)
  .map(x => x + 1)
  .chain(x => Task.of(x + 1))
  .fork(e => console.log('Err', e),
        s => console.log('Success', s)); //-> Err 1
```

### Semigroups and Monoids

Is a type with concat method. This idea come from abstract algebra. Formal definition is, semigroup is an algebraic structure consisting of a set together with associative binary operation.
 
Array and String are semigroup

```javascript
const result_01 = "a".concat("b").concat("c");
console.log(result_01); //-> abc

const result_02 = [1,2].concat([3,4].concat([5,6]));
console.log(result_02); //-> [1, 2, 3, 4, 5, 6]
```

Sometimes no all type are semigroup, because they no have the concat method. Example 1 + 2 = 3, We need to create the type:

```javascript
const Sum = x =>
({
  x, 
  concat: ({x: y}) => 
    Sum(x + y),
  inspect: () =>
    `Sum(${x})`,
  fold: () => x,
});

const result = Sum(1).concat(Sum(2));
console.log(result.fold()); //-> 3
```

Another type without concat method is boolean type.

True && False = False
True && True = True

```javascript
const All = x =>
({
  x,
  concat: ({x: y}) =>
    All(x && y),
  inspect: () =>
    `All(${x})`,
  fold: () => x,
});

const result_01 = All(true).concat(All(false));
console.log(result_01.fold()); //-> false

const result_02 = All(true).concat(All(true));
console.log(result_02.fold()); //-> true
```

Let create first semigroup, this semigroup always keep the first one.

```javascript
const First = x =>
({
  x,
  concat: _ => 
    First(x),
  inspect: () =>
    `First(${x})`,
  fold: () => x
});

const result = First("blah").concat(First("ice cream")).concat(First("meta programming"));
console.log(result.fold()); //-> blah
```

Let suppose we have this user with two same account, and they want to merge those account. Date come in this example object form.

```javascript
const Sum = x =>
({
  x, 
  concat: ({x: y}) => 
    Sum(x + y),
  inspect: () =>
    `Sum(${x})`,
  fold: () => x,
});

const All = x =>
({
  x,
  concat: ({x: y}) =>
    All(x && y),
  inspect: () =>
    `All(${x})`,
  fold: () => x,
});

const First = x =>
({
  x,
  concat: _ => 
    First(x),
  inspect: () =>
    `First(${x})`,
  fold: () => x
});

const acct1 = Map({name: First('Nico'), isPaid: All(true), points: Sum(10), friends: ['Franklin']});
const acct2 = Map({name: First('Nico'), isPaid: All(false), points: Sum(2), friends: ['Gatsby']});

const result = acct1.concat(acct2);
console.log(JSON.stringify(result.toJS()));
//-> 
/* 
 {
   "name":{"x":"Nico"},
   "isPaid":{"x":false},
   "points":{"x":12},
   "friends":["Franklin","Gatsby"]
 }
*/
```

Monoid is a semigroup with especial element, they act like special identity. Let consider addition, if we have: 

1 + 0 = 1
2 + 0 = 2

If we have anything x + 0 = x, if this addition is our concatenation, we have a neutral element that access to identity source. Let create some interface to proven.

```javascript
Sum.empty = () => Sum(0);

// Both must give me same result, because they have a neutral element
const result_01 = Sum.empty().concat(Sum(1).concat(Sum(2)));
const result_02 = Sum(1).concat(Sum(2));

console.log(result_01.fold()); //-> 3
console.log(result_02.fold()); //-> 3

// Now let try the same with All
// Neutral element will be true on this case
All.empty = () => All(true);

const result_03 = All(true).concat(All(true));
const result_04 = All(true).concat(All(true)).concat(All.empty());

console.log(result_03.fold()); //-> true
console.log(result_04.fold()); //-> true
```

If we try First, we cannot covert or promoted Semigroup to Monoid, because we no have way to have a neutral element. Normally we don’t receive json object or array with semigroup inner, we can deal this:

```javascript
const Sum = x =>
({
  x, 
  concat: ({x: y}) => 
    Sum(x + y),
  inspect: () =>
    `Sum(${x})`,
  fold: () => x,
});

Sum.empty = () => Sum(0);

const result_01 = Map({brian: 3, sara: 5})
  .map(x => Sum(x))
  .fold(Sum.empty());

console.log(result_01.fold()); //-> 8

const result_02 = List.of(1,2,3)
  .foldMap(Sum, Sum.empty());
	
console.log(result_02.fold()); //-> 6
```

### Applicative Functor (`Ap`)

Basically you can just map a function over a functor. Applicative functors allow you to take a "normal" function (taking non-functorial arguments) use it to operate on several values that are in functor contexts. 

An applicative functor is a pointed functor with an ap method.

Example, we have a Box(x => x + 1)  and we want to apply this box to another Box with value Box(2).

```javascript
const Box = x => ({
  map: f => Box(f(x)),
  inspect: () => `Box(${x})`,
  fold: f => f(x),
  chain: f => f(x),
  ap: second_box => second_box.map(x),
});

const result = Box(x => x + 1).ap(Box(2));
console.log(result);
```

Why we do this. You can take multiple Functors and you apply each one to a function. Notice the main function need to be on Curry form.

```javascript
const result = Box(x => y => x + y).ap(Box(2)).ap(Box(3));
console.log(result);
```

Helped function to do the same thing without mention Functor

```javascript
const liftA2 = (f, fx, fy) =>
  fx.map(f).ap(fy);

const liftA3 = (f, fx, fy, fz) =>
  fx.map(f).ap(fy).ap(fz);
	
const result_01 = liftA2(x => y => x + y, Box(2), Box(4));
console.log(result_01);

const result_02 = liftA3(x => y => z => x + y + z, Box(2), Box(4), Box(5));
console.log(result_02);
```

We are going to work with two different Either Box

```javascript
const Right = x =>
({
  map: f => Right(f(x)),
  inspect: () => `Right(${x})`,
  fold: (f, g) => g(x), // Take out value from the box
  chain: f => f(x), // Run a function and return another one
	ap: second_box => second_box.map(x),
});

const Left = x => ({
  map: f => Left(x),
  inspect: () => `Left(${x})`,
  fold: (f, g) => f(x),
  chain: f => Left(x),
});

Either.of = (x) => Right(x);

const Selector = element =>
  Either.of({element, height:10});

const getScreenSize = (screen, head, foot) =>
  screen - (head.height + foot.height);

const result = Selector('header')
  .chain(head => Selector('footer')
    .map(footer => getScreenSize(800, head, footer)));
											
console.log(result); //-> Object {x: 780}
```

If we see the previous example we still have a sequence process, we need to find the header first and them if not find is break out. We need to refactor with applicative, but change function to curry form.

```javascript
const getScreenSize = screen => head => foot => screen - (head.height + foot.height);

const result = Either.of(getScreenSize(800))
                 .ap(Selector('header'))
                 .ap(Selector('footer'));
											
console.log(result); //-> Object {x: 780}
```

Other way to used Applicative Functor is in the case we have loop inside to another loop to merge List. Example:

```javascript
for(x in xs){
  for(y in ys){
    for(z in zs){

    }
  }
}
```

We can solve this with Applicative Functor.
Note: For next example we are using “Immutable.js from Facebook and Immutable-ext.js from Brian Lonsdorf”

```javascript
const merch = () =>
  List.of(x => y => `${x}-${y}`)
    .ap(List(['teeshirt', 'sweater']))
    .ap(List(['large', 'medium', 'small']));

const result = merch();
console.log(result.toJS()); //-> ["teeshirt-large", "teeshirt-medium", "teeshirt-small", "sweater-large", "sweater-medium", "sweater-small"]

const merch = () =>
  List.of(x => y => z => `${x}-${y}-${z}`)
    .ap(List(['teeshirt', 'sweater']))
    .ap(List(['large', 'medium', 'small']))
    .ap(List(['black', 'white']));

const result = merch();
console.log(result.toJS()); //-> ["teeshirt-large-black", "teeshirt-large-white", "teeshirt-medium-black", "teeshirt-medium-white", "teeshirt-small-black", "teeshirt-small-white", "sweater-large-black", "sweater-large-white", "sweater-medium-black", "sweater-medium-white", "sweater-small-black", "sweater-small-white"]
```

### Traversable

Represents data structures which can be traversed while preserving the shape.

```javascript
const httpGet = (path, params) =>
  Task.of(`${path} result`);

const result = Map({home: '/', about: '/about-us', blog: '/blog'})
  .map(route => httpGet(route, {}));

console.log(result.toJS()); //-> Object {home: Task, about: Task, blog: Task}
```

In the previous example we have problem, a object values has Task inside of each value. And we want only one Task to all result.

```javascript
Map({home: '/', about: '/about-us', blog: '/blog'})
  .traverse(Task.of, route => httpGet(route, {}))
  .fork(e => console.log('err', e),
	s => console.log('success:', s.toJS())); //-> success: Object {home: "/ result", about: "/about-us result", blog: "/blog result"}
```

Another example with array:

```javascript
const files = ['box.js', 'config.json'];
const readFile = file =>
  Task.of(`${file}`);

const result = files.map(file => readFile(file));
console.log(result); //-> [Task, Task]

const readFile = file =>
  Task.of(`${file}`);
	
const files = List(['box.js', 'config.json']);
files
  .traverse(Task.of, file => readFile(file))
  .fork(e => console.log('err', e),
        s => console.log('success:', s.toJS())); //-> success: ["box.js", "config.json"]
```

### Natural Transformation

Is just a type of conversion, a Functor F than hold a value and become to a Functor G and hold same value. Fa -> Ga

```javascript
const eitherToTask = e =>
  e.fold(Task.rejected, Task.of);// fold out value inside of Either to a Task

eitherToTask(Either.Right('night-tales'))
  .fork(e => console.log('err:', e),
        x => console.log('success:', x)); //-> success: night-tales

eitherToTask(Either.Left('night-tales'))
  .fork(e => console.log('err:', e),
        x => console.log('success:', x)); //-> err: night-tales

const boxToEither = b =>
  b.fold(Either.Right);

const result = boxToEither(Box(100));
console.log(result); //-> Right {value: 100}
```
