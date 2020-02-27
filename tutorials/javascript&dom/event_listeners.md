---
layout: tutorials
title: Event Listeners
---
<h2 class="tutorials-content__sub-title">Event Listeners "Detector de eventos"</h2>

<h3 class="tutorials-content__sub-title">Event Listeners</h3>

<p class="tutorials-content__text">Un detector de eventos es un procedimiento o función el cual espera que ocurra un evento. Ejemplos de un evento son el usuario haciendo clic o moviendo el mouse, presionando una tecla en el teclado, etc. El oyente <b>Listener<b> está programado para reaccionar a una entrada o señal llamando al controlador del evento.</p>

<p class="tutorials-content__text">Utilizamos <code class="tutorials__code">addEventListener</code> para escuchar eventos en un elemento del DOM.</p>

<pre>
  <code class="language-html">
  &#60;button id="click_me"&#62;Click Me&#60;/button&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let btn = document.querySelector("#click_me");
  btn.addEventListener("click", function(event) {
    console.log(event); //-> MouseEvent
    console.log(event.target); //-> <button id="click_me">Click Me</button>
  }, false);
  </code>
</pre>
