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

<h3 class="tutorials-content__sub-title">Propiedades y metodos</h3>

<p class="tutorials-content__text">Las propiedades estan asociadas entre un nombre (llave "key") y el valor dentro del objeto, esto valores pueden ser representado por cualquier tipo de datos. Las propiedades comunmente hacen referencias a caracteristicas de algun objeto. Metodos son funciones el cual pueden transformar los valores de las propiedades del objeto.</p>

<h4 class="tutorials-content__sub-title">Acceso a propiedades del objeto</h4>

<p class="tutorials-content__text">Existen dos maneras de accesar las propiedades de un objeto.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Notacion de punto</li>
</ul>

<pre>
  <code class="language-javascript">
  const Person = {
    firstName: 'Steve ',
    lastName: 'McNiller',
    sayName: function() {
      console.log(this.firstName + this.lastName);
    }
  }

  console.log(Person.firstName); //-> Steve
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Notacion de corchetes</li>
</ul>

<pre>
  <code class="language-javascript">
  const Person = {
    firstName: 'Steve ',
    lastName: 'McNiller',
    sayName: function() {
      console.log(this.firstName + this.lastName);
    }
  }

  console.log(Person['firstName']); //-> Steve
  </code>
</pre>

<p class="tutorials-content__text">De las mismas manera podemos llamar metodos dentro del objetos.</p>

<pre>
  <code class="language-javascript">
  const Person = {
    firstName: 'Steve ',
    lastName: 'McNiller',
    sayName: function() {
      console.log(this.firstName + this.lastName);
    }
  }

  Person.sayName(); //-> Steve McNiller
  Person['sayName'](); //-> Steve McNiller
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Añadir o modificar propiedades de objeto</h4>

<p class="tutorials-content__text">Para añadir propiedades a objeto o modificarlo, utilizamos el operador de asignacion y cualquiera de los tipo de notacion.</p>

<pre>
  <code class="language-javascript">
  const Person = {
    firstName: 'Steve ',
    lastName: 'McNiller',
    sayName: function() {
      console.log(this.firstName + this.lastName);
    }
  }

  Person.age = 28;
  console.log(Person); //-> {firstName: "Steve ", lastName: "McNiller", sayName: ƒ, age: 28}

  Person['sex'] = 'Male';
  console.log(Person); //-> {firstName: "Steve ", lastName: "McNiller", sayName: ƒ, age: 28, sex: "Male"}
  </code>
</pre>

<p class="tutorials-content__text">De la misma manera podemos añadir metodos.</p>

<pre>
  <code class="language-javascript">
  const Person = {
    firstName: 'Steve ',
    lastName: 'McNiller',
    sayName: function() {
      console.log(this.firstName + this.lastName);
    }
  }

  Person.age = 28;
  Person['sex'] = 'Male';

  Person.sayAge = function() {
    console.log('My age is ' + this.age)
  };

  Person.sayAge(); //-> My age is 28
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Remover propiedades del objeto</h4>

<p class="tutorials-content__text">Para remover una propiedad dentro del objeto podemos utilizar la palabra reservada delete junto a la propiedad que deseamos remover. Al remover la propiedad tendremos de vuelta el valor cierto indicando que la propiedad a sido exitosamente removida de la propiedad.</p>

<pre>
  <code class="language-javascript">
  const Person = {
    firstName: 'Steve ',
    lastName: 'McNiller',
    sayName: function() {
      console.log(this.firstName + this.lastName);
    }
  }

  Person.age = 28;

  const confirmObjDel = delete Person.age;

  console.log(confirmObjDel); //-> true
  console.log(Person); //-> {firstName: "Steve ", lastName: "McNiller", sayName: ƒ}
  </code>
</pre>

<h4 class="tutorials-content__sub-title">Iteraciones atravez de propiedades de objeto</h4>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Por medio de <code class="tutorials__code">for...in</code></li>
</ul>

<pre>
  <code class="language-javascript">
  const Person = {
    firstName: 'Steve ',
    lastName: 'McNiller',
    age: 28,
    sayName: function() {
      console.log(this.firstName + this.lastName);
    }
  }

  for(let key in Person) {
    console.log(Person[key]);
  }

  //-> Steve
  //-> McNiller
  //-> 28
  //-> f()
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Utilizando metodo de <b>Object()</b> <code class="tutorials__code">Object.keys()</code> este metodo devuelve un Array de los valores del objeto el cual aplicamos el metodo.</li>
</ul>

<pre>
  <code class="language-javascript">
  const Person = {
    firstName: 'Steve ',
    lastName: 'McNiller',
    age: 28,
    sayName: function() {
      console.log(this.firstName + this.lastName);
    }
  }

  const PersonArray = Object.keys(Person);
  console.log(PersonArray); //-> ["firstName", "lastName", "age", "sayName"]
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Descriptor de propiedad del objeto</h3>

<p class="tutorials-content__text">Descriptores de objetos en JavaScript, son elemento dentro de los objetos en JavaScript el cual nos provee mas informacion sobre las propiedades dentro de nuestros objetos en JavaScript, estas propiedades determinan el estado del objeto en JavaScript.</p>

<p class="tutorials-content__text">Los objetos en JavaScript contiene los descriptores de dato, esto son <code class="tutorials__code">[[value]]</code>, <code class="tutorials__code">[[writable]]</code>, <code class="tutorials__code">[[configurable]]</code>, <code class="tutorials__code">[[enumerable]]</code> y descriptores de accessor el cual son <code class="tutorials__code">[[get]]</code>, <code class="tutorials__code">[[set]]</code>, <code class="tutorials__code">[[configurable]]</code> y <code class="tutorials__code">[[enumerable]]</code>.</p>

<pre>
  <code class="language-javascript">
  let obj = {
    name: 'Pete'
  };
  </code>
</pre>

<p class="tutorials-content__text">Por defecto cuando nosotros creamos un objeto como el ejemplo anterior, este objeto obtiene los valores por defecto. Basado al ejemplo anterior, <code class="tutorials__code">[[value]]</code> es el valor de name <code class="tutorials__code">'Pete'</code>, el cual es lo que muestra como salida, si escribimos los siguiente <code class="tutorials__code">console.log(obj.name)</code>. <code class="tutorials__code">[[writable]]</code> esta definido como cierto <b>"true"</b>, esto significa que esta permitido cambiar el valor del objeto. <code class="tutorials__code">[[configurable]]</code> esta definido como cierto <b>"true"</b>, este nos permite cambiar o utilizar las propiedades mencionadas. <code class="tutorials__code">[[enumerable]]</code> significa que si le aplicamos un bucle <code class="tutorials__code">for...in</code> al objeto de JavaScript, podemos recorrer por las propiedades definidas dentro del objeto JavaScript.</p>

<p class="tutorials-content__text">Los descriptores accessor o metodos de mutacion son metodos que nos permite buscar datos privado dentro de objetos, a estos metodos se les llama comunmente <code class="tutorials__code">[[getter]]</code> y <code class="tutorials__code">[[setter]]</code>.</p>

<p class="tutorials-content__text">En JavaScript los objetos contienen unos metodos el cual nos permiten definir y configurar objetos utilizando descriptores.</p>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.defineProperty</code></h4>

<p class="tutorials-content__text">Metodos es uno de los principales para manejar y configurar objetos.</p>

<pre>
  <code class="language-javascript">
  // Example of used
  Object.defineProperty(obj, propName, {})
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let user = {};
  Object.defineProperty(user, "firstName", {
    value: "Peter",
    configurable: true,
    writable: true,
    enumerable: true
  });

  console.log(user.firstName); //-> Peter
  </code>
</pre>

<p class="tutorials-content__text">Por defecto cuando definimos una propiedad dentro del objeto utilizando <code class="tutorials__code">Object.defineProperty</code>, si no le asignamos un valor utilizando <code class="tutorials__code">[[value]]</code>, este se creara con el valor <code class="tutorials__code">undefined</code></p>

<pre>
  <code class="language-javascript">
  let user = {};
  Object.defineProperty(user, "firstName", {
    configurable: true,
    writable: true,
    enumerable: true
  });

  console.log(user.firstName); //-> undefined
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.defineProperties</code></h4>

<p class="tutorials-content__text">Metodos nos permite definir varias propiedades a la misma vez.</p>

<pre>
  <code class="language-javascript">
  Object.defineProperties(obj, props)
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let user = {};
  Object.defineProperties(user, {
    firstName: {
      value: "Peter",
      writable: true
    },
    getName: {
      value: function() {
        console.log(this.firstName);
      }
    },
  });

  user.getName(); //-> Peter
  </code>
</pre>

<p class="tutorials-content__text">Observemos mas ejemplo del uso de estos metodos, digamos que queremos definir propiedades que nunca cambien, que sea constante.</p>

<pre>
  <code class="language-javascript">
  let user = {};
  Object.defineProperty(user, "firstName", {
    value: "Peter",
    writable: false,
    configurable: false
  });

  user.firstName = "Mike";
  console.log(user.firstName); // Peter
  </code>
</pre>

<p class="tutorials-content__text">Digamos que ahora en el proximo ejemplo queremos ocultar propiedades dentro del objeto en JavaScript.</p>

<pre>
  <code class="language-javascript">
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };

  Object.defineProperty(user, "socialSecNum", {
    value: "555-89-7844",
    enumerable: false
  });

  for(let prop in user) {
    console.log(prop);
  }
  //-> firstName
  //-> lastName
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.getOwnPropertyNames</code> and <code class="tutorials__code">Object.keys</code></h4>

<p class="tutorials-content__text">Metodos son familiar al metodo keys dictionary del lenguaje de programacion Python, estos nos devuelve un array de las propiedades que se encuentran dentro del objeto de JavaScript, la diferencia entre <code class="tutorials__code">Object.getOwnPropertyNames</code> y <code class="tutorials__code">Object.keys</code> es que <code class="tutorials__code">Object.getOwnPropertyNames</code> nos devuleve todas las propiedades incluyendo las configurada como falso en enumerable.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };

  Object.defineProperty(user, "socialSecNum", {
    value: "555-89-7844",
    enumerable: false
  });

  log(Object.getOwnPropertyNames(user)); //-> ["firstName", "lastName", "socialSecNum"]
  log(Object.keys(user)); //-> ["firstName", "lastName"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.values</code></h4>

<p class="tutorials-content__text">Metodo es similar a <code class="tutorials__code">Object.keys</code>, este nos devuelve el valor de cada propiedad y al igual que <code class="tutorials__code">Object.keys</code>, este no retornara propiedades definidas falsa en <code class="tutorials__code">[[enumerable]]</code>.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };

  Object.defineProperty(user, "socialSecNum", {
    value: "555-89-7844",
    enumerable: false
  });

  log(Object.values(user)); //-> ["firstName", "lastName"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.getOwnPropertyDescriptor</code></h4>

<p class="tutorials-content__text">Metodo nos devuelve los descriptores de una propiedad especifica que se encuentra dentro del objeto de JavaScript.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };
  log(Object.getOwnPropertyDescriptor(user, "firstName")); 
  //-> {value: "Peter", writable: true, enumerable: true, configurable: true}
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.getOwnPropertyDescriptors</code></h4>

<p class="tutorials-content__text">Metodo es similar a <code class="tutorials__code">Object.getOwnPropertyDescriptor</code>, la diferencia es que este nos devuelve todas las propiedades que se encuentre dentro del objeto JavaScript con sus descriptores.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };
  log(Object.getOwnPropertyDescriptors(user)); //-> {firstName: {…}, lastName: {…}}
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Getter and Setter</h3>

<p class="tutorials-content__text">Estos son descriptores de accessor o metodos de mutacion de objeto. Al contrario de los descriptores de dato, estos substituyen a los descriptores <code class="tutorials__code">[[value]]</code> y <code class="tutorials__code">[[writable]]</code>. <code class="tutorials__code">[[get]]</code> es la funcion por defecto que se ejecutara cuando llamamos a alguna propiedad el cual le asignamos este metodo <code class="tutorials__code">[[get]]</code>, por defecto sera <code class="tutorials__code">undefined</code> el valor que devuelve, cuando asignamos un valor a alguna propiedad, el metodo <code class="tutorials__code">[[set]]</code> es llamado y aplicado a esa propiedad que se la asignamos.</p>

<pre>
  <code class="language-javascript">
  let obj = {
    get propName() {
      // Getter, the code executed on getting obj.propName
    },
    set propName(value) {
      // Setter, the code executed on setting obj.propName = value
    }
  }
  </code>
</pre>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };

  Object.defineProperty(user, "fullName", {
    get: function() {
      return this.firstName + " " + this.lastName;
    },
    set: function(value) {
      let parts = value.split(' ');

      if(parts.length == 2) {
        this.firstName = parts[0];
        this.lastName = parts[1];
      }
      else {
        throw 'Invalid name format'
      }
    }
  });

  log(user.fullName); //-> Peter Jackson

  user.fullName = "Steve Finn";

  log(user.firstName); //-> Steve
  log(user.lastName); //-> Finn
  log(user.fullName); //-> Steve Finn
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Control el estado del objeto</h3>

<p class="tutorials-content__text">Existen momento el cual queremos prevenir que nuestros objetos esten en el estado de lectura o escritura, los objetos de JavaScript nos provee tres metodos para evitar estos cambios o usos. Estos metodos son: <code class="tutorials__code">Object.preventExtensions</code>, <code class="tutorials__code">Object.seal</code>, <code class="tutorials__code">Object.freeze</code></p>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.preventExtensions</code></h4>

<p class="tutorials-content__text">Metodo previene que el objeto de JavaScript sea extendible.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };
  Object.preventExtensions(user);

  Object.defineProperty(user, "age", {
    value: 22
  });

  user.age = "one";
  log(user.age); //-> Cannot define property age, object is not extensible
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.isExtensible</code></h4>

<p class="tutorials-content__text">Metodo nos devuelve un valor booleano que nos notifica si el objeto JavaScript puede ser extensible.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };

  log(Object.isExtensible(user)); //-> true
  Object.preventExtensions(user);
  log(Object.isExtensible(user)); //-> false
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.seal</code></h4>

<p class="tutorials-content__text">Metodo previene que podamos añadir o eliminar propiedades a objetos de JavaScript pero si nos permite editar propiedades del objeto de JavaScript, el objeto estara sellado.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };

  Object.seal(user);

  delete user.firstName;
  log(user.firstName); //-> Peter

  user.fullName = "Peter Jackson";
  log(user.fullName); //-> undefined

  user.firstName = "Tom";
  log(user.firstName); //-> Tom
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.isSealed</code></h4>

<p class="tutorials-content__text">Metodo nos devuleve un valor booleano que nos notifica se el objeto esta sellado.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };

  Object.seal(user);
  log(Object.isSealed(user)); //-> true
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">Object.freeze</code> and <code class="tutorials__code">Object.isFrozen</code></h4>

<p class="tutorials-content__text">Metodo es similar a <code class="tutorials__code">Object.seal</code>, la diferencia es que este objeto ademas que evita añadir y eliminar propiedades, no dejara editar propiedades. Este objeto estara completamente como una variable constante. <code class="tutorials__code">Object.isFrozen</code> nos devuelve un valor booleano para notificar si nuestro objeto esta congelado.</p>

<pre>
  <code class="language-javascript">
  const log = console.log;
  let user = {
    firstName: "Peter",
    lastName: "Jackson"
  };

  Object.freeze(user);
  user.fullName = "Peter Jackson";

  log(Object.isFrozen(user)); //-> true
  log(user.fullName);

  user.firstName = "Tom";
  log(user.firstName); //-> Peter
  </code>
</pre>
