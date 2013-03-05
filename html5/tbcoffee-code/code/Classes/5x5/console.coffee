#START:require
{Dictionary} = require './Dictionary'
{Grid} = require './Grid'
{Player} = require './Player'
{OWL2} = require './OWL2'
#END:require

grid = dictionary = currPlayer = player1 = player2 = null # module scope

inputCallback = null
stdin = process.openStdin()
stdin.setEncoding 'utf8'
stdin.on 'data', (input) -> inputCallback input

newGame = ->
  grid = new Grid
  dictionary = new Dictionary(OWL2, grid)
  currPlayer = player1 = new Player('Player 1', dictionary)
  player2 = new Player('Player 2', dictionary)
  
  console.log "Welcome to 5x5!"
  unless dictionary.usedWords.length is 0
    console.log """
      Initially used words:
      #{dictionary.usedWords.join(', ')}
      
    """
  
  promptForTile1()

printGrid = ->
  rows = grid.rows()
  rowStrings = (' ' + row.join(' | ') for row in rows)
  rowSeparator = ('-' for i in [1...grid.size * 4]).join('')
  console.log '\n' + rowStrings.join("\n#{rowSeparator}\n") + '\n'

promptForTile1 = ->
  printGrid()
  console.log "#{currPlayer}, please enter coordinates for the first tile."
  inputCallback = (input) ->
    try
      {x, y} = strToCoordinates input
    catch e
      console.log e
      return
    promptForTile2 x, y

promptForTile2 = (x1, y1) ->
  console.log "#{currPlayer}, please enter coordinates for the second tile."
  inputCallback = (input) ->
    try
      {x: x2, y: y2} = strToCoordinates input
    catch e
      console.log e
      return
    if x1 is x2 and y1 is y2
      console.log "The second tile must be different from the first."
    else
      console.log "Swapping (#{x1}, #{y1}) with (#{x2}, #{y2})..."
      x1--; x2--; y1--; y2--; # convert 1-based indices to 0-based
      {moveScore, newWords} = currPlayer.makeMove {x1, y1, x2, y2}
      unless moveScore is 0
        console.log """
          #{currPlayer} formed the following #{newWords.length} word(s)
          #{newWords.join(', ')}
          earning #{moveScore / newWords.length}x#{newWords.length} = #{moveScore} points
        """
      console.log """
        #{currPlayer}'s score after #{currPlayer.moveCount} moves: #{currPlayer.score}
      """
      currPlayer = if currPlayer is player1 then player2 else player1
      promptForTile1()

isInteger = (num) ->
  num is Math.round(num)

strToCoordinates = (input) ->
  halves = input.split(',')
  if halves.length is 2
    x = parseFloat halves[0]
    y = parseFloat halves[1]
    if !isInteger(x) or !isInteger(y)
      throw "Each coordinate must be an integer."
    else if not grid.inRange x - 1, y - 1
      throw "Each coordinate must be between 1 and #{grid.size}."
    else
      return {x, y}
  else
    throw 'Input must be of the form `x, y`.'

newGame()