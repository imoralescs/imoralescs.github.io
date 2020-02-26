---
layout: tutorials
title: Classes
---
<h2 class="tutorials-content__sub-title">Classes</h2>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">classList</code></h3>

<p class="tutorials-content__text">JavaScript proporciona la funciones <code class="tutorials__code">classList</code> que nos permite manipular las clases que se encuentran en nuestro DOM. Podemos agregar clases, eliminar clases, alternar clases y buscar clases en elementos.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section');

  // Add a class
  element.classList.add('section-color');

  // Remove a class
  element.classList.remove('section');

  // Toggle a class
  element.classList.toggle('section');

  // Check if an element has a class
  if(element.classList.contains('section')) {
    console.log('class in element'); //-> class in element
  }
  </code>
</pre>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">className</code></h3>

<p class="tutorials-content__text">Puede usar className para obtener todas las clases en un elemento como una cadena de caracteres, agregar una clase, reemplazar o eliminar completamente todas las clases.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section');

  // Get all of the classes on an element
  let elementClasses = element.className;
  console.log(elementClasses); //-> section

  // Add a class to an element
  element.className += ' section-color';

  // Completely replace all classes on an element
  element.className = ' section-blue';
  </code>
</pre>
