#START:main
userListItemTemplate = (username) ->
  """
    <li>
      <img class="avatar" src="avatars/#{username}.png" />
      <span class="username"><a href="/#{username}">#{username}</a></span>
    </li>
  """
#END:main

assert = require 'assert'
assert.ok userListItemTemplate('jack').indexOf('"avatars/jack.png"') > -1