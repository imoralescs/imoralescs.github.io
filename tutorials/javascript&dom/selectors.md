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

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">querySelector()</code></h3>

<p>Utilizamos la funcion <code class="tutorials__code">document.querySelector()</code> para encontrar el primer elemento coincidente en una página. Puede usar cualquier selector CSS válido.</p>

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
  let selectFirstSection = document.querySelector('section');

  // Get all elements with data-attribute
  let selectDataAttr = document.querySelector('[data-section="2"]');

  console.dir(selectFirstSection); //-> section.section
  console.dir(selectDataAttr); //-> section.section
  </code>
</pre>

<p>Si en el momento de encontrar algun elemento y este no existe en documento, la funcion nos devuelve el valor de nulo. Para esta situacion podemos utilizar condiciones para evitar valores nulos.</p>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">getElementById()</code></h3>

<p>Utilizamos la funcion <code class="tutorials__code">getElementById()</code> para encontrar el elemento coincidente al identificador.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" data-section="1"&#62;&#60;/section&#62;
  &#60;section in="section_2" class="section" data-section="2"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="3"&#62;&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let selectById = document.getElementById('section_2');

  console.dir(selectById); //-> section#section_2.section
  </code>
</pre>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">getElementsByClassName()</code></h3>

<p>Utilizamos la funcion <code class="tutorials__code">getElementsByClassName()</code> para encontrar todos los elementos coincidente a clase o grupos de clases.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" data-section="1"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="2"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="3"&#62;&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let selectByClass = document.getElementsByClassName('section');

  console.dir(selectByClass); //-> HTMLCollection(3)
  </code>
</pre>

<p>Importante que esta funcion devuelve una colección de elementos HTML en tiempo real. Si se agrega o elimina algun elemento del DOM después de definir dentro de variable, la coleccion se actualiza automáticamente para reflejar el DOM actual.</p>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">getElementsByTagName()</code></h3>

<p>Utilizamos la funcion <code class="tutorials__code">getElementsByTagName()</code> para encontrar todos los elementos coincidente a etiqueta HTML.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" data-section="1"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="2"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="3"&#62;&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let selectByTag = document.getElementsByTagName('section');

  console.dir(selectByTag); //-> HTMLCollection(3)
  </code>
</pre>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">matches()</code></h3>

<p>Utilizamos la funcion <code class="tutorials__code">getElementsByTagName()</code> para verificar si un elemento sería seleccionado por un selector particular o un conjunto de selectores. Devuelve verdadero si el elemento es una coincidencia o existe en el DOM, y falso cuando no.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" data-section="1"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="2"&#62;&#60;/section&#62;
  &#60;section class="section" data-section="3"&#62;&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let selectById = document.querySelector('#section_2');

  if(selectById.matches('.section')) {
    console.log('It matches!');
  }
  else {
    console.log('Not a match!');
  }
  //-> It matches!
  </code>
</pre>
