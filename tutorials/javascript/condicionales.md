---
layout: tutorials
title: Condicionales
---
<h2 class="tutorials-content__sub-title">Condicionales</h2>

<p class="tutorials-content__text">Los condicionales son expresiones que nos permite ejecutar una secuencia de intrucciones u otra diferente dependiendo de lo que estemos comprobando. Esto permite establecer el flujo de la ejecucion de nuestros programa de acuerdo a determinado estado.</p>

<h3 class="tutorials-content__sub-title">Asignacion Condicional</h3>

<p class="tutorials-content__text">Es un tipo de asignacion tambien conocida como if simplificado u operador ternario. Sirve para asignar en una sola linea un valor determinado si la condicion que se evalua es true o false.</p>

<pre>
  <code class="language-javascript">
  condicion ? valor_is_true : valor_is_false;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let data_01 = (true) ? 5 : 2;
  console.log(data_01); //-> 5

  let data_02 = (false) ? 5 : 2;
  console.log(data_02); //-> 2

  var age_01 = 11;
  age_01 > 18 ? console.log("true") : console.log("false"); //-> false

  var age_02 = 20;
  age_02 > 18 ? console.log("true") : console.log("false"); //-> true
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Sentencia IF</h3>

<p class="tutorials-content__text">Las sentencias IF es para los casos el cual nuestro flujo de programa requiere mucho mas pasos, tenemos 3 formas de aplicarlos.</p>

<h4 class="tutorials-content__sub-title">IF Simple</h4>

<p class="tutorials-content__text">Si se cumple la condicion dentro del parentesis, se ejecuta el bloque de codigo incluido entre las llaves.</p>

<pre>
  <code class="language-javascript">
  var year = 2011;
  if(year != 2011) { 
    console.log( 'year is 2011..' ); 
    console.log( '..this condition is true!' ); 
  }
  </code>
</pre>

<h4 class="tutorials-content__sub-title">IF/ELSE</h4>

<pre>
  <code class="language-javascript">
  var data = 6;

  if(data < 5) {
    result = 'Block Code 1';
    console.log(result);
  }
  else {
    result = 'Block Code 2';
    console.log(result);
  }
  </code>
</pre>

<h4 class="tutorials-content__sub-title">IF/ELSE IF</h4>

<pre>
  <code class="language-javascript">
  var message;
  var login = "Jack";

  if(login == 'John') {
    message = 'Hello John';
    console.log(message);
  } 
  else if(login == 'Jack') {
    message = 'Hello Jack!';
    console.log(message);
  } 
  else if(login === '') {
    message = 'Please type login!';
    console.log(message);
  } 
  else {
    message = 'Hmmm!';
    console.log(message);
  }
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Sentencia Switch</h3>

<p class="tutorials-content__text">Con Switch podemos sustituir un conjunto de sentencias <code class="tutorials__code">if-else</code> de una manera mas legible. Se comprueba la condicion y segun el caso devuelve o ejecutara un bloque u otro.</p>

<pre>
  <code class="language-javascript">
  switch(x) {
    case 'value1':  
      // if (x === 'value1')
      // Block Code
      break;
    case 'value2':  
      // if (x === 'value2')
      // Block Code
      break;
    default:
      // Block Code
      break;
  }
  </code>
</pre>

<p class="tutorials-content__text">Para poder separar los bloques utilizamos la palabra reservada <code class="tutorials__code">break</code> que permite salir de toda la sentencia. Por defecto podemos definir el bloque <code class="tutorials__code">default</code> el cual ejecutara un bloque en caso que no se cumpla ningun caso.</p>
