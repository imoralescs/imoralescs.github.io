---
layout: tutorials
title: Bucles
---
<h2 class="tutorials-content__sub-title">Bucles</h2>

<p class="tutorials-content__text">Se utilizan para ejecutar varias veces determinados bloques de codigo mientra se cumpla una condicion. Existen 3 elementos que controlan el flujo del bucle. La <b>inicializacion</b> que fija los valores con los que iniciamos el bucle, la condicion de <b>permanencia</b> en el bucle y la <b>actualizacion</b> de la variable de control al ejecutarse la iteracion.</p>

<h3 class="tutorials-content__sub-title">Bucle While</h3>

<p class="tutorials-content__text">Se ejecutara mientras se cumpla la condicion.</p>

<pre>
  <code class="language-javascript">
  var condicion; // Inicializacion

  while(condicion) { // Condicion de permanencia
    bloque_de_codigo // Codigo a ejecutar y actualizacion de la variable de control
  }
  </code>
</pre>

<pre>
  <code class="language-javascript">
  var i = 0; 

  while(i < 11) { 
    console.log(i); 
    i++; 
  }
  //-> 0 1 2 3 4 5 6 7 8 9 10
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Bucle Do/While</h3>

<p class="tutorials-content__text">Es similar al <code class="tutorials__code">while</code> con la salvedad de que ejecutamos un bloque de codigo dentro de do por primera vez y despues se comprueba la condicion de permanencia en el bucle.</p>

<pre>
  <code class="language-javascript">
  var i = 0; 

  do { 
    console.log( i ); 
    i++; 
  } 
  while(i < 11); 
  //-> 0 1 2 3 4 5 6 7 8 9 10
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Bucle For</h3>

<p class="tutorials-content__text">Nos permite resumir en una linea la forma de un bucle <code class="tutorials__code">while</code>.</p>

<pre>
  <code class="language-javascript">
  var i; 
  for(i = 0; i < 11; i++) { 
    console.log( i ); 
  } 
  //-> 0 1 2 3 4 5 6 7 8 9 10
  </code>
</pre>
