# Document Object Model (DOM)

In application is an HTML, XML or SVG document, when a web page is loaded, the browser creates the DOM of the page. Is basically an object they contain every element of the page inside it. The DOM is constructed as a tree of object and each object represents an element of the page. And each element is an object.

## DOM Structure

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

## Searching `getElemet*` and `querySelector*`

### `document.getElementById`

If an element has the `id` attribute, then there’s a global variable by the name from that `id`.

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

### `getElementsByTagName`

Looks for elements with the given `tag` and returns the collection of them. The tag parameter can also be a star "*" for “any tags”.

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

### `getElementsByClassName`

Returns elements that have the given CSS `class`. Elements may have other classes too.

```html
<form name="my-form">
  <div class="article">Article</div>
  <div class="long article">Long article</div>
</form>
```

```javascript
let nodeClass = document.getElementsByClassName('article');
console.log(nodeClass); //-> [div.article, div.long.article]
```

### `getElementsByName`

Returns elements with the given name attribute, document-wide. Exists for historical reasons, very rarely used, we mention it here only for completeness.

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

### `querySelector`

The call to `elem.querySelector(css)` returns the first element for the given CSS selector. In other words, the result is the same as `elem.querySelectorAll(css)[0]`, but the latter is looking for all elements and picking one, while `elem.querySelector` just looks for one. So it’s faster and shorter to write.

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

### `querySelectorAll`

The call to elem.querySelectorAll(css) returns all elements inside elem matching the given CSS selector. That’s the most often used and powerful method. Here we look for all `<li>` elements that are last children:

```html
<ul>
  <li>The</li>
  <li>test</li>
</ul>
<ul>
  <li>has</li>
  <li>passed</li>
</ul>
```

```javascript
let nodeFirstLI = document.querySelectorAll('ul > li:last-child');
console.log(nodeFirstLI); //-> [li, li]
```

### `matches`

Previous methods were searching the DOM. The `elem.matches(css)` does not look for anything, it merely checks if elem matches the given CSS-selector. It returns true or false. The method comes handy when we are iterating over elements (like in array or something) and trying to filter those that interest us.

```html
<a href="http://example.com/file.zip">...</a>
<a href="http://ya.ru">...</a>
```

```javascript
for (let elem of document.body.children) {
  if (elem.matches('a[href$="zip"]')) {
    console.log("The archive reference: " + elem.href );
  }
}
//-> The archive reference: http://example.com/file.zip
```

### `closest`

All elements that are directly above the given one are called its ancestors. In other words, ancestors are: parent, the parent of parent, its parent and so on. The ancestors together form the chain of parents from the element to the top. The method `elem.closest(css)` looks the nearest ancestor that matches the CSS-selector. The elem itself is also included in the search. In other words, the method closest goes up from the element and checks each of parents. If it matches the selector, then the search stops, and the ancestor is returned.

```html
<h1>Contents</h1>

<div class="contents">
  <ul class="book">
    <li class="chapter">Chapter 1</li>
    <li class="chapter">Chapter 1</li>
  </ul>
</div>
```

```javascript
let nodeChapter = document.querySelector('.chapter'); 

console.log(nodeChapter.closest('.book')); //-> <ul class="book">...</ul>
console.log(nodeChapter.closest('.contents')); //-> <div class="contents">...</div>
console.log(nodeChapter.closest('h1')); //-> null (because h1 is not an ancestor)
```
## Node Properties

### DOM node classes

DOM nodes have different properties depending on their class. The classes are:

* **EventTarget:** is the root “abstract” class. Objects of that class are never created. It serves as a base, so that all DOM nodes support so-called “events”, we’ll study them later.
* **Node:** is also an “abstract” class, serving as a base for DOM nodes. It provides the core tree functionality: parentNode, nextSibling, childNodes and so on (they are getters). Objects of Node class are never created. But there are concrete node classes that inherit from it, namely: Text for text nodes, Element for element nodes and more exotic ones like Comment for comment nodes.
* **Element:** is a base class for DOM elements. It provides element-level navigation like nextElementSibling, children and searching methods like getElementsByTagName, querySelector. In the browser there may be not only HTML, but also XML and SVG documents. The Element class serves as a base for more specific classes: SVGElement, XMLElement and HTMLElement.
* **HTMLElement:** is finally the basic class for all HTML elements. It is inherited by various HTML elements:
  * **HTMLInputElement** the class for `<input>` elements.
  * **HTMLBodyElement:** the class for `<body>` elements.
  * **HTMLAnchorElement:** the class for `<a>` elements.

…and so on, each tag has its own class that may provide specific properties and methods.

### `innerHTML` contents

The innerHTML property allows to get the HTML inside the element as a string. We can also modify it. So it’s one of most powerful ways to change the page.

```javascript
document.body.innerHTML = 'Lorem Ipsum!';
```

**`innerHTML+=` not do full overwrite**

```javascript
document.body.innerHTML += 'Ipsum';
document.body.innerHTML += 'Lorem';
```

### `outerHTML` full HTML of the element

The outerHTML property contains the full HTML of the element. That’s like innerHTML plus the element itself. Unlike innerHTML, writing to outerHTML does not change the element. Instead, it replaces it as a whole in the outer context. 

```javascript
var nodeOuter = document.getElementById('elem');
console.log(nodeOuter.outerHTML); //-> <div id="elem">Hello<b>World</b></div>
```
## Attributes and properties

### HTML Attribute

In HTML language, tags may have attributes. When the browser reads HTML text and creates DOM objects for tags, it recognizes standard attributes and creates DOM properties from them.

```html
<div id="elem">Hello World</div>
```

```javascript
var nodeOuter = document.getElementById('elem');
console.log(nodeOuter.id); //-> elem
```

So, if an attribute is non-standard, there won’t be DOM-property for it. All attributes are accessible using following methods:

* **`elem.hasAttribute(name)`:** checks for existance.
* **`elem.getAttribute(name)`:** gets the value.
* **`elem.setAttribute(name, value)`:** sets the value.
* **`elem.removeAttribute(name)`:** removes the attribute.

```html
<div id="elem">Hello World</div>
```

```javascript
var nodeElem = document.getElementById('elem');

console.log(nodeElem.getAttribute('id')); //-> elem
nodeElem.setAttribute('id', 'elem-02');
console.log(nodeElem.id); //-> elem-02
```

### Non-standard Attributes, Dataset

All attributes starting with `data-` are reserved for programmers’ use. They are available in dataset property.

```html
<div id="elem" data-about="Elephants"></div>
```

```javascript
var nodeByData = document.getElementById('elem');
console.log(nodeByData.dataset.about); //-> Elephants
```

## Modifying the document

DOM modifications is the key to create “live” pages. Here we’ll see how to create new elements “on the fly” and modify the existing page content.

### Create 

To create DOM nodes, there are two methods:

```javascript
var container = document.getElementById('container');
var nodeP = document.createElement('p');
var nodePContext = document.createTextNode('Nulla placerat');

var result = nodeP.appendChild(nodePContext);

container.appendChild(result);
```

### Insertion

```javascript
let nodeId = document.getElementById('elem');
let nodeDiv = document.createElement('div');

nodeDiv.className = "new-div";
nodeDiv.innerHTML = "<p>Lorem Ipsum</p>";

nodeId.appendChild(nodeDiv);
```

* **`parentElem.appendChild(node)`:** appends node as the last child of parentElem.
* **`parentElem.insertBefore(node, nextSibling)`:** anserts node before nextSibling into parentElem.
* **`parentElem.replaceChild(node, oldChild)`:** replaces oldChild with node among children of parentElem.

### prepend/append/before/after

This set of methods provides more flexible insertions:

* **`node.append(...nodes or strings)`:** append nodes or strings at the end of node.
* **`node.prepend(...nodes or strings)`:** insert nodes or strings into the beginning of node.
* **`node.before(...nodes or strings)`:** insert nodes or strings before the node.
* **`node.after(...nodes or strings)`:** insert nodes or strings after the node.
* **`node.replaceWith(...nodes or strings)`:** replaces node with the given nodes or strings.

### insertAdjacentHTML/Text/Element

There’s another, pretty versatile method: `elem.insertAdjacentHTML(where, html)`. The first parameter is a string, specifying where to insert, must be one of the following:

* **`beforebegin`:** insert html before elem.
* **`afterbegin`:** insert html into elem, at the beginning.
* **`beforeend`:** insert html into elem, at the end.
* **`afterend`:** insert html after elem.

### Cloning Nodes `cloneNode`

```javascript
let nodeId = document.getElementById('elem');
let cloneNodeId = nodeId.cloneNode(true);

nodeId.appendChild(cloneNodeId);
```

### Delete or Removal

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

### Document Write

The call to document.write(html) writes the html into page “right here and now”. The html string can be dynamically generated, so it’s kind of flexible. We can use JavaScript to create a full-fledged webpage and write it.

```javascript
let nodeId = document.getElementById('elem');
nodeId.appendChild(document.write('<b>Lorem Ipsum</b>'));
```

## Styles and Classes

### className and classList

**className**

className return class and allow you completly overwrite.

```html
<div class="main-page">main</div>
```

```javascript
let nodeClass = document.getElementsByTagName('DIV')[0];
console.log(nodeClass.className); //-> main-page
nodeClass.className = 'secondary-page';
console.log(nodeClass.className); //-> secondary-page
```

**classList**

The `elem.classList` is a special object with methods to add/remove/toggle classes.

```javascript
let nodeClass = document.getElementsByTagName('DIV')[0];
nodeClass.classList.add('container');
console.log(nodeClass.className); //-> main-page container
```

So we can operate both on the full class string using className or on individual classes using `classList`. What we choose depends on our needs.

Methods of classList:

* **`elem.classList.add/remove("class")`:** adds/removes the class.
* **`elem.classList.toggle("class")`:** if the class exists, then removes it, otherwise adds it.
* **`elem.classList.contains("class")`:** returns true/false, checks for the given class.


### Element style

The property elem.style is an object that corresponds to what’s written in the "style" attribute. Setting `elem.style.width="100px"` works as if we had in the attribute `style="width:100px"`.

```javascript
let nodeClass = document.getElementsByTagName('DIV')[0];
nodeClass.style.color = 'red';
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

Event is something that the browser or user can interact with. One of the most important features of the DOM is that it provides you with event binding functionality out of the box. An event is a signal that something has happened. All DOM nodes generate such signals (but events are not limited to DOM).

Event binding is the act of attaching event listeners that will be triggered based upon actions on certain nodes in the Document Object Model.

With event binding you can listen for events and wait until the event is fired to act accordingly. Each node can listen to multiple events.

### Events Type

Here a list of the most useful DOM events.

* **Browser Events:** a signal that something (an action) has happend in the browser.
* **Document Loading:** an action that takes place when the when the page loads up.
  * `DOMContentLoaded` : when the HTML is loaded and processed, DOM is fully built.
* **Event Handler Attachment:** attaching a handler to an event usually using the `.on` method.
* **Event Object:** is sent to a handler function as an argument.
* **Form Events:** takes place when an event is triggered pertaining to the form, like reset, search, etc.
  * `submit` : when the visitor submits a `<form>`.
  * `focus` : when the visitor focuses on an element, e.g. on an `<input>`.
* **Keyboard Events:** waiting for a press (up/down).
  * `keydown` and `keyup` : when the visitor presses and then releases the button.
* **Mouse Events:** an event is triggered when the mouse is clicked.
  * `click` : when the mouse clicks on an element (touchscreen devices generate it on a tap).
  * `contextmenu` : when the mouse right-clicks on an element.
  * `mouseover` : when the mouse cursor comes over an element.
  * `mousedown` and `mouseup` : when the mouse button is pressed and released over an element.
  * `mousemove` : when the mouse is moved.

In the following example we have a button, because this button is a node itself we can “attach” event listeners to it. The code will be explained in the comments.

```html
<button id="myButton">Say hi!</button>
```

### Events Handlers

To react on events we can assign a handler, a function that runs in case of an event. Handlers is a way to run JavaScript code in case of user actions.

There are several ways to assign a handler. Let’s see them, starting from the simplest one.

**Inline Events or HTML-attribute**

Is attach events right into the DOM element. Developers realized that this wasn't a good idea. They started for a better separation of concerns. JavaScript should be moved to a `<script>` tag or .js file. This is generally what’s referred to as unobtrusive JavaScript.

Example 1 HTML-attribute

```javascript
<a onclick="console.log('Yay');">Link</a>
```

Example 2 HTML-attribute:

```html
<button href="#" onclick="onClickLink()">Link</button>
```

```javascript
function onClickLink() {
  console.log('Yay');
}
```

Example DOM property

```html
<button>Link</button>
```

```javascript
let button = document.getElementsByTagName('button')[0];

function onClickButton() {
  console.log("Yayy");
}
  
button.onclick = onClickButton;
```

**Event Listeners**

The fundamental problem of the aforementioned ways to assign handlers, we can’t assign multiple handlers to one event. `addEventListener` function where it binds an element to a particular event. If you want to remove any applied event just call `removeEventListener`.

```javascript
element.addEventListener('click', doSomething, false);
```

Third optional parameter to control event bubbling.

**Event Object**

When an event happens, the browser creates an event object, puts details into it and passes it as an argument to the handler.

```html
<input type="button" value="Click Me" id="elem">
```

```javascript
let elem = document.getElementById('elem');

elem.onclick = function(event) {
  // show event type, element and coordinates of the click
  console.log(event.type + " at " + event.currentTarget);
  console.log(event.clientX + ":" + event.clientY);
};
```

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

### Event Delegation

Capturing and bubbling allow to implement one of most powerful event handling patterns called event delegation. The idea is that if we have a lot of elements handled in a similar way, then instead of assigning a handler to each of them, we put a single handler on their common ancestor. 

In the handler we get `event.target`, see where the event actually happened and handle it.

```html
<div id="menu">
  <button data-action="save">Save</button>
  <button data-action="load">Load</button>
  <button data-action="search">Search</button>
</div>
```

```javascript
class Menu {
  constructor(elem) {
	  this._elem = elem;
		elem.onclick = this.onClick.bind(this); // (*)
  }
	
	save() {
	  console.log('saving');
  }
	
	load() {
	  console.log('loading');
  }
	
	search() {
	  console.log('searching');
	}
	
	onClick(event) {
	  let action = event.target.dataset.action;
		if (action) {
		  this[action]();
		}
	};
}

new Menu(menu);
```

### Dispatching Custom Events

**Event constructor**

Events form a hierarchy, just like DOM element classes. The root is the built-in Event class. We can create Event objects like this:

```javascript
let event = new Event(event type[, options]);
```

Arguments:
* `event type` : may be any string, like "click" or our own like "hey-ho!".
* `options` : the object with two optional properties:
  * `bubbles` : true/false – if true, then the event bubbles.
  * `cancelable` : true/false – if true, then the “default action” may be prevented. Later we’ll see what it means for custom events.
  * By default both are false: {bubbles: false, cancelable: false}.

**dispatchEvent**

After an event object is created, we should “run” it on an element using the call `elem.dispatchEvent(event)`. Then handlers react on it as if it were a regular built-in event. If the event was created with the bubbles flag, then it bubbles.

```javascript
document.body.addEventListener("myEventName", doSomething, false);

function doSomething(event){
	console.log("Event is called: " + event.type);
}

let myEvent = new CustomEvent("myEventName");

document.body.dispatchEvent(myEvent); //-> Event is called: myEventName
```

## Forms and Controls

### Navigation Form and Elements

Document forms are members of the special collection `document.forms`. When we have a form, then any element is available in the named collection `form.elements`. There may be multiple elements with the same name, that’s often the case with radio buttons. In that case `form.elements[name]` is a collection

```html
<form name="myForm">
  <input name="one" value="1">
  <input name="two" value="2">
</form>
```

```javascript
// Get the form.
let form = document.forms.myForm;

// Get the element inside form.
let formElem = form.elements.one;
console.log(formElem.value); //-> 1
```

**Fieldsets as “subforms”**

A form may have one or many `<fieldset>` elements inside it. They also support the elements property.

```html
<form id="form">
  <fieldset name="userFields">
    <legend>info</legend>
    <input name="login" type="text">
  </fieldset>
</form>
```

```javascript
// Get the form.
let form = document.forms.form;

// Get the element inside form.
let formElem = form.elements.userFields;
console.log(formElem); //-> <fieldset name="userFields">...</fieldset>
```
### Form Event Handling

```html
<form id="register" novalidate>
  <label>Email</label>
  <input type="email" id="email" name="email"/>
  <label>Password</label>
  <input type="password_01" id="password_01" name="password_02"/>
  <label>Password Confirm</label>
  <input type="password_02" id="password_02" name="password_02"/>
  <button type="submit">Register</button>
</form>
```

```javascript
let form = {
  registerForm : document.getElementById('register'),
  emailField : document.getElementById('email'),
  password_01_Field : document.getElementById('password_01'),
  password_02_Field : document.getElementById('password_02')
};

let emailPattern = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/;
let checkForm = function(event){
  let msg = "";
  
  // Check Email
  !emailPattern.test(form.emailField.value) ? msg += "\nyour email": msg += "";
  
  // Check Password
  form.password_01_Field.value == "" || form.password_01_Field.value != form.password_02_Field.value ? msg += "\nyou password" : msg += "";
  
  // Complete Message
  msg != "" ? msg = "Please check: " + msg : msg = 'Form is valid!\nSubmitting...';
  console.log(msg);
  event.preventDefault();
}

form.registerForm.addEventListener('submit', checkForm);
```

### Form Elements

**input** and **textarea**

Normally, we can access the value as `input.value` or `input.checked` for checkboxes.

**select** and **option**

A `<select>` element has 3 important properties:

* **`select.options`:** the collection of `<option>` elements.
* **`select.value`:** the value of the chosen option.
* **`select.selectedIndex`:** the number of the selected option.

So we have three ways to set the value of a `<select>`:

* Find the needed `<option>` and set `option.selected` to true.
* Set `select.value` to the value.
* Set `select.selectedIndex` to the number of the option.

```html
<select id="select" multiple>
  <option value="blues" selected>Blues</option>
  <option value="rock" selected>Rock</option>
  <option value="classic">Classic</option>
</select>
```

```javascript
let selectField = document.getElementById('select');
let selected = Array.from(selectField);
let result = selected
              .filter(option => option.selected)
              .map(option => option.value);

console.log(result);
```

### Events focus/blur

**Focus**

An element receives a focus when the user either clicks on it or uses the Tab key on the keyboard. There’s also an autofocus HTML attribute that puts the focus into an element by default when a page loads and other means of getting a focus.

Focusing generally means: **prepare to accept the data here**, so that’s the moment when we can run the code to initialize or load something.

**Blur**

The moment of loosing the focus "blur" can be even more important. That’s when a user clicks somewhere else or presses Tab to go to the next form field, or there are other means as well.

Loosing the focus generally means: **the data has been entered**, so we can run the code to check it or even to save it to the server and so on.

```html
Your email please:<input type="email" id="input">
<div id="error"></div>
```

```css
.invalid {
  border-color: red;
}

#error {
  color: red
}
```

```javascript
let input = document.getElementById('input');
let error = document.getElementById('error');

// Add error message when blur
input.onblur = function() {
  if (!input.value.includes('@')) {
    input.classList.add('invalid');
    error.innerHTML = 'Please enter a correct email.'
  }
};

// Remove error message when focus.
input.onfocus = function() {
  if (this.classList.contains('invalid')) {
    this.classList.remove('invalid');
    error.innerHTML = "";
  }
};
```

### Form Submission

The submit event triggers when the form is submitted, it is usually used to validate the form before sending it to the server or to abort the submission and process it in JavaScript.

The method `form.submit()` allows to initiate form sending from JavaScript. We can use it to dynamically create and send our own forms to server.

```html
<form id="register" novalidate>
  <label>Email</label>
  <input type="email" id="email" name="email"/>
  <label>Password</label>
  <input type="password_01" id="password_01" name="password_02"/>
  <label>Password Confirm</label>
  <input type="password_02" id="password_02" name="password_02"/>
  <button type="submit">Register</button>
</form>
```

```javascript
let form = {
  registerForm : document.getElementById('register'),
  emailField : document.getElementById('email'),
  password_01_Field : document.getElementById('password_01'),
  password_02_Field : document.getElementById('password_02')
};

let emailPattern = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/;
let checkForm = function(event){
  let msg = "";
	
  // Check Email
  !emailPattern.test(form.emailField.value) ? msg += "\nyour email": msg += "";
	
  // Check Password
  form.password_01_Field.value == "" || form.password_01_Field.value != form.password_02_Field.value ? msg += "\nyou password" : msg += "";
	
  // Complete Message
  msg != "" ? msg = "Please check: " + msg : msg = 'Form is valid!\nSubmitting...';
  console.log(msg);
  event.preventDefault();
}

form.registerForm.addEventListener('submit', checkForm);
```
