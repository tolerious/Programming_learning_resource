#START:main
cube = (num) -> Math.pow num, 3
list = [1, 2, 3, 4, 5]
cubedList = (cube num for num in list)
#END:main

assert = require 'assert'
assert.deepEqual cubedList, [1, 8, 27, 64, 125]