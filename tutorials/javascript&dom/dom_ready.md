---
layout: tutorials
title: DOM Ready
---
<h2 class="tutorials-content__sub-title">DOM Ready</h2>

<p class="tutorials-content__text">Espere hasta que el DOM esté listo antes de ejecutar el código.</p>

<pre>
  <code class="language-javascript">
  let ready = function(fn) {

    // Sanity check
    if(typeof fn !== 'function') return;

    // If document is already loaded, run method
    if(document.readyState === 'interactive' || document.readyState === 'complete') {
      return fn();
    }

    // Otherwise, wait until document is loaded
    document.addEventListener( 'DOMContentLoaded', fn, false );
  };

  ready(function() {
      console.log('Run code');
  });
  </code>
</pre>
