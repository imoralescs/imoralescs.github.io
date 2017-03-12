# Reactjs

React is a Javascript library for creating user interfaces, authored by Facebook and Instagram engineers. It’s aimed to solve the challenges involved when developing complex user interfaces with datasets that change over time.

### React is all about components

Components are the core of React and the view to your application. They are encapsulated and composable, you can mix and match them to build complex UIs favoring code reuse and separation of concerns.

React components are written in plain JavaScript, instead of template languages or the HTML directives traditionally used for web application UIs.

## Virtual DOM

The Virtual DOM is a tree of JavaScript objects that represents the actual DOM.

## ReactElement

A ReactElement is a representation of a DOM element in the Virtual DOM. React will take these ReactElements and place them into the “actual DOM” for us. 

```javascript
let boldElement = React.createElement('b');
```
## Create ReactNode

ReactNode is a building block for a virtual DOM and can be either:

* **ReactElement:** This is the primary type in React. It’s a light, stateless, immutable, virtual representation of a DOM element.
* **ReactText:** This is a string or a number. It’s a virtual representation of a Text Node in the DOM.
* **ReactFragment:** This is an array of ReactNode elements.

```javascript
ReactDOM.render(ReactElement, DOMElement, callback);

ReactDOM.render(
  // We create element h1
  React.createElement('h1', null, 'Hello, Worlds!'), //<-- nextElement
  // Render it to the DOM node with ID "root"
  document.getElementById('root') //<-- container
);
```

```javascript
ReactDOM.render(
  React.DOM.h1(null, 'Hello World!'),
  document.getElementById('root')
);
```

```javascript
// HTML argument, for and class
ReactDOM.render(
  React.createElement('h1', {className: 'class-1'}, 'Hello World!'),
  document.getElementById('root')
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

Props is a short for properties, Props are immutable meaning they don't change. They are passed by parent components to their children components. You used to be able to change props with setProps and replaceProps but these have been deprecated. During a component’s life cycle props should not change (consider them immutable).

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

| Type          | Example        | Class                  |
| --------- |:------------------:| ----------------------:|
| String    | `'hello'`	         | React.PropTypes.string |
| Number    | `10, 0.1`          | React.PropTypes.number |
| Boolean   | `true` / `false`   | React.PropTypes.bool   |
| Function  |                    | React.PropTypes.func   |
| Symbol    | `Symbol("msg")`    | React.PropTypes.symbol |
| Object    | `{name: 'Ari'}`    | React.PropTypes.object |


Collection Types
We can pass through iterable collections in our props.

Type			Example		Class
Array			[]			React.PropTypes.array
Array of numbers	[1, 2, 3]		React.PropTypes.arrayOf([type])
Enum			['Red', 'Blue']	React.PropTypes.oneOf([arr])

Object Types
It's possible to define types that need to be of a certain shape or instance of a certain class.

Type			Example		Class
Object		{name: 'Ari'}	React.PropTypes.object
Number object	{count: 42}		React.PropTypes.objectOf()
Instance		new Message()	React.PropTypes.objectOf()
Object shape	{name: 'Ari'}	React.PropTypes.shape()

React Types
We can also pass through React elements from a parent to a child. This is incredibly useful for building templates and providing customization with the templates.

Type			Example		Class
Element		<Title />		React.PropTypes.element

Requiring Types
It's possible to require a prop to be passed to a component by appending any of the proptype descriptions with .isRequired

Widget.propTypes = {
  title: React.PropTypes.name.isRequired,
}

Default Props
Sometimes we want to be able to set a default value for a prop.

Widget.defaultProps = {
  title: 'Home page activity'
}

