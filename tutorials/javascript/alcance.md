---
layout: tutorials
title: Alcance
---
<h2 class="tutorials-content__sub-title">Scope "Alcance"</h2>

<p class="tutorials-content__text">El alcance(scope) decide a que variables tienes acceso en cada parte del codigo para ser utilizadas. Existen dos tipos de alcance, el alcance(scope) global y el alcance(scope) local.</p>

<h3 class="tutorials-content__sub-title">Alcance(Scope) Local</h3>

<p class="tutorials-content__text">Cuando puedes acceder a una variable únicamente en cierta parte del código, se dice que esa variable está declarada en el alcance local. Estas también son conocidas como variables locales. Un ejemplo de esto es cuando una variable está declarada dentro de un bloque o una función. Si tratas de acceder a esta variable fuera de esta función o bloque, tendrás un error que dirá que la variable no está definida.</p>

<pre>
  <code class="language-javascript">
  // Global Scope
  function greeting() {
    // Local Scope
    let name = "John";
    return "Hello " + name;
  }

  let fullGreeting = greeting();

  console.log(name);
  console.log(fullGreeting);
  //-> undefined
  //-> Hello John
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Alcance(Scope) Global</h3>

<p class="tutorials-content__text">Se dice que una variable está en el alcance global cuando está declarada fuera de una función o de un bloque. También son conocidas como variables globales. Puedes acceder a este tipo de variables desde cualquier parte de tu código, ya sea dentro o fuera de una función.</p>

<pre>
  <code class="language-javascript">
  // Global Scope
  let name = "John";

  function greeting(name) {
    // Local Scope
    return "Hello " + name;
  }

  let fullGreeting = greeting(name);

  console.log(fullGreeting);
  //-> Hello John
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Alcance(Scope) de bloque</h3>

<p class="tutorials-content__text">Un alcance de bloque es la sección dentro de las condiciones <code class="tutorials__code">if</code>, <code class="tutorials__code">switch</code>, o dentro de métodos de iteración como while. El concepto de bloque significa simplemente un conjunto de llaves de apertura y cierre <code class="tutorials__code">{}</code>. Estas palabras clave soportan la declaración de alcances locales dentro de bloque de instrucciones y tu como desarrollador puedes declarar variables que existen solamente dentro de un <b>bloque</b> específico.</p>

<p class="tutorials-content__text">Es importante entender que las variables <code class="tutorials__code">var</code> tiene alcance de función (global o local), y las variables <code class="tutorials__code">let</code> y <code class="tutorials__code">const</code> tienen alcance de bloque.</p>

<pre>
  <code class="language-javascript">
  var age = 2;

  if(age == 2) {
    var toddleAge = age * 2;
    console.log(`My son age is: ${toddleAge}`)
  }

  console.log(toddleAge); 
  //-> My son age is: 4
  //-> 4
  </code>
</pre>

<pre>
  <code class="language-javascript">
  var age = 2;

  if(age == 2) {
    let toddleAge = age * 2;
    console.log(`My son age is: ${toddleAge}`)
  }

  console.log(toddleAge); 
  //-> My son age is: 4
  //-> Uncaught ReferenceError: toddleAge is not defined
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Cadena de alcance(Scope chain)</h3>

<p class="tutorials-content__text">Para que entendamos el concepto vamos al siguien ejemplo, cuando invocamos una funcion, dentro de esta funcion se forma un contexto de ejecucion, en donde parte de sus fases esta colocar en memoria y leer variables que esten en dicho contexto. Digamos que en esta fase de ejecucion de contexto no encuentra una variable dentro de su propio alcance(Scope), pues automaticamente buscara en su <b>outter enviroment</b> las variable que necesite. a esto se le llama cadena de alcance (Scope chain).</p>

<h3 class="tutorials-content__sub-title">Palabra reservada <code class="tutorials__code">this</code></h3>

<p class="tutorials-content__text">Esta palabra reservada dentro del codigo, su valor hace referencia al propietario de la funcion que la estas invocando o en su defecto, al objeto donde dicha funcion es un metodo. Para entender de donde toma <code class="tutorials__code">this</code> su valor, hay que saber que su valor dependera de como es ejecutada la funcion en donde se encuentra.</p>

<h4 class="tutorials-content__sub-title">Dentro de una funcion</h4>

<p class="tutorials-content__text">Cuando la funcion no es parte del prototipo de una funcion constructora, el valor de this sera igual al objeto window, importante que esto es asi aunque sea un <b>Closure "Clausura"</b></p>

<pre>
  <code class="language-javascript">
  function a() {
    var c = function c() {
      console.log(this === window); //-> true
    }

    setTimeout(function b() {
      console.log(this === window); //-> true
    });

    c();
    console.log(this === window);
  }

  a();
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Dentro de un metodo</h4>

<p class="tutorials-content__text">Cuando se usa this dentro de un metodo, el valor de this sera equivalente al elemento en el que se ejecuta al metodo.</p>

<pre>
  <code class="language-javascript">
  const Person = {
    sayHi() {
      console.log(this === Person); //-> true
    }
  }

  Person.sayHi();
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Dentro de un constructor o metodo</h4>

<p class="tutorials-content__text">En este caso, this siempre hara referencia a la instancia.</p>

<pre>
  <code class="language-javascript">
  function Person() {}

  Person.prototype.sayHi = function() {
    console.log(this === Person); //-> false
    console.log(this instanceof Person); //-> true
  }

  const person = new Person();
  person.sayHi();
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Usando bind, call o apply</h4>

<p class="tutorials-content__text">Para sobreescribir el valor de <code class="tutorials__code">this</code>, podemos hacerlo de manera dinamica utilizando las funciones <code class="tutorials__code">bind</code>, <code class="tutorials__code">call</code> y <code class="tutorials__code">apply</code></p>

<pre>
  <code class="language-javascript">
  function greeting(age) {
    console.log(`Hello, i'm ${this.name} and I have ${age} years old.`)
  }

  const john = { name: "John Doe" }
  const jane = { name: "Jane Doe" }
  const josh = { name: "Josh Smith" }

  greeting.bind(john)(24) //-> Hello, i'm John Doe and I have 24 years old.
  greeting.call(jane, 23) //-> Hello, i'm Jane Doe and I have 23 years old.
  greeting.apply(josh, [25]) //-> Hello, i'm Josh Smith and I have 25 years old.
  </code>
</pre>
