Some programs read cin for their input.
Sample data files are in the data directory:

     File           Programs that use that input file
     ----           --------
   use_equalrange   use_equalrange
   use_find         use_find
   arrow            arrow
   use-ostream-iter use-ostream-iter
   iostream_iter    iostream_iter
                    use-istream-iter
                    equiv-istream-iter
   reverse-iter     reverse-iter
   parms            parms
   fox_story        elim-dups

The program:

   count-size

reads the standard input and report information about
what was read.  Any file can be provided as the input;
the file 'data/fox_story' contains the data used in the book.

The program:

   vocab

prompts the user for one or more files and reads the specified
file(s), and reports statistics about the words used in those files.

The programs:

    iostream_iter
    use-istream-iter
    equiv-istream-iter

read integers from standard input and write what was read to the
standard output.  The file `data/iostream_iter' can be used with
any of these three programs.

Programs not listed above print output and do
not read any input

