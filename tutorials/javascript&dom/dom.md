---
layout: tutorials
title: DOM "Document Object Model"
---
<h2 class="tutorials-content__sub-title">DOM "Document Object Model"</h2>

<p class="tutorials-content__text">El DOM "Document Object Model" da una representación del documento HTML como un grupo de nodos y objetos estructurados que tienen propiedades y métodos. En resumen, es la representación de la página web en la memoria del navegador, a la que podemos acceder a través de JavaScript. El DOM es un árbol donde cada nodo es un objeto con todas sus propiedades y métodos que nos permiten modificarlo.</p>

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
