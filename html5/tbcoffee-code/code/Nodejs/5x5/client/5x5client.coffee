socket = tiles = selectedCoordinates = myNum = myTurn = null

startTurn = ->
  myTurn = true
  showMessage 'firstTile'

endTurn = ->
  selectedCoordinates = null
  myTurn = false
  showMessage 'waitForMove'

drawTiles = ->
    gridHtml = ''
    for y in [0...tiles.length]
      gridHtml += '<ul>'
      for x in [0...tiles.length]
        gridHtml += "<li id='tile#{x}_#{y}'>#{tiles[x][y]}</li>"
      gridHtml += '</ul>'
    $('#grid').html gridHtml

showMessage = (messageType) ->
  switch messageType
    when 'waitForConnection'
      messageHtml = "Waiting for another player to connect to the server..."
    when 'waitForMove'
      messageHtml = "Waiting for the other player to make a move..."
    when 'firstTile'
      messageHtml = "Please select your first tile."
    when 'secondTile'
      messageHtml = "Please select a second tile."
  $('#message').html messageHtml

showThenFade = ($elem) ->
  $elem.insertAfter $('#grid')
  animationTarget = opacity: 0, height: 0, padding: 0
  $elem.delay(5000).animate animationTarget, 500, -> $elem.remove()

tileClick = ->
  return unless myTurn
  $this = $(this)
  if $this.hasClass 'selected'
    # undo
    selectedCoordinates = null
    $this.removeClass 'selected'
    showMessage 'firstTile'
  else
    [x, y] = @id.match(/(\d+)_(\d+)/)[1..]

    if selectedCoordinates is null
      selectedCoordinates = {x1: x, y1: y}
      $this.addClass 'selected'
      showMessage 'secondTile'
    else
      selectedCoordinates.x2 = x
      selectedCoordinates.y2 = y
      socket.send "move:#{JSON.stringify selectedCoordinates}"
      endTurn()

swapTiles = ({x1, y1, x2, y2}) ->
  [tiles[x1][y1], tiles[x2][y2]] = [tiles[x2][y2], tiles[x1][y1]]
  drawTiles()

#START:regex
typeAndContent = (message) ->
  [ignore, type, content] = message.match /(.*?):(.*)/
  {type, content}
#END:regex

#START:handleMessage
handleMessage = (message) ->
  {type, content} = typeAndContent message
  switch type
    when 'welcome'
      {players, currPlayerNum, tiles, yourNum: myNum} = JSON.parse content
      startGame players, currPlayerNum
    when 'moveResult'
      {player, swapCoordinates, moveScore, newWords} = JSON.parse content
      showMoveResult player, swapCoordinates, moveScore, newWords

startGame = (players, currPlayerNum) ->
  for player in players
    $("#p#{player.num}name").html player.name
    $("#p#{player.num}score").html player.score
  drawTiles()
  if myNum is currPlayerNum
    startTurn()
  else
    endTurn()

showMoveResult = (player, swapCoordinates, moveScore, newWords) ->
  $("#p#{player.num}score").html player.score
  $notice = $('<p class="notice"></p>')
  if moveScore is 0
    $notice.html "#{player.name} formed no words this turn."
  else
    $notice.html """
      #{player.name} formed the following #{newWords.length} word(s):<br />
      <b>#{newWords.join(', ')}</b><br />
      earning <b>#{moveScore / newWords.length}x#{newWords.length}
      = #{moveScore}</b> points!
    """
  showThenFade $notice
  swapTiles swapCoordinates
  if player.num isnt myNum then startTurn()
#END:handleMessage

#START:documentReady
$(document).ready ->
  $('#grid li').live 'click', tileClick
  socket = new io.Socket()
  socket.connect()
  socket.on 'connect', -> showMessage 'waitForConnection'
  socket.on 'message', handleMessage
#END:documentReady