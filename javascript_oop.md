# Javascript OOP

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

## OOP Functional Style

### Public and Private Property

1. Local variables, including constructor parameters, can be considered private properties. Local constructor variables can not be accessed from the outside, but they are available within the constructor itself.
2. The properties recorded in `this` can be considered public.

```javascript
let Machine = function(powerAmount) {
  this.waterAmount = 0;
  console.log('Initial power of machine is: ' + powerAmount);
}

let coffeMachine = new Machine(100);

console.log(coffeMachine.waterAmount); //-> 0
coffeMachine.waterAmount = 200;
console.log(coffeMachine.waterAmount); //-> 200
```

### Public and Private Methods

```javascript
let Machine = function(powerAmount) {
  this.waterAmount = 0;
  
  // Private Methods
  function getBoilTime() {
    return 1000;
  }
  
  function onReady() {
    console.log('Machine Ready')
  }
  
  // Public Methods
  this.run = function(){
    setTimeout(onReady, getBoilTime());
  }
}

let coffeMachine = new Machine(100);
coffeMachine.waterAmount = 200;

coffeMachine.run();
```

### Constant

```javascript
let Machine = function(powerAmount) {
  this.waterAmount = 0;
  
  // Constant
  let WATER_HEAT_CAPACITY = 4200;
  
  // Private Methods
  function getBoilTime() {
    return this.waterAmount * WATER_HEAT_CAPACITY * 80 / powerAmount;
  }
  
  function onReady() {
    console.log('Machine Ready')
  }
  
  // Public Methods
  this.run = function(){
    setTimeout(onReady, getBoilTime());
  }
}

let coffeMachine = new Machine(1000);
coffeMachine.waterAmount = 200;

coffeMachine.run();
```

### Access The Object From The Internal Method

**Using `this`**

```javascript
let Machine = function(powerAmount) {
  this.waterAmount = 0;
  
  // Constant
  let WATER_HEAT_CAPACITY = 4200;
  
  // Private Methods
  function getBoilTime() {
    return this.waterAmount * WATER_HEAT_CAPACITY * 80 / powerAmount;
  }
  
  function onReady() {
    console.log('Machine Ready')
  }
  
  // Public Methods
  this.run = function(){
    setTimeout(onReady, getBoilTime.call(this));
  }
}

let coffeMachine = new Machine(100000);
coffeMachine.waterAmount = 200;

coffeMachine.run();
```

**Using `bind`**

```javascript
let Machine = function(powerAmount) {
  this.waterAmount = 0;
  
  // Constant
  let WATER_HEAT_CAPACITY = 4200;
  
  // Private Methods
  let getBoilTime = function() {
    return this.waterAmount * WATER_HEAT_CAPACITY * 80 / powerAmount;
  }.bind(this);
  
  function onReady() {
    console.log('Machine Ready')
  }
  
  // Public Methods
  this.run = function(){
    setTimeout(onReady, getBoilTime);
  }
}

let coffeMachine = new Machine(100000);
coffeMachine.waterAmount = 200;

coffeMachine.run();
```

### Getters and Setters

### Functional Inheritance

```javascript
let Machine = function() {
  let enabled = false;
  
  this.enable = function() {
    enabled = true;
    console.log(enabled);
  };
  
  this.disable = function() {
    enabled = false;
    console.log(enabled);
  };
}

let CoffeMachine = function(powerAmount){
  Machine.call(this);
  
  let waterAmount = 0;
  
  this.setWaterAmount = function(amount) {
    waterAmount = amount;
    console.log(waterAmount);
  };
}

let coffeAmazon = new CoffeMachine(1000);

coffeAmazon.enable(); //-> true
coffeAmazon.setWaterAmount(100); //-> 100
coffeAmazon.disable(); //-> false
```

**Functional Inheritance Protected Properties**

1. They does not have access to the private properties of the parent.
2. For their to have access to the property, it must be written in `this`.

Wrong case:

```javascript
let Machine = function() {
  let enabled = false;
  
  this.enable = function() {
    enabled = true;
    console.log(enabled);
  };
  
  this.disable = function() {
    enabled = false;
    console.log(enabled);
  };
}

let CoffeMachine = function(powerAmount){
  Machine.call(this);
  
  this.enable();
  
  console.log(enabled); //-> ReferenceError: enabled is not defined
}

let coffeAmazon = new CoffeMachine(1000);
```

Right case:

```javascript
let Machine = function() {
  this._enabled = false;
  
  this.enable = function() {
    enabled = true;
    console.log(enabled);
  };
  
  this.disable = function() {
    enabled = false;
    console.log(enabled);
  };
}

let CoffeMachine = function(powerAmount){
  Machine.call(this);
  
  this.enable(); //-> true
  
  console.log(this._enabled); 
}

let coffeAmazon = new CoffeMachine(1000); //-> false
```

**Transferring A Property To Protected**

```javascript
let Machine = function(power) {
  this._power = power;
  this._enabled = false;
  
  this.enable = function() {
    enabled = true;
    console.log(enabled);
  };
  
  this.disable = function() {
    enabled = false;
    console.log(enabled);
  };
}

let CoffeMachine = function(power){
  Machine.apply(this, arguments);
  
  this.enable(); //-> true
  
  console.log(this._enabled); 
  console.log(this._power); 
}

let coffeAmazon = new CoffeMachine(1000); //-> false, 1000
```

**Overriding Methods**

```javascript
let Machine = function(power) {
  this._enabled = false;
  let self = this;
  
  this.enable = function() {
    self._enabled = true;
    console.log(self._enabled);
  };
  
  this.disable = function() {
    self._enabled = false;
    console.log(self._enabled);
  };
}

let CoffeMachine = function(power){
  Machine.apply(this, arguments);
  
  let waterAmount = 0;
  
  this.setWaterAmount = function(amount) {
    waterAmount = amount;
  }
	
  let parentEnable = this.enable; 
  this.enable = function() {
    parentEnable();
    this.run();
  }
  
  function onReady() {
    console.log("Machine Ready");
  }
  
  this.run = function() {
    setTimeout(onReady, 1000);
  };
}

let coffeAmazon = new CoffeMachine(1000); //-> true
coffeAmazon.setWaterAmount(50);
coffeAmazon.enable();
```

## OOP Prototype Style

### Object Prototype

Objects in JavaScript can be organized into chains, mean that a property not found in one object is automatically looked up in another. The connecting link is a special property called `__proto__` .

**Proto proto**

If one object has a special reference `__proto__` to another object, then when reading a property from it, if the property is not in the object itself, it is searched in the `__proto__` object.

```javascript
var animal = {
  eats: true
};

var rabbit = {
  jumps: true
};

rabbit.__proto__ = animal;

console.log(rabbit.jumps); //-> true
console.log(rabbit.eats);  //-> true
```

The object pointed to by the `__proto__` is called a **prototype**.  In this case, it turned out that the animal is a prototype for rabbit. It is also said that the rabbit object "prototype inherits" from the animal.

