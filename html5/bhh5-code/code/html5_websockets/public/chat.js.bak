/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
WEB_SOCKET_SWF_LOCATION = "websocket_js/WebSocketMain.swf";



   var webSocket = new WebSocket('ws://localhost:9394/');
   
   webSocket.onopen = function(event){
     $('#chat').append('<br>Connected to the server');
   };
   
   webSocket.onmessage = function(event){
     $('#chat').append("<br>" + event.data);
     $('#chat').animate({scrollTop: $('#chat').height()});
   };
   
   webSocket.onclose = function(event){
     $("#chat").append('<br>Connection closed');
   };
   
   
   $(function(){
     $("form#chat_form").submit(function(e){
        e.preventDefault();
        var textfield = $("#message");
        webSocket.send(textfield.val());
        textfield.val("");
      });
    $("form#nick_form").submit(function(e){
      e.preventDefault();
      var textfield = $("#nickname");
      webSocket.send("/nick " + textfield.val());
    });
    
   })
   


