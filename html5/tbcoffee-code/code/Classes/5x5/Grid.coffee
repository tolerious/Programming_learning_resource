#START:moduleVars
tileCounts =
  A: 9, B: 2, C: 2, D: 4, E: 12, F: 2, G: 3, H: 2, I: 9, J: 1, K: 1, L: 4
  M: 2, N: 6, O: 8, P: 2, Q: 1, R: 6, S: 4, T: 6, U: 4, V: 2, W: 2, X: 1
  Y: 2, Z: 1

totalTiles = 0
totalTiles += count for letter, count of tileCounts
alphabet = (letter for letter of tileCounts).sort()

randomLetter = ->  
  randomNumber = Math.ceil Math.random() * totalTiles
  x = 1
  for letter in alphabet
    x += tileCounts[letter]
    return letter if x > randomNumber
#END:moduleVars

#START:constructor
class Grid
  constructor: ->
    @size = size = 5
    @tiles = for x in [0...size]
      for y in [0...size]
        randomLetter()
#END:constructor

#START:simpleFuncs
  inRange: (x, y) ->
    0 <= x < @size and 0 <= y < @size
  
  swap: ({x1, y1, x2, y2}) ->
    [@tiles[x1][y1], @tiles[x2][y2]] = [@tiles[x2][y2], @tiles[x1][y1]]
  
  rows: ->
    for x in [0...@size]
      for y in [0...@size]
        @tiles[y][x]
#END:simpleFuncs

root = exports ? window
root.Grid = Grid