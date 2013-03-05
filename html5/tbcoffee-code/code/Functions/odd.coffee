# branching version
#START:func
odd = (num) ->
  if typeof num is 'number'
    if num is Math.round num
      if num > 0
        num % 2 is 1
      else
        throw "#{num} is not positive"
    else
      throw "#{num} is not an integer"
  else
    throw "#{num} is not a number"
#END:func

#START:try
try
  odd 5.1
catch e
  console.log e
#END:try

# non-branching version
#START:func2
odd = (num) ->
  unless typeof num is 'number'
    throw "#{num} is not a number"
  unless num is Math.round num
    throw "#{num} is not an integer"
  unless num > 0
    throw "#{num} is not positive"
  num % 2 is 1    
#END:func2

try
  odd 5.1
catch e
  console.log e