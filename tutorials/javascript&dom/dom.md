---
layout: tutorials
title: DOM "Document Object Model"
---
<h2 class="tutorials-content__sub-title">DOM "Document Object Model"</h2>

<p class="tutorials-content__text">El DOM "Document Object Model" da una representación del documento HTML, sirve como referencia para el navegador al colocar elementos en la página web. Las ubicaciones donde los elementos se colocan en el DOM se denominan <code class="tutorials__code">Nodes</code>, y en la página web, no solo los elementos HTML obtienen su nodo, sino que los atributos de los elementos HTML, cada fragmento de texto tiene su nodo (nodos de texto). La relación estructural de estos nodos refleja la estructura del documento HTML. Por eso, podemos definir las relaciones entre los elementos en la página como las relaciones entre sus nodos en el DOM.</p>

<pre>
  <code class="language-html">
  &#60;!doctype html&#62;
  &#60;html lang="en"&#62;
   &#60;head&#62;
     &#60;title&#62;My first web page&#60;/title&#62;
    &#60;/head&#62;
   &#60;body&#62;
      &#60;h1&#62;Hello, world!&#60;/h1&#62;
      &#60;p&#62;How are you?&#60;/p&#62;
    &#60;/body&#62;
  &#60;/html&#62;
  </code>
</pre>

<p class="tutorials-content__text">Este documento puede representarse como el siguiente árbol de nodos:</p>

<ul class="dom-tree">
  <li>
    <span>html</span>
    <ul>
      <li> <!-- start head -->
        <span>head</span>
        <ul>
          <li>
            <span>title</span>
            <ul>
              <li>
                <span>My first web page</span>
              </li>
            </ul>
          </li> <!-- end title -->
        </ul>
      </li> <!-- end head -->
      <li> <!-- start body -->
        <span>body</span>
        <ul>
          <li>
            <span>h1</span>
            <ul>
              <li>
                <span>Hello, world!</span>
              </li>
            </ul>
          </li> <!-- end h1 -->
          <li>
            <span>p</span>
            <ul>
              <li>
                <span>How are you?</span>
              </li>
            </ul>
          </li> <!-- end p -->
        </ul>
      </li> <!-- end body -->
    </ul> 
  </li> <!-- end html -->
</ul>

<p class="tutorials-content__text">Podemos manipular los elementos de la página web con un lenguaje de programación, como JavaScript, lo hacemos a través de sus nodos DOM. Al acceder a un nodo DOM de un elemento dado, podemos manipular sus propiedades, como posición, apariencia, contenido, comportamiento, etc. A menudo queremos realizar acciones en los elementos que tienen algún tipo de relación entre ellos, conocidos como nodos relacionados.</p>
