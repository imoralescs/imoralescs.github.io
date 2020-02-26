---
layout: tutorials
title: Attributes
---
<h2 class="tutorials-content__sub-title">Attributes</h2>

<h3 class="tutorials-content__sub-title"><code class="tutorials__code">getAttribute()</code>, <code class="tutorials__code">setAttribute()</code>, and <code class="tutorials__code">hasAttribute()</code></h3>

<p class="tutorials-content__text"><code class="tutorials__code">getAttribute()</code>, <code class="tutorials__code">setAttribute()</code>, and <code class="tutorials__code">hasAttribute()</code> los métodos le permiten obtener, establecer y verificar la existencia de atributos (incluidos los atributos de datos) en un elemento.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section" data-value="main"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section');

  // Get value of an attribute
  let elementArea = element.getAttribute('data-value');

  console.log(elementArea); //-> main

  // Set value of an attribute
  element.setAttribute('data-value', 'side-bar');

  if(element.hasAttribute('data-value')) {
    console.log('Attribute exist');
  }
  </code>
</pre>

<p class="tutorials-content__text">Estos métodos también se pueden usar para manipular otros tipos de atributos (como id, tabindex, name, etc.), pero estos se hacen mejor llamando directamente al atributo en el elemento.</p>

<h3 class="tutorials-content__sub-title">Propiedades de atributo</h3>

<p class="tutorials-content__text">Puede obtener y establecer atributos directamente en un elemento.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section" data-value="main"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section');

  // Get Attribute
  let id = element.id;

  console.log(id);

  // Set Atrribute
  element.id = "main";
  </code>
</pre>
