console.log("Javascript running...!");

/*
 * Accordion 
 */
var accordionItems = document.querySelectorAll(".accordion-header");
for (const accordion of accordionItems) {
  accordion.addEventListener('click', function(event) {
    event.prefentDefault();
    console.dir(event.target);
  })
}
