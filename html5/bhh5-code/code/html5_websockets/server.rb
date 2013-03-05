#---
# Excerpted from "HTML5 and CSS3",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
#---
# # Chat server, based on example from em-websocket-server
# # prerequisites:
# #   gem install em-websocket-server json
# #
# # run with:
# #   ruby server.rb

require 'rubygems'
require 'em-websocket'
require 'json'

EventMachine.run do
  
  # create a chatroom object. Shared by every connection
  @chatroom = EM::Channel.new

  EventMachine::WebSocket.start(:host => "0.0.0.0", :port => 9394, :debug => true) do |ws|

    # fires when we open a connection
    ws.onopen do
      
      # holds info about the user's chat session. 
      chatsession = {:nick => "GuestUser"}
      
      # subscribe to the chatroom
      sid = @chatroom.subscribe do |msg|
        ws.send msg 
      end
      
      @chatroom.push "#{Time.now.strftime("%H:%M:%S")}  | #{chatsession[:nick]} joined!"
      
      # fires when we receive a message on the channel
      ws.onmessage do |msg|
        
        if msg[0].chr == "/"
          parse_command(ws, msg, chatsession)
        else
          @chatroom.push "#{Time.now.strftime("%H:%M:%S")}  | #{chatsession[:nick]} |  #{msg}"
        end
      end
      
      # fires when someone leaves
      ws.onclose do
        @chatroom.unsubscribe(sid)
        @chatroom.push "User #{chatsession[:nick]} has left"
      end
      
      # command parser - looking for /nick newname
      def parse_command(ws, msg, chatsession)
        parts = msg.split(" ")
        command = parts.delete(parts[0])
        command = command[1..-1] # strip the /
        options = parts.join(" ")
        case command
        when "nick"
          oldnick = chatsession[:nick]
          chatsession[:nick] = options
          ws.send "Changed your nick to #{chatsession[:nick]}."
          @chatroom.push "#{oldnick} is now known as #{chatsession[:nick]}"
        end
      end

    end
  end

  puts "Chat server started"
end
