---
layout: tutorials
title: Closure "Clausura"
---
<h2 class="tutorials-content__sub-title">Closure "Clausura"</h2>

<p class="tutorials-content__text">Los closures "clausuras" son funciones que manejan variables independientes. En otras palabras, la funcion definida en el closure "recuerda" el entorno en el que se ha creado. - <a  class="tutorials-content__reference-link--inline" href='https://developer.mozilla.org/es/docs/Web/JavaScript/Closures'>mdn</a></p>

<p class="tutorials-content__text">Para entender el concepto digamos que tenemos la siguiente función el cual nos regresa un objeto. Este objeto y sus propiedades estarán basada en los argumentos que le entremos a la función.</p>

<pre>
  <code class="language-javascript">
    function getStudent(name, neighborhood) {
      return {
        name,
        neighborhood
      }
    }
    
    const studentOne = getStudent('Sebasthian', 'Indian Rock')
    const studentTwo = getStudent('Markus', 'Anona')
    
    const students = [
      studentOne,
      studentTwo
    ]
    
    console.log(students) //-> [{name: "Sebasthian", neighborhood: "Indian Rock" }, {name: "Markus", neighborhood: "Anona"}]
  </code>
</pre>

<p class="tutorials-content__text">En el ejemplo la función nos crea un objeto llamado estudiante "student", la utilizamos uno a uno para crear múltiples objetos llamado estudiantes, luego inicializamos una instancia de colección "Array" para crear una lista de estudiantes "students". En orden de poder distinguir cada estudiante en la lista debemos añadirle a cada objeto estudiante un número de identificación, este número identificador se lo debemos asignar dentro de la función el cual crea el objeto estudiante, porque cuando utilizamos la función, no queremos tener que preocupar por cual número de identificación le daremos a cada objeto.</p>

<pre>
  <code class="language-javascript">
    function getStudent(name, neighborhood) {
      let studentNumber = 1
      return {
        identifier: studentNumber,
        name,
        neighborhood
      }
    }
    
    const studentOne = getStudent('Sebasthian', 'Indian Rock')
    const studentTwo = getStudent('Markus', 'Anona')
    
    const students = [
      studentOne,
      studentTwo
    ]
    
    console.log(students) 
    //-> [{identifier: 1, name: "Sebasthian", neighborhood: "Indian Rock" }, {identifier: 1, name: "Markus", neighborhood: "Anona"}]
  </code>
</pre>

<p class="tutorials-content__text">Por el momento cada objeto estudiante tienen como número de estudiante el número 1, el cual no es correcto ya que el número de identificación debería ser único en la lista de estudiantes, usualmente este número de estudiante debería incrementar por uno cada vez que un objeto estúdiate es introducido a la lista de estudiantes.</p>

<p class="tutorials-content__text">La función para crear el objeto estudiante no puede añadir el número correcto al objeto estudiante sin que algún valor externo de la función le diga cual seria el número correcto. Este valor externo ayudara a tener un seguimiento del número que le corresponde a cada objeto estudiante el cual cree la función.</p>

<pre>
  <code class="language-javascript">
    let studentNumber = 1
    
    function getStudent(name, neighborhood) {
      return {
        identifier: studentNumber++,
        name,
        neighborhood
      }
    }
    
    const studentOne = getStudent('Sebasthian', 'Indian Rock')
    const studentTwo = getStudent('Markus', 'Anona')
    
    const students = [
      studentOne,
      studentTwo
    ]
    
    console.log(students) 
    //-> [{identifier: 1, name: "Sebasthian", neighborhood: "Indian Rock" }, {identifier: 2, name: "Markus", neighborhood: "Anona"}]
  </code>
</pre>

<p class="tutorials-content__text">Al Mover una variable fuera del ámbito de la función a un ámbito global para tener seguimiento del valor que corresponde a cada objeto estudiante, hemos solucionado un problema. Pero ahora tenemos el siguiente problema.</p>

<pre>
  <code class="language-javascript">
    let studentNumber = 1
    
    function getStudent(name, neighborhood) {
      return {
        identifier: studentNumber++,
        name,
        neighborhood
      }
    }
    
    const studentOne = getStudent('Sebasthian', 'Indian Rock')
    studentNumber = 50
    const studentTwo = getStudent('Markus', 'Anona')
    
    const students = [
      studentOne,
      studentTwo
    ]
    
    console.log(students) 
    //-> [{identifier: 1, name: "Sebasthian", neighborhood: "Indian Rock" }, {identifier: 50, name: "Markus", neighborhood: "Anona"}]
  </code>
</pre>

<p class="tutorials-content__text">Como ahora la variable el cual sigue el valor de identificación de cada objeto estudiante esta en un ámbito global, este valor puede ser alterado de forma muy sencilla o puede ser alterado por error de la lógica de nuestro código. Es aquí que las clausura (Closure) nos ayudan con los problema de las variables y sus ámbitos.</p>

<pre>
  <code class="language-javascript">
    function getStudentFactory() {
      let studentNumber = 1
      return function(name, neighborhood) {
        return {
          identifier: studentNumber++,
          name,
    	    neighborhood
  	    }
	    }
    }
    
    const getStudent = getStudentFactory()
    
    const studentOne = getStudent('Sebasthian', 'Indian Rock')
    const studentTwo = getStudent('Markus', 'Anona')
    
    const students = [
      studentOne,
      studentTwo
    ]
    
    console.log(students) 
    //-> [{identifier: 1, name: "Sebasthian", neighborhood: "Indian Rock" }, {identifier: 2, name: "Markus", neighborhood: "Anona"}]
  </code>
</pre>

<p class="tutorials-content__text">Las clausura (Closure) es una técnica de encapsulamiento, basada en el anidamiento de funciones, en otras palabras funciones dentro de otra función que permite crear privacidad, Para que dé este modo, el ámbito (Scope) de una función interna contenga como también o pueda heredar el ámbito de una función padre, eh incluso si esta función padre ya ha devuelto algún valor, pues conservar dicho ámbito en caché o memoria, dentro de la clausura.</p>


<h2 class="tutorials-content__sub-title">Casos de uso útiles para clausura (Closure) en JavaScript</h2>

<h3 class="tutorials-content__sub-title">Problemas con iteración</h3>

<pre>
  <code class="language-javascript">
    let 
      fns = [], 
      gns = []
      
    for(var i = 0; i < 5; i++) {
      var c = i * 2
      fns.push( _ => console.log(c))
    }
      
    fns.forEach(f => f()) //-> 8 8 8 8 8
      
    for(var i = 0; i < 5; i++) {
      ( _ => {
	var c = i * 2
	gns.push( _ => console.log(c))
      })()
    }
      
    gns.forEach(f => f()) //-> 0 2 4 6 8
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Simular enfoque de variables privadas</h3>

<pre>
  <code class="language-javascript">
    class MyClass {
      constructor(fname, lname) {
        this.first_name = fname
        this.last_name = lname
      }
      
      getFullName() {
  	return [this.first_name, this.last_name].join(" ")
      }
      
      setFirstName(fn) {
        this.first_name = fn
      }
      
      setLastName(ln) {
        this.last_name = ln
      }
    }

    const person_01 = new MyClass('Marcus', 'Right')
    console.log(person_01.getFullName()) //-> Marcus Right

    function MyObject(fn, ln) {
      let
        fname = fn,
	lname = ln
    
      const getFullName = () => {
        return [fname, lname].join(" ")
      }
      
      const setFirstName = first => {
        fname = first
      }
      
      const setLastName = last => {
        lname = last
      }
      
      return {
        getFullName,
	setFirstName,
	setLastName
      }
    }
    
    const person_02 = new MyObject('Peter', 'Twice')
    console.log(person_02.getFullName()) //-> Peter Twice
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Ejecución retrasada</h3>

<pre>
  <code class="language-javascript">
    function greetDelay(delay) {
      let greet = "Hello world!"
      
      setTimeout( _ => {
        console.log(greet)
      }, delay)
      
      return "Done!"
    }
    
    console.log(greetDelay(1000))
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Composición de funciónes</h3>

<pre>
  <code class="language-javascript">
    const makeIncrementer = function(a) {
      return function(b) {
        return a + b
      }
    }

    const incBy10 = makeIncrementer(10)

    console.log(incBy10(5)) //-> 15
  </code>
</pre>
