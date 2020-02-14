---
layout: tutorials
title: Operadores
---
<h2 class="tutorials-content__sub-title">Operadores</h2>

<p class="tutorials-content__text">JavaScript posee operadores para tipos y objetos, estos operadores permiten desarrollar expresiones lo cual nos permite resolver problemas. Las operaciones mas comunes son las aritmeticas.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Suma de numeros <code class="tutorials__code">5 + 2</code></li>
  <li class="tutorials-content__list-element" >Resta <code class="tutorials__code">5 - 2</code></li>
  <li class="tutorials-content__list-element" >Operaciones con parentesis <code class="tutorials__code">(3 + 2) - 5</code></li>
  <li class="tutorials-content__list-element" >Divisiones <code class="tutorials__code">3 / 3</code></li>
  <li class="tutorials-content__list-element" >Multiplicaciones <code class="tutorials__code">6 * 3</code></li>
</ul>

<p class="tutorials-content__text">Los operadores y operaciones en programacion tiene sus propias terminologia el cual debemos de entender claramente antes de proseguir.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Operando</li>
</ul>

<p class="tutorials-content__text">Esto es, a que valores se le aplica el operador, por ejemplo <code class="tutorials__code">5 * 2</code>, el operador de multiplicacion el cual es aplicado a los operando de izquierda a derecha.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Unario</li>
</ul>

<p class="tutorials-content__text">Es un operador que se le aplica para desarrollar una simple expresion.</p>

<pre>
  <code class="language-javascript">
  let x = 10;
  let y = 20;
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Binario</li>
</ul>

<p class="tutorials-content__text">Es un operandor que se le aplica a dos operando.</p>

<pre>
  <code class="language-javascript">
  // Multiply, Divide, Add
  const x = 7;
  const result = x * 2;
  console.log(result); //-> 14
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Operador Binario +</h3>

<p class="tutorials-content__text">Usualmente cuando utilizamos el operador de suma y se lo aplicamos a operando numero, esto nos retorna la suma de los dos valores. Ahora bien este operador tiene un comportamiento diferente cuando nuestros operando son cadena de caracteres o caracter. Es esta forma en que podemos concatenar cadenas de caracteres.</p>

<pre>
  <code class="language-javascript">
  // String Concatenation
  let s = "Hello";
  const result = s + ", Worlds!"
  console.log(result); //-> Hello, Worlds!
  </code>
</pre>

<p class="tutorials-content__text">Tenemos que tener cuidado en aplicar el operador de suma a dos operando diferente como cadena de caracteres y numero. Esto nos retornara una concatenacion del numero y la cadena de caracteres.</p>

<pre>
  <code class="language-javascript">
  // String and Number Concatenation
  console.log('1' + 2); //-> "12"
  console.log(2 + '1'); //-> "21"
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Operadores Post, Pre, Incremento y Decremento</h3>

<p class="tutorials-content__text">Esto añaden uno o resta uno a la variable al cual se le aplica el operador.</p>

<pre>
  <code class="language-javascript">
  let x = 1;
  console.log(++x); //-> 2
  </code>
</pre>

<p class="tutorials-content__text">Dependiendo si los operadores son pre o post aplicado a la variable, esa variable es autoincrementa o decrementa antes o despues de la sentencia.</p>

<pre>
  <code class="language-javascript">
  let x = 1;
  let y = ++x;

  console.log(x); //-> 2
  console.log(y); //-> 2

  let z = y++ + x;
  console.log(x); //-> 2
  console.log(y); //-> 3
  console.log(z); //-> 4
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Operador <code class="tutorials__code">typeof</code></h3>

<p class="tutorials-content__text">Este operador es especial que nos permite conocer el tipo de variable al cual se lo aplicamos.</p>

<pre>
  <code class="language-javascript">
  typeof 5; //-> number
  typeof false; //-> boolean
  typeof "John"; //-> string
  typeof undefined; //-> undefined
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Operadores Booleanos</h3>

<p class="tutorials-content__text">Estos operadores nos permite transformar valores booleanos.</p>

<h4 class="tutorials-content__sub-title">Negacion</h4>

<p class="tutorials-content__text">Este operador convierte un valor booleano en su opuesto, se representa con el signo <code class="tutorials__code">!</code> .</p>

<h4 class="tutorials-content__sub-title">Identidad o Igualdad</h4>

<p class="tutorials-content__text">Igualdad se representa con <code class="tutorials__code">==</code> o igualdad estricta con <code class="tutorials__code">===</code> . La desigualdad estricta se representa con <code class="tutorials__code">!==</code>.</p>

<h4 class="tutorials-content__sub-title">Comparacion</h4>

<p class="tutorials-content__text">Podemos comparar si dos valores son menores, mayores o iguales con los operadores de comparacion representados por los simbolos <code class="tutorials__code"><</code>,<code class="tutorials__code">></code>, <code class="tutorials__code"><=</code>, y <code class="tutorials__code">>=</code>.</p>
  
<h3 class="tutorials-content__sub-title">Operadores Logicos</h3>

<h4 class="tutorials-content__sub-title">Operador AND</h4>

<p class="tutorials-content__text">Es un operador logico que devuelve el valor <code class="tutorials__code">true</code> siempre que todos los valores comparados sean <code class="tutorials__code">true</code>. Si uno de ellos es <code class="tutorials__code">false</code>, devuelve <code class="tutorials__code">false</code> . Se representa con el simbolo <code class="tutorials__code">&&</code>.</p>

<h4 class="tutorials-content__sub-title">Operador OR</h4>

<p class="tutorials-content__text">Es otro operador logico que funciona a la inversa que <code class="tutorials__code">AND</code>.</p>
