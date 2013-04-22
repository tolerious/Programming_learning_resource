# executable files for this directory
OBJECTS = string_size.exe char_repl.exe init_vec.exe \
	  string_add.exe str_vers3.exe \
	  str_vers2.exe vec_assign.exe \
	  cctype.exe strcompare.exe bits.exe \
	  string_io2.exe add_using.exe \
	  word_echo.exe getline.exe string_io.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
vec_decls.o: vec_decls.cc ..\1\Sales_item.h
