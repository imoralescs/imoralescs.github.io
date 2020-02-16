---
layout: tutorials
title: Entorno lexico & Contexto de ejecucion
---
<h2 class="tutorials-content__sub-title">Entorno lexico & Contexto de ejecucion</h2>

<h3 class="tutorials-content__sub-title">Entorno lexico (Lexical environment)</h3>

<p class="tutorials-content__text">Entorno lexico es todo el entorno que rodea donde esta escrito el codigo, por ejemplo un archivo <code class="tutorials__code">.js</code> es un entorno lexico.</p>

<h3 class="tutorials-content__sub-title">Contexto de ejecucion (Execution context)</h3>

<p class="tutorials-content__text">Cada vez que se inicia una ejecucion de una funcion por ejemplo, se genera un nuevo contexto de ejecucion, de hecho al iniciar toda la aplicacion se genera un contexto de ejecucion global, podemos pensar que esto es como un "Wrapper(o algo que envuelve)" que ayuda a manejar el codigo que se este ejecutando en un momento dado y se crea para facilitar tareas. Cada contexto de ejecucion son independientes entre si.</p>

<pre>
  <code class="language-javascript">
  // This is global execution context
  let name = "John";

  function greeting(name) {
    // This is a greeting function execution context
    return "Hello " + name;
  }

  let fullGreeting = greeting(name);

  console.log(fullGreeting);
  //-> Hello John
  </code>
</pre>

<p class="tutorials-content__text">Ahora vamos a una representacion grafica para un mejor entendimento.</p>

<pre>
  <code class="language-javascript">
  function a() {
    // This is a function execution context
    console.log("a");
  }

  function b() {
    // This is b function execution context
    console.log("b");
    a();
  }

  b();
  //-> b a
  </code>
</pre>

<div class="tutorials-content__image">
  <img src="https://raw.githubusercontent.com/imoralescs/imoralescs.github.io/master/images/execution-context-como-se-crea-paso-a-paso.png" />
</div>
