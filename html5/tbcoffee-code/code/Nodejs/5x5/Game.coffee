#START:imports
{Dictionary} = require './Dictionary'
{Grid} = require './Grid'
{OWL2} = require './OWL2'
{Player} = require './Player'
#END:imports

class Game
  constructor: ->
    @grid = new Grid
    @dictionary = new Dictionary(OWL2, @grid)
    @currPlayer = @player1 = new Player(1, 'Player 1', @dictionary)
    @player2 = new Player(2, 'Player 2', @dictionary)
    @player1.id = @player2.id = null
  
  addPlayer: (sessionId) ->
    if !@player1.id
      @player1.id = sessionId
    else
      @player2.id = sessionId
  
  removePlayer: (sessionId) ->
    @playerWithId(sessionId).id = null
  
  isOpen: ->
    not @isFull()
  
  isFull: ->
    if @player1.id and @player2.id then true else false
  
  playerWithId: (sessionId) ->
    if sessionId is @player1.id
      @player1
    else if sessionId is @player2.id
      @player2

  otherPlayer: (sessionId) ->
    if sessionId is @player2.id
      @player1
    else if sessionId is @player1.id
      @player2
  
  endTurn: ->
    if @currPlayer is @player1
      @currPlayer = @player2
    else
      @currPlayer = @player1

root = exports ? window
root.Game = Game