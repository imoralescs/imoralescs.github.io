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

## Function Composition (Pipe)

Is the process of combining two or more functions in order to produce a new function or perform some computation. "take the output of program A and put it into program B". Composing functions together is like snapping together a series of pipes for our data to flow through.

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

## Accumulators (Recursion)

Useful tool to aid in building up a single result by iterating over a collection. Recursion is popular within functional programming languages and many of them actually offer an optimization called "tail call optimization". The problem with for loops is that the control flow through the loop is mutable. Instead we can make use of an accumulator, a tool for combining multiple values from a collection into a single value.

An accumulator is an additional argument added to a function. As the function that has an accumulator is continually called upon, the result of the computation so far is stored in the accumulator. After the recursion is done, the value of the accumulator itself is often returned unless further manipulation of the data is needed.


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

Essentially, Functional Programming asks us to wrap virtually everything in javascript object, write lots of small reusable functions and simply call them one after the other to get the result or in a compose fashion. 

Everything in JavaScript is an object, which means that we can adding functionality to existing objects to improve their look. Operating on collections of objects is a space in which functional programming provides some powerful features. 

### Box "Functor"

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

Is a interface to put or place a value into the type. And we called lifting a value into a type.

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

### Either "Maybe"

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

**Monads**

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

Is strategy which delays the evaluation or execution of an expression until its value is needed. Typically they wrap a function. IO Monad, Task, Promise, Observable, all are Lazy Evaluation Monad.

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
