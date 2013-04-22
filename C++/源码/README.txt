Each of the subdirectories in this directory contains files 
corresponding to the complete programs and many of the program
fragments shown in the related chapter.  

BUILDING EXECUTABLES
--------------------
We provide two different source code distributions: One that
works with Microsoft Visual Studio .Net compiler and the other 
that works with the GNU compiler.  The source code in these
two versions are largely the same, although there are some
programs in later chapters that had to be changed to accommodate
limitations in MS handling of nested templates.

Each version of the source code contains a general makefile_template
in the top-level directory and directory-specific makefiles
in each chapter subdirectory.  The makefiles are fairly simple 
and we have provided comments in the hope that even those who
are not familiar with makefiles can understand how to compile
these programs by hand if so desired.

In the top level directory there is a makefile that will make
the entire source tree -- it does a cd, in turn, to each subdirectory
and makes the executables in that directory.  The top level
makefile also has targets "clean" and "clobber" to remove the
object files or object and executable file respectively.

To use make on a Windows operating system you invoke the command
name "nmake":

    ## Windows machines
    > nmake             # compiles all the programs
    > nmake clean       # removes all the object files and stackdumps
    > nmake clobber     # removes executable, object and stackdump files

INPUT and OUTPUT
----------------
Because not all of the programs are complete, many of them 
do not generate "sensible" output, but instead often print 
some detail about the internal state of the program.  To
understand the output, you will have to understand the program.
This is intentional.

The input, if any, to these programs varies:

   Some programs print a prompt and wait for input on the standard input

   Other programs read the standard input but do not print a prompt

   Others take one or more arguments specifying a file name to read

   Yet others take a file name argument and read the standard input

Each chapter subdirectory contains a README that explains the
input, if any, expected by each executable file.

RUNNING THE PROGRAMS
--------------------
Each directory contains a simple batch file named "runpgms.bat" that
runs the executables made in that directory.

Note that on some systems, the default setting for
the PATH variable does not include the current directory.  
So, for example, if you try to execute

     add_item <data\add_item

the "add_item" program will not be found.  Instead, you must write

     .\add_item <data\add_item


SAMPLE DATA FILES
-----------------
For many of the programs that expect input, we have provided
small, sample input files.  Input files are always found in a 
subdirectory named "data".  For example, the program 'add_item' 
in directory 1 reads Sales_item transactions from the 
standard input but does *not* prompt for input.  
If the program is invoked:

    add_item

it will wait for input, which must be in the format of a Sales_item
transaction.

Alternatively, the file data\add_item can be used to provide
input to this program by using the operating system's support
for file redirection.  Assuming the following is executed in 
the directory named '1' writing

    add_item < data\add_item

will bind the standard input to the file 'data\add_item' and will
execute the program 'add_item' on the data in that file.

Programs that take an argument to main will fail if they are
invoked with no argument.  In general, we provide a file to use
in each case, although in some cases any file could be used
as input.  For example, in the directory for chapter 10, there
is a program named word_count that can read any file and prints
the count of how often each word in that file occurs.  Another
program in that directory, the word_transform program, requires 
two input files.  You might invoke these programs as follows:

    # the program will use the README file as its input
    word_count README  

    # word_transform takes two files, samples are in the data directory
    # this execution uses the file data\trans-map to transform the
    # text in data\trans-text
    word_transform data\trans-map data\trans-text

