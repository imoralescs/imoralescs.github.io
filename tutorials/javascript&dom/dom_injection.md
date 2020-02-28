---
layout: tutorials
title: HTML
---
<h2 class="tutorials-content__sub-title">Inyección HTML</h2>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">innerHTML</code></h3>

<p class="tutorials-content__text">Usamos <code class="tutorials__code">.innerHTML</code> para obtener y establecer contenido HTML.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section');

  let content = element.innerHTML;

  console.log(content); //-> Section Content

  // Set HTML content
  element.innerHTML = "We can dynamically change the HTML.";

  // Add HTML to end
  element.innerHTML += " Add this after.";

  // Add HTML at beginning
  element.innerHTML = "We can add this before. " + element.innerHTML; 

  // Inject entire element
  element.innerHTML += "<p>A new paragraph</p>";
  </code>
</pre>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">createElement</code></h3>

<p class="tutorials-content__text"><code class="tutorials__code">createElement</code> nos permite, como su nombre lo indica, crear un nuevo elemento. Este es un nodo DOM totalmente manipulable, y podemos agregarle clases y atributos. Cuando estemos listos, usaremos <code class="tutorials__code">insertBefore()</code> para inyectarlo en el DOM.</p>
