console.log("Javascript running...!");

/*
 * Accordion 
 */
var accordionItems = document.querySelectorAll(".accordion__header");
for (const accordion of accordionItems) {
  accordion.addEventListener('click', function(event) {
    event.preventDefault();
    var accordionContent = event.target.nextElementSibling;
    accordionContent.classList.toggle("active");
  })
}
