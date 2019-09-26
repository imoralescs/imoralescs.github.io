---
layout: tutorials
title: You're up and running!
---
<h2 class="tutorials-content__sub-title">Settup HTML Canvas</h2>

<p class="tutorials-content__text">To start with HTML Canvas, you need to used a canvas tag, them you can specify it width and height property (width and height units are in pixels.). Remember to close the canvas tag. (Notice that you can not use CSS to specify its width and height.)</p>

<pre>
  <code class="language-html">
    <canvas id="my-canvas" width="400" height="200"></canvas>
  </code>
</pre>

<p>Also, you can setup Canvas width or height via JavaScript.</p>

<pre>
  <code class="language-javascript">
    let canvas = document.getElementById('display')
    canvas.width  = 400
    canvas.height = 200
  </code>
</pre>
