---
layout: tutorials
title: Cadena de caracteres "String"
---
<h2 class="tutorials-content__sub-title">String "Cadena de caracteres"</h2>

<p class="tutorials-content__text">Cadena de caracteres es una secuencia de uno o mas caracteres que consiste de letras, numeros o simbolos. Cadena de caracteres es un tipo de dato primitivo y es completamente inmutable. Las cadena de caracteres nos ayuda a proveer texto atraves de nuestra aplicacion. Este puede ser creado de manera primitiva o utilizando el objeto String de Javascript.</p>

<h4 class="tutorials-content__sub-title">Crear cadena de caracteres</h4>

<p class="tutorials-content__text">En JavaScript tenemos tres maneras de crear cadena de caracteres. comillas simples <code class="tutorials__code">'...'</code>, comillas dobles <code class="tutorials__code">"..."</code> y comillas invertidas<code class="tutorials__code">`</code> .</p>

<pre>
  <code class="language-javascript">
  'This string uses single quotes.';
  "This string uses double quotes.";
  `This string uses backticks.`;
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Cadena de caracteres primitivo</h4>

<pre>
  <code class="language-javascript">
  const stringPrimitive = "A new string.";
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Objeto de cadena de caracteres</h4>

<pre>
  <code class="language-javascript">
  const stringObject = new String("A new string.");
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Concatenar cadena de caracteres</h3>

<p class="tutorials-content__text">Cuando aplicamos el operador de suma <code class="tutorials__code">+</code> a dos cadenas de caracteres, nos concatena o nos unes dos cadenas de caracteres y forma una sola cadena de caracteres.</p>

<pre>
  <code class="language-javascript">
  let string = "lorem" + " ipsum";
  console.log(string); //-> lorem ipsum
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Literales de plantillas "Template Literals"</h3>

<p class="tutorials-content__text">Las comillas invertidas, tambien se le conoce como literales de plantillas, estas podemos tambien interpolar una variable dentro del literal utilizando <code class="tutorials__code">${...}</code></p>

<pre>
  <code class="language-javascript">
  let name = "John";
  let greeting = `Hello ${name}, how your day!`;
  console.log(greeting); //-> Hello John, how your day!
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Acceso a caracteres</h3>

<p class="tutorials-content__text">Para tener acceso a un caracter de una cadena de caracteres, utilizamos el indice de ese caracter que queremos.</p>

<pre>
  <code class="language-javascript">
  console.log("How are you?"[5]); //-> r
  </code>
</pre>

<p class="tutorials-content__text">Tambien podemos utilizar el metodo <code class="tutorials__code">.charAt</code> el cual nos devuelve el caracter base al indice.</p>

<pre>
  <code class="language-javascript">
  console.log("How are you?".charAt(5)); //-> r
  </code>
</pre>

<p class="tutorials-content__text">Una alternativa que tenemos para identificar indice a base de caracteres es utilizando el metodo <code class="tutorials__code">.indexOf</code> y <code class="tutorials__code">.lastIndexOf</code></p>

<pre>
  <code class="language-javascript">
  console.log("How are you?".indexOf("o")); //-> 1
  console.log("How are you?".lastIndexOf("o")); //-> 9
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Extraer partes de una cadena de caracteres</h3>

<p class="tutorials-content__text">Para extraer parte de una cadena de caracteres podemos utilizar el metodo <code class="tutorials__code">.slice</code></p>

<pre>
  <code class="language-javascript">
  console.log("How are you?".slice(8)); //-> you?
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Identificar longitud de cadena de caracteres</h3>

<pre>
  <code class="language-javascript">
  console.log("How are you?".length); //-> 12
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Convertir cadenas de caracteres a letras mayusculas o minuscula</h3>

<p class="tutorials-content__text">Podemos convertir una cadena de caracteres a todas sus letras mayuscula o minuscula utilizando los metodos <code class="tutorials__code">.toUpperCase</code> y <code class="tutorials__code">.toLowerCase</code></p>

<pre>
  <code class="language-javascript">
  console.log("How are you?".toUpperCase()); //-> HOW ARE YOU?
  console.log("How are you?".toLowerCase()); //-> how are you?
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Dividir cadena de caracteres</h3>

<p class="tutorials-content__text">Podemos utilizar el metodo <code class="tutorials__code">.split</code> para dividir cadena de caracteres y transformandolo en un array.</p>

<pre>
  <code class="language-javascript">
  const originalString = "How are you?";

  const splitString = originalString.split(" ");

  console.log(splitString); //-> ["How", "are", "you?"]
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Buscar y remplazar valores en cadena de caracteres</h3>

<p class="tutorials-content__text">El metodo <code class="tutorials__code">.replace</code> nos ayuda a remplazar partes de cadena de caracteres.</p>

<pre>
  <code class="language-javascript">
  const originalString = "How are you?";

  const newString = originalString.replace("How", "Where");

  console.log(newString); //-> Where are you?
  </code>
</pre>
