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

<h3 class="tutorials-content__sub-title">Return</h3>

<p class="tutorials-content__text">La instruccion return determina que valores la funcion devolvera al final de la ejecucion de la misma funcion. Al no utilizar la instruccion <code class="tutorials__code">return</code> dentro de la funcion, esta funcion si utilizar la intruccion devolvera el valor por defecto <code class="tutorials__code">undefined</code>.</p>

<p class="tutorials-content__text">Existe una excepcion cuando creamos una objeto de JavaScript utilizando la palabra reservada <code class="tutorials__code">new</code>, el valor por defecto que devolvera de una funcion sera la misma funcion o el valor <code class="tutorials__code">this</code> en el cual se creo el objeto.</p>

<pre>
  <code class="language-javascript">
  function Intro() {
    console.log(this);
  }

  Intro();
  // Window

  var intro = new Intro();  

  // Intro {}
  intro;
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Parametros o Argumentos</h3>

<p class="tutorials-content__text">Las funciones utilizan valores de entrada para luego ser procesado dentro de la misma, a estos valores o variables se decimos argumentos o parametros. Los parametros o argumentos se comportan como unas variables regulares del mismo lenguage de programacion. Dentro de la funciones existe una variable llamada <code class="tutorials__code">arguments</code> el cual es como una especie de semi array, y indico semi porque no es un array regular o concreto, realmente es un objecto de JavaScript, el cual podemos utilizar sin indicar la definicion de esta misma variable dentro de la funcion.</p>

<p class="tutorials-content__text"><code class="tutorials__code">arguments</code> representa por el medio de una lista, cada parametro el cual introducimos entre los parentesis (...) de la funcion, tambien se le conoce como arity. De esta manera tenemos una segunda forma de acceder a los parametros que se le pasan a la funcion por argumento. En el siguiente ejemplo definimos una funcion con sus parametros por defecto y otra sin los parametro por defecto, esto desarrollara diferente resultados al verificar el espacio de cada funcion.</p>

<pre>
  <code class="language-javascript">
  function hello_01() {
    var firstName = arguments[0];
    var lastName = arguments[1];
    return("Hello " + firstName + " " + lastName + "!");
  }
  console.log(hello_01("John", "Johnson")); //-> Hello John Johnson!

  const Hello_01 = hello_01.length;
  console.log(Hello_01); //-> 0

  function hello_02(firstName, lastName) {};
  const Hello_02 = hello_02.length;
  console.log(Hello_02); //-> 2
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Parametros por defecto</h4>

<p class="tutorials-content__text">Una buena practica para evitar errores o que se tome el valor <code class="tutorials__code">undefined</code> sin que podamos controlarlo, es utilizar de los operadores booleanos como por ejemplo el operador OR <code class="tutorials__code">||</code> podemos asignar un valor por defecto si no esta definido el parametro.</p>

<pre>
  <code class="language-javascript">
  function hello(firstName, lastName) {
    var firstName = firstName || "First Name Please";
    var lastName = lastName || "Last Name Please";
    return("Hello " + firstName +  " " + lastName + "!");
  }

  console.log(hello()); //-> Hello First Name Please Last Name Please!
  console.log(hello("John")); //-> Hello John Last Name Please!
  console.log(hello("John", "Johnson")); //-> Hello John Johnson!
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Utilizar argumentos como array</h4>

<p class="tutorials-content__text">Existen momento que queremos utilizar la variable argument dentro de la funciones como un verdadero array, asi sea para utilizar funciones de array como <code class="tutorials__code">.push</code>, <code class="tutorials__code">.pop</code> o <code class="tutorials__code">.slice</code>. Esto es completamente imposible ya que la variable <code class="tutorials__code">arguments</code> es realmente un objecto JavaScript y no un array. Pero si podemos convertir esa variable objecto a array y utilizarla como array.</p>

<pre>
  <code class="language-javascript">
  // Method 1
  function has() {  
    let args = [].slice.call(arguments);
    args.forEach((arg) => console.log(arg));
  }

  has(1,2,3,4); //-> 1 2 3 4 

  // Method 2
  function has() {  
    let args = Array.prototype.slice.call(arguments);
    args.forEach((arg) => console.log(arg));
  }

  has(1,2,3,4); //-> 1 2 3 4
  </code>
</pre>

<p class="tutorials-content__text">En JavaScript las funciones pueden ser tratadas como valores, esto significa que podemos asignarlas a una variable, para luego ser pasada como parametro a otra funcion o ser tambien devuelta por una funcion. A esto se le suele conocer como funciones de primera clase <b>"first-class"</b>.</p>

<h4 class="tutorials-content__sub-title">Funciones de primera clase "First-class function"</h4>

<p class="tutorials-content__text">El termino se refiere a cuando una funcion puede ser tratada y/o manejada como si fuera una variable cualquiera.</p>

<pre>
  <code class="language-javascript">
  var validateDataForAge = function(data) {
    person = data();
    console.log(person);

    if (person.age <1 || person.age > 99) {
      return true;
    }
    else {
      return false;
   }
  };

  var errorHandlerForAge = function(error) {
    console.log("Error while processing age");
  };

  function parseRequest(data, validateData, errorHandler) {
    var error = validateData(data);

    if (!error) {
      console.log("no errors");
    } 
    else {
      errorHandler();
    }
  }

  var generateDataForScientist = function() {
    return {
      name: "Albert Einstein",
      age : Math.floor(Math.random() * (100 - 1)) + 1,
    };
  };

  var generateDataForComposer = function() {
    return {
      name: "J S Bach",
      age : Math.floor(Math.random() * (100 - 1)) + 1,
    };
  };

  // Parse Request
  parseRequest(generateDataForScientist, validateDataForAge, errorHandlerForAge);
  // -> {name: "Albert Einstein", age: 42} no errors
  parseRequest(generateDataForComposer, validateDataForAge, errorHandlerForAge);
  // -> {name: "J S Bach", age: 87} no errors
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Expresión de función invocada inmediatamente (Immediately-Invoked Function Expression / IIFE)</h3>

<p class="tutorials-content__text">Antes de entra a en que significa este termino, primero debemos de entender algunos punto importantes. La diferencia entre una declaracion de funcion y una expresion de funcion. El ejemplo mas basico de una declaracion de funcion es el siguiente:</p>

<pre>
  <code class="language-javascript">
  function do() {
    // Some logic
  }
  </code>
</pre>

<p class="tutorials-content__text">Es bien simple de comprender, es la forma mas comun de utilizar las funciones. Utilizamos la palabra reservada <code class="tutorials__code">function</code> seguido de nombre de la funcion y terminamos con los parentesis <code class="tutorials__code">(...)</code> para los parametros y llaves <code class="tutorials__code">{...}</code> para el bloque de codigo. Por el otro lado un ejemplo de una expresion de funcion es la siguiente:</p>

<pre>
  <code class="language-javascript">
  const do = function() {
    // Some logic
  }
  </code>
</pre>

<p class="tutorials-content__text">Visualmente podemos observar diferencia entre ambas, pero pueden ser utilizada de la misma manera <code class="tutorials__code">do()</code>. Estos nos ayuda a entender el cuerpo o la figura de como se compone un IIFE.</p>

<p class="tutorials-content__text">IIFE visualmente es una declaracion de una funcion anonima, el cual no tiene nombre dentro de parentesis <code class="tutorials__code">(...)</code>.</p>

<pre>
  <code class="language-javascript">
  (function() {
    // Some logic
  })()
  </code>
</pre>

<p class="tutorials-content__text">Primero explicamos los parentesis <code class="tutorials__code">(...)</code> en el cual esta encerrada la funcion, JavaScript asume que cuando escribimos la palabra reservada function y el interpretador del codigo cuando encuentra con ella, para el interpretado esto significa que estas declarando una funcion. Esto es importante porque fuera de estos parentesis al tratar de crear in IIFE, JavaScript entendera otra cosa y tendremos error al interpretar el codigo.</p>

<p class="tutorials-content__text">Es en este siguiente punto que destacamos la diferencia entre declaracion y expresion de funciones, al escribir el codigo o la funcion dentro de parentesis <code class="tutorials__code">(...)</code>, el interpretador de JavaScript entiendes que estas usando la funcion como una expresion y no declarada. Estos nos ayudara a no tener poblemas de errores.</p>

<p class="tutorials-content__text">Segundo, hablemos de los parentesis () luego de la los parentesis que encierra la funcion. Estos parentesis es para la invocacion inmediata de la misma expresion que encerramos dentro de los parentesis. Sin estos parentesis () finales, la funcion nunca sera invocada.</p>

<p class="tutorials-content__text">Ahora bien IIFF es utilizada para las siguientes objetivos:</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" ><b>Privacidad</b> - privacidad para el enfoque y contexto ejecucion dentro de la misma funcion o bloque de codigo. Estos nos ayuda a evitar tener conflicto con variable globales.</li>
</ul>

<pre>
  <code class="language-javascript">
  (function(){
    var secret = 123456;
  })()

  console.log(secret); //-> Uncaught ReferenceError: secret is not defined
  </code>
</pre>
