foo = -> console.log Array::slice.call(arguments).join(' and ') + '!'
bar = 'Curiouser'
baz = 'curiouser'
#START:snippet
foo bar, baz
#END:snippet