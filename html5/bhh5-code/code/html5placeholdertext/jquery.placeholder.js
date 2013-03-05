/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
// Some from http://www.morethannothing.co.uk/wp-content/uploads/2010/01/placeholder.js
// some from http://plugins.jquery.com/files/jquery-placeholder-0.1.js.txt

(function($){  
  
  $.fn.placeholder = function(){   
    
    function valueIsPlaceholder(input){
      return ($(input).val() == $(input).attr("placeholder"));
    }
    return this.each(function() {  
  
      $(this).find(":input").each(function(){
      
        if($(this).attr("type") == "password"){ 
          
          var new_field = $("<input type='text'>");
          new_field.attr("rel", $(this).attr("id"));
          new_field.attr("value", $(this).attr("placeholder"));
          $(this).parent().append(new_field);
          new_field.hide();
          
          function showPasswordPlaceHolder(input){
            if( $(input).val() == "" || valueIsPlaceholder(input) ){ 
              $(input).hide();
              $('input[rel=' + $(input).attr("id") + ']').show();
            };
          };
          
          new_field.focus(function(){
            $(this).hide();
            $('input#' + $(this).attr("rel")).show().focus();
          });

          $(this).blur(function(){
             showPasswordPlaceHolder(this);
          });

          showPasswordPlaceHolder(this); 
        
        }else{
          
          // Replace the value with the placeholder text. 
          // optional reload parameter solves FF and
          // IE caching values on fields.
          function showPlaceholder(input, reload){
            if( $(input).val() == "" || 
              ( reload && valueIsPlaceholder(input) ) ){ 
                $(input).val($(input).attr("placeholder"));
              }
          };
          
          $(this).focus(function(){
            if($(this).val() == $(this).attr("placeholder")){
              $(this).val("");
            };
          });

          $(this).blur(function(){
             showPlaceholder($(this), false)
          });
          
          showPlaceholder(this, true); 
        };
      });
      
      // Prevent forms from submitting default values
      $(this).submit(function(){  
        $(this).find(":input").each(function(){
          if($(this).val() == $(this).attr("placeholder")){
            $(this).val("");
          }          
        });
      });
      
    });  
  };
  
})(jQuery); 

