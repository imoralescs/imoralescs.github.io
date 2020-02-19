---
layout: tutorials
title: Prototype
---
<h2 class="tutorials-content__sub-title">Prototype</h2>

<p class="tutorials-content__text">JavaScript es un lenguaje de programacion prototipado, esto significa que nuestros objetos de JavaScript pueden compartir propiedades y metodos. Cuando compartimos propiedades o metodos de nuestro objetos de JavaScript o creamos clones de un objeto de JavaScript le llamamos herencia prototipica a diferencia de herencia de clase.</p>

<p class="tutorials-content__text">Todo objeto de JavaScript, cuando es creado mediante:</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  const dir = console.dir;

  let guest = new Object;
  dir(guest); //-> Object__proto__: Object

  let admin = {};
  dir(admin); //-> Object__proto__: Object

  log(Object.getPrototypeOf(admin));
  //-> {constructor: ƒ, __defineGetter__: ƒ, __defineSetter__: ƒ, hasOwnProperty: ƒ, __lookupGetter__: ƒ, …}

  log(guest.__proto__);
  //-> {constructor: ƒ, __defineGetter__: ƒ, __defineSetter__: ƒ, hasOwnProperty: ƒ, __lookupGetter__: ƒ, …}
  </code>
</pre>
