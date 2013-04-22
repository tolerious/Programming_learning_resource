# executable files for this directory
OBJECTS = inserters.exe use-istream-iter.exe \
	  equiv-istream-iter.exe \
	  scores.exe rev-iters.exe innerprod.exe \
	  use_find.exe vocab.exe elim-dups.exe \
	  use_equalrange.exe iostream_iter.exe \
	  use-ostream-iter.exe reverse-iter.exe \
	  count-size.exe arrow.exe parms.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# one or more files in this directory includes a header
# defined in chapter 1
LOCFLAGS=-I ..\1

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
count-size.exe: count-size.obj ..\7\mk_plural2.obj
	$(CPP) $(CPPFLAGS) count-size.obj \
	                       ..\7\mk_plural2.obj -o count-size.exe

vocab.exe: vocab.obj ..\8\get_openfile.obj ..\7\mk_plural2.obj
	$(CPP) $(CPPFLAGS) vocab.obj ..\8\get_openfile.obj ..\7\mk_plural2.obj \
                                -o vocab.exe

