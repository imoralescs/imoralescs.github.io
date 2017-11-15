# React

React is a Javascript library for creating user interfaces, authored by Facebook and Instagram engineers. It’s aimed to solve the challenges involved when developing complex user interfaces with datasets that change over time.

### React is all about components

Components are the core of React and the view to your application. They are encapsulated and composable, you can mix and match them to build complex UIs favoring code reuse and separation of concerns.

React components are written in plain JavaScript, instead of template languages or the HTML directives traditionally used for web application UIs.

## Javascript

### Declaring Variables in ES6

* **`const`:** A constant is a variable that cannot be changed.
* **`let`:** In javascript we create code block with curly braces.

```
{
  let a = 42;
  {
    let b = 24;
    {
    }
  }
  //console.log(b);
  console.log(a);
}
```

`if` and `for` create code block scope, not function scope. Arrow function create new scope.

### Template Strings

Template strings provide us with an alternative to string concatenation. They also allow us to insert variables into a string.

```
console.log(`${lastName}, ${firstName} ${middleName}`);
```

### Default Parameters

Allow developers to declare default values for function arguments.

```
function logActivity(name="Shane McConkey", activity="skiing") {
  console.log(`${name} loves ${activity}`);
}

logActivity();

const defaultPerson = {
  name: {
    first: "Shane",
    last: "McConkey"
  },
  favActivity: "skiing"
};

function log_Activity(p=defaultPerson) {
  console.log(`${p.name.first} loves ${p.favActivity}`);
}

log_Activity();
```

### Arrow Functions

With arrow functions, you can create functions without using the function keyword. You also often do not have to use the return keyword.

### Transpiling ES6

Not all web browsers support ES6, and even those that do don’t support everything. The only way to be sure that your ES6 code will work is to convert it to ES5 code before running it in the browser. This process is called transpiling. 

### ES6 Objects and Arrays

* **Destructuring Assignment:** The destructuring assignment allows you to locally scope fields within an object and to declare which values will be used.
* **Object Literal Enhancement:** Object literal enhancement is the opposite of destructuring. It is the process of restruc turing or putting back together. With object literal enhancement, we can grab variables from the global scope and turn them into an object.
* **Spread Operator:** Spread operator is three dots (...) that perform several different tasks. First, the spread operator allows us to combine the contents of arrays. Can also be used to get some, or the rest, of the items in the array and we can also use the spread operator to collect function arguments as an array.

### Promises

Promises give us a way to make sense out of asynchronous behavior.

### Classes

### ES6 Modules

A JavaScript module is a piece of reusable code that can easily be incorporated into other JavaScript files. 

## Virtual DOM

HTML is simply a set of instructions that a browser follows when constructing the document object model, or DOM. The elements that make up an HTML document become DOM elements when the browser loads HTML and renders the user interface. In HTML, elements relate to each other in a hierarchy that resembles a family tree.

The DOM API is a collection of objects that JavaScript can use to interact with the browser to modify the DOM. If you have used `document.createElement` or `document.appendChild`, you have worked with the DOM API. Updating or changing rendered DOM elements in JavaScript is relatively easy. However, the process of inserting new elements is slow. This means if web developers are meticulous about how they make changes to UI, they can improve the performance of their applications.

With React, we do not interact with the DOM API directly. Instead, we interact with a virtual DOM, or set of instructions that React will use to construct the UI and interact with the browser. The virtual DOM is made up of React elements, which conceptually seem similar to HTML elements, but are actually JavaScript objects. It is much faster to work directly with JavaScript objects than it is to work with the DOM API. 

Example of the difference DOM API vs Virtual DOM:

```html
<div id="react"></div>
<div id="dom"></div>
```

```javascript
const renderWithReact = () => {
  ReactDOM.render(
    React.createElement('div', null, 'Render by react:', 
      React.createElement('button', null, 'Save'),
      React.createElement('span', null, new Date().toString()),
    ),
    document.getElementById('react'),
  );
};

// This case we removing the entire dom each moment on the interval.
const renderWithDOM = () => {
  const mountNode = document.getElementById('dom');
  mountNode.innerHTML = `
    <div>
      Render by DOM:
      <button>Save</button>
      <span>${new Date().toString()}</span>
    </div>
  `;
};

setInterval(() => {
  renderWithReact();
  renderWithDOM();
}, 1000);
```

## ReactElement

The browser DOM is made up of DOM elements. Similarly, the React DOM is made up of React elements. DOM elements and React elements may look the same, but they are actually quite different. A React element is a description of what the actual DOM element should look like. In other words, React elements are the instructions for how the browser DOM should be created.

We can create a React element to represent an h1 using `React.createElement` method:

```javascript
React.createElement("h1", null, "Baked Sweet Potato");
```

`React.createElement` takes in three arguments. The first is a tag name string (div, span, etc) or a custom component class as object, the second is data in form of javascript object with any attributes you want the element to have, the third is contents or the children of the element, in this case the text "Baked Sweet Potato".

Example of more element created by `React.createElement`:

```
const button = function(props) {
  return React.createElement('button');
};

const link = function(props) {
  return React.createElement('a',{href: 'https://facebook.com'},'Click me !');
};

const div = function(props) {
  return React.createElement('div');
};

const divComponent = function(props) {
  return React.createElement('div', null, 'This is div component');
};

const divComponentWithProps = function(props) {
  return React.createElement('div', null, 
    React.createElement('h2', 
      {
        style: {
	  color: props.color
	}
      },
      props.title));
};

const firstComponent = function() {
  return React.createElement('div',
    {
      id: 'first-component'
    },
    React.createElement(divComponentWithProps,{title: 'Game', color: 'yellowgreen'}),
    React.createElement(divComponentWithProps,{title: 'Stranger', color: 'greenyellow'}),
    React.createElement(divComponentWithProps,{title: 'Rick', color: 'limegreen'}),
    React.createElement(divComponentWithProps,{title: 'House', color: 'peru'})
  );
}

const books = [
  {id : 1, title: 'Book 1', price: 2900},
  {id : 7, title: 'Book 9', price: '3900'},
  {id : 99, title: 'Book 14', price: 4900},
  {id : 101, title: 'Book 66', price: 1900},
];

// Approach 1
const BookList = ({books}) => {
  return(
    React.createElement('ul',{}, 
      books.map(({id, title, price}) => {
        return React.createElement('li', {key: id}, `${title}, ${price}`);
      }
    )
  );
};

// Approach 2
const Book = ({id, title, price}) => {
  return React.createElement('li', {key: id}, `${title}, ${price}`);
}

Book.propTypes = {
  title: PropTypes.string.isRequired,
  price: PropTypes.number.isRequired
};

const BookList = ({books}) => {
  return(
    React.createElement('ul', {},
      books.map(book => {
        return <Book key={book.id} {...book} />
      })
    )
  );
};
```

* **`data-reactroot`:** Appear as an attribute of the root element of your React component. Prior to version 15, React IDs were added to each node that was a part of your component. This helped with rendering and keeping track of which elements needed to be updated. Now, there is only an attribute added to the root, and rendering is kept track of based on the hierarchy of elements.

## ReactDOM

`ReactDOM` contains the tools necessary to render React elements in the browser. ReactDOM is where we will find the render method as well as the `renderToString` and `renderToStaticMarkup` methods that are used on the server. 

```javascript
ReactDOM.render(ReactElement, DOMElement, callback);

ReactDOM.render(
  // We create element h1
  React.createElement('h1', null, 'Hello, Worlds!'), //<-- nextElement
  // Render it to the DOM node with ID "root"
  document.getElementById('root') //<-- container
);
```

### `render()`

All react component require at least a `render()` function. This function is expected to return a virtual DOM representation of the browser elements. To rendering our element require two thing:

1. The root of our virtual tree
2. The mount location where we want React write to the actual browser DOM

```javascript
let boldElement = React.createElement('b');
let mountElement = document.getElementById('root');
ReactDOM.render(boldElement, mountElement);
```

## JSX

JSX is an inline markup that looks like HTML and get transformed to Javascript. A JSX expression starts with an HTML-like open tag, and ends with the corresponding closing tag. JSX tags support the XML self close syntax so you can optionally leave the closing tag off.

### Creating Elements

```
ReactDOM.render( 
  React.createElement('h1', null, 'Hello Worlds'),
  mountNode
);
```

JSX method:

```
ReactDOM.render( 
  <h1>Hello Worlds</h1>,
  mountNode
);
```

### Creating JSX Components

Way to define component:

* **ES6 using `React.Component`**

`React.Component`, an abstract class that we can use to build new React components. We can create custom components through inheritance by extending this class with ES6 syntax. Component class name must start with a capital letter.

```javascript
class HelloWorld extends React.Component {
  render() {
    return(
      <h1>Hello Worlds!</h1>
    )
  }
}

ReactDOM.render(
  <HelloWorld />,
  document.getElementById('root')
);
```

* **ES5 using `createClass`**

```javascript
const HelloWorld = React.createClass({
  render: function() {
    return(
      <h1>Hello Worlds!</h1>
    )
  }
});

ReactDOM.render(
  <HelloWorld />,
  document.getElementById('root')
);
```

**Note:**  `createClass()` is deprecated. You’ll get warnings in the console if you’re using it in your code and, when React 16 comes out, `createClass()` will be removed entirely. To still used `createClass()` without ES6, you can used **'create-react-class'** library. Example of used:

```
var createReactClass = require('create-react-class');
var App = createReactClass({
  render: function() {
    return(
      <h1>Hello Worlds!</h1>
    )
  }
});

const mountNode = document.getElementById('root');
ReactDOM.render(
  <App />,
  mountNode
);
```

### Output Variables JSX

On the initial case we are using ES5 template string, for output variable.

```
class DateTimeNow extends React.Component {
  render() {
    let dateTimeNow = new Date().toLocaleString();
    return React.createElement(
      'span',
      null,
      `Current date and time is ${dateTimeNow}`);
    }
  }
}
```

In JSX, you can use curly braces `{}` notation to output variables dynamically.

```
class DateTimeNow extends React.Component {
  render() {
    let dateTimeNow = new Date().toLocaleString();
    return <span>Current date and time is { dateTimeNow }</span>
  }
}
```

### Properties In JSX

Element properties are defined using attribute syntax. That is, you use `key1=value1 key2=value2...` notation inside of the JSX tag to define both HTML attributes and React component properties. This is similar to attribute syntax in HTML/XML.

```
class ProfileLink extends React.Component {
  render() {
    return( 
      <a  href={this.props.url}
          title={this.props.label}
	  target='_blank'>Profile</a>
    )
  }
}

const mountNode = document.getElementById('root');
ReactDOM.render( 
  <ProfileLink url='/users/john' label='Profile for John' />,
  mountNode
);
```

### Creating Component Methods

```
class Content extends React.Component {
  getUrl() {
    return 'https://google.com';
  }
  
  render() {
    return( 
      <div>
        <p>Your REST API URL is: 
	  <a href={this.getUrl()}>
            {this.getUrl()}
          </a>
        </p>
      </div>
    );	
  }
}
```

### Conditional Statement

We have different way to implement this. First one If..Else by doing all js and assigning the JSX block to a variable.

```javascript
class HelloWorld extends React.Component {
  render() {
    let userMessage;
  
    if(this.props.loggedIn) {
      userMessage = (
        <span>
          <h2>{ `Welcome back ${this.props.name}` }</h2>      
          <p>You can visit setting to reset your password</p>
        </span>
      )
    }
    else {
      userMessage = (
        <h2>Hey! Sign in to see this section</h2>
      )
    }
    return (
      <div>
        {userMessage}
      </div>
    )
  }
}

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      name : "John Newton", 
      logged : true
    };
    this.changeLogging = this.changeLogging.bind(this);
  }
  
  changeLogging(event) {
    let name = this.state.name;
    this.setState({name : name, logged : false})
  }
  
  render() {
    return (
      <div>
	  <HelloWorld loggedIn={this.state.logged} name={this.state.name} />
        <button onClick={this.changeLogging}>Change Login Status To False</button>
	</div>
    )
  }
}
```

Second way is for keep the render function cleaned, separate the conditional in a different function that handler the If...Else statement.

```javascript
class HelloWorld extends React.Component {
  renderUserMessage() {
    if(this.props.loggedIn) {
      return(
        <span>
          <h2>{ `Welcome back ${this.props.name}` }</h2>      
          <p>You can visit setting to reset your password</p>
        </span>
      );
    }
    else {
      return(
        <h2>Hey! Sign in to see this section</h2>
      );
    }
  }
  
  render() {
    return (
      <div>
        {this.renderUserMessage()}
      </div>
    )
  }
}
```

Third is for smaller stuff, with the ternary operator inside the JSX block.

```javascript
class HelloWorld extends React.Component {  
  render() {
    return (
      <div>
        {
	  this.props.loggedIn 
	  ? 'You are logged In'
	  : 'You are not logged In'
	}
      </div>
    )
  }
}
```

### Output List

The easiest way to implement a list in React is to use array and `map()`. List are often used on webpage.

* **ES6**

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = { 
      users : [
        {name: "John", id: 120, age: 22, gender: "male"},
 	  {name: "Beth", id: 443, age: 24, gender: "female"},
 	  {name: "Jane", id: 510, age: 19, gender: "female"}
	]
    }
  }
	
  render() {
    return (
      <div>
	  <ul>
	    {this.state.users.map((user, index) => {
	      return <li key={user.id}>{user.name}</li>
	    })}
	  </ul>
	</div>
    )
  }
}
```

* **ES5**

```javascript
const App = React.createClass({
  getInitialState() {
    return {
      users : [
        {name: "John", id: 120, age: 22, gender: "male"},
 	  {name: "Beth", id: 443, age: 24, gender: "female"},
 	  {name: "Jane", id: 510, age: 19, gender: "female"}
	]
    }
  },
  render() {
    return (
      <div>
	  <ul>
	    {this.state.users.map((user, index) => {
	      return <li key={user.id}>{user.name}</li>
	    })}
	  </ul>
      </div>
    );
  }
});
```

## Variable 

On JSX we have two class of variable prop and state.

### Props

Data within a component can come from the outside. Props are immutable meaning they don't change. They are passed by parent components to their children components. You used to be able to change props with setProps and replaceProps but these have been deprecated. During a component’s life cycle props should not change (consider them immutable).

* **ES6**

```javascript
class ClickCounterButton extends React.Component {
  render() {
    return <button onClick={this.props.handler}>Dont click me {this.props.counter} times! </button>
  }
}

// Supplying Props
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {counter : 0};
    this.click = this.click.bind(this);
  }
  
  click(event) {
    this.setState({counter : ++this.state.counter})
  }
  
  render() {
    return (
      <div>
        <ClickCounterButton counter={this.state.counter} handler={this.click}/>
      </div>
    )
  }
}

ReactDOM.render(
  <App />,
  document.getElementById('root')
);
```

* **ES5**

```javascript
const ClickCounterButton = function(props) {
  return (
    <button onClick={props.handler}>Dont click me {props.counter} times! </button>
  )
};

const App = React.createClass({
  getInitialState() {
    return {counter : 0}
  },
  click(event) {
    this.setState({counter : ++this.state.counter})
  },
  render() {
    return (
      <div>
        <ClickCounterButton counter={this.state.counter} handler={this.click}/>
      </div>
    );
  }
});

ReactDOM.render(
  <App />,
  document.getElementById('root')
);
```

### State

They holds information about the component. By default component has no state. State are mutable properties of components meaning they can changes. When state change the corresponding view changes, but everything else in DOM remain intact. 

State is created in the component constructor method.

* **ES6**

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {name : "Hello Worlds"};
  }
    
  render() {
    return (
    	<h1>{this.state.name}</h1>
    )
  }
}
```

* **ES5**

```javascript
const App = React.createClass({
  getInitialState() {
    return {name : "Hello Worlds"}
  },
  render() {
    return (
      <h1>{this.state.name}</h1>
    );
  }
});
```

To update state, we using this.setState method.

* **ES6**

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {name : "Hello Worlds"};
    this.click = this.click.bind(this);
  }
  
  click(event) {
    this.setState({name : "Goodbye Worlds"});
  }
  
  render() {
    return (
      <div>
	  <button onClick={this.click}>Change State</button>
    	  <h1>{this.state.name}</h1>
	</div>
    )
  }
}
```

* **ES5**

```javascript
const App = React.createClass({
  getInitialState() {
    return {name : "Hello Worlds"}
  },
  click(event) {
    this.setState({name : "Goodbye Worlds"})
  },
  render() {
    return (
      <div>
	  <button onClick={this.click}>Change State</button>
    	  <h1>{this.state.name}</h1>
	</div>
    );
  }
});
```

## Events

The way of handling events in React components is much similar to DOM events processing in pure Javascript. Just define a response function and let it be the event handler and listen an event. React has event system which called Synthetic Events is cross-browser wrapper.

## Synthetic Event Handlers

Whenever you call an event handler within ReactJS, they are passed an instance of SyntheticEvent instead of the native event handler. This has the same interface as the native event handler's, except it's cross-browser compatible so you can use it
without worrying whether you need to make exceptions in your code for different browser implementations.

The events are triggered in a bubbling phase. This means that the event is first captured down to the deepest target and then propagated to outer elements. You can stop propagation by calling `event.stopPropagation()` or `event.preventDefault()` where appropriate.

### Declaring Events, Bind Method and onClick

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {counter : 0};
    this.clickCount = this.clickCount.bind(this);
  }
	
  clickCount(event) {
    this.setState({counter : ++this.state.counter})
  }
	
  render() {
    return (
      <div>
        <p>Count number: <span>{this.state.counter}</span></p>
	<button onClick={this.clickCount}>++ Count</button>
      </div>
    )
  }
}


ReactDOM.render(
  <App />,
  document.getElementById('root')
);
```

* **`onClick`:**  Attribute is added to the target element in order to specify the function to be executed when that element is clicked.

## Form

### Accessing User Input With Refs

```javascript
Refs mean is reference to specific node value.

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = { names : [] };
    this.onFormSubmit = this.onFormSubmit.bind(this);
  }
	
  onFormSubmit(evt) {
    evt.preventDefault();
    const name = this.refs.name.value;
    const names = [ ...this.state.names, name];
    this.setState({ names : names });
    this.refs.name.value = '';	
  }
	
  render() {
    return (
      <div>
	  <h1>Sign Up Sheet</h1>
	  <form onSubmit={this.onFormSubmit}>
	    <input
	      placeholder='Name'
		ref='name'/>
	    <input type='submit'/>
	  </form>
	  <div>
	    <h3>Names</h3>
	    <ul>
	      {this.state.names.map((name, i) => {
	        return <li key={i}>{name}</li>
	      })}
	    </ul>
	  </div>
      </div>
    )
  }
}

let mountElement = document.getElementById('root');
ReactDOM.render(<App/>, mountElement);
```

### Uncontrolled and Controlled Components

If we have a plain, normal HTML page, and we put a `<input id="myTextbox" type="text" />` to my page. We I start typing into the textbox the browser store the current value for that input.

```javascript
const button = document.getElementById("myButton");
button.onclick = function(event) {
  const input = document.getElementById("myTextbox");
  const currentText = input.value;
  console.log(currentText);
}
```

Later we can use the following javascript to get the value. So normal HTML input field effectively stores its own value at all times, and you can get the element when you ask for its value. This is what we refer to as an Uncontrolled input.  We write HTML form, We have a Submit button, when the button is clicked, We get each input and grab the value, put all the values in an object, and do something with that.

```javascript
class App extends React.Component {  
  constructor(props) {
    super(props);
    this.handleSubmit = this.handleSubmit.bind(this);
  }

  handleSubmit() {
    const input = this.refs.myTextbox;
    const value = input.value;
    console.log(value);
  }
  
  render() {  
    return (
      <div>
	  <input type="text" ref="myTextbox"/>  
	  <button onClick={this.handleSubmit}>Return Textbox Value</button>
      </div>
    )
  }  
}  

let mountElement = document.getElementById('root');
ReactDOM.render(<App/>, mountElement);
```

Now a React-standard way to do things, we can render an input, and tell it what its value should be: `return <input type="text" value="Hello World!" />`, this applies to all input types, not just `type="text"`. But, now we have a problem. if click to return value after try to type "asdf".... nothing will happen, because every time I type, React will re-render and React will see that the value is supposed to be "Hello World!, That's my problem so far.

**Controlled** input is when you specify the value. And, in order to update the value, you must also specify an onChange callback for the input. The event in the callback will have the new suggested value from the input. It is then your job to take that new value and put it somewhere in your state, then re-render with the new value.

```javascript
class App extends React.Component {  
  constructor(props) {
    super(props);
    this.state = {value: ''};

    this.handleChange = this.handleChange.bind(this);
    this.handleSubmit = this.handleSubmit.bind(this);
  }
    
  handleChange(event) {
    this.setState({value: event.target.value});
  }

  handleSubmit(event) {
    event.preventDefault();
    console.log(this.state.value);
  }
    
  render() {  
    return (
      <div>
	  <input 
	    type="text" 
	    value={this.state.value} 
	    onChange={this.handleChange}/>  
	  <button 
	    onClick={this.handleSubmit}>Return Textbox Value</button>
      </div>
    )
  }  
}  

let mountElement = document.getElementById('root');
ReactDOM.render(<App/>, mountElement);
```

### Multiples Fields

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = { fields: {}, people:[] };
		
    this.onInputChange = this.onInputChange.bind(this);
    this.onFormSubmit = this.onFormSubmit.bind(this);
  }
	
  onInputChange(evt) {
    const fields = this.state.fields;
    fields[evt.target.name] = evt.target.value;
    this.setState({ fields });
  }
	
  onFormSubmit(evt) {
    const people = [
      ...this.state.people,
	this.state.fields,
    ];
		
    this.setState({ people, fields: {} });
    evt.preventDefault();
  }
	
  render() {
    return (
      <div>
	  <h1>Sign Up Sheet</h1>
	  <form onSubmit={this.onFormSubmit}>
	    <input
            placeholder='Name'
		name='name'
		value={this.state.fields.name}
		onChange={this.onInputChange}/>
						
	    <input
	      placeholder='Email'
		name='email'
		value={this.state.fields.email}
		onChange={this.onInputChange}/>
						
	    <input type='submit'/>
	  </form>
	  <div>
	    <h3>Names</h3>
	    <ul>
	      {this.state.people.map(({name, email}, i) => {
		  return <li key={i}>{name}({email})</li>
		})}
	    </ul>
        </div>
      </div>
     )
  }
}

let mountElement = document.getElementById('root');
ReactDOM.render(<App/>, mountElement);
```

### Forms Validation

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = { 
      fields: {},
	fieldErrors: {},
	people:[] 
    };
		
    this.onInputChange = this.onInputChange.bind(this);
    this.onFormSubmit = this.onFormSubmit.bind(this);
    this.isEmail = this.isEmail.bind(this);
    this.validate = this.validate.bind(this);
  }
	
  onInputChange(evt) {
    const fields = this.state.fields;
    fields[evt.target.name] = evt.target.value;
    this.setState({ fields });
  }
	
  isEmail(email) {
    const emailRegExp = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.	[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return emailRegExp.test(email);
  }
  
  onFormSubmit(evt) {
    evt.preventDefault();
    const people = [ ...this.state.people ];
    const person = this.state.fields;
    const fieldErrors = this.validate(person);
    this.setState({ fieldErrors });
		
    if(Object.keys(fieldErrors).length) return;
      people.push(person);
	this.setState({ people, fields: {} });
    }
		
  validate(person) {
    const errors = {};
    if(!person.name) errors.name = 'Name Required';
    if(!person.email) errors.email = 'Email Required';
    if(person.email && !this.isEmail(person.email)) errors.email = 'Invalid Email';
    return errors;
  }
  
  render() {
    return (
      <div>
	  <h1>Sign Up Sheet</h1>
	  <form onSubmit={this.onFormSubmit}>
	  <input
	    placeholder='Name'
	    name='name'
	    value={this.state.fields.name}
	    onChange={this.onInputChange}/>
	  <span style={{ color: 'red' }}>{ this.state.fieldErrors.name }</span>
        <br/>
        <input
	    placeholder='Email'
	    name='email'
          value={this.state.fields.email}
	    onChange={this.onInputChange}/>
	  <span style={{ color: 'red' }}>{ this.state.fieldErrors.email }</span>
	  <br/>
	  <input type='submit'/>
	  </form>
	  <div>
          <h3>Names</h3>
            <ul>
		  {this.state.people.map(({name, email}, i) => {
		    return <li key={i}>{name}({email})</li>
		  })}
		</ul>
	  </div>
	</div>
    )
  }
}

let mountElement = document.getElementById('root');
ReactDOM.render(<App/>, mountElement);
```

## PropTypes

### Reusable React Components

This mean breaking down common design elements (buttons, form fields, layout components) into reusable components with well-defined interfaces to increase consistency across your application’s making look and feel, and minimize effort when building future UI. This allows for cross team collaboration, increases maintainability, speeds up development time, eliminates bugs, and reduces the file-size of your application.

Is important only top-level functional area components should hold state.

### PropTypes

You may have noticed we use props to pass data to ours child's components (Reusable Components), we expect these props types or set of types have the correct data for ours childs component.

The React.PropTypes object exports a bunch of different types which we can use to define what type a component's prop should be. We can define these using the propTypes method in the ES6 class-style React prop:

```javascript
class Widget extends React.Component {  
  render () {
    return (
      <div>
        <h1>{this.props.title}</h1>
      </div>
    )
  }
}

Widget.propTypes = {  
  title: React.PropTypes.string.isRequired,
}
```

### Basic Types

React exposes a few basic types we can use out of the box.

| Type      | Example            | Class                    |
| --------- |:------------------:| ------------------------:|
| String    | `'hello'`	         | `React.PropTypes.string` |
| Number    | `10, 0.1`          | `React.PropTypes.number` |
| Boolean   | `true` / `false`   | `React.PropTypes.bool`   |
| Function  |                    | `React.PropTypes.func`   |
| Symbol    | `Symbol("msg")`    | `React.PropTypes.symbol` |
| Object    | `{name: 'Ari'}`    | `React.PropTypes.object` |


### Collection Types

We can pass through iterable collections in our props.

| Type             | Example            | Class                             |
| ---------------- |:------------------:| ---------------------------------:|
| Array	           | `[]`               | `React.PropTypes.array`           |
| Array of numbers | `[1, 2, 3]`        | `React.PropTypes.arrayOf([type])` |
| Enum             | `['Red', 'Blue']`  | `React.PropTypes.oneOf([arr])`    |

### Object Types

It's possible to define types that need to be of a certain shape or instance of a certain class.

| Type          | Example         | Class                        |
| ------------- |:---------------:| ----------------------------:|
| Object        | `{name: 'Ari'}` | `React.PropTypes.object`     |
| Number object	| `{count: 42}`	  | `React.PropTypes.objectOf()` |
| Instance      | `new Message()` | `React.PropTypes.objectOf()` |
| Object shape  | `{name: 'Ari'}` | `React.PropTypes.shape()`    |

### React Types

We can also pass through React elements from a parent to a child. This is incredibly useful for building templates and providing customization with the templates.

| Type    | Example      | Class                     |
| ------- |:------------:| -------------------------:|
| Element | `<Title />`	 | `React.PropTypes.element` |

### Requiring Types

It's possible to require a prop to be passed to a component by appending any of the proptype descriptions with .isRequired

```javascript
Widget.propTypes = {
  title: React.PropTypes.name.isRequired,
}
```

### Default Props

Sometimes we want to be able to set a default value for a prop.

```javascript
Widget.defaultProps = {
  title: 'Home page activity'
}
```

## Pure Components “Stateless”

React offers several different methods for creating components. React also allows us to create pure, stateless components using a normal JavaScript function. Pure or stateless component simply present the data as provided. They do not have any state, they do not use any React lifecycle methods, they no backing instance, they no reference to the component, no refs, they only define the render method and nothing more.

**Example 1:**

```javascript
const HelloWorld = () => (<div>Hello World!</div>);

let mountElement = document.getElementById('root');
ReactDOM.render(<HelloWorld />, mountElement);
```

**Example 2:**

```javascript
const Notification = (props) => {
  const {message} = props;
  return (
    <div>{message}</div>
  )
};

let mountElement = document.getElementById('root');
ReactDOM.render(<Notification message={"Error Message"}/>, mountElement);
```

Stateless components that are pure functions to their props, state must be managed elsewhere. In other words state must be managed externally and passed down to the components as props.

### Compose Components

On the next example we can compose `TodoList` as smaller reusable parts. We can split it into 3 part.

```javascript
class TodoList extends React.Component {
  render() {
    const createItem = (item) => {
      return (
	  <li key={item.id}>{item.text}</li>
      );
    };

    return (
      <div>
        <ul>
          {this.props.todos.map(createItem)}
        </ul>
      </div>
    );
  }
};

let mountElement = document.getElementById('root');
ReactDOM.render(<TodoList {...state} />, mountElement);
```

**Step from bottom to top composition:**

* **List:** `List` container is a function that expects an application state and return a new component according to this state.
* **ListItem:** Then mapping over a number of todo `ListItem` and creating list along the way.
* **Item:** The result is then passed onto `ListItem` via props and rendered inside the component.

**Entire implementation:**

```javascript
const state = {
  todos: [
    {id:1, text: 'Buy milk'}, 
    {id:2, text: 'Buy cheese'},
    {id:3, text: 'Buy bread'}
  ]
};

const List = item => <ul>{item}</ul>;
const ListItem = todo => <li key={todo.id}>{todo.text}</li>;
const Item = R.prop('todos');

// Compose
const TodoList = R.compose(List, R.map(ListItem), Item);

let mountElement = document.getElementById('root');
ReactDOM.render(<TodoList {...state} />, mountElement);
```

### Combine Components

We want to include now another components.

```javascript
const Header = title => <h1>{title}</h1>;
```

But we cannot use compose `TodoList` containing a header and a list of todo items. What we’re actually looking for is the ability to compose `Header` and `List`.

We’re passing application state to the `TodoList` function, which first of all filters all the todos and then iterates over the filtered todos to create an array of Items that are then passed on to `List`. How can Header then retrieve title information from state? 

We want the ability to pass in application state and enable all components to retrieve any needed properties. To make it even more obvious I have called the function mapStateToProps.

```javascript
const mapStateToProps = R.curry((f, g) => R.compose(g, f));
```

Our `mapStateProps` expects a function as well as a component and then applies state to the provided function first and then passes the result on to the component.

```javascript
const TodoHeader = mapStateToProps(s => s.title, Header);
```

We still need the ability to compose the results of TodoList with Header to create our App. combine function, that expects two components and returns a new component back.

```javascript
const combine = R.curry((c, o) => x => (<div>{c(x)} {o(x)}</div>));
```

**Entire implementation:**

```javascript
const state = {
  title: 'Todos Title',
  todos: [
    {id:1, text: 'Buy milk'}, 
    {id:2, text: 'Buy cheese'},
    {id:3, text: 'Buy bread'}
  ]
};

const mapStateToProps = R.curry((f, g) => R.compose(g, f));

const List = item => <ul>{item}</ul>;
const ListItem = todo => <li key={todo.id}>{todo.text}</li>;
const Item = R.prop('todos');
const TodoList = mapStateToProps(Item, R.compose(List, R.map(ListItem)));

const Header = title => <h1>{title}</h1>;
const TodoHeader = mapStateToProps(s => s.title, Header);

const combine = R.curry((c, o) => x => (<div>{c(x)} {o(x)}</div>));
const App = combine(TodoHeader, TodoList);

let mountElement = document.getElementById('root');
ReactDOM.render(<App {...state} />, mountElement);
```

### Reduce Components

Now we need to add a Footer to our App just to be able to print out the current year. This is what might come to mind first:

```javascript
const App = combine(TodoHeader, combine(TodoList, TodoFooter));
```

Combine `TodoList` with `TodoFooter` and then combine the resulting output with the `TodoHeader`. This will work, but will become obscure the more components we want to combine.

Another way to do this is creating array of components .

```javascript
const comps = [TodoHeader, TodoList, TodoFooter]
const App = comps => 
  reduce((acc, x) => combine(acc, x), init, comps)
```

Now that we have an idea, let’s take a look at a concrete implementation:

```javascript
const combineComponents = (...args) => {
  const [first, ...rest] = args
  return R.reduce((acc, c) => combine(acc, c), first, rest)
}
```

Referencing `combineReducers` in redux, we could call our reducer `combineComponents`. `combineComponents` takes a number of components and reduces them to a single function expecting the component state.

**Entire implementation:**

```javascript
const state = {
  title: 'Todos Title',
  todos: [
    {id:1, text: 'Buy milk'}, 
    {id:2, text: 'Buy cheese'},
    {id:3, text: 'Buy bread'}
  ],
  year: '2017'
};

const mapStateToProps = R.curry((f, g) => R.compose(g, f));

const List = item => <ul>{item}</ul>;
const ListItem = todo => <li key={todo.id}>{todo.text}</li>;
const Item = R.prop('todos');
const TodoList = mapStateToProps(Item, R.compose(List, R.map(ListItem)));

const Header = title => <h1>{title}</h1>;
const TodoHeader = mapStateToProps(s => s.title, Header);

const Footer = text => <div>{text}</div>;
const TodoFooter = mapStateToProps(s => s.year, Footer);

const combine = R.curry((c, o) => x => (<div>{c(x)} {o(x)}</div>));
const combineComponents = (...args) => {
  const [first, ...rest] = args
  return R.reduce((acc, c) => combine(acc, c), first, rest)
};

const App = combineComponents(TodoHeader, TodoList, TodoFooter);

let mountElement = document.getElementById('root');
ReactDOM.render(<App {...state} />, mountElement);
```

With the help of `mapStateToProps`, combine and `combineComponents` we are able to compose components now. Regarding `mapStateToProps`, we can do one last refinement. 

Ramda offer a function called pipe. pipe simply run all functions from left to right. 

```javascript
const state = {
  title: 'Todos Title',
  todos: [
    {id:1, text: 'Buy milk'}, 
    {id:2, text: 'Buy cheese'},
    {id:3, text: 'Buy bread'}
  ],
  year: '2017'
};

const List = item => <ul>{item}</ul>;
const ListItem = todo => <li key={todo.id}>{todo.text}</li>;
const Item = R.prop('todos');
const TodoList = R.pipe(Item, R.compose(List, R.map(ListItem)));

const Header = title => <h1>{title}</h1>;
const TodoHeader = R.pipe(s => s.title, Header);

const Footer = text => <div>{text}</div>;
const TodoFooter = R.pipe(s => s.year, Footer);

const combine = R.curry((c, o) => x => (<div>{c(x)} {o(x)}</div>));
const combineComponents = (...args) => {
  const [first, ...rest] = args
  return R.reduce((acc, c) => combine(acc, c), first, rest)
};

const App = combineComponents(TodoHeader, TodoList, TodoFooter);

let mountElement = document.getElementById('root');
ReactDOM.render(<App {...state} />, mountElement);
```
