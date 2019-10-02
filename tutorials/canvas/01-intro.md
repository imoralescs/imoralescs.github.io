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
      document.addEventListener('DOMContentLoaded', init);
    }
  </code>
</pre>

<h2 class="tutorials-content__sub-title">Contenido Canvas (Canvas Context)</h2>

<p class="tutorials-content__text">En el desarrollo de aplicaciones con Canvas es necesario tener un contenido canvas para poder dibujar. Esto es posible ya que el metodo getContext() nos devuelve el contenido del canvas el cual estamos trabajando. A este metodo se le puede pasar un parametro para especificar que tipo de contenido deseamos. Los parametros validos para este metodos son:</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element">2d : Usado para canvas.</li>
  <li class="tutorials-content__list-element">webgl : Usado para graficas 3 dimensiones.</li>
  <li class="tutorials-content__list-element">webgl2 : Usado para graficas 3 dimensiones, segunda version.</li>
  <li class="tutorials-content__list-element">bitmaprenderer : Usado para ImageBitmap.</li>
</ul>
