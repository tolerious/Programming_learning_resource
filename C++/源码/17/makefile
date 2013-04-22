# executable files for this directory
OBJECTS = use-handle.exe book.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
# MS compiler does not appear to handle try blocks on 
# template constructors
use-handle.obj: MS_Handle.h

Sales_item.obj book.obj: Sales_item.h
book.exe: Sales_item.obj book.obj 
	$(CPP) $(CPPFLAGS) book.obj Sales_item.obj -o book.exe
