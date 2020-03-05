---
layout: tutorials
title: DOM Traversing 
---

<h2 class="tutorials-content__sub-title">DOM Traversing "Atravesando el DOM"</h2>

<p class="tutorials-content__text">DOM es un árbol de elementos, con el nodo raíz, que apunta al nodo html, que a su vez apunta a la cabeza y el cuerpo de sus nodos elementos secundarios, y así sucesivamente. Desde cada uno de esos elementos, puede navegar por la estructura DOM y moverse a diferentes nodos.</p>

<h3 class="tutorials-content__sub-title">Recorriendo el DOM hacia abajo</h3>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">querySelector</code> y <code class="tutorials__code">querySelectorAll</code></h4>

<p class="tutorials-content__text"><code class="tutorials__code">querySelector</code> y <code class="tutorials__code">querySelectorAll</code> no se limitan solo a ejecutarse en el documento. Se pueden ejecutar en cualquier elemento para buscar solo elementos dentro de él.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section_1"&#62;Section Content&#60;/section&#62;
  &#60;section class="section" id="section_2"&#62;Section Content&#60;/section&#62;
  &#60;section class="section" id="section_3"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section_2');
  console.dir(element); //-> section#section_2.section

  let elements = document.querySelectorAll('section');
  console.dir(elements); //-> NodeList(3)
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">children</code></h4>

<p class="tutorials-content__text">Mientras <code class="tutorials__code">querySelector</code> y <code class="tutorials__code">querySelectorAll</code> buscan en todos los niveles dentro de una estructura DOM / HTML anidada, es posible que desee obtener descendientes inmediatos de un elemento en particular. Para esto utilizamos <code class="tutorials__code">children</code>.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section_1"&#62;Section Content&#60;a href="webpage"&#62;Link&#60;/a&#62;&#60;/section&#62;
  &#60;section class="section" id="section_2"&#62;Section Content&#60;/section&#62;
  &#60;section class="section" id="section_3"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section_1');
  let decendants = element.children;
  console.dir(decendants); //-> HTMLCollection(1)
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Recorriendo el DOM hacia arriba</h3>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">parentNode</code></h4>

<p class="tutorials-content__text">Utilizamos <code class="tutorials__code">parentNode</code> para obtener el padre de un elemento.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section_1"&#62;Section Content&#60;a href="webpage" id="link_1" &#62;Link&#60;/a&#62;&#60;/section&#62;
  &#60;section class="section" id="section_2"&#62;Section Content&#60;/section&#62;
  &#60;section class="section" id="section_3"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#link_1');
  let parent = element.parentNode;
  console.dir(parent); //-> section#section_1.section
  </code>
</pre>
