#---
# Excerpted from "HTML5 and CSS3",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
#---
# This is a code server for the book's example files.
# It uses Sinatra to display all of the code example pages
# by simply iterating over the public folder, which we set to the code/ folder
# You need Ruby to run this, and the Sinatra and HAML gems.

# gem install sinatra haml --no-ri --no-rdoc

# To run this, use  
#
#  ruby server.rb
#
# then point your browser to http://localhost:4567
#
# Reason for the server? Made it easier for me to test examples on
# other computers / web browsers. And lets me write backedn responses 
# for testing AJAX.

require 'rubygems'
require 'sinatra'
require 'haml'

  set :public, File.dirname(__FILE__) + "/"
  
  get "/" do
    @pages = Dir.glob(File.dirname(__FILE__) + '/**/*.html')
    @pages.collect{|page| page.gsub('code/', "")}.sort
    haml :index
  end
  
  post '/signup' do
    params.inspect
  end
  
__END__
@@index
!!!
%html{:lang=>"en-US"}
  %head
    %title Examples
  %body
  
    %h1 HTML5 and CSS3 Examples
    %ul
      -@pages.each do |page|
        %li
          %a{:href=>page}=page

