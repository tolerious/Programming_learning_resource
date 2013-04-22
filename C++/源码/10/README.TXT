The programs in this directory that read the standard input 
place no requirements on their input data -- they read 
whitespace separated text and count occurences or
remove specified words etc.  Any file, for example this README, 
could be supplied as input to these programs:

     word_count:   counts occurrences of each word in the input
     erasemap:     like word_count builds a map of the words in the
                   input and then erases the word "the"

Other programs require one or more files to be specified
as an argument to main:

     Program            File
    setexclusion       remove_words
    word_transform     trans-map, trans-text
    query              Alice_story
    3edquery           Alice_story

setexclusion: 
   reads the standard input and also requires takes a file 
   name as an argument to the program.  
   The specified file contains a list of words to ignore 
   when counting words read from the standard input.
   The file data/exclude_words is a sample file of words
   to ignore.

word_transform:
   takes two files as arguments to main.  
   The first specifies a map from input word to output word
   The second is the text to transform.

query and 3rdquery:
   These programs take an argument that specifies the file to read
   and then read the standard input iterating with the user for words 
   to find in the file.  
   The file 'data/Alice_story' is the simple story used for queries
   presented in the book

multimap: 
   Is self-contained. It writes to the standard input but do no input.

