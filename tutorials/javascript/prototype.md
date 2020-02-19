---
layout: tutorials
title: Prototype "Prototipo"
---
<h2 class="tutorials-content__sub-title">Prototype "Prototipo"</h2>

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

<p class="tutorials-content__text">Ellos en sus propiedades internas contienen la propiedad <code class="tutorials__code">[[Prototype]]</code> esta propiedad no puede ser accedida de manera directa, para acceder a ella utilizamos el metodo <code class="tutorials__code">Object.getPrototypeOf</code> o utilizando la propiedad <code class="tutorials__code">Object._proto__ </code>. Como resultado al acceder a <code class="tutorials__code">[[Prototype]]</code> podemos observar que dentro existe otras propiedades y metodos.</p>

<h3 class="tutorials-content__sub-title">Herencia base prototipo</h3>

<p class="tutorials-content__text">Cuando tratamos de accesar a alguna propiedad o metodo de algun objeto de JavaScript, este primero busca en el mismo objeto esa propiedad o metodo deseada, si no encuentra esa propiedad o metodo, el buscara en su propia propiedad <code class="tutorials__code">[[Prototype]]</code>, Esta propiedad nos enlazas a ese objeto padre o antecesor el cual el primer objeto que creamos hereda sus propiedades y metodos. Si en nuestro segundo intento de encontrar esa propiedad o metodo que deseamo no es encontrada, el seguira a la proxima propiedad <code class="tutorials__code">[[Prototype]]</code> y asi seguira hasta encontrar en los objetos antecesores del objeto inicial, a esto se le conoce como cadena de prototipos <b>chain prototype</b>.</p>

<p class="tutorials-content__text">Un ejemplo con el objeto array, en esencia un array es un objeto JavaScript el cual esta definido por el interpretador de JavaScript y el tiene definido unos metodos el cual utilizamos para transformar el array como por ejemplo <code class="tutorials__code">.push</code> y <code class="tutorials__code">.pop</code>.</p>

<pre>
  <code class="language-javascript">
  const clear = console.clear;
  const log = console.log;
  const dir = console.dir;

  clear();

  let y = [];
  dir(y.__proto__); 
  //-> Array(0) 
  //-> [constructor: ƒ, concat: ƒ, pop: ƒ, push: ƒ, …]

  dir(y.__proto__.__proto__); 
  //-> Object 
  //-> {constructor: ƒ, __defineGetter__: ƒ, __defineSetter__: ƒ, hasOwnProperty: ƒ, __lookupGetter__: ƒ, …}
  </code>
</pre>

<p class="tutorials-content__text">Podemos hacer varias comparaciones, para demostrar que es cierto nuestra herencias y cadena de prototipos.</p>

<pre>
  <code class="language-javascript">
  log(y.__proto__ === Array.prototype); //-> true
  log(y.__proto__.__proto__ === Object.prototype); //-> true
  log(y instanceof Array); //-> true
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Funciones como constructor</h3>

<p class="tutorials-content__text">Cuando utilizamos la palabra reservada <code class="tutorials__code">new</code> y una funcion, se dice que estamos creando un objeto utilizando una funcion como constructor. Un ejemplo de su aplicacion es cuando creamos un array utilizando la palabra reservada <code class="tutorials__code">new</code> ,<code class="tutorials__code">new Array()</code>, en este caso estamos creando un objeto o array basado al modelo <code class="tutorials__code">Array</code>.</p>

<pre>
  <code class="language-javascript">
  const clear = console.clear;
  const log = console.log;
  const dir = console.dir;

  clear();

  function User(firstName, lastName, role) {
   this.firstName = firstName;
   this.lastName = lastName;
   this.role = role;
  };

  let admin = new User('John', 'Muller', 'Administrator');

  log(admin.role); //-> Administrator
  log(admin); //-> User {firstName: "John", lastName: "John", role: "Administrator"}
  </code>
</pre>

<p class="tutorials-content__text">En el ejemplo anterior nuestro nuevo objeto <code class="tutorials__code">admin</code>, tiene como <code class="tutorials__code">[[Prototype]]</code> al objeto User, podemos verificar esto mediante el siguiente ejemplo:</p>

<pre>
  <code class="language-javascript">
  log(Object.getPrototypeOf(admin));
  //-> {constructor: ƒ} constructor: ƒ User(firstName, lastName, role)
  </code>
</pre>

<p class="tutorials-content__text">Tambien podemos crear y añadirle metodos a nuestro objecto utilizando la propiedad <code class="tutorials__code">Object.prototype</code>.</p>

<pre>
  <code class="language-javascript">
  User.prototype.getFullname = function() {
    return this.firstName + " " + this.lastName;
  }

  log(admin.getFullname()); //-> John Muller
  </code>
</pre>

<p class="tutorials-content__text">Podemos utilizar la funcion <code class="tutorials__code">.call</code> para hacer copias de propiedades de un constructor de objeto a otra funcion de creacion de objeto.</p>

<pre>
  <code class="language-javascript">
  const clear = console.clear;
  const log = console.log;
  const dir = console.dir;

  clear();

  function User(firstName, lastName, role) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.role = role;
  };

  User.prototype.getFullname = function() {
    return this.firstName + " " + this.lastName;
  }

  let admin = new User('John', 'Muller', 'Administrator');

  log(admin.role); //-> Administrator
  log(admin); //-> User {firstName: "John", lastName: "John", role: "Administrator"}

  function Member(firstName, lastName, role, payment) {
    User.call(this, firstName, lastName, role);
    this.payment = payment;
  }

  // Method Inheritance
  Member.prototype = new User;

  function Guest(firstName, lastName, role, member) {
    User.call(this, firstName, lastName, role);
    this.member = member;
  }

  Member.prototype.verifyPaid = function() {
    return this.payment
      ? 'Welcome back ' + this.firstName + '!'
      : 'Sorry ' + this.firstName + ' you last payment dont processed!';
  }

  // Method Inheritance and Method overriding
  Guest.prototype = new User;

  Guest.prototype.getFullname = function() {
    return 'Unknown user!';
  }

  Guest.prototype.verifyUserAreMember = function() {
    return this.member
      ? 'Welcome back ' + this.firstName + '!'
      : 'Sorry this area is restricted';
  }

  const member_01 = new Member('Steve', 'Morgan', 'member', true);
  log(member_01.verifyPaid()); //-> Welcome back Steve!
  log(member_01.getFullname()); //-> Steve Morgan

  const guest_01 = new Guest('Mike', 'Paul', 'guest', false);
  log(guest_01.verifyUserAreMember()); //-> Sorry this area is restricted
  log(guest_01.getFullname()); //-> Unknown user!
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Herencia moderna</h3>

<p class="tutorials-content__text">Una forma moderna enlazar <code class="tutorials__code">[[Prototype]]</code> de un objeto a otro es utilizando el metodo <code class="tutorials__code">Object.create</code>, igual que el ejemplo anterior debemos de hacer este enlace antes de crear nuevos metodos.</p>

<pre>
  <code class="language-javascript">
  Member.prototype = Object.create(User.prototype);
  Guest.prototype = Object.create(User.prototype);
  </code>
</pre>
