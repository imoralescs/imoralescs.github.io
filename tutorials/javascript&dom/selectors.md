---
layout: tutorials
title: Selectors "Selectores"
---
<h2 class="tutorials-content__sub-title">Selectors "Selectores"</h2>

<p class="tutorials-content__text">Obtener elementos en el DOM "Document Object Model"</p>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">querySelectorAll()</code></h3>

<p>Utilizamos la funcion <code class="tutorials__code">document.querySelectorAll()</code> para encontrar todos los elementos coincidentes en una página. Puede usar cualquier selector CSS válido.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" data-section="1"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="2"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="3"&#62;&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  // Get all elements with tag section
  let selectAllSections = document.querySelectorAll('section');

  // Get all elements with class
  let selectAllByClass = document.querySelectorAll('.section');

  // Get all elements with data-attribute
  let selectAllDataAttr = document.querySelectorAll('[data-section]');

  console.dir(selectAllSections); //-> NodeList(3);
  console.dir(selectAllByClass); //-> NodeList(3)
  console.dir(selectAllDataAttr); //-> NodeList(3)
  </code>
</pre>
