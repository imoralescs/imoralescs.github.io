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

<h3 class="tutorials-content__sub-title">Pila de ejecucion o llamada (Execution stack)</h3>

<p class="tutorials-content__text">Pila de ejecucion o Pila de llamadas, “call stack”, es una estructura dinámica de datos LIFO que almacena información sobre las subrutinas de una aplicación. Piensalo como el lugar para llamadas de funciones, o una estructura de datos que implementa el tipo de datos de la pila (stack), en que solamente se puede ejecutar una función a la vez.</p>

<p class="tutorials-content__text">Volvamos al ejemplo anterior y mostrando en graficas como la pila de ejecucion se comporta. Cuando el motor de Javascript llega a la línea 1 crea nuestro Contexto de Ejecución y lo apila en una pila de ejecución creando un nuevo Contexto de Ejecución: <b>«Execution Context Global«</b>.</p>

<div class="tutorials-content__image">
  <img src="https://raw.githubusercontent.com/imoralescs/imoralescs.github.io/master/images/pila-de-ejecuci%C3%B3n-paso-1.png" />
</div>

<p class="tutorials-content__text">Cuando nuestro código llega a la línea 11 y ejecuta la funcion <b>«b»</b>. Se crea un nuevo Contexto de Ejecución: El Contexto de Ejecución de la función <b>«b»</b>. Nuestro actual Contexto <b>«Execution Context Global»</b> queda en segundo plano y el motor de Javascript pasa a crear y ejecutar el contexto de la función <b>«b»</b>.</p>

<div class="tutorials-content__image">
  <img src="https://raw.githubusercontent.com/imoralescs/imoralescs.github.io/master/images/pila-de-ejecuci%C3%B3n-paso-2.png" />
</div>

<p class="tutorials-content__text">Recordemos que una pila funciona de la siguiente forma: El ultimo que entra es el primero que sale, y traducido a nuestros Contextos de Ejecución, el ultimo Contexto de Ejecución que entra en la pila, sera el primero en ser ejecutado. Es por eso que el motor de Javascript cambia del contexto de ejecución Global al Contexto de Ejecución de la función <b>«b»</b>. Luego pasa lo mismo con la función <b>«a»</b> cuando llega a la línea que ejecuta la función <code class="tutorials__code">a()</code>. En nuestra pila de ejecución se crea un nuevo contexto (Execution Context de la función <b>a</b>) y el motor pasa a ejecutar ese contexto, dejando «en espera» al contexto anterior.</p>

<div class="tutorials-content__image">
  <img src="https://raw.githubusercontent.com/imoralescs/imoralescs.github.io/master/images/pila-de-ejecuci%C3%B3n-paso-3.png" />
</div>

<p class="tutorials-content__text">Una vez que finaliza de ejecutarse la función <b>«a»</b> su contexto desaparece y el motor de Javascript pasa a ejecutar el contexto <b>«anterior»</b>, en este caso sería el Contexto de Ejecución de la función <b>«b»</b>.</p>

<div class="tutorials-content__image">
  <img src="https://raw.githubusercontent.com/imoralescs/imoralescs.github.io/master/images/pila-de-ejecuci%C3%B3n-paso-2.png" />
</div>

<p class="tutorials-content__text">Y lo mismo al finalizar de ejecutarse la función <b>«B»</b>, o mejor dicho su contexto, se lo saca de la pila y se ejecuta el contexto anterior; en el ejemplo, al no haber más Execution Context de ninguna función, el Contexto de Ejecución que se ejecuta es el Global.</p>

<div class="tutorials-content__image">
  <img src="https://raw.githubusercontent.com/imoralescs/imoralescs.github.io/master/images/pila-de-ejecuci%C3%B3n-paso-1.png" />
</div>

<p class="tutorials-content__text">Y para terminar, cuando este contexto finaliza, o sea cuando nuestro programa finaliza, se vacía la pila.</p>

<div class="tutorials-content__image">
  <img src="https://raw.githubusercontent.com/imoralescs/imoralescs.github.io/master/images/pila-de-ejecuci%C3%B3n-paso-0.png" />
</div>
