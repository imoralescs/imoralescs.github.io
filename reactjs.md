# Reactjs

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

## Synthetic Event Handlers

Whenever you call an event handler within ReactJS, they are passed an instance of SyntheticEvent instead of the native event handler. This has the same interface as the native event handler's, except it's cross-browser compatible so you can use it
without worrying whether you need to make exceptions in your code for different browser implementations.

The events are triggered in a bubbling phase. This means that the event is first captured down to the deepest target and then propagated to outer elements. You can stop propagation by calling `event.stopPropagation()` or `event.preventDefault()` where appropriate.

## ReactElement

The browser DOM is made up of DOM elements. Similarly, the React DOM is made up of React elements. DOM elements and React elements may look the same, but they are actually quite different. A React element is a description of what the actual DOM element should look like. In other words, React elements are the instructions for how the browser DOM should be created.

We can create a React element to represent an h1 using `React.createElement` method:

```javascript
React.createElement("h1", null, "Baked Sweet Potato");
```

`React.createElement` takes in three arguments. The first is a tag name string (div, span, etc), the second is javascript object with any attributes you want the element to have, the third is contents or the children of the element, in this case the text "Baked Sweet Potato".

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

JSX expressions evaluate to ReactElements. Think of them as shorthand for calling `React.createElement()`.

## Component-Based Architecture

The concept of components is the foundation of React.js philosophy. They allow you to reuse code and logic. They are like templates only better. 

Way to define component:

* **ES6 using class / extends**

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

* **ES5 using `createClass()`**

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

## Variable 

On JSX we have two class of variable prop and state, and we can introducing using bracket {}.

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

## Conditional Statement

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
        {this.props.loggedIn ? 'You are logged In' : 'You are not logged In'}
      </div>
    )
  }
}
```

## List On React

### Using map function

The easiest way to implement a list in React is to use array and map(). List are often used on webpage.

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

## Method 

It possible to invoke components method from the {} interpolation.

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
  }
  
  getRandomNumber() {
    return Math.random();
  }
  
  render() {
    return (
      <div>
        <h2>My random number is: {this.getRandomNumber()}.</h2>
	</div>
    )
  }
}
```

## Events

The way of handling events in React components is much similar to DOM events processing in pure Javascript. Just define a response function and let it be the event handler and listen an event. React has event system which called Synthetic Events is cross-browser wrapper.

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

## React Components Lifecycle

Since we're defining virtual representations of nodes in our DOM tree with React, we're not actually defining DOM nodes. Instead, we're building up an in-memory view that React maintains and manages for us.

### Mounting

When we talk about mounting, we're talking about the process of converting the virtual components into actual DOM elements that are placed in the DOM by React.

As React mounts our application, it gives us some hooks where we can insert our own functionality at different times in the component's lifecycle. In order to hook into the lifecycle, we'll need to define functions on our component which React calls at the appropriate time for each hook. 
 
### Initialization

The initialization phase is where we define defaults and initial values for this.props and this.state by implementing `getDefaultProps()` and `getInitialState()` respectively.

* **`getDefaultProps()`:** Method is called once and cached — shared across instances — when the class is created, before any instance of the component are created, hence we can’t rely on this.props here. This method returns an object which properties values will be set on this.props if that prop is not specified by the parent component.

* **`getInitialState()`:** Method is also invoked once, right before the mounting phase. The return value of this method will be used as initial value of this.state and should be an object. 

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);


    // Get Initial State getInitialState() ES6
    this.state = { count : 0 };
		
    this.handleIncrement = this.handleIncrement.bind(this);
    this.handleDecrement = this.handleDecrement.bind(this);
  }
	
  // Get Default Props
  handleIncrement() {
    const count = this.state.count + 1;
    this.setState({count: count});
  }
    
  handleDecrement() {
    const count = this.state.count - 1;
    this.setState({count: count});
  }
		
  render() {
    return (
      <div>
        <h1>{this.props.title}</h1>
        <div>{this.state.count}</div>
        <input type='button' value='+' onClick={this.handleIncrement} />
        <input type='button' value='-' onClick={this.handleDecrement} />
      </div>
    )
  }
}

// Get Default Props, getDefaultProps() ES6
App.defaultProps = {
  title: "Basic Counter!!!"
};

let mountElement = document.getElementById('root');
ReactDOM.render(<App/>, mountElement);
```

### Mounting

Again mounting in simple form is the process that occurs when a component is being inserted into the DOM. This phase has two methods that we can hook up with:

* **`componentWillMount()`:** Method is the first called in this phase. It’s invoked once and immediately before the initial rendering occurs, hence before React inserts the component into the DOM. It’s very important to note that calling `this.setState()` within this method will not trigger a re-render. Your component is in default position at this point. Almost everything should be taken care of by the rest of your component code, without the complication of an additional lifecycle method. 

**Most common use case:** App configuration in your root component. 
**Can call setState:** Don’t. Use default state instead.

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = { title : "Hello Worlds" };
  }
	
  componentWillMount() {
    console.log('componentWillMount');
  }
	
  render() {
    return (
      <div>
        <h1>{this.state.title}</h1>
      </div>
    )
  }
}

let mountElement = document.getElementById('root');
ReactDOM.render(<App/>, mountElement);
```

* **`componentDidMount()`:** Is the second invoked in this phase, just once and immediately after React inserts the component into the DOM. Now the updated DOM is available for access, which means that this method is the best place for initializing other Javascript libraries that need access to the DOM and for data fetching operations. ComponentDidMount is also where you can do all the fun things you couldn’t do when there was no component to play with. Here are some examples: draw on a `<canvas>` element that you just rendered, initialize a masonry grid layout from a collection of elements or add event listeners. 

**Most common use case:** Starting AJAX calls to load in data for your component. 
**Can call setState:** Yes.

```javascript
class App extends React.Component {
  constructor(props) {
    super(props);
      this.state = { 
        data : [],
        fetching : false,
        error: []
      };
  }
	
  componentDidMount() {
    fetch('https://jsonplaceholder.typicode.com/users')
    .then(res => {
      return res.json()
    })
    .then(data => {
      this.setState({
	  data : data,
	  fetching : true
	})
    })
  }
	
  render() {
    const loading = <span>Loading...</span>;
    const data = this.state.data.map((data) => {
      return(
        <p key={data.id}>{data.name} : <b>{data.email}</b></p>
      );
  });
  
  return (
    	<div>
				{this.state.fetching ? data : loading}
			</div>
    )
  }
}

let mountElement = document.getElementById('root');
ReactDOM.render(<App/>, mountElement);
```

### Updating

Sometime we want to update some data of our component before or after we change the actual rendering. We have method that allow us to execute code relative to when a component state or properties get updated.

**Case 1:** When receiving new props from the parent
**Step:**
1. componentWillReceiveProps
2. shouldComponentUpdate
3. componentWillUpdate
4. render
5. componentDidUpdate

**Case 2:** When the state change via this.setState()
**Step:**
1. shouldComponentUpdate
2. componentWillUpdate
3. render
4. componentDidUpdate

**`componentWillReceiveProps()`**

This method is called when props are passed to the child component instance.

This method was called because React has no way of knowing that the data did not change. Therefore React needs to call componentWillReceiveProps, because the component needs to be notified of the new props.

componentWillReceiveProps allows us to check and see if new props are coming in and we can make choices based on data.

**Most Common Use case:** Acting on particular prop changes to trigger state transitions.

**Can call setState:** Yes.

```javascript
class TextField extends React.Component {
  constructor(props){
    super(props);
    this.state = {
      name: ''
    };
    this.handleChange = this.handleChange.bind(this);
  }

  handleChange(event) {
    this.setState({ name: event.currentTarget.value });
  }

  render() {
    return (
      <div>
	  <input type="text" onChange={ this.handleChange } />
        <Person name={this.state.name} />
	</div>
    );
  }
}

class Person extends React.Component {
  constructor(props) {
    super(props);
  }
	
  componentWillReceiveProps(newProps){
    if(this.props != newProps) {
      console.log('componentWillReceiveProps: ' + newProps);
    }
  }
	
  render() {
    return (
      <p>{this.props.name}</p>
    )
  }
}

let mountElement = document.getElementById('root');
ReactDOM.render(<TextField/>, mountElement);
```

**`shouldComponentUpdate()`**

This method invoked whenever the component receives new props or a change in state occurs.

By default, shouldComponentUpdate returns a true value. If you override it and return false, the component will never be updated despite receiving updated props or a new state.

We can used this method, if we create a component that should only be updated if certain conditions are met.

```javascript
class CounterButton extends React.Component {
  constructor(props) {
    super(props);
    this.state = {count: 1};
  }

  shouldComponentUpdate(nextProps, nextState) {
    // Actual State
    console.log(this.state);//-> Object {count: 1}
		
    // New State
    console.log(nextState);//-> Object {count: 2}
		
    // Props Case
    if (this.props.color !== nextProps.color) {
      return true;
    }
    
    // State Case
    if (this.state.count !== nextState.count) {
      return true;
    }
    
    return false;
  }

  render() {
    return (
      <button
        color={this.props.color}
        onClick={() => this.setState(state => ({count: state.count + 1}))}>
        Count: {this.state.count}
      </button>
    );
  }
}

let mountElement = document.getElementById('root');
ReactDOM.render(<CounterButton/>, mountElement);
```

**Most common use case:** Controlling exactly when your component will re-render.
**Can call setState:** No.

**`componentWillUpdate()`**

We can called just like `componentWillMount()` this method is called before `render()`.

The method `componentWillUpdate()` is similar to `componentWillMount()`. The difference being that `componentWillUpdate()` called every time re-render is required, such as when `this.state()` is called.

We can used this `componentWillUpdate()` is a chance for us to handle configuration changes and prepare for the next render.

**Most common use case:** Used instead of componentWillReceiveProps on a component that also has shouldComponentUpdate (but no access to previous props).
**Can call setState:** No.

```javascript
componentWillUpdate(nextProps, nextState) {
  if (nextState.open == true && this.state.open == false) {
    this.props.onWillOpen();
  }
}
```

**`componentDidUpdate()`**

We can called this method like `componentDidMount()`, the `componentDidUpdate()` is called after all of the children are updated.

The most common uses of `componentDidUpdate()` is managing 3rd party UI elements and interacting with the Native UI. When using 3rd Party libraries, like our Chart example, we need to update the UI library with new data.

**Most common use case:** Updating the DOM in response to prop or state changes.
**Can call setState:** Yes.

```javascript
componentDidUpdate(prevProps, prevState) {
  // only update chart if the data has changed
  if (prevProps.data !== this.props.data) {
    this.chart = c3.load({
      data: this.props.data
    });
  }
}
```

### `componentWillUnmount()`

Before the component is unmounted, React will call out to the `componentWillUnmount()` callback. This is the time to handle any clean-up events we might need, such as clearing timeouts, clearing data, disconnecting websockets, etc.

**Most common use case:** Cleaning up any leftover debris from your component.
**Can call setState:** No.

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

## Redux

Redux is a library that manage state of application on response of actions. Instead of directly modifying the state, the modification is handled through simple objects called actions. Then you write a special function called reducer to decide how each action transforms the state of the entire application.

Redux it's design inspiration from the Flux pattern, but is not itself a pure flux implementation. It provides the same general principles around how to update the data in our application, but in slightly different way.

The 3 major principles of Redux we'll keep in mind as we implement Redux in our app are:

* Updates are made with pure functions (in reducers)
* state is a read-only property
* state is the single source of truth (there is only one store in a Redux app)


### Redux without React

```javascript
const {createStore} = Redux;

// State
const state = {count: 0, sum: 0};

// Action
const decreaseAction = () => {
  return { type: 'DECREMENT' };
}

const increaseAction = () => {
  return { type: 'INCREMENT' };
}

const sumAction = (value_1, value_2) => {
  return {
    type: 'SUM',
    field_1: value_1,
    field_2: value_2,
  };
}

// Reducer
const counter = (currentState, action) => {
  const DEFAULT_STATE = 0;
  
  if (currentState === undefined) { 
    return currentState = DEFAULT_STATE;
  }
		
  switch(action.type){
    case 'DECREMENT':
      return currentState - 1;
    case 'INCREMENT':
      return currentState + 1;
    default:
      return currentState;
  }
}

const sum = (currentState, action) => {
  const DEFAULT_STATE = 0;
  
  if (currentState === undefined) { 
    return currentState = DEFAULT_STATE;
  }


  switch(action.type){
    case 'SUM':
      return parseInt(action.field_1) + parseInt(action.field_2);
    default:
      return currentState;
  }
}

const combineReducer = (currentState = state, action) => {
  let nextState = Object.assign({}, currentState);
  
  nextState = {
    count:counter(nextState.count, action),
    sum: sum(nextState.sum, action),
  }
  return nextState;
}

// Event Handler
document.getElementById('decrement').addEventListener('click', function () {
  store.dispatch(decreaseAction());
});

document.getElementById('increment').addEventListener('click', function () {
  store.dispatch(increaseAction());
});

document.getElementById('sum').addEventListener('click', function () {
  var field_1 = document.getElementById('field-1').value;
  var field_2 = document.getElementById('field-2').value;

  store.dispatch(sumAction(field_1, field_2));
});

// Main
const store = createStore(combineReducer);
      
const render = () => {
  let state = store.getState();
  console.log(state);
  document.getElementById('count').innerHTML = state.count;
  document.getElementById('result').innerHTML = state.sum;
}

store.subscribe(render);

// UI Trigger
render();
```

**Store**

Redux Store API is the place where application state is holding. Allow access to the state, allow the state to be update through the dispatch and register listener. To create store we need to used createStore() from Redux library. 

```javascript
const store = createStore(combineReducer);
```

This object has only four method:

* `store.getState()` - Returns the current state object tree.
* `store.dispatch(action)` - Dispatch an action to change the state.
* `store.subscribe(listener)` - Listen to changes in the state tree.
* `store.replaceReducer(nextReducer)` - Replaces the current reducer with another. This method is used in advanced use cases such as code splitting.

**Reducer**

Is a function that takes an object that represents a old state, then create a brand new object by copying all the old object state details into a it and overriding old properties with new ones. 

Reducer is a pure or must be a pure function, Redux simply checks whether the old object is the same as the new object by comparing the memory locations of the two objects. So if you mutate the old object’s property inside a reducer, the “new state” and the “old state” will both point to the same object. 

But why?  There is only one way to know if two JavaScript objects have the same properties. To deep-compare them. In other words, new objects represent new states.

Reducer executed when an action is fired, It can either handle the action or no handle it and return the original state. The reducer function receive two argument when it called:

* state tree.
* action which triggered a change

```javascript
const counter = (currentState, action) => {
  const DEFAULT_STATE = 0;


  if (currentState === undefined) { 
    return currentState = DEFAULT_STATE;
  }
	
  switch(action.type){
    case 'DECREMENT':
      return currentState - 1;
    case 'INCREMENT':
      return currentState + 1;
    default:
      return currentState;
  }
}
```

Reducers should return a new object, instead. You can do that with `Object.assing({}, state, {thingToChange})`, for instance. You can't `.push()` new items to an array in a reducer, because `push()` is a mutating operation. Likewise so are `pop()`, `shift()` `splice()` any other mutator method.

**combineReducer**

Is a function on Redux library on the case we have multiple reducer and you want to create a root reducer where we combine multiple reducer.

const combineReducer = (currentState = state, action) => {
  let nextState = Object.assign({}, currentState);
  nextState = {
    count:counter(nextState.count, action),
    sum: sum(nextState.sum, action),
  }
  return nextState;
}

**Action**

They are simple javascript object, they need to have property type, this property just indicate the action to make.

```javascript
{ type: 'DECREMENT' }
```

**Action Creator**

They are simple javascript function, to create javascript object redux action.

const decreaseAction = () => {
  return { type: 'DECREMENT' };
}

Action Dispatch

Is a function inside of store object. They just send or dispatch action.

```javascript
store.dispatch(decreaseAction());
```

### Redux and React

```javascript
const {createStore} = Redux;

// Reducers
const counter = (currentState, action) => {
  currentState = currentState || { count : 0 }; // Initial State
  switch(action.type){
    case 'INCREMENT':
      return Object.assign({}, currentState, {count : currentState.count + 1});
    case 'DECREMENT':
      return Object.assign({}, currentState, {count : currentState.count - 1});
    default:
      return currentState;
  }
}

// Create Store
const store = createStore(counter);

// React Component
class Counter extends React.Component{
  constructor() {
    super();
    this.state = store.getState();
    this.unsubscribe = store.subscribe(() => {
      this.setState(store.getState());
    });
		
    this.increaseAction = this.increaseAction.bind(this);
    this.decreaseAction = this.decreaseAction.bind(this);
  }
	
  increaseAction() {
    store.dispatch({ type: 'INCREMENT' });
  }
	
  decreaseAction() {
    store.dispatch({ type: 'DECREMENT' });
  }
	
  componentWillUnmount() {
    this.unsubscribe();
  }
	
  render(){
    return(
      <div>
        <button onClick={this.decreaseAction}>-</button>
	  <span>{this.state.count}</span>
        <button onClick={this.increaseAction}>+</button>
      </div>
    )
  }
}

const mountElement = document.getElementById('root');
ReactDOM.render(
  <Counter />,
  mountElement
);
```

### Redux, React and react-redux

Redux has no relation to React, but with react-redux library we can connect both technology in a better implementation. With react-redux you won't have to define componentWillUnmount on all components that listen to the store. Even better, you won't have to do `this.state = {...}` in the constructor anymore.

```javascript
const {createStore} = Redux;
const { Provider, connect } = ReactRedux;

// Reducers
const count = (currentState, action) => {
  currentState = currentState || { count : 0 }; // Initial State
  switch(action.type) {
    case 'INCREMENT':
      return Object.assign({}, currentState, {count : currentState.count + 1});
    case 'DECREMENT':
      return Object.assign({}, currentState, {count : currentState.count - 1});
    default:
      return currentState;
  }
}

// Create Store
const store = createStore(count);

class Counter extends React.Component{
  constructor(props) {
    super(props);
  }	
	
  render(){
    return(
      <div>
        <button onClick={this.props.decrement}>-</button>
        <span>{this.props.count}</span>
        <button onClick={this.props.increment}>+</button>
      </div>
    )
  }
}

const mapStateToProps = function (state) {
  console.log(state);
  return {
    count: state.count,
  };
};

const mapDispatchToProps = (dispatch) => {
  return {
    increment: () => dispatch({type: 'INCREMENT'}),
    decrement: () => dispatch({type: 'DECREMENT'}),	
  }
};

const App = connect(mapStateToProps, mapDispatchToProps)(Counter);

const mountElement = document.getElementById('root');
ReactDOM.render(
  <Provider store={store}>
    <App/>
  </Provider>,
  mountElement
);
```

**Provider**

Provider component “provides” the store for our app. Wrap it around the App component.

**connect()**

Function is how `react-redux` binds your redux state to your components. The `connect()` function take `mapStateToProps` and mapDispatchToProps functions and ties it to your App component.

**mapStateToProps**

This function allows to map our state to fit needs of specific view, we can filter some values or change the order of some kind of items held in state, this function have to return object.

**mapDispatchToProps**

`mapDispatchToProps` returns object with functions allowing to dispatch actions to store, in that way views doesn’t have to know what actions are dispatched.

```javascript
const {createStore, combineReducers, bindActionCreators} = Redux;
const { Provider, connect } = ReactRedux;

// React Component
const Todo = ({ onClick, completed, text }) => (
  <li
    onClick={onClick}
    style={{
      textDecoration: completed ? 'line-through' : 'none'
    }}
  >
  {text}
  </li>
);

const TodoList = ({ todos, onTodoClick }) => (
  <ul>
    {todos.map(todo =>
      <Todo
        key={todo.id}
        {...todo}
        onClick={() => onTodoClick(todo.id)}/>
    )}
  </ul>
);

class AddTodo extends React.Component{
  constructor(props) {
    super(props);
    this.onFormSubmit = this.onFormSubmit.bind(this);
  }	
	
  onFormSubmit(evt) {
    evt.preventDefault();
    const todo = this.refs.todo.value;
    this.props.addTodo(todo);
    this.refs.todo.value = '';
  }
	
  render(){
    return (
      <div>
        <form onSubmit={this.onFormSubmit}>
          <input ref='todo'/>
          <button type="submit">Add Todo</button>
        </form>
        <TodoList 
          todos={this.props.todos} 
          onTodoClick={this.props.onTodoClick}/>
      </div>
    )
  }
}

class Counter extends React.Component{
  render(){
    return(
      <div>
        <button onClick={this.props.decrement}>-</button>
        <span>{this.props.count}</span>
        <button onClick={this.props.increment}>+</button>
      </div>
    )
  }
}

class App extends React.Component{
  constructor(props) {
    super(props);
  }	
	
  render(){
    return(
      <div>
        <AddTodo 
          todos={this.props.todos} 
          addTodo={this.props.addTodo} 
          onTodoClick={this.props.onTodoClick}/>
        <Counter 
          increment={this.props.increment} 
          decrement={this.props.decrement} 
          count={this.props.count}/>
      </div>
    )
  }
}

// Reducers
const count = (currentState, action) => {
  currentState = currentState || 0; // Initial State
  switch(action.type) {
    case 'INCREMENT':
      return currentState + 1;
    case 'DECREMENT':
      return currentState - 1;
    default:
      return currentState;
  }
}

const todo = (currentState, action) => {
  currentState = currentState || {}; // Initial State
  switch (action.type) {
    case 'ADD_TODO':
      // Adding To State
    	return {
        id: action.id,
        text: action.text,
        completed: false
      }
    case 'TOGGLE_TODO':
	// Updating State
      if (currentState.id !== action.id) {
        return currentState;
      }
      return {
        ...currentState,
        completed: !currentState.completed
      }
    default:
      return currentState
  }
}

const todos = (currentState, action) => {
  currentState = currentState || []; // Initial State
  switch (action.type) {
    case 'ADD_TODO':
      return [
        ...currentState,
        todo(undefined, action)
      ]
    case 'TOGGLE_TODO':
      return currentState.map(t => 
        todo(t, action)
      )
    default:
      return currentState
  }
}

// Reducers Combiner
const AppReducers = combineReducers({
  todos,
  count
});

// Actions Creators
let nextTodoId = 0;
const actions = {
  increment: () => {
    return {
      type: 'INCREMENT'
    }
  },
  decrement: () => {
    return {
      type: 'DECREMENT'
    }
  },
  addTodo: (text) => {
    return {
      type: 'ADD_TODO', 
      id: nextTodoId++, 
      text
    }
  },
  onTodoClick: (id) => {
    return {
      type: 'TOGGLE_TODO', 
      id 
    }
  }
};

// Create Store
const store = createStore(AppReducers);

const mapStateToProps = function (state) {
  return {
    count: state.count,
    todos: state.todos
  };
};

const mapDispatchToProps = dispatch => {
  return bindActionCreators(actions, dispatch);
};

const AppContainer = connect(mapStateToProps, mapDispatchToProps)(App);

const mountElement = document.getElementById('root');
ReactDOM.render(
  <Provider store={store}>
    <AppContainer/>
  </Provider>,
  mountElement
);
```

**bindActionCreators**

This function maps action functions to an object using the names of the action functions. These functions automatically dispatch the action to the store when the function is called.

### Redux Middleware

Main point is intercept every single action they come through reducer and modify that action or cancel that action. The essence of middleware is that it runs in the Store before the action is dispatched to the reducer. Can provides a third-party extension point between dispatching an action, and the moment it reaches the reducer.

```javascript
const {createStore, applyMiddleware} = Redux;
const { Provider, connect } = ReactRedux;

const initialState = { count : 0 };

// Middleware
const logger = (store) => (next) => (action) => {
  console.log('action fired', action);
  next(action);
}

// Reducers
const counter = (currentState = initialState, action) => {
  const DEFAULT_STATE = { count : 0 };
  
  if (currentState === undefined) { 
    return currentState = DEFAULT_STATE;
  }
	
  switch(action.type){
    case 'INCREMENT':
      return Object.assign({}, currentState, {count : currentState.count + 1});
    case 'DECREMENT':
      return Object.assign({}, currentState, {count : currentState.count - 1});
    default:
      return currentState;
  }
}

// Create Store
const store = createStore(counter, applyMiddleware(logger));

// React Component
class Counter extends React.Component{
  constructor(props) {
    super(props);
  }

  render(){
    console.log(this.props);
    return(
      <div>
        <button onClick={this.props.decrement}>-</button>
        <span>{this.props.count}</span>
        <button onClick={this.props.increment}>+</button>
      </div>
    )
  }
}

const mapStateToProps = function (state) {
  return {
    count: state.count
  };
};

const mapDispatchToProps = dispatch => ({
  increment: () => dispatch({type: 'INCREMENT'}),
  decrement: () => dispatch({type: 'DECREMENT'}),	
});

const App = connect(mapStateToProps, mapDispatchToProps)(Counter);

const mountElement = document.getElementById('root');
ReactDOM.render(
  <Provider store={store}>
    <App/>
  </Provider>,
  mountElement
);
```

**Thunk Middleware**

The main problem we have we reducer on Redux is the concept of a reducer is that it take the current state and an action and return the next state. It's a pure function that does not modify the current state.

```javascript
function myReducer(previousState, someAction){  
  var nextState = {
    foo:previousState.foo,
    bar:someAction.bar
  };
}
```

But if would we want to do some async stuff we would have to wait until a Promise is resolved and then return the next state. We could just return the previous state and dispatch a new action once our Promise is resolved. 

```javascript
function myReducer(previousState, someAction){
  someAsyncMethod(someAction.bar)
  .then(function(result){
    myStore.dispatch({type:"SOME_TYPE", bar:result});
  });
  return previousState;
}
```

This is a bad approach because we can have side effect here. We can used the thunk middleware, runs in the Store before the action is dispatched to the reducer. 

The thunk middleware look like this:

```javascript
const {createStore, combineReducers, bindActionCreators, applyMiddleware} = Redux;
const { Provider, connect } = ReactRedux;

// React Component
const Todo = ({ onClick, completed, text }) => (
  <li
    onClick={onClick}
    style={{
      textDecoration: completed ? 'line-through' : 'none'
    }}
  >
  {text}
  </li>
);

const TodoList = ({ todos, onTodoClick }) => (
  <ul>
    {todos.map(todo =>
      <Todo
        key={todo.id}
        {...todo}
        onClick={() => onTodoClick(todo.id)}/>
    )}
  </ul>
);

class AddTodo extends React.Component{
  constructor(props) {
    super(props);
    this.onFormSubmit = this.onFormSubmit.bind(this);
  }	
	
  onFormSubmit(evt) {
    evt.preventDefault();
    const todo = this.refs.todo.value;
    this.props.addTodo(todo);
    this.refs.todo.value = '';
  }
	
  render(){
    return (
      <div>
        <form onSubmit={this.onFormSubmit}>
          <input ref='todo'/>
          <button type="submit">Add Todo</button>
        </form>
        <TodoList 
          todos={this.props.todos} 
          onTodoClick={this.props.onTodoClick}/>
      </div>
    )
  }
}

class Counter extends React.Component{
  render(){
    return(
      <div>
        <button onClick={this.props.decrement}>-</button>
        <span>{this.props.count}</span>
        <button onClick={this.props.increment}>+</button>
      </div>
    )
  }
}

class App extends React.Component{
  constructor(props) {
    super(props);
  }	
  
  render(){
    console.log(this.props)
    return(
      <div>
        <AddTodo 
          todos={this.props.todos} 
          addTodo={this.props.addTodo}                    
          onTodoClick={this.props.onTodoClick}/>
        <Counter 
          increment={this.props.increment} 
          decrement={this.props.decrement} 
          count={this.props.count}/>
        <br/>
        <ul>
          {(this.props.isLoading) ? <span>loading....</span> :
            this.props.authors.map(function(author){ 
              return ( 
                <li key={author.id}>{author.name}</li>  
              ) 
            })
           }
        </ul>
      </div>
    )
  }
}

// Middleware
const thunkMiddleware = ({ dispatch, getState }) => {  
  return next => action =>
    typeof action === 'function' ?
      action(dispatch, getState) :
      next(action);
}

// Reducers
const loadAuthors = () => {
  return (dispatch) => {
    store.dispatch({type: "IS_LOADING", isLoading: true});
    return fetch('https://jsonplaceholder.typicode.com/users')
    .then(function(result) {
      // Loading process end.
      store.dispatch({type: "IS_LOADING", isLoading: false});
      
      if(result.status === 200) {
        return result.json();
      }

      throw "request failed";
    })
    .then(function(json) {
      // Populate state with data.
      store.dispatch({type: 'LOAD_AUTHORS_SUCCESS', authors:json});
    })
    .catch(function(err) {
      // In case of error.
    });
  }
}

const authors = (currentState, action) => {
  currentState = currentState || []; // Initial State
  switch(action.type){
    case 'LOAD_AUTHORS_SUCCESS':
      return action.authors
      break;
    default:
      return currentState;
  }
};

const isLoading = (currentState, action) => {
  currentState = currentState || false; // Initial State
  switch(action.type){
    case "IS_LOADING":
      return action.isLoading
    default:
      return currentState;
  }
};

const todo = (currentState, action) => {
  currentState = currentState || {}; // Initial State
  switch (action.type) {
    case 'ADD_TODO':
      // Adding To State
    	return {
        id: action.id,
        text: action.text,
        completed: false
      }
    case 'TOGGLE_TODO':
      // Updating State
      if (currentState.id !== action.id) {
        return currentState;
      }
      return {
        ...currentState,
        completed: !currentState.completed
      }
    default:
      return currentState
  }
}

const todos = (currentState, action) => {
  currentState = currentState || []; // Initial State
  switch (action.type) {
    case 'ADD_TODO':
      return [
        ...currentState,
        todo(undefined, action)
      ]
    case 'TOGGLE_TODO':
      return currentState.map(t => 
        todo(t, action)
      )
    default:
      return currentState
  }
}

const count = (currentState, action) => {
  currentState = currentState || 0; // Initial State
  switch(action.type) {
    case 'INCREMENT':
      return currentState + 1;
    case 'DECREMENT':
      return currentState - 1;
    default:
      return currentState;
  }
}

// Reducers Combiner
const AppReducers = combineReducers({
  authors,
  isLoading,
  todos,
  count
});

// Actions Creators
let nextTodoId = 0;
const actions = {
  increment: () => {
    return {
      type: 'INCREMENT'
    }
  },
  decrement: () => {
    return {
      type: 'DECREMENT'
    }
  },
  addTodo: (text) => {
    return {
      type: 'ADD_TODO', 
      id: nextTodoId++, 
      text
    }
  },
  onTodoClick: (id) => {
    return {
      type: 'TOGGLE_TODO', 
      id 
    }
  }
};

// Create Store
const store = createStore(AppReducers, applyMiddleware(thunkMiddleware));

const mapStateToProps = function (state) {
  // Varify State
  // console.log(state);
  return {
    count: state.count,
    todos: state.todos,
    authors: state.authors,
    isLoading: state.isLoading
  };
};

const mapDispatchToProps = dispatch => {
  return bindActionCreators(actions, dispatch);
};

const AppContainer = connect(mapStateToProps, mapDispatchToProps)(App);

store.dispatch(loadAuthors());

const mountElement = document.getElementById('root');
ReactDOM.render(
  <Provider store={store}>
    <AppContainer/>
  </Provider>,
  mountElement
);
```

## Static Type Check (Flow)

In programming Type is a classification of information. Example number, string, boolean. Programming language used types class to classificate his own data and know how to manage or threat data on the execution time or on runtime. They are language with static type and other with dynamically type. 

The core difference is that statically-typed languages perform type checking at compile time, while dynamically-typed languages perform type checking at runtime.

### Type-checking

This mean for example in Java if you define a boolean as:

```
boolean result = 123;
```

This has the correct type, because the boolean annotation matches the value given to result, as opposed to an inter or anything else. if you tried to declare:

```
boolean result = 123;
```

This would fail before run.

Type-checking verifies and enforces that the type of a construct (constant, boolean, number, variable, array, object) matches an invariant that you’ve specified. You might, for example, specify that “this function always returns a string.” When the program runs, you can safely assume that it will return a string.

Let see a case we Javascript where we are not using type-checking and we are using the wrong type on the process:

```
const length = 12;
const num = length(54); -> TypeError: length is not a function
```

We can get this error after time execution because Javascript is a dynamically-type language. In a statically-typed language, type errors occur during the compilation step, that is, at compile time. In dynamically-typed languages, the errors occur only once the program is executed. That is, at runtime.

This means that a program written in a dynamically-typed language can compile even if it contains type errors that would otherwise prevent the script from running properly. On the other hand, if a program written in a statically-typed language contains type errors, it will fail to compile until the errors have been fixed.
