Some programs read cin for their input.
Sample data files are in the data directory:

     File           Programs that use that input file
     ----           --------
   bad_items        exception_example
   add_item         exception_example
   doWhile          doWhile

Two other programs: vowels and othercnt read input.
They can read any file, such as the program itself.
It is worth noting, that the vowels and othercnt
programs read characters using the input operator,
which, by default, ignores whitespace.  The output
of this program will, therefore, not match any system
utility such as the UNIX 'wc' command that counts all
characters.

All other programs print output and do not read any input

