/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
/* Corner radius support for older browsers */

/* via http://perfectionkills.com/feature-testing-css-properties/ */
function hasBorderRadius(){
  var element = document.documentElement;
  var style = element.style;
  if (style){
    return typeof style.borderRadius == "string" ||
      typeof style.MozBorderRadius == "string" ||
      typeof style.WebkitBorderRadius == "string" ||
      typeof style.KhtmlBorderRadius == "string";
  }
  return null;
}

(function($){  
  $.fn.formCorner = function(){   
    return this.each(function() {  
      var input = $(this);
      var input_background = input.css("background-color");
      var input_border = input.css("border-color");
      input.css("border", "none");
      var wrap_width = parseInt(input.css("width")) + 4;
      var wrapper = input.wrap("<div></div>").parent();
      var border = wrapper.wrap("<div></div>").parent();
      wrapper.css("background-color", input_background)
             .css("padding", "1px");
      border.css("background-color",input_border)
            .css("width", wrap_width + "px")
            .css('padding', '1px');
      wrapper.corner("round 5px");
      border.corner("round 5px");
    });  
  };  
})(jQuery); 

$(function(){
  if(!hasBorderRadius()){
    $("input").formCorner();
    $("fieldset").corner("round 5px");
    $("legend").corner("round top 5px cc:#fff");  
  }
});
