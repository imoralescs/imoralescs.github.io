---
layout: tutorials
title: Conceptos basicos de HTML5 Canvas, Rectangulo y Figuras
---
<h2 class="tutorials-content__sub-title">Canfigurar HTML Canvas</h2>

<p class="tutorials-content__text">Para comenzar con Canvas, necesitas utilizar la etiqueta HTML &lt;canvas&gt;. Luego dentro de la etiqueta podemos especificar ancho y largo del elemento, estas medidas deben ser especificadas en pixeles.</p>

<pre>
  <code class="language-html">
    &lt;canvas id="my-canvas" width="400" height="200"&gt;&lt;canvas&gt;
  </code>
</pre>

<p class="tutorials-content__text">Otra manera de configurar ancho y largo del elemento canvas es por medio de JavaScript.</p>

<pre>
  <code class="language-javascript">
    let canvas = document.getElementById('display')
    canvas.width  = 400
    canvas.height = 200
  </code>
</pre>

<p class="tutorials-content__text">El elemento canvas es soportado por la mayoria de los exploradores de nueva generacion, pero existen ocasiones que no todos soportan. Como programadores debemos notificarle al usuario que su explorador necesita ser actualizado o de lo contrario no podran utilizar nuestra aplicacion con elementos canvas.</p>

<pre>
  <code class="language-html">    
    &lt;canvas id='display'&gt;
      &lt;!-- Browsers which not supported HTML5 canvas will display the content below --&gt;
      Sorry, HTML5 Canvas is not supported in this browser!
    &lt;/canvas&gt;
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Cargar aplicacion de canvas</h3>

<p class="tutorials-content__text">JavaScript necesita asegurar que todos los elemento de la aplicacion esten listo para ejecutar la aplicacion de manera satifactoria, es por esta razon que debemos crear esta verificacion de que todo este listo para ejecutar.</p>

<pre>
  <code class="language-javascript">
    const init = () => {
      let canvas = document.getElementById('display')
      canvas.width  = 400
      canvas.height = 200
      canvas.classList.add('display-400-200')
    }
    
    if(document.readyState !== 'loading') {
      init()
    } 
    else {
      document.addEventListener('DOMContentLoaded', init)
    }
  </code>
</pre>

<h2 class="tutorials-content__sub-title">Contenido Canvas (Canvas Context)</h2>

<p class="tutorials-content__text">En el desarrollo de aplicaciones con Canvas es necesario tener un contenido canvas para poder dibujar. Esto es posible ya que el metodo getContext() nos devuelve el contenido del canvas el cual estamos trabajando. A este metodo se le puede pasar un parametro para especificar que tipo de contenido deseamos. Los parametros validos para este metodos son:</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element"><span class="tutorials__code">2d</span> - Usado para canvas.</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">webgl</span> - Usado para graficas 3 dimensiones.</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">webgl2</span> - Usado para graficas 3 dimensiones, segunda version.</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">bitmaprenderer</span> - Usado para ImageBitmap.</li>
</ul>

<pre>
  <code class="language-javascript">
    const init = () => {
      let canvas = document.getElementById('display')
      canvas.width  = 400
      canvas.height = 200
      canvas.classList.add('display-400-200')
      
      let display = canvas.getContext('2d')
      display.fillRect(50, 50, 100, 100)
    }
    
    if(document.readyState !== 'loading') {
      init()
    }
    else {
      document.addEventListener('DOMContentLoaded', init)
    }
  </code>
</pre>

<p class="tutorials-content__text">El origin de los puntos en canvas son x = 0 y y = 0. Estos punto se lee de la siguiente forma, izquierda tope del elemento canvas.</p>

<h2 class="tutorials-content__sub-title">Dibujando un rectangulo</h2>

<p class="tutorials-content__text">Canvas nos provee lo siguientes metodos para dibujar un rectangulo.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element"><span class="tutorials__code">fillRect(x, y, width, height)</span> - LLenar un rectangulo comenzando en la posicion x, y con acho y largo.</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">strokeRect(x, y, width, height)</span> - LLenar el contorno de rectangulo comenzando en la posicion x, y con acho y largo.</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">clearRect()</span> - Borra el área especificada y la hace completamente transparente.</li>
</ul>

<pre>
  <code class="language-javascript">
    const init = () => {
      let canvas = document.getElementById('display')
      canvas.width  = 400
      canvas.height = 200
      canvas.classList.add('display-400-200')
      
      let display = canvas.getContext('2d')
      display.fillRect(50, 50, 100, 100)
      display.strokeRect(200, 100, 50, 50)
    }
    
    if(document.readyState !== 'loading') {
      init()
    } 
    else {
      document.addEventListener('DOMContentLoaded', init)
    }
  </code>
</pre>

<h2 class="tutorials-content__sub-title">Propiedades de canvas</h2>

<p class="tutorials-content__text">El objeto de contexto Canvas tiene propiedades, por ejemplo fillStyle y strokeStyle. Al dibujar formas rellenas, ingrese un código de color en la propiedad fillStyle, cambiará el estilo de las formas rellenas.</p>

<pre>
  <code class="language-javascript">
    const init = () => {
      let canvas = document.getElementById('display')
      canvas.width  = 400
      canvas.height = 200
      canvas.classList.add('display-400-200')
      
      let display = canvas.getContext('2d')
      display.fillStyle = '#FA293E'
      display.fillRect(50, 50, 100, 100)
      
      display.strokeStyle = '#F3E02F'
      display.strokeRect(200, 100, 50, 50)
    }
    
    if(document.readyState !== 'loading') {
      init()
    }
    else {
      document.addEventListener('DOMContentLoaded', init)
    }
  </code>
</pre>

<h2 class="tutorials-content__sub-title">Dibujar lineas y caminos</h2>

<p class="tutorials-content__text">Todo lo que no sea rectangular que desee dibujar en Canvas debe crearse con una ruta. Una ruta o camino es una lista de puntos conectados por lineas rectas o curvas. Pueden ser abiertos o cerrados y cada segmento de la ruta puede tener un estilo diferente. Para hacer una forma usando ruta, hay tres pasos:</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element">Crea el camino</li>
  <li class="tutorials-content__list-element">Dibujar en el camino</li>
  <li class="tutorials-content__list-element">Trace o llenar el camino para representarlo.</li>
</ul>

<p class="tutorials-content__text">Para hacer esto utilizamos los siguientes metodos que provee Canvas:</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element"><span class="tutorials__code">beginPath()</span> - Esto crea una nueva ruta</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">moveTo(x, y)</span> - Mueves la posicion de dibujo a la indicada por los punto x, y.</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">lineTo(x, y)</span> - Traza linea de punto inicial al indicado por el metodo.</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">closePath()</span> - Agrega una linea recta a la ruta entre la posicion actual y inicio.</li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">stroke()</span> - </li>
  <li class="tutorials-content__list-element"><span class="tutorials__code">fill()</span> - Rellena de color la figura creada por las lineas.</li>
</ul>

<pre>
  <code class="language-javascript">
    const backgroundScale = 'display-400-200'
    const removeScale = document.getElementById('removeScale')
    
    removeScale.addEventListener('click', function(event) {
      let canvas = document.getElementById('display')
      canvas.classList.toggle(backgroundScale)
    })
    
    const init = () => {
      let canvas = document.getElementById('display')
      canvas.width  = 400
      canvas.height = 200
      canvas.classList.add(backgroundScale)
      
      let display = canvas.getContext('2d')
      display.strokeStyle = '#FA293E'
      display.lineWidth = 2
      display.beginPath()
      display.moveTo(50, 50)
      display.lineTo(150, 50)
      display.lineTo(50, 150)
      display.closePath()
      display.stroke()
    }
    
    if(document.readyState !== 'loading') {
      init()
    }
    else {
      document.addEventListener('DOMContentLoaded', init)
    }
  </code>
</pre>
