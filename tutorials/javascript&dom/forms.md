---
layout: tutorials
title: Forms
---
<h2 class="tutorials-content__sub-title">Forms</h2>

<p class="tutorials-content__text">Los elementos de formulario HTML son una excelente manera de recopilar información del usuario, incluso cuando los datos del formulario se procesan completamente mediante JavaScript del lado del cliente y nunca se envían al servidor. Hay algunas propiedades útiles de los elementos que facilitan un poco el trabajo con formularios en JavaScript.</p>

<h3 class="tutorials-content__sub-title">Obtenga todos los formularios en una página</h3>

<pre>
  <code class="language-javascript">
  let forms = document.forms;
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Obtenga todos los elementos en un formulario</h3>

<pre>
  <code class="language-javascript">
  let form = document.querySelector('form');
  let elements = form.elements;
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Atributos del elemento de formulario</h3>

<p class="tutorials-content__text">Puede verificar el valor de los atributos del elemento de formulario llamándolos directamente.</p>

<pre>
  <code class="language-html">
  &#60;form id="signin"&#62;
    &#60;label for="username"&#62;Username&#60;/label&#62;
    &#60;input type="text" id="username"&#62;

    &#60;label for="password"&#62;Password&#60;/label&#62;
    &#60;input type="password" id="password"&#62;

    &#60;input type="checkbox" id="rem_password" name="rem_password"&#62;
    &#60;label for="rem_password"&#62;Remember password&#60;/label&#62;

    &#60;input type="radio" id="personal" name="login_mode" value="personal" checked&#62;
    &#60;label for="personal"&#62;Personal&#60;/label&#62;

    &#60;input type="radio" id="group" name="login_mode" value="group"&#62;
    &#60;label for="group"&#62;Group&#60;/label&#62;

    &#60;button&#62;Sign In&#60;/button&#62;
  &#60;/form&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let input = document.querySelector('#username');
  let type = input.type;
  console.log(type); //-> text

  let checkbox = document.querySelector('#rem_password');
  let name = checkbox.name;
  console.log(name); //-> rem_password

  let radio = document.querySelector('[name="login_mode"]:checked');
  let value = radio.value;
  console.log(value); //-> personal
  </code>
</pre>

<p class="tutorials-content__text">También puede cambiar y establecer atributos con el mismo enfoque.</p>

<pre>
  <code class="language-javascript">
  let input = document.querySelector('#username');
  input.type = 'password';
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Atributos del elemento booleano</h3>

<p class="tutorials-content__text">Ciertos atributos, como si una entrada está o no deshabilitada, de solo lectura o marcada, usan valores booleanos simples verdadero o falso.</p>

<pre>
  <code class="language-javascript">
  let checkbox = document.querySelector('#rem_password');
  checkbox.checked;

  let radio = document.querySelector('#group');
  radio.checked = true;
  </code>
</pre>
