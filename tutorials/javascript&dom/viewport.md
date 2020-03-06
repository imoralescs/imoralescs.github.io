---
layout: tutorials
title: DOM Ready
---
<h2 class="tutorials-content__sub-title">Viewport</h2>

<h3 class="tutorials-content__sub-title">Obtener la altura de la ventana gráfica</h3>

<p class="tutorials-content__text">Hay dos métodos para obtener la altura de la ventana gráfica: <code class="tutorials__code">window.innerHeight</code> y <code class="tutorials__code">document.documentElement.clientHeight</code>. El primero es más preciso. Este último tiene mejor soporte en diferentes navegadores.</p>

<pre>
  <code class="language-javascript">
  let viewportHeight = window.innerHeight || document.documentElement.clientHeight;

  console.dir(viewportHeight); //-> 515
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Obtener el ancho de la ventana gráfica</h3>

<p class="tutorials-content__text">Hay dos métodos para obtener el ancho de la ventana gráfica: <code class="tutorials__code">window.innerWidth</code> y <code class="tutorials__code">document.documentElement.clientWidth</code>. El primero es más preciso. Este último tiene mejor soporte en diferentes navegadores.</p>

<pre>
  <code class="language-javascript">
  let viewportWidth = window.innerWidth || document.documentElement.clientWidth;

  console.dir(viewportWidth); //-> 463
  </code>
</pre>
