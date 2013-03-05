/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
var worker = new Worker("worker.js");

$(function(){
  $("#button").click(function(event){
    $("#output").html("starting...");
    worker.postMessage("start");
  });
  
  worker.onmessage = function(event){
    $("#output").html(event.data);
  }
  
})