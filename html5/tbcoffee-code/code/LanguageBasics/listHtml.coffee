#START:main
listHtml = '''
           <ul>
             <li>Amazing!</li>
             <li>Extraordinary!</li>
             <li>Superlative!</li>
           </ul>
           '''
#END:main

assert = require 'assert'
assert.equal listHtml, '<ul>\n  <li>Amazing!</li>\n  <li>Extraordinary!</li>\n  <li>Superlative!</li>\n</ul>'