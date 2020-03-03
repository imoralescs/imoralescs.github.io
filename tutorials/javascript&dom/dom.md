---
layout: tutorials
title: DOM "Document Object Model"
---
<h2 class="tutorials-content__sub-title">DOM "Document Object Model"</h2>

<p class="tutorials-content__text">El DOM "Document Object Model" da una representación del documento HTML como un grupo de nodos y objetos estructurados que tienen propiedades y métodos.</p>

<p class="tutorials-content__text">El DOM "Document Object Model", sirve como referencia para el navegador al colocar elementos en la página web. Las ubicaciones donde los elementos se colocan en el DOM se denominan <code class="tutorials__code">Nodes</code>, y en la página web, no solo los elementos HTML obtienen su nodo, sino que los atributos de los elementos HTML, cada fragmento de texto tiene su nodo (nodos de texto), y hay muchos otros tipos de nodos. La relación estructural de estos nodos refleja la estructura del documento HTML. Por eso, podemos definir las relaciones entre los elementos en la página como las relaciones entre sus nodos en el DOM.</p>

<p class="tutorials-content__text">En resumen, es la representación de la página web en la memoria del navegador, a la que podemos acceder a través de JavaScript. El DOM es un árbol donde cada nodo es un objeto con todas sus propiedades y métodos que nos permiten modificarlo.</p>

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
