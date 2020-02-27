---
layout: tutorials
title: Event Listeners
---
<h2 class="tutorials-content__sub-title">Event Listeners "Captura de eventos"</h2>

<h3 class="tutorials-content__sub-title">Event Listeners</h3>

<p class="tutorials-content__text">Un capturador de eventos es un procedimiento o función el cual espera que ocurra un evento. Ejemplos de un evento son el usuario haciendo clic o moviendo el mouse, presionando una tecla en el teclado, etc. El capturador <b>Listener</b> está programado para reaccionar a una entrada o señal llamando al controlador del evento.</p>

<p class="tutorials-content__text">Utilizamos <code class="tutorials__code">addEventListener</code> para capturar eventos en un elemento del DOM.</p>

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

<h3 class="tutorials-content__sub-title">Evento a multiples elementos</h3>

<p class="tutorials-content__text">La función <code class="tutorials__code">addEventListener</code> de JavaScript requiere que pase un elemento específico e individual para capturar evento. No es posible pasar una matriz o lista de nodos de elementos coincidentes. En lugar de capturar elementos específicos, capturamos todos los clics en una página y luego verificaremos si el elemento seleccionado tiene un selector coincidente.</p>

<pre>
  <code class="language-html">
  &#60;button class="click-me" id="click_me"&#62;Click Me&#60;/button&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  window.addEventListener('click', function ( event ) {
    if (event.target.classList.contains( 'click-me' ) ) {
      console.log(event.target); //-> <button id="click_me">Click Me</button>
    }
  }, false);
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Multiple eventos</h3>

<p class="tutorials-content__text">En JavaScript, cada tipo de evento requiere su propio capturador de eventos. Podemos usar una función con nombre y pasarla a su capturador de eventos, para evitar tener que escribir el mismo código una y otra vez.</p>

<pre>
  <code class="language-javascript">
  const eventFunction = () => {
    console.log("Event happen");
  }

  window.addEventListener('click', eventFunction, false);
  window.addEventListener('scroll', eventFunction, false);
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Rebote de evento "Event Debouncing"</h3>

<p class="tutorials-content__text">Eventos como scroll y resize causan problemas grande en el desempeño de algunos exploradores, para esto utilizamos rebote. Rebote es una forma de obligar a un capturador de eventos a esperar un cierto período de tiempo antes de disparar evento nuevamente. Para usar ests tecnica, configuraremos un tiempo de espera. Esto se usa como un contador para decirnos cuánto tiempo ha pasado desde la última vez que se ejecutó el evento.</p>

<p class="tutorials-content__text">Cuando se dispara nuestro evento, si el tiempo de espera no tiene valor, asignaremos una función setTimeout que caduque después de 66 ms y contenga nuestros métodos que queremos ejecutar en el evento.</p>

<p class="tutorials-content__text">Si han pasado menos de 66 ms desde que se ejecutó el último evento, no sucederá nada más.</p>

<pre>
  <code class="language-javascript">
  let timeout;

  window.addEventListener('resize', function(event) {
    console.log( 'no debounce' );

    if(!timeout) {
      timeout = setTimeout(function() {

        // Reset timeout
        timeout = null;

        // Run our resize functions
        console.log( 'debounced' );
      }, 66);
    }
  }, false);
  </code>
</pre>
