# React Components Lifecycle

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
      <div>{this.state.fetching ? data : loading}</div>
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
