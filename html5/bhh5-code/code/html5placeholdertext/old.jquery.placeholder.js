/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
// Plugin based on Andrew January's work at
// http://www.morethannothing.co.uk/wp-content/uploads/2010/01/placeholder.js
// and other solutions.

(function($){  
  
  $.fn.placeholder = function(){   
    return this.each(function() {  
      if ($(this).attr('type') == 'password') {
        $(this).addClass('placeholder_password_field');
      }

      function valueIsPlaceholder(input){
        return ($(input).val() == $(input).attr("placeholder"));
      }
      
      function isAPasswordField(input){
        return ($(input).hasClass("placeholder_password_field"));
      }

      // Replace the value with the placeholder text. 
      // optional reload parameter solves FF and IE caching values on fields.
      function showPlaceholder(input, reload){
        if( $(input).val() == "" || ( reload && valueIsPlaceholder(input) ) ){ 
          
          if (isAPasswordField(input)){  
            try { input.setAttribute('type', 'input');
              $(input).focus();
            } catch (e) { }
          }
          
          $(input).val($(input).attr("placeholder"));
          
        }
      }
      
      function hidePlaceholder(input){
        if(valueIsPlaceholder(input)){
 
          if(isAPasswordField(input)){
            try { input.setAttribute('type', 'password');
              $(input).focus();
            } catch (e) { }
          }
          
          $(input).val("");
        };
      }

      showPlaceholder(this, true); 
      $(this).focus(function(){
         hidePlaceholder(this);
      });

      $(this).blur(function(){
        showPlaceholder(this, false);
      });
    });  
  };

  
})(jQuery); 

