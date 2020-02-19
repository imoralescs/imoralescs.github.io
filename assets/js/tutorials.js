console.log("Javascript running...!");

/*
 * Accordion 
 */
var accordionItems = document.querySelectorAll(".accordion__header");
for (const accordion of accordionItems) {
  accordion.addEventListener('click', function(event) {
    event.preventDefault();
    var accordionHeader = event.target;
    var accordionContent = event.target.nextElementSibling;
    accordionHeader.classList.toggle("active");
    accordionContent.classList.toggle("active");
  })
}
