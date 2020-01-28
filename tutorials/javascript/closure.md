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

<p class="tutorials-content__text">En el ejemplo la funcion nos crea un objeto llamado estudiante "student", esta funcion la utilizamos uno a uno para crear multiples objetos llamado estudiantes, luego inicializamos una instancia de coleccion "Array" para crear una lista de estudiantes "students". En orden de poder distinguir cada estudiante en la lista debemos añadirle a cada objeto estudiante un numero de identificacion, este numero identificador se lo debemos asignar dentro de la funcion el cual crea el objeto estudiante, porque cuando utilizamos la funcion, no queremos tener que preocuparno por cual numero de identificacion le daremos a cada objeto.</p>

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

<p class="tutorials-content__text">Por el momento cada objeto estudiante tienen como numero de estudiante el numero 1, el cual no es correcto ya que el numero de identificacion deberia ser unico en la lista de estudiantes, usualmente este numero de estudiante deberia incrementar por uno cada vez que un objeto estudiate es introducido a la lista de estudiantes.</p>

<p class="tutorials-content__text">La funcion para crear el objeto estudiante no puede añadir el numero correcto al objeto estudiante sin que algun valor externo de la funcion le diga cual seria el numero correcto. Este valor externo ayudara a tener un seguimiento del numero que le corresponde a cada objeto estudiante el cual cree la funcion.</p>

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

<p class="tutorials-content__text">Al Mover una variable fuera del ambito de la funcion a un ambito global para tener seguimiento del valor que corresponde a cada objeto estudiante, hemos solucionado un problema. Pero ahora tenemos el siguiente problema.</p>

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

<p class="tutorials-content__text">Como ahora la variable el cual sigue el valor de identificacion de cada objeto estudiante esta en un ambito global, este valor puede ser alterado de forma muy sencilla o puede ser alterado por error de la logica de nuestro codigo. Es aqui que las clausura (Closure) nos ayudan con los problema de las variables y sus ambitos.</p>

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

<p class="tutorials-content__text">Las clausura (Closure) es una técnica de encapsulamiento, basada en el anidamiento de funciones, en otras palabras funciones dentro de otra funcion que permite crear privacidad, Para que de este modo, el ambito (Scope) de una función interna contenga como tambien o pueda heredar el ambito de una función padre, eh incluso si esta función padre ya ha retornado algun valor, pues conservar dicho ambito en caché o memoria, dentro de la clausura.</p>
