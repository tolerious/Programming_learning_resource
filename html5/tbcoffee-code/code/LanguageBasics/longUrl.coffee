#START:main
longUrl = 'http://intergalacticplanetary
           planetaryintergalactic.com'
#END:main

assert = require 'assert'
assert.equal longUrl, 'http://intergalacticplanetaryplanetaryintergalactic.com'