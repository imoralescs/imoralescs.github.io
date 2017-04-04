# Javascript Design Patterns

A pattern is a reusable solution that can be applied to commonly occurring problems in software design, in our case, in writing JavaScript web applications. Another way of looking at patterns are as templates for how we solve problems, ones which can be used in quite a few different situations.

So, why is it important to understand patterns and be familiar with them? Design patterns have three main benefits:

* **Patterns are proven solutions:** They provide solid approaches to solving issues in software development using proven techniques that reflect the experience and insights the developers that helped define them bring to the pattern.
* **Patterns can be easily reused:** A pattern usually reflects an out of the box solution that can be adapted to suit our own needs. This feature makes them quite robust.
* **Patterns can be expressive:** When we look at a pattern there’s generally a set structure and vocabulary to the solution presented that can help express rather large solutions quite elegantly.

## Constructor Pattern

In classical object-oriented programming languages, a constructor is a special method used to initialize a newly created object once memory has been allocated for it. Object constructors are used to create specific types of objects, both preparing the object for use and accepting arguments which a constructor can use to set the values of member properties and methods when the object is first created.

### Object Creation / Creating a New Object

```javascript
var obj = {};
var nextObj = Object.create(Object.prototype);
var lastObj = new Object();
```

### Assigning Keys and Values

There are then four ways in which keys and values can then be assigned to an object.

**Dot Syntax**

```javascript
// Set properties
obj.someKey = "Hello Worlds";

// Get properties
var key = obj.someKey;
console.log(key); //-> Hello Worlds
```

**Square Bracket**

```javascript
// Set properties
nextObj["someKey"] = "Hello Worlds"; 

// Get properties
var key = nextObj["someKey"];
console.log(key); //-> Hello Worlds
```

**Object.defineProperty**

```javascript
// Set properties
Object.defineProperty(lastObj, "someKey",{
	value: "for more control of the property behavior",
	writable: true,
	enumerable: true,
	configurable: true
});

var key = lastObj.someKey;
console.log(key); //-> for more control of the property behavior

// If above code feels difficult to read.
var defineProp = function(obj, key, value){
	this.config = {};
	this.config.value = value;
	Object.defineProperty(obj, key, this.config);
};

var person = Object.create(Object.prototype);

// Populate the object with properties
defineProp(person, "car", "Toyota");
defineProp(person, "dateOfBirth", "1981");

console.log(person.car); //-> Toyota
console.log(person.dateOfBirth); //-> 1981
```

**Object.defineProperties**

```javascript
// Set properties
var lastNextObj = {};
Object.defineProperties( lastNextObj, {
	"someKey": {
		value: "Hello Worlds",
		writable: true
	},
	"anotherKey":{
		value: "Foo Bar",
		writable: false
	}
});

console.log(lastNextObj.someKey); //-> Hello Worlds
console.log(lastNextObj.anotherKey); //-> Foo Bar
```

### Basic Constructors

```javascript
function Car(model, year, miles){
  this._model = model;
	this._year = year;
	this._miles = miles;
	
	this.toString = function(){
		return this._model + " has done " + this._miles + " miles";
	};
}

var civic = new Car("Honda Civic", 2009, 20000);
console.log(civic.toString()); //-> Honda Civic has done 20000 miles
```

### Constructors with prototypes

Functions in JavaScript have a property called a prototype. When we call a JavaScript constructor to create an object, all the properties of the constructor's prototype are then made available to the new object.

```javascript
function Car(model, year, miles){
  this._model = model;
	this._year = year;
	this._miles = miles;
}

Car.prototype.toString = function(){
	return this._model + " has done " + this._miles + " miles";
}

var civic = new Car("Honda Civic", 2009, 20000);
console.log(civic.toString()); //-> Honda Civic has done 20000 miles
```

## Module Pattern

The Module pattern was originally defined as a way to provide both private and public encapsulation for classes in conventional software engineering.

In JavaScript, the Module pattern is used to further emulate the concept of classes in such a way that we're able to include both public/private methods and variables inside a single object, thus shielding particular parts from the global scope. 

The module pattern is, by far, the most commonly used design pattern and widely accepted in a number of large projects such as jQuery, Dojo, ExtJS and YUI.

In JavaScript, there are several options for implementing modules. These include:

* The Module pattern
* Object literal notation
* AMD modules
* CommonJS modules
* ECMAScript Harmony modules

**Advantages**
* Cleaner approach for developers
* Supports private data
* Less clutter in the global namespace
* Localization of functions and variables through closures

**Disadvantages**
* Private methods are unaccessible.
* Some people say that this leads to the inability of unit testing but more often than not, if you're questioning the integrity of a function, it should probably be engineered in such a fashion that exposes the utility of that function publicly, thus making it testable. Given the adaptation of the module pattern by jQuery and their everyday use of QUnit to automate testing, this bullet point isn't really relevant but still listed for documentation purposes.
* Private methods and functions lose extendability since they are unaccessible (see my comment in the previous bullet point).

### Module using Object Literal

```javascript
var myObjectLiteral = {
	myProperty: "someValue",
	myConfig: {
		useCache: true,
		language: "en"
	},
	// Basic method
	myMethod_01: function(){
		console.log("My method 1");
	},
	// Output a value based on the current configuration
	myMethod_02: function(){
		console.log("Caching is:" + (this.myConfig.useCache) ? "enabled" : "disabled");
	},
	myMethod_03: function(newConfig){
		if(typeof newConfig === "object"){
			this.myConfig = newConfig;
			console.log(this.myConfig.language);
		}
	}
};

var myModule = myObjectLiteral;
myModule.myMethod_01(); //-> My method 1
myModule.myMethod_02(); //-> enabled
myModule.myMethod_03({language: "fr", useCache: false}); //-> fr
```

### Module using IIFE

**Example 1**

```javascript
(function(window,undefined) {
  function MyModule() {
    
    // `this` refers to the instance of `MyModule` when created
    this.myMethod = function myMethod() {
      console.log('My method');
    };
    
    // Note that we still use a function declaration even when using a function expression.
    this.myOtherMethod = function myOtherMethod() {
      console.log('My other method');
    };
  }
  
  // Expose access to the constructor
  window.MyModule = MyModule;
})(window);

var myModule = new MyModule();
myModule.myMethod(); //-> my method
myModule.myOtherMethod(); //-> my other method
```

**Example 2**

```javascript
var MyModule = (function(window,undefined) {

  // This object is used to store private variables and methods across multiple instantiations
  var privates = {};
	
  function MyModule() {
    
    this.myMethod = function myMethod() {
      console.log('My method');
    };

    this.myOtherMethod = function myOtherMethod() {
      console.log('My other method');
    };
  }

  return MyModule;
})(window);

var myMod = new MyModule();
myMod.myMethod(); // alerts "my method"
myMod.myOtherMethod(); // alerts "my other method"

var shoppingCartModule = (function(window, undefined){
	// Privates
	let basket = [];
	
	function doSomethingPrivate(x){
		return basket[x];
	}
	
	return {
		// Add items to our basket
		addItem: function(values){
			basket.push(values);
		},
		// Get the count of items in the basket
		getItemCount: function(){
			return basket.length;
		},
		getItem: function(arrayId) {
			return doSomethingPrivate(arrayId);
		},
		// Get the total value of items in the basket
		getTotal: function(){
			let q = this.getItemCount(),
          p = 0;
      while (q--) {
        p += basket[q].price;
      }
      return p;
		}
	}
}(window));

shoppingCartModule.addItem({item: "bread", price: 1.00});
shoppingCartModule.addItem({item: "milk", price: 1.25});
shoppingCartModule.addItem({item: "ham", price: 2.00});

console.log(shoppingCartModule.getTotal()); //-> 4.25
console.log(shoppingCartModule.getItem(1)); //-> Object {item: "milk", price: 1.25}
console.log(shoppingCartModule.basket); //-> undefined
```

## Revealing Module Pattern

This pattern is the same concept as the module pattern in that it focuses on public & private methods. The only difference is that the revealing module pattern was engineered as a way to ensure that all methods and variables are kept private until they are explicitly exposed; usually through an object literal returned by the closure from which it's defined. Personally, I like this approach for vanilla JavaScript as it puts a clear emphasis on both the intent of the developer and the module itself.

**Advantages**
* Cleaner approach for developers
* Supports private data
* Less clutter in the global namespace
* Localization of functions and variables through closures
* The syntax of our scripts are even more consistent
* Explicitly defined public methods and variables which lead to increased readability

**Disadvantages**
* Private methods are unaccessible. 
* Some people say that this leads to the inability of unit testing but more often than not, if you're questioning the integrity of a function, it should probably be engineered in such a fashion that exposes the utility of that function publicly, thus making it testable. Given the adaptation of the module pattern by jQuery and their everyday use of QUnit to automate testing, this bullet point isn't really relevant but still listed for documentation purposes.
* Private methods and functions lose extendability since they are unaccessible (see my comment in the previous bullet point).
* It's harder to patch public methods and variables that are referred to by something private.

```javascript
var myRevealingModule = function(window, undefined){
	let private_var = "Ben Cherry",
	    public_var = "Hey there!";
	
	function privateFunction(){
		console.log("Name: " + private_var);
	}
	
	function publicSetName(strName){
		private_var = strName;
	}
	
	function publicGetName(){
		privateFunction();
	}
	
	// Reveal
	return {
		setName: publicSetName,
		getName: publicGetName,
		greeting: public_var
	};
}(window);

myRevealingModule.getName(); //-> Name: Ben Cherry
myRevealingModule.setName("Paul Kinlan");
myRevealingModule.getName(); //-> Name: Paul Kinlan
console.log(myRevealingModule.greeting); //-> Hey there!
```

## Singleton Pattern

The Singleton pattern is thus known because it restricts instantiation of a class to a single object. Singletons differ from static classes (or objects) as we can delay their initialization, generally because they require some information that may not be available during initialization time. This isn't too common amongst JavaScript projects today but more common in WordPress

**Advantages**
* Reduced memory footprint
* Single point of access
* Delayed initialization that prevents instantiation until required

**Disadvantages**
* Once instantiated, they're hardly ever "reset"
* Harder to unit test and sometimes introduces hidden dependencies

```javascript
var mySingleton = ( function( window, undefined ) {
	let instance = null;
  
  // Revealing module pattern that handles initialization of our new module
  function initializeNewModule() {
    function myMethod() {
      console.log('My method');
    }
    function myOtherMethod() {
      console.log('My other method');
    }
    return {
      someMethod : myMethod,
      someOtherMethod : myOtherMethod
    };
  }
	
  // Handles the prevention of additional instantiations
  function getInstance() {
    if(!instance) {
      instance = new initializeNewModule();
    }
    return instance;
  }
  
  return {
    getInstance : getInstance
  };
})(window);

mySingleton.getInstance().someMethod(); //-> My method
mySingleton.getInstance().someOtherMethod(); //-> My other method
```

## Observer Pattern

This pattern implements a single object (the subject) that maintains a reference to a collection of objects (known as "observers") and broadcasts notifications when a change to state occurs. When we don't want to observe an object, we simply remove it from the collection of objects being observed. The observer pattern is similar to both the pub/sub implementation and the mediator pattern but still different in purpose & theory and worth mentioning.

**Advantages**
* Requires deeper-level thinking of the relationship between the various components of an application
* Helps us pinpoint dependencies
* Excellent at decoupling objects which often promotes smaller, reusable components

**Disadvantages**
* Checking the integrity of your application can become difficult
* Switching a subscriber from one publisher to another can be costly

Subject object becomes a base class from which we build an example stock tracking application.

```javascript
var Subject = (function(window, undefined) {

	function Subject() {
		this._list = [];
  }

  // This method will handle adding observers to the internal list
  Subject.prototype.observe = function observeObject(obj) {
    console.log('added new observer');
    this._list.push( obj );
  };
  
  Subject.prototype.unobserve = function unobserveObject(obj) {
    for(let i = 0, len = this._list.length; i < len; i++) {
      if(this._list[ i ] === obj) {
        this._list.splice(i, 1);
        console.log('removed existing observer');
        return true;
      }
    }
    return false;
  };
  
  Subject.prototype.notify = function notifyObservers() {
    var args = Array.prototype.slice.call(arguments, 0);
    for(var i = 0, len = this._list.length; i < len; i++) {
      this._list[ i ].update.apply(null, args);
    }
  };

  return Subject;

})(window);

// Setup an object that fetchs stocks
function StockGrabber() {
  var subject = new Subject();
	
  this.addObserver = function addObserver(newObserver) {
    subject.observe(newObserver);
  };
  
  this.removeObserver = function removeObserver(deleteObserver) {
    subject.unobserve(deleteObserver);
  };
  
  this.fetchStocks = function fetchStocks() {
    // fake fetching the stocks
    var stocks = {
      aapl : 167.00,
      goog : 243.67,
      msft : 99.34
    };
    
    // notify our observers of the stock change
    subject.notify(stocks);
  };
}

// define a couple of different observers
var StockUpdaterComponent = {
  update : function() {
    console.log('"update" called on StockUpdater with: ', arguments);
  }
};
var StockChartsComponent = {
  update : function() {
    console.log('"update" called on StockCharts with: ', arguments);
  }
};

var stockApp = new StockGrabber();
stockApp.addObserver(StockUpdaterComponent);
stockApp.fetchStocks(); //-> "update" called on StockUpdater with...
stockApp.addObserver(StockChartsComponent);
stockApp.fetchStocks(); //-> "update" called on StockUpdater with... "update" called on StockCarts with...
stockApp.removeObserver(StockUpdaterComponent);
stockApp.fetchStocks(); //-> "update" called on StockCharts with...
stockApp.removeObserver(StockChartsComponent);
stockApp.fetchStocks(); //-> does nothing; no observers
```

You can see that the StockGrabber object uses the Subject object internally to handle notifications to other components of the application such as the StockUpdaterComponent and the StockChartsComponent.

## Mediator Pattern

The mediator pattern usually implements a single object that becomes a shared resource through all of the different pieces of an application. It's a higher-level version of pub/sub in that it's commonly used to communicate across the different features of an application in contrast to being used within one feature to communicate with all of the individual pieces of that same feature.

Provides central authority over a group of objects by encapsulating how these objects interact. This model is useful for scenarios where there is a need to manage complex conditions in which every object is aware of any state change in any other object in the group. 

**Advantages**
* Reduces the communication relationship from "many-to-many" to "many-to-one"
* Helps us pinpoint dependencies
* Excellent at decoupling objects which often promotes smaller, reusable components

**Disadvantages**
* Introduces a single point of failure
* When modules communicate back and forth using a mediator pattern, it tends to become cumbersome and usually results in a clear performance hit. It's best when the mediator is only used to coordinate actions across multiple features and not for communication within the individual features themselves; keep the airways clean!

```javascript
var Mediator = (function(window, undefined) {
  function Mediator() {
    this._topics = {};
  }

  Mediator.prototype.subscribe = function mediatorSubscribe(topic, callback) {
    if (!this._topics.hasOwnProperty(topic)) {
      this._topics[topic] = [];
    }

    this._topics[topic].push(callback);
    return true;
  };

  Mediator.prototype.unsubscribe = function mediatorUnsubscrive(topic, callback) {
    if (!this._topics.hasOwnProperty(topic)) {
      return false;
    }

    for (let i = 0, len = this._topics[topic].length; i < len; i++) {
      if (this._topics[topic][i] === callback) {
        this._topics[topic].splice(i, 1);
        return true;
      }
    }

    return false;
  };

  Mediator.prototype.publish = function mediatorPublish() {
    var args = Array.prototype.slice.call(arguments);
    var topic = args.shift();

    if (!this._topics.hasOwnProperty(topic)) {
      return false;
    }

    for (let i = 0, len = this._topics[topic].length; i < len; i++) {
      this._topics[topic][i].apply(undefined, args);
    }
    return true;
  };

  return Mediator;

})(window);

var Subscriber = function ExampleSubscriber(myVariable) {
  console.log(myVariable);
};

var myMediator = new Mediator();
myMediator.subscribe('some event', Subscriber);
myMediator.publish('some event', 'foo bar'); //-> foo bar
```

Example of colleagues interface data between Mediator.

```javascript
var Participant = function(name) {
  this.name = name;
  this.chatroom = null;
};

Participant.prototype = {
  send: function(message, to) {
    this.chatroom.send(message, this, to);
  },
  receive: function(message, from) {
    console.log(from.name + " to " + this.name + ": " + message);
  }
};

// Mediator is the chatrooms
var Chatroom = function() {
  var participants = {};

  return {
    register: function(participant) {
      participants[participant.name] = participant;
      participant.chatroom = this;
    },
    send: function(message, from, to) {
      if (to) {
        // Single message
        to.receive(message, from);
      } else {
        // Broadcast message
        for (key in participants) {
          if (participants[key] !== from) {
            participants[key].receive(message, from);
          }
        }
      }
    }
  };
};

var yoko = new Participant("Yoko");
var john = new Participant("John");
var paul = new Participant("Paul");
var ringo = new Participant("Ringo");

var chatroom = new Chatroom();

chatroom.register(yoko);
chatroom.register(john);
chatroom.register(paul);
chatroom.register(ringo);

yoko.send("All you need is love.");
yoko.send("I love you John.");
john.send("Hey, no need to broadcast", yoko);
paul.send("Ha, I heard that!");
ringo.send("Paul, what do you think?", paul);
```

## Prototype Pattern

The prototype pattern focuses on creating an object that can be used as a blueprint for other objects through prototypal inheritance. This pattern is inherently easy to work with in JavaScript because of the native support for prototypal inheritance in JS which means we don't need to spend time or effort imitating this topology.

**Advantages**
* New objects created from the "skeleton" of an existing object inherit references to existing functions on the prototype chain, thus boosting performance and keeping memory footprints to a minimum.
* Great for an application where the focus is on object creation

**Disadvantages**
* Overkill for a project that uses very few objects and/or does not have an underlying emphasis on the extension of prototype chains

```javascript
var myBluePrint = function myBluePrintObject() {
  this.someFunction = function someFunction() {
    console.log('Some function');
  };

  this.someOtherFunction = function someOtherFunction() {
    console.log('Some other function');
  };

  this.showMyName = function showMyName() {
    console.log(this.name);
  };

};

function myObject() {
  this.name = 'Testing';
}

myObject.prototype = new myBluePrint();

var testObject = new myObject();
testObject.someFunction(); //-> Some function
testObject.someOtherFunction(); //-> Some other function
testObject.showMyName(); //-> Testing
```

## Facade Pattern

The purpose of the facade pattern is to conceal the underlying complexity of the code by using an anonymous function as an extra layer. Internal subroutines are never exposed but rather invoked through a facade which makes this pattern secure in that it never exposes anything to the developers working with it. The facade pattern is both extremely interesting and very useful for adding an extra layer of security to your already minified code. This pattern is extremely useful when coupled with the revealing module pattern.

**Advantages**
* Enhances security for your web application
* Works well in combination with other patterns
* Easy to implement
* Makes it easy to patch internals
* Provides a simpler public interface
* Proven useful for other major libraries such as jQuery

**Disadvantages**
* There aren't any real drawbacks as it provides a unified interface to a set of interfaces in a subsystem. As a result, you aren't forced to make any unwanted compromises, thus a win-win. One possible note worth mentioning is that a developer must decide whether the implicit cost of implementation is really worth the abstraction (though this is generally a small footprint).

```javascript
var module = (function() {

  // All kinds of function
  var _private = {
    processString: function(string) {
      return string.substring(0, string.length / 2);
    },
    processNumber: function(number) {
      return number * number;
    },
    processBoolean: function(bool) {
      return !bool;
    },
    processArray: function(array) {
      return array.length;
    },
    processObject: function(object) {
      return Object.keys(object).length;
    }
  };

  // Facade implement
  return {
    processThing: function(thing) {
      switch (Object.prototype.toString.call(thing)) {
        case '[object String]':
          return _private.processString(thing);
        case '[object Number]':
          return _private.processNumber(thing);
        case '[object Boolean]':
          return _private.processBoolean(thing);
        case '[object Array]':
          return _private.processArray(thing);
        case '[object Object]':
          return _private.processObject(thing);
        default:
          return 'Unable to process the thing';
      }
    }
  };
}());

console.log(module.processThing('test string')); //-> test
console.log(module.processThing(5)); //-> 25
console.log(module.processThing(true)); //-> false
console.log(module.processThing([1, 2, 3])); //-> 3
console.log(module.processThing({foo: 'faa', poop: 'poop'})); //-> 2
```

## Factory Pattern

This pattern focuses on object creation but differs from other patterns in the creation category in that it does not require a constructor function. The factory pattern generally supplies an interface for developers to create new objects through the use of the factory rather than invoking the new operator on an object. Imagine that you needed a car door so you might goto a car factory that produces the product you're interested in and ask it to give you what you need. The factory then supervises the creation of the new car door (or object) and gives it to you. This example paints a good picture for how the factory pattern works; you simply ask it for a type of component, it instantiates the component (given it exists), and returns you what you were looking for.

**Advantages**
* Makes complex object creation easy through an interface that can bootstrap this process for you
* Great for generating different objects based on the environment
* Practical for components that require similar instantiation or methods
* Great for decoupling components by bootstrapping the instantiation of a different object to carry out work for particular instances

**Disadvantages**
* Unit testing can be difficult as a direct result of the object creation process being hidden by the factory methods

**Example 1**

```javascript
function CarDoor(options) {
  this.color = options.color || 'red';
  this.side = options.side || 'right';
  this.hasPowerWindows = options.hasPowerWindows || true;
}

function CarSeat(options) {
  this.color = options.color || 'gray';
  this.material = options.material || 'leather';
  this.isReclinable = options.isReclinable || true;
}

function CarPartFactory() {};

CarPartFactory.prototype.createPart = function createCarPart(options) {
  var parentClass = null;
  
  if(options.partType === 'door') {
    parentClass = CarDoor;
  } 
	else if(options.partType === 'seat') {
    parentClass = CarSeat;
  }
  
  if(parentClass === null) {
    return false;
  }
  
  return new parentClass(options);
}

var myPartFactory = new CarPartFactory();
var seat = myPartFactory.createPart({
  partType : 'seat',
  material : 'leather',
  color : 'blue',
  isReclinable : false
});

console.log(seat instanceof CarSeat); //-> true
console.log( seat ); //-> CarSeat {color: "blue", material: "leather", isReclinable: true}
```

**Example 2**

```javascript
// Create my video  and image object
var Video = function(attributes) {
  this.length = attributes.length || 0;
  this.name = attributes.name || '';
};

var Image = function(attributes) {
  this.width = attributes.width || 0;
  this.height = attributes.height || 0;
  this.name = attributes.name || '';
};

// Creating mediaFactory.

var Media = function() {};

// Adding as default object.
Media.prototype.mediaClass = Image;

Media.prototype.createMedia = function(type) {
  switch (type.mediaType) {
    case 'Image':
      this.mediaClass = Image;
      break;
    case 'Video':
      this.mediaClass = Video;
      break;
  }

  return new this.mediaClass(type);
};

var mediaFactory = new Media();

var media_object_1 = mediaFactory.createMedia({
  mediaType: 'Video',
  length: 100,
  name: 'My Video'
});

var media_object_2 = mediaFactory.createMedia({
  mediaType: 'Image',
  width: 10,
  height: 10,
  name: 'My Image'
});

console.log(media_object_1 instanceof Video); //-> true

console.log(media_object_1); //-> Video {length: 100, name: "My Video"}
console.log(media_object_2); //-> Image {width: 10, height: 10, name: "My Image"}
```

## Mixin Pattern

In traditional programming languages such as C++ and Lisp, Mixins are classes which offer functionality that can be easily inherited by a sub-class or group of sub-classes for the purpose of function re-use.


## Decorator Pattern

Decorators are a structural design pattern that aim to promote code re-use. Similar to Mixins, they can be considered another viable alternative to object sub-classing.

Classically, Decorators offered the ability to add behaviour to existing classes in a system dynamically. The idea was that the decoration itself wasn't essential to the base functionality of the class, otherwise it would be baked into the superclass itself.


**Decorating Constructors With New Functionality**

```javascript
// Vehicle Constructor
function Vehicle(vehicleType) {
  // Default
  this.vehicleType = vehicleType || "car";
  this.model = "default";
  this.license = "00000-000";
}

let compactCar = new Vehicle("car");
console.log(compactCar); //-> Vehicle {vehicleType: "car", model: "default", license: "00000-000"}

let truckCar = new Vehicle("truck");

// New functionality we are decorating Vehicle with
truckCar.setModel = function(modelName) {
  this.model = modelName;
};

truckCar.setColor = function(color) {
  this.color = color;
};

truckCar.setModel("Toyota");
truckCar.setColor("blue");
console.log(truckCar); //-> Vehicle {vehicleType: "truck", model: "Toyota", license: "00000-000", color: "blue"}

// Main Vehicle is still unaltered
let motorCar = new Vehicle("motor");
console.log(motorCar); //-> Vehicle {vehicleType: "motor", model: "default", license: "00000-000"}
```

**Decorating Objects With Multiple Decorators**

```javascript
function MacBook() {
  this.cost = function() {
    return 997;
  };
  this.screenSize = function() {
    return 11.6;
  };
}

// Decorator 1
function Memory(macbook) {
  let c = macbook.cost();
  macbook.cost = function() {
    return c + 75;
  };
}

// Decorator 2
function Engraving(macbook) {
  let c = macbook.cost();
  macbook.cost = function() {
    return c + 200;
  };
}

// Decorator 3
function Insurance(macbook) {
  let c = macbook.cost();
  macbook.cost = function() {
    return c + 250;
  };
}

let mac_pro = new MacBook();
console.log(`$${mac_pro.cost()}`); //-> $997

Memory(mac_pro);
Engraving(mac_pro);
Insurance(mac_pro);

console.log(`$${mac_pro.cost()}`); //-> $1522
console.log(mac_pro.screenSize()); //-> 11.6
```

## Others Pattern

### Proxy Pattern

Provide a surrogate or placeholder for another object to control access to it.

```javascript
var Location = function() {
  this.coordinate = function(position) {

    var coords;

    switch (position) {
      case 'Right':
      case 'right':
        coords = "x=10, y=0";
        break;
      case 'Left':
        coords = "x=-10, y=0";
        break;
      case 'Top':
        coords = "x=0, y=10";
        break;
      case 'Botton':
        coords = "x0, y=-10";
        break;
      default:
        break;
    }

    return coords;
  };
};

var LocationProxy = function() {
  var location = new Location();
  var locationCache = {};

  return {
    coordinate: function(position) {
      if (!locationCache[position]) {
        locationCache[position] = location.coordinate(position);
      }
      return locationCache[position];
    }
  };
};


var loc = new LocationProxy();

console.log(loc.coordinate('Top')); //-> x=0, y=10
console.log(loc.coordinate('Left')); //-> x=-10, y=0
console.log(loc.coordinate('right')); //-> x=10, y=0
```

### Composite Pattern

Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly. 

```javascript
var Node = function(name) {
  this.name = name;
  this.children = [];
  this.parent = null;
};

Node.prototype.addChild = function(child) {
  this.children.push(child);
  child.parent = this;
};

Node.prototype.traverseUp = function() {
  if (this.parent) {
    console.log(this.name + ' is the child of ' + this.parent.name);
    this.parent.traverseUp();
  } else {
    console.log(this.name + ' is the root node');
  }
};

Node.prototype.traverseDown = function() {
  if (this.children.length) {
    this.children.forEach(function(child) {
      console.log(this.name + ' is the parent of ' + child.name);
      child.traverseDown();
    }, this);
  } else {
    console.log(this.name + ' is a leaf node');
  }
};



var root = new Node('Fred'),
  child1 = new Node('John'),
  child2 = new Node('Jane'),
  child3 = new Node('Jack'),
  child4 = new Node('Jill'),
  child5 = new Node('James'),
  child6 = new Node('Jess');

root.addChild(child1);
root.addChild(child2);

child2.addChild(child3);
child2.addChild(child4);

child4.addChild(child5);

child5.addChild(child6);

root.traverseDown();
```

### Adapter Pattern

Adapters basically allow objects or classes to function together which normally couldn't due to their incompatible interfaces. The adapter translates calls to its interface into calls to the original interface and the code required to achieve this is usually quite minimal. 

```javascript
// Old Interface
function Shipping() {
  this.request = function(zipStart, zipEnd, weight) {
    return "$49.75";
  }
}

// New Interface
function AdvancedShipping() {
  this.login = function(credentials) { /* ... */ };
  this.setStart = function(start) { /* ... */ };
  this.setDestination = function(destination) { /* ... */ };
  this.calculate = function(weight) {
    return "$39.50";
  };
}

// Adapter Interface
function ShippingAdapter(credentials) {
  var shipping = new AdvancedShipping();

  shipping.login(credentials);

  return {
    request: function(zipStart, zipEnd, weight) {
      shipping.setStart(zipStart);
      shipping.setDestination(zipEnd);
      return shipping.calculate(weight);
    }
  };
}

var shipping = new Shipping();
var credentials = {
  token: "30a8-6ee1"
};
var adapter = new ShippingAdapter(credentials);

// original shipping object and interface
var cost = shipping.request("78701", "10010", "2 lbs");
console.log("Old cost: " + cost); //-> Old cost: $49.75

// new shipping object with adapted interface
cost = adapter.request("78701", "10010", "2 lbs");
console.log("New cost: " + cost); //-> New cost: $39.50
```

### Iterator Pattern

```javascript
var createIterator = function(collection) {
  var index = 0;
  return {
    next: function() {
      if (index < collection.length) {
        var value = collection[index++];
        return value;
      } 
			else {
        var done = "Iterator done..!!";
        return done;
      }
    }
  };
}

var arr = [1, 2, 3, 4, 5];

var collection = createIterator(arr); //-> Get the iterator

console.log(collection.next()); //-> 1
console.log(collection.next()); //-> 2
console.log(collection.next()); //-> 3
console.log(collection.next()); //-> 4
console.log(collection.next()); //-> 5
console.log(collection.next()); //-> Iterator done..!!
console.log(collection.next()); //-> Iterator done..!!
```

### Chain Of Responsibility Pattern

Chain Of Responsibility have three parts, sender, receiver, and request. The sender makes the request. The receiver is a chain of 1 or more objects that choose whether to handle the request or pass it on. The request itself can be an object that encapsulates all the appropriate data.

```javascript
var Request = function(amount) {
  this.amount = amount;
  console.log("Request " + amount);
};

Request.prototype = {
  get: function(bill) {
    var count = Math.floor(this.amount / bill);
    this.amount -= count * bill;
    console.log("Dispense " + count + " $" + bill + " bills");
    return this;
  }
};

var request = new Request(378);

request.get(100).get(50).get(20).get(10).get(5).get(1);
//->
/*
Request 378
Dispense 3 $100 bills
Dispense 1 $50 bills
Dispense 1 $20 bills
Dispense 0 $10 bills
Dispense 1 $5 bills
Dispense 3 $1 bills
*/
```

### Strategy Pattern

Its primary purpose is to help you separate the parts of an object which are subject to change from the rest of the static bits.

```javascript
var Shipping = function() {
  this.company = "";
};

Shipping.prototype = {
  setStrategy: function(company) {
    this.company = company;
  },
  calculate: function(package) {
    return this.company.calculate(package);
  }
};

var UPS = function() {
  this.calculate = function(package) {
    // Calculations
    return "$45.95";
  }
};

var USPS = function() {
  this.calculate = function(package) {
    // Calculations
    return "$39.40";
  }
};

var Fedex = function() {
  this.calculate = function(package) {
    // Calculations
    return "$43.20";
  }
};

var package = {
  from: "76712",
  to: "10012",
  weigth: "lkg"
};

// The 3 strategies
var ups = new UPS();
var usps = new USPS();
var fedex = new Fedex();

var shipping = new Shipping();

shipping.setStrategy(fedex);
console.log(shipping.calculate(package)); //-> $43.20
```

## Resources
* http://bdcampbell.net/javascript/JavaScriptDesignPatterns.html
