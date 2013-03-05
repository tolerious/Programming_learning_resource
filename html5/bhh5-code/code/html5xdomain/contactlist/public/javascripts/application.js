/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
$(function(){
  $("#contacts li").click(function(event){
    var email = ($(this).find(".email").html());
    var origin = "http://192.168.1.244:3000/index.html";
    if(window.postMessage){
      window.parent.postMessage(email, origin); 
    }else{
      $.getScript("javascripts/jquery.postmessage.js", function(){
        $.postMessage(email, origin, window.parent);        
      });
    }
  });
});
