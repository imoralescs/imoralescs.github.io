---
layout: tutorials
title: Funciones
---
<h2 class="tutorials-content__sub-title">Funciones</h2>

<p class="tutorials-content__text">Son bloques de codigos ejecutable, a los que podemos pasar parametros y operar con ellos. Nos sirven para modular nuestros programa y estructurarlos en bloques que realicen una tarea concreta.</p>

<p class="tutorials-content__text">Las funciones nos sirven para las siguientes tareas, por ejemplo:</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" ><b>Mapeos</b> - producir uno o varios valor de salida basado al valor el cual se le introduce al inicio del proceso. Las funciones normalmente al acabar su ejecucion devuelve un valor que conseguimos con el parametro <code class="tutorials__code">return</code>.</li>
  <li class="tutorials-content__list-element" ><b>Procedimientos</b> - funciones pueden ser llamada en secuencias de pasos.</li>
  <li class="tutorials-content__list-element" ><b>I/O</b> - Algunas funciones solo existen para comunicarte con parte del sistema el cual utilizas, asi como lenguage de programacion, sistema de hardware, sistema de record, etc.</li>
</ul>

<p class="tutorials-content__text">Para declarar una funcion utilizamos la palabra reservada <code class="tutorials__code">function</code> y normalmente continua con el nombres para luego en el flujo del programa poder invocarla, si no lleva numbre se les llama funciones anonimas.</p>

<pre>
  <code class="language-javascript">
  function hello(name) {
    return("Hello " + name + "!");
  }
  console.log(hello("John")); //-> Hello John!
  </code>
</pre>

<p class="tutorials-content__text">En la funcion del ejemplo se le llama a la funcion <code class="tutorials__code">hello</code> y se le pasa un unico parametro entre parentesis <code class="tutorials__code">(...)</code> que es <code class="tutorials__code">name</code>. Parametros funciona como contenedores de una variable que sera utilizada dentro del bloque d codigo de la funcion, la instruccion <code class="tutorials__code">return</code> devolvera el String que concatena texto con el valor que contiene el parametro <code class="tutorials__code">name</code>.</p>
