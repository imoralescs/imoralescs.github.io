---
layout: tutorials
title: Array "Colecciones"
---
<h2 class="tutorials-content__sub-title">Colecciones "Array"</h2>

<p class="tutorials-content__text">Array en JavaScript es un tipo de objeto global el cual utilizamos para guardar datos. Array consiste en una colleccion o lista que contiene cero o mas tipos de datos, estos array utilizan un indice como punto de inicio cero 0 y el cual ese indice tambien se utilizando para acceder al valor dentro de elemento del array.</p>

<p class="tutorials-content__text">Los array son utiles para guardar multiples valores en una simple variable, el cual pueden ser organizado por medio de codigo para que pueda ser más legible y mantenible los datos dentro del array. Un array puede contener cualquier tipo de dato incluyendo numeros, cadena de caracteres y/o objetos.</p>

<p class="tutorials-content__text">Ejemplo de como es util el uso de array:</p>

<pre>
  <code class="language-javascript">
  // Assign the five oceans to five variables
  const ocean1 = "Pacific";
  const ocean2 = "Atlantic";
  const ocean3 = "Indian";
  const ocean4 = "Arctic";
  const ocean5 = "Antarctic";

  // Using arrays, assign the five oceans
  let oceans = [
    "Pacific",
    "Atlantic",
    "Indian",
    "Arctic",
    "Antarctic",
  ];
  </code>
</pre>

<p class="tutorials-content__text">Como podemos ver en el ejemplo, en vez de crear cinco 5 variables separada, podemos usar una sola variable el cual contiene los cinco 5 element, utilizando corchete [...] simple que crea el array.</p>

<h3 class="tutorials-content__sub-title">Creacion de array</h3>

<p class="tutorials-content__text">Existen dos maneras de crear array.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Array literal, utilizando corchete simple <code class="tutorials__code">[...]</code></li>
</ul>

<pre>
  <code class="language-javascript">
  let oceans = [
    "Pacific",
    "Atlantic",
    "Indian",
    "Arctic",
    "Antarctic",
  ];

  console.log(oceans); //-> ["Pacific", "Atlantic", "Indian", "Arctic", "Antarctic"]
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Por medio de constructor, utilizando la palabra reservada new</li>
</ul>

<pre>
  <code class="language-javascript">
  let oceans = new Array(
    "Pacific",
    "Atlantic",
    "Indian",
    "Arctic",
    "Antarctic",
  );

  console.log(oceans); //-> ["Pacific", "Atlantic", "Indian", "Arctic", "Antarctic"]
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Indice array</h3>

<p class="tutorials-content__text">Los array no contienen pares de nombre/valor <b>key/value</b> como los objeto, en vez de nombre/valor <b>key/value</b>, los array contienen indice con un valor entero el cual comienza en 0.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish"
  ];
  </code>
</pre>

<p class="tutorials-content__text">En la siguen tabla, veremos un ejemplo de la relacion del indice con el array.</p>

<table class="tutorials-content__table">
  <tr>
    <th>octopus</th>
    <th>squid</th> 
    <th>shark</th>
    <th>seahorse</th>
    <th>starfish</th>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>2</td>
    <td>3</td>
    <td>4</td>
  </tr>
</table>

<p class="tutorials-content__text">Cuando creamos el array, el mismo array contiene propiedades y metodos el cual podemos utilizar para saber cual es el tamaño del array <code class="tutorials__code">.length</code> y el indice de cada elemento <code class="tutorials__code">.indexOf()</code>.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish"
  ];

  console.log(seaCreatures.length); //-> 5
  console.log(seaCreatures.indexOf("shark")); //-> 2
  </code>
</pre>

<p class="tutorials-content__text">Cuando no existe el elemento dentro del array, la funcion de <code class="tutorials__code">.indexOf()</code> nos devuelve -1</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish"
  ];

  console.log(seaCreatures.indexOf("cuttlefish")); //-> -1
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Acceso a element de array</h3>

<p class="tutorials-content__text">Para acceder a un elemento dentro del array, utilizamos la variable del array junto el indice del elemento en conchetes.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish"
  ];

  console.log(seaCreatures[2]); //-> shark
  </code>
</pre>

<p class="tutorials-content__text">Tambien podemos acceder a array anidados, utilizando la variables y indice pariente del elemento que queremos acceder.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    [
      "octopus",
      "squid",
    ],
    [
      "shark",
      "seahorse",
      "starfish"
    ]
  ];

  console.log(seaCreatures[1][0]); //-> shark
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Añadir elemento a array</h3>

<p class="tutorials-content__text">Nuestra variable contiene cinco 5 elementos, sus indices consiste de 0 a 4, si queremos añadir otro elemento podemos asignar el valor al proximo indice del array.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish"
  ];

  seaCreatures[5] = "whale";
  console.log(seaCreatures); //-> ["octopus", "squid", "shark", "seahorse", "starfish", "whale"]
  </code>
</pre>

<p class="tutorials-content__text">Si por error asignamos valor indice mas adelantado que nuestro ultimo indice disponible, el interpretador de JavaScript asignara undefined a los valores saltados.</p>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.push</code></h4>

<p class="tutorials-content__text">Para evitar problemas de añadir elementos a array en indice equivocado, podemos utilizar el metodo <code class="tutorials__code">.push</code> que nos provee el mismo array.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish"
  ];

  seaCreatures.push("whale");
  console.log(seaCreatures); //-> ["octopus", "squid", "shark", "seahorse", "starfish", "whale"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.unshift</code></h4>

<p class="tutorials-content__text">A diferencia del metodo <code class="tutorials__code">.push</code>, este metodo de array añade un nuevo valor al array al indice inicial y mueve los demas elemento al proximo indice.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish"
  ];

  seaCreatures.unshift("whale");
  console.log(seaCreatures); //-> ["whale", "octopus", "squid", "shark", "seahorse", "starfish"]
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Remover elemento de array</h3>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.splice</code></h4>

<p class="tutorials-content__text">Podemos utilizar el metodo .splice del array, este metodo utiliza el primer parametro para indicar que indice vas a utilizar como punto de partida a eliminar y el segundo parametro es cuanto elemento eliminara desde ese punto de inicio que indicaste en el primer parametro.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish",
    "whale"
  ];

  seaCreatures.splice(2, 1);
  console.log(seaCreatures); //-> ["octopus", "squid", "seahorse", "starfish", "whale"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.slice</code></h4>

<p class="tutorials-content__text">Este metodo es similar a .splice el cual remueve elemento de array, la diferencia esta en que este metodo crea un nuevo array y evita modificar el array original. Segundo la manera de implementacion es diferente, el primer parametro es el indice de elemento que desea que sea parte de este nuevo array modificado y el segundo parametro el indice hasta cual indice desea que sea incluido dentro del nuevo array.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish",
    "whale"
  ];

  let newSeaCreatures = seaCreatures.slice(2, 5);
  console.log(newSeaCreatures); //-> ["shark", "seahorse", "starfish"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.pop</code></h4>

<p class="tutorials-content__text">Metodo <code class="tutorials__code">.pop</code> de array elimina el ultimo elemento de un array.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish",
    "whale"
  ];

  seaCreatures.pop();
  console.log(seaCreatures); //-> ["octopus", "squid", "shark", "seahorse", "starfish"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.shift</code></h4>

<p class="tutorials-content__text">Al contrario de <code class="tutorials__code">.unshift</code> este remueve elemento inicial del array.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish",
    "whale"
  ];

  seaCreatures.shift();
  console.log(seaCreatures); //-> ["squid", "shark", "seahorse", "starfish", "whale"]
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Modificar elementos en array</h3>

<p class="tutorials-content__text">Para modificar un array simplemente podemos usar el operador de asignacion.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish",
    "whale"
  ];

  seaCreatures[0] = "manatee";
  console.log(seaCreatures); //-> ["manatee", "squid", "shark", "seahorse", "starfish", "whale"]
  </code>
</pre>

<p class="tutorials-content__text">Otra manera que podemos modificar un array es utilizando un tercer parametro en el metodo de array <code class="tutorials__code">.splice</code>, este tercer parametro es el nuevo valor.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish",
    "whale"
  ];

  seaCreatures.splice(2, 1, "manatee");
  console.log(seaCreatures); //-> ["octopus", "squid", "manatee", "seahorse", "starfish", "whale"]
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Iteraciones atraves de array</h3>

<p class="tutorials-content__text">Podemos hacer iteraciones por los array utilizando bucles <code class="tutorials__code">for</code>.</p>

<pre>
  <code class="language-javascript">
  let seaCreatures = [
    "octopus",
    "squid",
    "shark",
    "seahorse",
    "starfish",
    "whale"
  ];

  for(let i = 0; i < seaCreatures.length; i++) {
      console.log(i, seaCreatures[i]);
  }
  //-> 0 "octopus"
  //-> 1 "squid"
  //-> 2 "shark"
  //-> 3 "seahorse"
  //-> 4 "starfish"
  //-> 5 "whale"
  </code>
</pre>

<p class="tutorials-content__text">Tambien podemos utilizar bucles <code class="tutorials__code">for...of</code>, este bucle es parte de las nuevas funcionalidades de JavaScript.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "crystal"
  ];

  for(let game of pokemonGames) {
      console.log(game);
  }
  //-> "red"
  //-> "blue"
  //-> "yellow"
  //-> "gold"
  //-> "silver"
  //-> "crystal"
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Metodos mutadores</h3>

<p class="tutorials-content__text">Como hemos visto, los array contienen metodos propios el cual podemos utilizar para transformar el propio array, estas transformaciones modifican el propio array, a esto se le conoce como metodos mutadores.</p>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.isArray</code></h4>

<p class="tutorials-content__text">Este metodos nos ayuda a verificar si una variable es un array, este devuelve un valor booleano indicando la validez.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "crystal"
  ];

  console.log(Array.isArray(pokemonGames)); //-> true
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.pop</code></h4>

<p class="tutorials-content__text">Metodo remueve ultimo elemento al final de elementos en array.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "crystal"
  ];

  pokemonGames.pop();
  console.log(pokemonGames); //-> ["red", "blue", "yellow", "gold", "silver"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.shift</code></h4>

<p class="tutorials-content__text">Metodo remueve primer elemento al inicio de elementos en array.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "crystal"
  ];

  pokemonGames.shift();
  console.log(pokemonGames); //-> ["blue", "yellow", "gold", "silver", "crystal"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.push</code></h4>

<p class="tutorials-content__text">Metodo añade elemento al final de elementos en array.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.push("crystal");
  console.log(pokemonGames); //-> ["red", "blue", "yellow", "gold", "silver", "crystal"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.unshift</code></h4>

<p class="tutorials-content__text">Metodo añade elemento al inicio de elementos de array.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.unshift("crystal");
  console.log(pokemonGames); //-> ["crystal", "red", "blue", "yellow", "gold", "silver"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.splice</code></h4>

<p class="tutorials-content__text">Metodo puede añadir como remover elemento en cualquier posicion de array, como hecho puede hacerlo de manera simultanea. Metodo .splice acepta tres parametro, el primero es el indice donde comienza, segundo cuantos elementos a eliminar desde el punto indice definido en el primer parametro y el tercer parametro que es opcional es el valor el cual quieres incluir en sustitucion de los eliminados.</p>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Añadir con <code class="tutorials__code">.splice</code></li>
</ul>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.splice(1, 0, "ruby");
  console.log(pokemonGames); //-> ["red", "ruby", "blue", "yellow", "gold", "silver"]
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Remover con <code class="tutorials__code">.splice</code></li>
</ul>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.splice(1, 2);
  console.log(pokemonGames); //-> ["red", "gold", "silver"]
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" >Añadir y remover con <code class="tutorials__code">.splice</code></li>
</ul>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.splice(1, 2, "ruby");
  console.log(pokemonGames); //-> ["red", "ruby", "gold", "silver"]
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" ><code class="tutorials__code">.reverse</code></li>
</ul>

<p class="tutorials-content__text">Metodo puede cambiar el orden de elemento del array.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.reverse();
  console.log(pokemonGames); //-> ["silver", "gold", "yellow", "blue", "red"]
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" ><code class="tutorials__code">.fill</code></li>
</ul>

<p class="tutorials-content__text">Metodo puede remplazar todos los elemento del array a un valor estatico.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.fill("ruby");
  console.log(pokemonGames); //-> ["ruby", "ruby", "ruby", "ruby", "ruby"]
  </code>
</pre>

<p class="tutorials-content__text">Este metodo tambien como opcion puede aceptar dos mas parametros, el primero es indice de inicio el cual comienza el remplazo y segundo punto indice el cual termina el remplazo.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.fill("ruby", 1, 3);
  console.log(pokemonGames); //-> ["red", "ruby", "ruby", "gold", "silver"]
  </code>
</pre>

<ul class="tutorials-content__list">
  <li class="tutorials-content__list-element" ><code class="tutorials__code">.sort</code></li>
</ul>

<p class="tutorials-content__text">Metodo nos permite organizar los elemento base a la primera letra de cada elemento o numero enteros.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  pokemonGames.sort();
  console.log(pokemonGames); //-> ["blue", "gold", "red", "silver", "yellow"]
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Metodos accesor</h3>

<p class="tutorials-content__text">Metodos accesor son esos tipos de metodo al contrario de los mutadores que crean o devuelven un nuevo array transformado y evita cambiar el array original, tambien conocido como inmutadores.</p>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.concat</code></h4>

<p class="tutorials-content__text">Metodo nos ayuda a unir dos array.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  let pokemonNewGames = [
    "sun",
    "moon"
  ];

  let pokemon = pokemonGames.concat(pokemonNewGames);
  console.log(pokemon); //-> ["red", "blue", "yellow", "gold", "silver", "sun", "moon"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.join</code></h4>

<p class="tutorials-content__text">Metodo convierte el array en una cadena de caracteres, cada elemento sera separado por comas.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  let pokemonGame = pokemonGames.join();
  console.log(pokemonGame); //-> red,blue,yellow,gold,silver
  </code>
</pre>

<p class="tutorials-content__text">Este metodo tambien puede recibir un parametro el cual es utilizado para sustituir la coma entre elementos.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  let pokemonGame = pokemonGames.join(', ');
  console.log(pokemonGame); //-> red, blue, yellow, gold, silver
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.slice</code></h4>

<p class="tutorials-content__text">Metodo copia una porcion de un array a un nuevo array. Primer parametro es el indice el cual comienza y segundo parametro es donde termina la copia.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  let pokemonGame = pokemonGames.slice(1, 3);
  console.log(pokemonGame); //-> ["blue", "yellow"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.indexOf</code></h4>

<p class="tutorials-content__text">Metodo nos devuelve el indice del elemento.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver"
  ];

  console.log(pokemonGames.indexOf("yellow")); //-> 2
  </code>
</pre>

<p class="tutorials-content__text">En este metodo cuando no encuentra el valor, este devuelve el valor de negativo uno -1.</p>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.lastIndexOf</code></h4>

<p class="tutorials-content__text">Metodo nos devuelve el indice del ultimo elemento de array el cual es utilizado varias veces.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "blue"
  ];

  console.log(pokemonGames.lastIndexOf("blue")); //-> 5
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Metodos de iteración</h3>

<p class="tutorials-content__text">Una tercera clase de metodos en array es la iteracion, estos metodos nos permite aplicar operaciones como funciones a cada elemento del array. Estos metodos tambien devuelve como resultado un nuevo array con la transformacion del array por aplicar la operacion o funcion.</p>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.forEach</code></h4>

<p class="tutorials-content__text">Metodo llama y aplica una funcion a cada elemento del array.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "blue"
  ];

  pokemonGames.forEach((game) => {
    console.log(game);
  });
  //-> red
  //-> blue
  //-> yellow
  //-> gold
  //-> silver
  //-> blue
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.map</code></h4>

<p class="tutorials-content__text">Metodo crea un nuevo array luego de haber aplicado una funcion.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "blue"
  ];

  let games = pokemonGames.map((game) => {
    return `${game} !`;
  });

  console.log(games); //-> ["red !", "blue !", "yellow !", "gold !", "silver !", "blue !"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.filter</code></h4>

<p class="tutorials-content__text">Metodo crea un nuevo array con elementos el cual cumpla las condiciones de la operacion o funcion aplicada.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "blue"
  ];

  let games = pokemonGames.filter((game) => {
      return game[0] === "b";
  });

  console.log(games); //-> ["blue", "blue"]
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.reduce</code> fold</h4>

<p class="tutorials-content__text">Metodo reduce un array a un valor simple.</p>

<pre>
  <code class="language-javascript">
  let numbers = [42, 23, 16, 15, 5, 8];

  let sum = numbers.reduce((a, b) => {
    return a + b;
  });

  console.log(sum); //-> 109
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.find</code></h4>

<p class="tutorials-content__text">Metodo devuelve el primer valor que cumpla las condiciones de la operacion o funcion aplicada.</p>

<pre>
  <code class="language-javascript">
  let pokemonGames = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "blue"
  ];

  const pokemonNewGames = newGame => {
    return ["blue", "moon", "sun"].includes(newGame);
  }

  let game = pokemonGames.find(pokemonNewGames)

  console.log(game); //-> blue
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">.findIndex</code></h4>

<p class="tutorials-content__text">Metodo devuleve el primer elemento del array el cual cumpla las condiciones de la operacion o funcion aplicada. Si no encuentra lo que deseamos, devolvera el negativo uno -1.</p>
