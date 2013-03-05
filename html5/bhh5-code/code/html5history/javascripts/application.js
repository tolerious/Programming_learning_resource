/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
// HTML5 structural element support for IE 6, 7, and 8
document.createElement("header");
document.createElement("footer");
document.createElement("section");
document.createElement("aside");
document.createElement("article");
document.createElement("nav");

function supportsHistory(){
  return !!(window.history && window.history.pushState);  
}
if(supportsHistory()){
  window.history.pushState( {tab: "#welcome"}, '#welcome');
  window.onpopstate = function(event) {  
    if(event.state){
      var tab = (event.state["tab"]);
      $(".visible")
        .removeClass("visible")
        .addClass("hidden")
        .hide();
      $(tab)
        .removeClass("hidden")
        .addClass("visible")
        .show();
    }
  };
};


$(function(){
  
  
  
  $("#services, #about, #contact").hide().addClass("hidden"); 
  $("#welcome").addClass("visible");
  
  $("nav ul").click(function(event){ 
    target = $(event.target);
    if(target.is("a")){   
      event.preventDefault();
      if ( $(target.attr("href")).hasClass("hidden") ){  
      
        if(supportsHistory()){
          var tab = $(target).attr("href");  
          var stateObject = {tab: tab};
          window.history.pushState(stateObject, tab);  
        };
      
        $(".visible").removeClass("visible").addClass("hidden").hide();
        $(target.attr("href")).removeClass("hidden").addClass("visible").show();
      };
    };  
  });
});

