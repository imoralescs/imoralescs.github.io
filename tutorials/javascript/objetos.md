---
layout: tutorials
title: Objetos
---
<h2 class="tutorials-content__sub-title">Objetos</h2>

<p class="tutorials-content__text">Un objecto en JavaScript es un tipo de dato que se compone de una coleccion de nombres o llave y valores representados en pares de nombre: valor <b>"name:value"</b>. Los pares de nombre:valor <b>"name:value"</b>, pueden consistir de propiedades <b>"properties"</b> el cual contiene cualquier valor numerico, cadena de caracteres, nulo, undefined o booleano, al igual que metodos <b>"methods"</b> el cual es una funcion dentro del objeto.</p>

<p class="tutorials-content__text">Un objeto de JavaScript puede ser completamente enlazada a una entidad independiente como un objeto de la vida real. Por ejemplo un libro, el cual como objeto podemos describirlo por titulo, autor, numeros de paginas y/o genero. Similar a un vehiculo el cual puede describirse por color, desarrollador, modelo y/o poder de fuerza.</p>

<h3 class="tutorials-content__sub-title">Creacion de objeto</h3>

<p class="tutorials-content__text">Objeto en JavaScript es un tipo de dato, asi como numeros o cadena de caracteres. Como tipo de dato los objetos puede ser contenida en una variable. Existe dos formas de construir un objeto de JavaScript.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Objeto literal, usando pareas de llaves <code class="tutorials__code">{...}</code></li>
</ul>

<pre>
  <code class="language-javascript">
  const objectLiteral = {};
  console.log(typeof objectLiteral); //-> Object

  let Person = {
    name: "John"
  };

  console.log(Person.name); //-> John
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Constructor de objeto, el cual es utilizando la palabra reservada <code class="tutorials__code">new</code></li>
</ul>

<pre>
  <code class="language-javascript">
  const objectConstructor = new Object();
  console.log(typeof objectConstructor); //-> Object

  let Person = new Object();
  Person.name = "John";

  console.log(Person.name); //-> John
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Utilizando el metodo de <b>Objeto()</b> <code class="tutorials__code">Object.create()</code></li>
</ul>

<pre>
  <code class="language-javascript">
  const objectCreate = Object.create(null);
  console.log(typeof objectCreate); //-> Object

  let Person = Object.create(null);
  Person.name = "John";

  console.log(typeof Person); //-> Object
  console.log(Person.name); //-> John
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Utilizando una funcion en combinacion de la palabra reservada <code class="tutorials__code">new</code></li>
</ul>

<pre>
  <code class="language-javascript">
  function myObject() {};
  const objectFunction = new myObject();
  console.log(typeof myObject); //-> Function
  console.log(typeof objectFunction); //-> Object

  function Person(name) {
    this.name = name;
  };

  let john = new Person("John");

  console.log(typeof Person); //-> Function
  console.log(typeof john); //-> Object
  console.log(john.name); //-> John
  </code>
</pre>
