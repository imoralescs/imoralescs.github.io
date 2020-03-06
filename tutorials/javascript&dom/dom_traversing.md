---
layout: tutorials
title: DOM Traversing 
---

<h2 class="tutorials-content__sub-title">DOM Traversing "Atravesando el DOM"</h2>

<p class="tutorials-content__text">DOM es un árbol de elementos, con el nodo raíz, que apunta al nodo html, que a su vez apunta a la cabeza y el cuerpo de sus nodos elementos secundarios, y así sucesivamente. Desde cada uno de esos elementos, puede navegar por la estructura DOM y moverse a diferentes nodos.</p>

<h3 class="tutorials-content__sub-title">Recorriendo el DOM hacia abajo</h3>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">querySelector</code> y <code class="tutorials__code">querySelectorAll</code></h4>

<p class="tutorials-content__text"><code class="tutorials__code">querySelector</code> y <code class="tutorials__code">querySelectorAll</code> no se limitan solo a ejecutarse en el documento. Se pueden ejecutar en cualquier elemento para buscar solo elementos dentro de él.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section_1"&#62;Section Content&#60;/section&#62;
  &#60;section class="section" id="section_2"&#62;Section Content&#60;/section&#62;
  &#60;section class="section" id="section_3"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section_2');
  console.dir(element); //-> section#section_2.section

  let elements = document.querySelectorAll('section');
  console.dir(elements); //-> NodeList(3)
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">children</code></h4>

<p class="tutorials-content__text">Mientras <code class="tutorials__code">querySelector</code> y <code class="tutorials__code">querySelectorAll</code> buscan en todos los niveles dentro de una estructura DOM / HTML anidada, es posible que desee obtener descendientes inmediatos de un elemento en particular. Para esto utilizamos <code class="tutorials__code">children</code>.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section_1"&#62;Section Content&#60;a href="webpage"&#62;Link&#60;/a&#62;&#60;/section&#62;
  &#60;section class="section" id="section_2"&#62;Section Content&#60;/section&#62;
  &#60;section class="section" id="section_3"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#section_1');
  let decendants = element.children;
  console.dir(decendants); //-> HTMLCollection(1)
  </code>
</pre>

<h3 class="tutorials-content__sub-title">Recorriendo el DOM hacia arriba</h3>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">parentNode</code></h4>

<p class="tutorials-content__text">Utilizamos <code class="tutorials__code">parentNode</code> para obtener el padre de un elemento.</p>

<pre>
  <code class="language-html">
  &#60;section class="section" id="section_1"&#62;Section Content&#60;a href="webpage" id="link_1" &#62;Link&#60;/a&#62;&#60;/section&#62;
  &#60;section class="section" id="section_2"&#62;Section Content&#60;/section&#62;
  &#60;section class="section" id="section_3"&#62;Section Content&#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let element = document.querySelector('#link_1');
  let parent = element.parentNode;
  console.dir(parent); //-> section#section_1.section
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">getClosest</code></h4>

<p class="tutorials-content__text"><code class="tutorials__code">getClosest</code> es un método que escribímos como utilidad para obtener el padre más cercano en el árbol DOM que coincide con un selector. Este metodo es equivalente al método <code class="tutorials__code">.closest</code> de jQuery.</p>

<pre>
  <code class="language-html">
  &#60;section class="section"&#62;
    &#60;ul class="lists-outer" data-lists="one"&#62;
      &#60;ul class="lists-inner" data-lists="two&#62;"&#62;
        &#60;li&#62;&#60;span id="number_1"&#62;Number One&#60;/span&#62;&#60;/li&#62;
        &#60;li&#62;&#60;span id="number_2"&#62;Number Two&#60;/span&#62;&#60;/li&#62;
      &#60;/ul&#62;
    &#60;/ul&#62;
  &#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let getClosest = function(elem, selector) {

    // Element.matches() polyfill
    if(!Element.prototype.matches) {
      Element.prototype.matches =
        Element.prototype.matchesSelector ||
        Element.prototype.mozMatchesSelector ||
        Element.prototype.msMatchesSelector ||
        Element.prototype.oMatchesSelector ||
        Element.prototype.webkitMatchesSelector ||
        function(s) {
          let matches = (this.document || this.ownerDocument).querySelectorAll(s),
            i = matches.length;

          while(--i >= 0 && matches.item(i) !== this) {}

          return i > -1;
        };
    }

    // Get closest match
    for( ; elem && elem !== document; elem = elem.parentNode) {
      if ( elem.matches( selector ) ) return elem;
    }

    return null;
  };

  let element = document.querySelector("#number_1");

  let closestParent = getClosest(element, 'ul');
  console.dir(closestParent); //-> ul.lists-inner

  let closestParentByDataAttr = getClosest(element, '[data-lists]');
  console.dir(closestParentByDataAttr); //-> ul.lists-inner
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">getParents</code></h4>

<p class="tutorials-content__text"><code class="tutorials__code">getParents</code> es un método que escribímos como utilidad para obtener una matriz de elementos padres, opcionalmente coincidiendo con un selector. Este metodo es equivalente al método <code class="tutorials__code">.parents</code> de jQuery.</p>

<pre>
  <code class="language-html">
  &#60;section class="section"&#62;
    &#60;ul class="lists-outer" data-lists="one"&#62;
      &#60;ul class="lists-inner" data-lists="two&#62;"&#62;
        &#60;li&#62;&#60;span id="number_1"&#62;Number One&#60;/span&#62;&#60;/li&#62;
        &#60;li&#62;&#60;span id="number_2"&#62;Number Two&#60;/span&#62;&#60;/li&#62;
      &#60;/ul&#62;
    &#60;/ul&#62;
  &#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let getParents = function(elem, selector) {

    // Element.matches() polyfill
    if(!Element.prototype.matches) {
      Element.prototype.matches =
        Element.prototype.matchesSelector ||
        Element.prototype.mozMatchesSelector ||
        Element.prototype.msMatchesSelector ||
        Element.prototype.oMatchesSelector ||
        Element.prototype.webkitMatchesSelector ||
        function(s) {
          let matches = (this.document || this.ownerDocument).querySelectorAll(s),
          i = matches.length;
          while (--i >= 0 && matches.item(i) !== this) {}
          return i > -1;
        };
    }

    // Setup parents array
    let parents = [];

    // Get matching parent elements
    for(; elem && elem !== document; elem = elem.parentNode) {

      // Add matching parents to array
      if(selector) {
        if(elem.matches(selector)) {
          parents.push( elem );
        }
      } 
      else {
        parents.push(elem);
      }
    }

    return parents;

  };

  let element = document.querySelector("#number_1");

  let closestParentSelector = getParents(element, 'ul');
  console.dir(closestParentSelector); //-> Array(2) 0: ul.lists-inner 1: ul.lists-outer

  let closestParentAll = getParents(element);
  console.dir(closestParentAll); //-> Array(7) 0: span#number_1 1: li 2: ul.lists-inner 3: ul.lists-outer 4: section.section 5: body 6: html
  </code>
</pre>

<h4 class="tutorials-content__sub-title"><code class="tutorials__code">getParentsUntil</code></h4>

<p class="tutorials-content__text"><code class="tutorials__code">getParentsUntil</code> es un método que escribímos como utilidad para obtener una matriz de elementos principales hasta que se encuentre un elemento padre coincidente, opcionalmente coincidente con un selector. Este metodo es equivalente al método <code class="tutorials__code">.parentsUntil</code> de jQuery.</p>

<pre>
  <code class="language-html">
  &#60;section class="section"&#62;
    &#60;ul class="lists-outer" data-lists="one"&#62;
      &#60;ul class="lists-inner" data-lists="two&#62;"&#62;
        &#60;li&#62;&#60;span id="number_1"&#62;Number One&#60;/span&#62;&#60;/li&#62;
        &#60;li&#62;&#60;span id="number_2"&#62;Number Two&#60;/span&#62;&#60;/li&#62;
      &#60;/ul&#62;
    &#60;/ul&#62;
  &#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let getParentsUntil = function(elem, parent, selector) {

    // Element.matches() polyfill
    if(!Element.prototype.matches) {
      Element.prototype.matches =
        Element.prototype.matchesSelector ||
        Element.prototype.mozMatchesSelector ||
        Element.prototype.msMatchesSelector ||
        Element.prototype.oMatchesSelector ||
        Element.prototype.webkitMatchesSelector ||
        function(s) {
          let matches = (this.document || this.ownerDocument).querySelectorAll(s),
            i = matches.length;
          while (--i >= 0 && matches.item(i) !== this) {}
          return i > -1;
        };
    }

    // Setup parents array
    let parents = [];

    // Get matching parent elements
    for(; elem && elem !== document; elem = elem.parentNode) {
      if(parent) {
        if(elem.matches(parent)) break;
      }

      if(selector) {
        if(elem.matches(selector)) {
          parents.push(elem);
        }

        break;
      }

      parents.push( elem );
    }

    return parents;
  };

  let element = document.querySelector("#number_1");

  let parentsUntil = getParentsUntil(element, '.section');
  console.dir(parentsUntil); //-> Array(4) 0: span#number_1 1: li 2: ul.lists-inner 3: ul.lists-outer
  </code>
</pre> 

<h3 class="tutorials-content__sub-title">Atravesando lateralmente en el DOM</h3>

<p class="tutorials-content__text"><code class="tutorials__code">getSiblings</code> es un método que escribímos como utilidad para obtiene los hermanos de un elemento en el DOM. Por ejemplo: si tenía un elemento de la lista <code class="tutorials__code">li</code> y quería obtener todos los demás elementos de la lista.</p>

<pre>
  <code class="language-html">
  &#60;section class="section"&#62;
    &#60;ul class="lists-outer" data-lists="one"&#62;
      &#60;ul class="lists-inner" data-lists="two&#62;"&#62;
        &#60;li id="number_1"&#62;&#62;&#60;span&#62;Number One&#60;/span&#62;&#60;/li&#62;
        &#60;li id="number_2"&#62;&#62;&#60;span&#62;Number Two&#60;/span&#62;&#60;/li&#62;
        &#60;li id="number_3"&#62;&#62;&#60;span&#62;Number Three&#60;/span&#62;&#60;/li&#62;
        &#60;li id="number_4"&#62;&#62;&#60;span&#62;Number Four&#60;/span&#62;&#60;/li&#62;
      &#60;/ul&#62;
    &#60;/ul&#62;
  &#60;/section&#62;
  </code>
</pre>

<pre>
  <code class="language-javascript">
  let getSiblings = function(elem) {
    let siblings = [];
    let sibling = elem.parentNode.firstChild;

    for(; sibling; sibling = sibling.nextSibling) {
      if(sibling.nodeType === 1 && sibling !== elem) {
        siblings.push( sibling );
      }
    }

    return siblings;
  };

  let element = document.querySelector("#number_3");

  let siblings = getSiblings(element);
  console.dir(siblings); //-> Array(3) 0: li#number_1 1: li#number_2 2: li#number_4
  </code>
</pre> 
