Developed by Netscape in 1995 to create product and application that run in the browser, its is primarily client-side. To work with JavaScript, they are some term, you need to understand.

## Parser

Process the code as text and produce a structure in memory.

## Syntax Parser

Is a program that read all your Javascript code and determines what it does and if its grammar is valid. JavaScript Engine, is in you browser, and they read all you code and determines what is wrong.

## Script Tag

The script tag is used for specifying JavaScript which should ran in a web page. Script tags are executed in the order they appear.

```html
<script>
  var x = 3;
  alert(x);
</script>

// External resource
<script src="//url.com/fj3j1j2.js"></script>
```

This mean you can significantly slow down your site if you have slow script loading early in the page. Also means script which appear later on the page can depend on things scripts which appear earlier have done.

Elements on the page won't render until all script tags preceding them have loaded and executed. This means you can do all sorts of tweak to performance the page.

### Where to place the script tag

Script position in the DOM affect when they run.

```html
<html>
  <head>
    <script>
      // document.head is available
      // document.body is not!
    </script>
  </head>
  <body>
    <script>
      // document.head is available
      // document.body is available
    </script>
  </body>
</html>
```

#### Using attribute on script tag for external call

* **Script:** Without any attribute, HTML file will parsed until script file hit. At that point parsing will stop and a request will made to fetch the file external.

* **Async:** Download the file during HTML parsing and will pause the HTML parser to execute it when it has finish download. Will start running before the load event gets fired.

* **Defer:** Download the file during HTML parsing and will only execute it after the parser has completed. Before DOMContentLoaded event get fired.

#### Encoding and tag META
