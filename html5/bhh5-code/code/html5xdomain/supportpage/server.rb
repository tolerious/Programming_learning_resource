#---
# Excerpted from "HTML5 and CSS3",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
#---
require 'webrick'
s = WEBrick::HTTPServer.new(:Port => 3000, :DocumentRoot => Dir.pwd + "/public")
trap('INT') { s.shutdown }
s.start
