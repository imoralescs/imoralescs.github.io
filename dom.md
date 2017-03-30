## Document Object Model (DOM)

In application is an HTML, XML or SVG document, when a web page is loaded, the browser creates the DOM of the page. Is basically an object they contain every element of the page inside it. The DOM is constructed as a tree of object and each object represents an element of the page. And each element is an object.

### DOM Structure

* DOCUMENT_NODE
* ELEMENT_NODE

```html
<html> <head> <body> <h1> <p>
```

* TEXT_NODE

```html
<p>I am text node</p>
```

* ATTRIBUTE_NODE

```html
<img src="attribute node">
```

## Transverse DOM

DOM allows to do anything with elements and their contents, but first we need to reach the corresponding DOM object, get it into a variable, and then we are able to modify it.

### documentElement and body

The topmost tree nodes are available directly as document properties:

* **`<html>` = `document.documentElement`:** The topmost document node is document.documentElement. That’s DOM node of `<html>` tag.
* **`<body>` = `document.body:`** Another widely used DOM node is the `<body>` element – document.body.
<head> = document.head

The <head> tag is available as document.head.

### Topology

The DOM objects relate to each other in a certain way, but there are some relationships that will be present in most situations:

* **Parents nodes:** Are nodes that nest further nodes in them. Examples of the nodes that most of the times will contain nested nodes are the `<html>` and `<body>` tags.
* **Child nodes:** Child nodes have something in common, they have a parent. Examples of child nodes can be `<head>`, `<body>` and `<p>`
* **Sibling nodes:** Sibling nodes are nodes that are placed next to another node in the tree. A paragraph (`<p>`)node can be a sibling of a heading (`<h1>`) node.

### DOM nodes

A node is the minimal unit that a DOM tree is made of. Each element in a well formatted HTML will become a node. Nodes have properties and methods attached to them. During the creation of the DOM, the browser attaches the attributes, the HTML itself, the styles and the events to each node.

The browser then provides JavaScript (and other languages) with an API (Application Programming Interface) that will serve to modify, insert, alter or remove any node in the DOM tree. In fact, each node is an interface on its own.

Each node will inherit from the Node interface which contains some basic functionality attached to it. This functionality will be then accessible to the language (JavaScript in this case) to allow it to modify the node properties or read the current state of the node.

You can see a node like a box containing all kind of fun stuff you can play with, including other nodes (the nested nodes). Properties such as `[node].nodeName` or `[node].firstChild` and `[node].nextSibling`. 

### Access To Node

**`getElementsByTagName`**

```html
<div>
  <p>Proin a aliquet</p>
  <p>Nulla placerat</p>
</div>
```

```javascript
// Return all element
var nodeP = document.getElementsByTagName('p');
console.log(nodeP); //-> [p, p]

// Return specify by array position
var nodeP = document.getElementsByTagName('p')[0];
console.log(nodeP); //-> <p>Proin a aliquet</p>
```

**`getElementsByName`**

```html
<div>
  <p>Proin a aliquet</p>
  <p name="node_two">Nulla placerat</p>
</div>
```

```javascript
var nodeP = document.getElementsByName('node_two');
console.log(nodeP); //-> [p], <p>Nulla placerat</p>
```

**`getElementById`**

```html
<div>
  <p>Proin a aliquet</p>
  <p id="node_two">Nulla placerat</p>
</div>
```

```javascript
var nodeP = document.getElementById('node_two');
console.log(nodeP); //-> <p id="node_two">Nulla placerat</p>
```

**`querySelector`**

```html
<div>
  <p class="node_one">Proin a aliquet</p>
  <p id="node_two">Nulla placerat</p>
</div>
```

```javascript
var nodeClass = document.querySelector('#node_two');
console.log(nodeClass); //-> <p id="node_two">Nulla placerat</p>

var nodeId = document.querySelector('.node_one');
console.log(nodeId); //-> <p class="node_one">Proin a aliquet</p>
```

### Create and Delete Node

**Create**

```javascript
var container = document.getElementById('container');
var nodeP = document.createElement('p');
var nodePContext = document.createTextNode('Nulla placerat');

var result = nodeP.appendChild(nodePContext);

container.appendChild(result);
```

**Delete**

```html
<div>
  <div id="text">Nulla placerat</div>
  <div>Proin a aliquet</div>
</div>
```

```javascript
var nodePToDelete = document.getElementById('text');
nodePToDelete.parentNode.removeChild(nodePToDelete);
```

```html
<div>
  <div>Proin a aliquet</div>
</div>
```

### Access To Attribute Node

```html
<div>
  <a href="https://www.acelerisque.com">Acelerisque</a>
  <div id="div" data-name="Nulla placerat">Tristique scelerisque</div>
  <p class="cerat">Sed aliquet leo</p>
</div>
```

```javascript
var nodeA = document.getElementsByTagName('a')[0];
var nodeDiv = document.getElementsByTagName('div')[0];
var nodeDivId = document.getElementById('div');
var nodeP = document.getElementsByTagName('p')[0];

console.log(nodeA.href); //-> https://www.acelerisque.com/

// Access to style of the element.
nodeDiv.style.fontWeight = "900";

// Access by classname
console.log(nodeP.className); //-> cerat

// Access by dataset
console.log(nodeDivId.dataset.name); //-> Nulla placerat
```

## Browser Object Model (BOM)

Is a core object generated by the browser, allow us manipulate or interact with the browser core element.

### Window

The window object (global object), which is at the very top of the browser model hierarchy, can be thought of as the frame of the the browser and include scroll bars, navigator bars, and icons. And inside of the window object is the document object, this can be represented by the html page.

Window have five properties object are history, location, navigator, screen, and document properties.

**History**

The history property keeps track of the pages the user visits. History has a few methods including `back()` and `foward()`, to switch between pages the user has visited. The `go()` method which specifies how far foward or back in the history to go. And a `length()` property that shows how many pages are in the history stack.

```javascript
// This is like back button on browser.
window.history.go(-1);
```

**Location**

The location object displays information about the page’s location. It contains the page’s url, the server, port number of the server connection and the protocal used. This information is made available through the location object’s href, hostname, port, and protocol properties.

```javascript
const url = window.location.href;
console.log(url); //-> https://fiddle.jshell.net/

const protocol = window.location.protocol;
console.log(protocol); //-> https:
```

**Navigator**

Using the navigator method allows you to see information about the browser and the operating system. It’s propeties allow you to find out which browser, version, and operating system the user has. So that you are able to act on that information and make sure your code works only in browsers that support it. An important property of the navigator object is geolocation, which uses the geophysical position of the device or computer. The main method of geolocation is `getCurrentPosition()`. It requires a callback function that executes when `getCurrentPosition()` is done running.

```javascript
const appVersion = window.navigator.appVersion;
console.log(appVersion); //-> 5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36

const appLang = window.navigator.language;
console.log(appLang); //-> en-US
```

**Screen**

The screen property gives information about the display capabilities of the user’s machine, it includes the height and width properties. They display the vertical and horizontal range of the screen.

```javascript
const browserHeight = window.screen.height;
console.log(browserHeight); //-> 1080
```

### Window Method

Like javascript, the browser itself also has methods. Two example methods of the window are `alert()` and `prompt()`.

### Feature Window Detection

An if statement can be used to test if the browser supports a certain feature.

```javascript
if (typeof navigator.geolocation != “undefined”) { 
  // use geolocation
}
```

## Events

Event is something that the browser or user can interact with. One of the most important features of the DOM is that it provides you with event binding functionality out of the box.

Event binding is the act of attaching event listeners that will be triggered based upon actions on certain nodes in the Document Object Model.

With event binding you can listen for events and wait until the event is fired to act accordingly. Each node can listen to multiple events.

### Events Type

* **Browser Events:** a signal that something (an action) has happend in the browser.
* **Document Loading:** an action that takes place when the when the page loads up.
* **Event Handler Attachment:** attaching a handler to an event usually using the `.on` method.
* **Event Object:** is sent to a handler function as an argument.
* **Form Events:** takes place when an event is triggered pertaining to the form, like reset, search, etc.
* **Keyboard Events:** waiting for a press (up/down).
* **Mouse Events:** an event is triggered when the mouse is clicked.

In the following example we have a button, because this button is a node itself we can “attach” event listeners to it. The code will be explained in the comments.

```html
<button id="myButton">Say hi!</button>
```

### Events Handlers

**Inline Events**

Is attach events right into the DOM element. Developers realized that this wasn't a good idea. They started for a better separation of concerns. JavaScript should be moved to a `<script>` tag or .js file. This is generally what’s referred to as unobtrusive JavaScript.

* **Common events:**
* `onload // When the page loads.`
* `onclick // When a user clicks something.`
* `onmouseover // When a user mouses over something.`
* `onfocus // When a user puts the cursor in a form field.`
* `onblur // When a user leaves a form field.`
* `DOMContentLoaded // When your document's DOM has fully loaded.`
* `keydown // When you press down on a key on your keyboard.`
* `scroll // When an element is scrolled around.`

```javascript
<a onclick="console.log('Yay');">Link</a>
```
```javascript
function onload () {
  let button = document.getElementById('myButton')
  function onclick () {
    button.innerHTML = 'Hi!, you clicked me!'
  }
  
  button.addEventListener('click', onclick)
}

window.onload(onload)
```

**Event Listeners**

`addEventListener` function where it binds an element to a particular event. If you want to remove any applied event just call `removeEventListener`.

```javascript
element.addEventListener('click', doSomething, false);
```

Third optional parameter to control event bubbling.

### Event Bubbling

We have this html structure:

```html
<div id="one_a" class="item">
  <div id="two" class="item">
    <div id="three_a" class="item">
      <button id="buttonOne" class="item">one</button>
    </div>
    <div id="three_b" class="item">
      <button id="buttonTwo" class="item">two</button>
      <button id="buttonThree" class="item">three</button>
    </div>
  </div>
</div>
<div id="one_b" class="item"> 
</div>
```

And we attach a event to `buttonOne`, let's say that we click on the `buttonOne` element. When the DOM initiate an event, the event always starts at the root `window`, goes down until it hits the target in this case `buttonOne`, and then goes back up to the root `window`.

This entire journey is very formally defined:

* **Event Capturing Phase:** where you initiate the event and the event barrels down the DOM from the root `window`.
* **Event Bubbling Phase:** where your event bubbles back up to the root `window`.

Why this is important?

Event bubbling work like this. If an element A and that element is contained within element B, and element A is clicked, the click event fires for element A and then it will bubble up and fire for element B. This occurs because technically you are clicking both elements.

Example:

```javascript
// If you click innerDiv, they will fired: two, three_b, buttonThree
innerDiv = document.getElementById("buttonThree");
innerDiv.addEventListener("click",function(){
  console.log("buttonThree");
});

outterDiv = document.getElementById("three_b");
outterDiv.onclick = function() {
  console.log("three_b");
};

containerDiv = document.getElementById("two");
containerDiv.onclick = function() {
  console.log("two");
}
```

To avoid this conflict we need to used `event.stopPropagation();` this function is hiding in the shadows to kill the event on specific point. 

```javascript
innerDiv = document.getElementById("buttonThree");
innerDiv.addEventListener("click",function(event){
  console.log("buttonThree");
  event.stopPropagation();
}); //-> buttonThree
```

This fixing resolve the conflict and allow us to only fired event from specifying an element trigger.

### `event.preventDefault()`

Another function that lives on your event object.  Many HTML elements exhibit a default behavior when you interact with them. For example, clicking in a textbox gives that textbox focus with a little blinking text cursor appearing. Using your mouse wheel in a scrollable area will scroll in the direction you are scrolling. Clicking on a checkbox will toggle the checked state on or off. All of these are examples of built-in reactions to events your browser instinctively knows what to do about.

If you want to turn off this default behavior, you can call the `.preventDefault()` function. 

### Event Arguments and Event Type

Your event handler does more than just get called when an event gets overheard by an event listener. It also provides access to the underlying event object as part of its arguments. To access this event object easily, we need to modify your event handler signature to support this argument.

```javascript
function myEventHandler(e) {
  // e <- event object
  // event handlery stuff
}
```

This event object contains properties that are relevant to the event that was fired. Some of the popular properties from the Event type that you will use are:

* `currentTarget`
* `target`
* `preventDefault`
* `stopPropagation`
* `type`
