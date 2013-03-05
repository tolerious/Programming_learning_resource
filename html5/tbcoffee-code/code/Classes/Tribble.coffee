#START:definition
class Tribble
  constructor: ->
    @isAlive = true
    Tribble.count++
  
  # Prototype properties
  breed: -> new Tribble if @isAlive
  die: ->
    Tribble.count-- if @isAlive
    @isAlive = false
  
  # Class-level properties
  @count: 0
  @makeTrouble: -> console.log ('Trouble!' for i in [1..@count]).join(' ')
#END:definition

#START:trouble
tribble1 = new Tribble
tribble2 = new Tribble
Tribble.makeTrouble()   # "Trouble! Trouble!"
#END:trouble

#START:dying
tribble1.die()
Tribble.makeTrouble()   # "Trouble!"
#END:dying

#START:breeding
tribble2.breed().breed().breed()
Tribble.makeTrouble()   # "Trouble! Trouble! Trouble! Trouble!"
#END:breeding