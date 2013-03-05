#START:requireFS
fs = require 'fs'
#END:requireFS

# OWL2.txt source: http://www.zyzzyva.net/wordlists.shtml
#START:readWordList
# OWL2.txt is a list of Scrabble-valid dictionary and meanings
dictionary = []
text = fs.readFileSync 'OWL2.txt', 'utf8'
for line in text.split /\n/
  word = line.split(/\s/)[0]
  dictionary.push word unless word is ''
#END:readWordList

#START:isWord
usedWords = []
#END:isWord

#START:randomLetter
# Probabilities are taken from Scrabble, except that there are no blanks.
# See http://www.hasbro.com/scrabble/en_US/faqGeneral.cfm
tileCounts =
  A: 9, B: 2, C: 2, D: 4, E: 12, F: 2, G: 3, H: 2, I: 9, J: 1, K: 1, L: 4
  M: 2, N: 6, O: 8, P: 2, Q: 1, R: 6, S: 4, T: 6, U: 4, V: 2, W: 2, X: 1
  Y: 2, Z: 1
totalTiles = 0; totalTiles += count for letter, count of tileCounts

# JavaScript hashes are unordered, so we need to make our own key array:
alphabet = (letter for letter of tileCounts)
alphabet.sort()

randomLetter = ->  
  randomNumber = Math.ceil(Math.random() * totalTiles)
  x = 1
  for letter in alphabet
    x += tileCounts[letter]
    return letter if x > randomNumber
#END:randomLetter

#START:grid
GRID_SIZE = 5
MIN_WORD_LENGTH = 2
grid = []     # 2D array: grid[col][row], where 0, 0 is the upper-left corner
for x in [0...GRID_SIZE]
  grid[x] = []
  for y in [0...GRID_SIZE]
    grid[x][y] = randomLetter()
#END:grid

inRange = (x, y) ->
  0 <= x < GRID_SIZE and 0 <= y < GRID_SIZE

#START:score
# Each letter has the same point value as in Scrabble.
tileValues =
  A: 1, B: 3, C: 3, D: 2, E: 1, F: 4, G: 2, H: 4, I: 1, J: 8, K: 5, L: 1
  M: 3, N: 1, O: 1, P: 3, Q: 10, R: 1, S: 1, T: 1, U: 1, V: 4, W: 4, X: 8,
  Y: 4, Z: 10

getPossibleWords = (grid, x, y) ->
  [x, y] = [parseInt(x, 10), parseInt(y, 10)]
  possibleWords = []
  for length in [MIN_WORD_LENGTH..GRID_SIZE]
    range = length - 1
    addTiles = (func) ->
      possibleWords.push (func(i) for i in [0..range]).join ''
    for offset in [0...length]
      # Vertical
      if inRange(x - offset, y) and
         inRange(x - offset + range, y)
        addTiles (i) -> grid[x - offset + i][y]
      # Horizontal
      if inRange(x, y - offset) and
         inRange(x, y - offset + range)
        addTiles (i) -> grid[x][y - offset + i]
      # Diagonal (upper-left to lower-right)
      if inRange(x - offset, y - offset) and
         inRange(x - offset + range, y - offset + range)
        addTiles (i) -> grid[x - offset + i][y - offset + i]
      # Diagonal (lower-left to upper-right)
      if inRange(x - offset, y + offset) and
         inRange(x - offset + range, y + offset - range)
        addTiles (i) -> grid[x - offset + i][y + offset - i]
  possibleWords
        
scoreMove = (oldGrid, newGrid) ->
  newWords = []
  for x, col of newGrid
    for y, cell of col
      if !oldGrid or cell isnt oldGrid[x][y]
        # Score all original dictionary that go through this cell
        possibleWords = getPossibleWords newGrid, x, y
        for str in possibleWords
          if dictionary.indexOf(str) isnt -1 and usedWords.indexOf(str) is -1
            newWords.push str
            usedWords.push str
  moveScore = 0
  for word in newWords
    moveScore += tileValues[letter] for letter in word
  moveScore *= newWords.length
  return {moveScore, newWords}
#END:score

#START:printGrid
printGrid = ->
  # Transpose the grid so we can draw rows
  rows = []
  for y in [0...GRID_SIZE]
    rows[y] = (grid[x][y] for x in [0...GRID_SIZE])
  rowStrings = (' ' + row.join(' | ') for row in rows)
  rowSeparator = ('-' for i in [1...GRID_SIZE * 4]).join('')
  console.log '\n' + rowStrings.join("\n#{rowSeparator}\n") + '\n'
#END:printGrid

#START:gameStart
console.log "Welcome to 5x5!"
printGrid()
scoreMove null, grid
unless usedWords.length is 0
  console.log "Initially used words:"
  console.log usedWords.join(', ')
console.log "Please choose a tile in the form (x, y)."
#END:gameStart

#START:gameLoop
validateInput = (input) ->
  if input.split(',').length is 2
    x = input.split(',')[0].replace(/\s/, '')
    y = input.split(',')[1].replace(/\s/, '')
    if not inRange x - 1, y - 1
      throw "Each coordinate must be between 1 and #{GRID_SIZE}"
    else
      return {x, y}
  else
    throw 'Input must be of the form `x, y`'

x1 = x2 = y1 = y2 = null
newMove = true
score = 0
moveCount = 0

stdin = process.openStdin()
stdin.setEncoding 'utf8'
stdin.on 'data', (input) ->
  try
    if newMove 
      {x: x1, y: y1} = validateInput(input)
      console.log "First tile: #{grid[x1][y1]} (#{x1}, #{y1})"
      console.log "Please choose second tile to swap with this one:"
      newMove = false
    else
      {x: x2, y: y2} = validateInput(input)
      console.log "Second tile: #{grid[x2][y2]} (#{x2}, #{y2})"
      console.log "Swapping (#{x1}, #{y1}) with (#{y2}, #{y2}).."
      oldGrid = JSON.parse JSON.stringify(grid) # deep copy
      x1--; x2--; y1--; y2--; # convert 1-based indices to 0-based
      [grid[x1][y1], grid[x2][y2]] = [grid[x2][y2], grid[x1][y1]]
      {moveScore, newWords} = scoreMove oldGrid, grid
      score += moveScore
      unless newWords.length is 0
        console.log "You formed the following word(s):"
        console.log newWords.join(', ')
      moveCount++
      console.log "Your score after #{moveCount} moves: #{score}"
      printGrid()
      console.log "Please choose a tile in the form (x, y):"
      newMove = true
  catch e
    console.log e
#END:gameLoop