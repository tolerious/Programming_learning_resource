#---
# Excerpted from "HTML5 and CSS3",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
#---
# # Flash policy server.
# # Flash needs a socket policy file served as xml
# # and it will expect to see it at the same domain
# # on port 843. 
# 
# # You must have root to start the service at port 843.
# # Windows users shouldn't be restricted by this.
# 
# # windows:  ruby flashpolicyserver.rb
# # everyone else:  sudo ruby flashpolicyserver.rb
# 
# # This server is *not* recommended for production use.
# 


require 'rubygems'
require 'eventmachine'

module FlashPolicyServer  
  def receive_data(data)
    puts "received #{data}"
    send_data(respond_with_policy(data))
    
  end
  
    def respond_with_policy(request)
      policy = %Q{<?xml version="1.0"?>
  <!DOCTYPE cross-domain-policy SYSTEM "http://www.macromedia.com/xml/dtds/cross-domain-policy.dtd">
  <cross-domain-policy>
    <allow-access-from domain="*" to-ports="*" />
  </cross-domain-policy>
      }
    end
  
end

EventMachine::run do
  host = '0.0.0.0'
  port = 843
  EventMachine::start_server host, port, FlashPolicyServer
  puts "Started FlashPolicyServer on #{host}:#{port}…"
end






# require 'webrick'
# s = WEBrick::HTTPServer.new(:Port => 843, :DocumentRoot => Dir.pwd + "/public")
# trap('INT') { s.shutdown }
# 
# 
# class FlashServlet < WEBrick::HTTPServlet::AbstractServlet
#   
#   def do_GET(request, response)
#     status, content_type, body = respond_with_policy(request)
#     
#     response.status = status
#     response['Content-Type'] = content_type
#     response.body = body
#     puts "*********** SERVED A POLICY FILE *********"
#   end
#   
#   def respond_with_policy(request)
#     policy = %Q{<?xml version="1.0"?>
# <!DOCTYPE cross-domain-policy SYSTEM "http://www.macromedia.com/xml/dtds/cross-domain-policy.dtd">
# <cross-domain-policy>
#   <allow-access-from domain="*" to-ports="*" />
# </cross-domain-policy>
#     }
#     return 200, "application/xml", policy
#   end
#   
# end
# 
# 
# 
# s.mount "/", FlashServlet, "red", "2em"
# s.start
