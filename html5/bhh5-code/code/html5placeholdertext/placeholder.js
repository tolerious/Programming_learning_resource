/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
(function($){  
  
  $.fn.placeholder = function(){   
    return this.each(function() {  
      if($(this).attr("type") == "password"){
        var new_field = $("<input type='text'>");
        $(this).hide();
        new_field.attr("rel", $(this).attr("id"));
        new_field.attr("value", $(this).attr("placeholder"));
        new_field.focus(function(){
          $(this).hide();
          $('input#' + $(this).attr("rel")).show().focus();
        });

        $(this).blur(function(){
          if($(this).val() == ""){
            $(this).hide();
            $('input[rel=' + $(this).attr("id") + ']').show();
          };
        });

        $(this).parent().append(new_field);
        
      }else{
        $(this).focus(function(){
          if($(this).val() == $(this).attr("placeholder")){
            $(this).val("");
          };
        });

        $(this).blur(function(){
          if($(this).val() == ""){
            $(this).val($(this).attr("placeholder"));
          };
        });

        $(this).blur();
    
    });  
  };
  
})(jQuery); 

