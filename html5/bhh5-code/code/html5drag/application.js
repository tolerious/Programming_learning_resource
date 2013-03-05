/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/

$(function() {
  var contacts = $('#images img');
  contacts.attr('draggable', 'true');
  
  contacts.bind('dragstart', function(event) {
      var data = event.originalEvent.dataTransfer; 
      var src = $(this).attr("data-large");
      data.setData("Text", src); 
      return true;
  });
  

  
  var target = $('#preview');

  target.bind('drop', function(event) {
    var data = event.originalEvent.dataTransfer;
    var src = ( data.getData('Text') ); 
    
    var img = $("<img></img>").attr("src", src);
    $(this).html(img);
    if (event.preventDefault) event.preventDefault();
    return(false);
  });

 
  target.bind('dragover', function(event) {    
    if (event.preventDefault) event.preventDefault();
    return false;
  });

   target.bind('dragenter', function(event) {
     $(this).addClass('hover');
     if (event.preventDefault) event.preventDefault();
     return false;
   });

   target.bind('dragleave', function(event) {
     $(this).removeClass('hover');
     if (event.preventDefault) event.preventDefault();
     return false;  
  });


   contacts.bind('dragend', function(event) {
     if (event.preventDefault) event.preventDefault();
     return false;
   });

});