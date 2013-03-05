#---
# Excerpted from "HTML5 and CSS3",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
#---
# Simple server to test contenteditable server-side
# persistence. 
# run with  ruby content_editable_server.rb
require 'rubygems'
require 'sinatra'

get "/:page.html" do
  File.read( File.dirname(__FILE__)  + "/#{params[:page]}.html")
end

post "/users/:id" do
  if request.xhr?
    "Successfully edited the record via an AJAX request"
  else
    "Successfully edited the record without AJAX"
  end
end
