$ = ajax: (obj) -> return obj.data
hexMD5 = (str) -> 'hex' + str

#START:main
passwordHash = 'e2fc714c4727ee9395f324cd2e7f331f'
# do other stuff...
sendPasswordHashToServer = (password) ->
  passwordHash = hexMD5(password)
  $.ajax data: passwordHash
#END:main

assert = require 'assert'
assert.equal passwordHash, 'e2fc714c4727ee9395f324cd2e7f331f'
sendPasswordHashToServer 'password'
assert.equal passwordHash, 'hexpassword'