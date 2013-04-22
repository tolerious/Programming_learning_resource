Some programs read cin for their input.
Sample data files are in the data directory:

     File           Programs that use that input file
     ----           --------
     chars          no-skipws, skipws, getput, getc
     badgetc        badgetc

NOTE: the fourth character in badgetc is the one on
our system that converts to the same character as EOF.
Other systems may have to use other values.

Two other programs, require input files:

    main-proto reads a file that is specifed as an
        argument to main.  main-proto reads that file 
        and prints what is read separating each word
        by a newline.
    seek reads and writes to a file named copyOut that 
        it expects to be in the current directory.  
        The file data/seek matches the example in the book.

Programs not listed above print output and do
not read any input

