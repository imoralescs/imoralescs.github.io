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
