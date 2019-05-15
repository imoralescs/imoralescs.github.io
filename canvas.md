# Canvas

Canvas is a 2D drawing API. Essentially the browser gives you a rectanglar area on the screen that you can draw into. You can draw lines, shapes, images, text; pretty much anything you want.

### HTML Canvas Tag

First we need to know how to setup a canvas. By using a canvas tag, you can specify it width and height property (width and height units are in pixels.). Other way to do this is by using Javascript, adding a ID selector to the Canvas HTML tag and query this tag by id. After grabbing the DOM element we can specify the width and height. 

```
let 
	canvas = document.getElementById('display'),
  display = canvas.getContext('2d')

display.width = 600
display.height = 300
```

### Draw Canvas After Document Loaded

In JavaScript, we need to ensure that the canvas will display our graphic, so we should draw canvas after the HTML document is loaded. You can done with Vanilla JavaScript.

## 2D Basic Shapes

### Canvas Context

In HTML Canvas, we need to have a canvas context object to draw canvas. We based on drawing 2D graphics, which means there are 3D context based on WebGL. However, we will focus on drawing 2D graphics, let’s create the 2D canvas context object.

The '''CanvasRenderingContext2D''' interface is used for drawing rectangles, text, images and other objects onto the canvas element. It provides the 2D rendering context for the drawing surface of a <canvas> element.
  
```
let 
	canvas = document.getElementById('display'),
  display = canvas.getContext('2d')

display.width = 600
display.height = 300
```

### Coordinate in Canvas
