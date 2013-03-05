namespace :chatserver do
  task :start do
    puts "Starting Websocket Chat Server..."
    `ruby server.rb`
  end
end

namespace :chatclient do
  task :start do
    puts "Starting Frontend Web Server"
    `ruby client.rb`
  end
end

namespace :flashpolicyserver do
  task :start do
    puts "Starting Flash Policy Server"
    `sudo ruby flashpolicyserver.rb`
  end
end

multitask :start => [ 'flashpolicyserver:start', 'chatserver:start', 'chatclient:start' ]
multitask :chat_start => ['flashpolicyserver:start', 'chatserver:start']