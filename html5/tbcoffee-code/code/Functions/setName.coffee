#START:func
setName = (name) -> @name = name
#END:func

#START:methodContext
cat = {}
cat.setName = setName
cat.setName 'Mittens'
console.log cat.name   # 'Mittens'
#END:methodContext

#START:callContext
pig = {}
setName.apply pig, ['Babe']
console.log pig.name   # 'Babe'
#END:callContext

#START:callProperty
horse = {}
cat.setName.apply horse, ['Mr. Ed']
console.log horse.name   # 'Mr. Ed'
#END:callProperty

#START:newContext
Dog = setName   # By convention, constructors are capitalized
dog1 = new Dog('Jimmy')
dog2 = new Dog('Jake')
console.log dog1.name   # 'Jimmy'
console.log dog2.name   # 'Jake'
#END:newContext

#START:globalContext
setName 'Lulu'
console.log name     # 'Lulu'
console.log @name    # undefined
#END:globalContext