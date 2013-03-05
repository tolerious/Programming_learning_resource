/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
/* http://beckelman.net/post/2009/02/16/Use-jQuery-to-Show-a-Linke28099s-Address-After-its-Text-When-Printing-In-IE6-and-IE7.aspx */
$(function() {
  if (window.onbeforeprint !== undefined) {  
      window.onbeforeprint = ShowLinks;
      window.onafterprint = HideLinks;
  }
});

function ShowLinks() {  
  $("a").each(function() {
    $(this).data("linkText", $(this).text());
    $(this).append(" (" + $(this).attr("href") + ")");                
  });
}

function HideLinks() {   
  $("a").each(function() {
    $(this).text($(this).data("linkText"));
  });
}
