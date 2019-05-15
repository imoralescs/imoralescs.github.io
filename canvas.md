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

![](https://raw.githubusercontent.com/imoralescs/imoralescs.github.io/master/images/Coordinate%20System%20in%20HTML%20Canvas.png)

In order to know where to draw your graphic, the illustration shows the coordination of the canvas. Both width and height are in unit of pixels. The origin (point (x = 0, y = 0)) is at the left-top side of the canvas. The white square is located at about (x = 15, y =15).

Before we draw a pattern, we must know where we will draw the pattern. The above figure is a schematic diagram of the coordinate system of Canvas. The coordinate units of both axes are pixels, and the upper left corner of Canvas is its origin (coordinates (x = 0, y = 0)). Then the white square coordinates in the diagram are (x = 15, y = 15).

### Drawing a Rectangle

Canvas provide a simple method to draw rectangle, which is ```fillRect()``` method or ```strokeRect()``` method. The ```fillRect()``` method draws a filled rectangle and the ```strokeRect()``` method draws the outline of a rectangle. Both of the method need the specify four parameters, the position X, position Y of the rectangle and both the width and height of the rectangle.

```
let 
  canvas = document.getElementById('display'),
  display = canvas.getContext('2d')

display.fillRect(100, 100, 400, 300)
display.strokeRect(50, 250, 50, 50)
```

Canvas context object has two properties, they are ```fillStyle``` and ```strokeStyle```. When drawing filled shapes, input a colour code into ```fillStyle``` property, it will change the style of the filled shapes. On the other hand, the ```strokeStyle``` property controls the stroked shapes.

The canvas background object has two properties, which can change the solid pattern and the style of the border pattern, respectively. ```fillStyle``` Can change the color of the solid pattern, and ```strokeStyle``` the pattern is changed border color.

```
let 
  canvas = document.getElementById('display'),
  display = canvas.getContext('2d')

display.fillStyle = '#DB2C12'
display.fillRect(100, 100, 400, 300)
```

### Drawing Lines (Paths)

First, we need to tell canvas we are going to draw a line by using the canvas context method ```beginPath()```, it requires no input parameter. ```beginPath()``` turns the canvas context object into a series of command that can draw lines.

Second, we need to move to the location where we need to start drawing line, with ```moveTo()``` method, it requires the position X and Y two parameters.

Third, with ```lineTo()``` method and specify the location position X and Y as two parameters, we can draw a line (from the location where we moved to), and you can always add more ```lineTo()``` command to draw more lines as you wish.

During drawing the lines, you can choose to close the path with ```closePath()``` method. The method connects the final position to the starting position with a line and returns the command state back to normal canvas context object.

Finally, you can choose ```stroke()``` method to make your lines (or paths) into outline, or you can use ```fill()``` method to fill the path into a solid filled shape. 

```
let 
  canvas = document.getElementById('display'),
  display = canvas.getContext('2d')
  
canvas.height = innerHeight
canvas.width = innerWidth

// Triangle
display.beginPath()
display.moveTo(10, 10)
display.lineTo(10, 200)
display.lineTo(200, 10)
display.closePath()
 
// Outline
display.lineWidth = 10
display.strokeStyle = '#008799'
display.stroke()
 
// Fill color
display.fillStyle = '#DB2C12'
display.fill()
```
