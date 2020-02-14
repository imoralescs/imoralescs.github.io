---
layout: tutorials
title: Variables
---
<h2 class="tutorials-content__sub-title">Variables</h2>

<p class="tutorials-content__text">Las variables consiste de un nombre y un espacio en la mamoria del navegador en el cual corresponde el valor de esa variable. JavaScript es un lenguaje de programacion no tipado, esto significa que no indicamos que tipo de variable declaramos. Todas las variables permiten todos los tipos de valor y estos valores puede ser reescrito de forma muy sencilla.</p>

<p class="tutorials-content__text">El valor de una variable es una entidad individual del programa, el proceso de programacion puede recrear expresiones matematicas y estas expresiones matematica pueden generar un nuevo valor de otro valor ya existente.</p>

<h3 class="tutorials-content__sub-title">Definicion de variables</h3>

<p class="tutorials-content__text">Para definir una variable utilizamos la palabra reservada <code class="tutorials__code">var</code> esto es en el caso que utilicemos la version ECMAScript 5 de JavaScript, <code class="tutorials__code">const</code> o <code class="tutorials__code">let</code> en el caso que estemos utilizando la version JavaScript ECMAScript 6 o ECMAScript 7.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" ><code class="tutorials__code">var</code></li>
</ul>

<pre>
  <code class="language-javascript">
  // Declarando variable
  var = message;

  // Escribiendo valor a la variable
  message = "Hola Mundo!";

  // Asignando valor y a la misma vez declarando variable
  var dato = 0;
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" ><code class="tutorials__code">let</code></li>
</ul>

<p class="tutorials-content__text">Es una nueva forma de declara variable similar a <code class="tutorials__code">var</code>, la diferencia de <code class="tutorials__code">let</code> y <code class="tutorials__code">var</code> es que <code class="tutorials__code">let</code> permite utilizar el valor solo dentro del bloque (Block Scope) de donde es declarada la misma variable.</p>

<pre>
  <code class="language-javascript">
  {
    let a = 42;
    {
      let b = 24;
      {
        console.log(b);
      }
      console.log(b);
    }
    // console.log(b);
    //-> b is not defined
    console.log(a);
  }
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" ><code class="tutorials__code">const</code></li>
</ul>

<p class="tutorials-content__text">Es igual que <code class="tutorials__code">let</code>, la unica diferencia es que el valor solo se puede leer y no modificar en el proceso. Igual que <code class="tutorials__code">let</code> respeta el alcance de bloque en el cual fue inicializada. Importante saber que cuando utilizamos <code class="tutorials__code">const</code> con variables que representan objectos en JavaScript esto no convirte el objeto en algo inmutable, solo que su valor de referencia es fijo.</p>

<pre>
  <code class="language-javascript">
  const MSG = "MSG_ME";
  </code>
</pre>
