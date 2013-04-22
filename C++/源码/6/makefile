# executable files for this directory
OBJECTS = forcount.exe copy_array.exe wdebug.exe nodebug.exe \
	  vowels.exe othercnt.exe doWhile.exe exception_example.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# one or more files in this directory includes a header
# defined in chapter 1
LOCFLAGS = -I..\1

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
wdebug.exe: wdebug.cpp
	$(CPP) $(CPPFLAGS) wdebug.cpp -o wdebug.exe

nodebug.exe: wdebug.cpp
	$(CPP) -D NDEBUG $(CPPFLAGS) wdebug.cpp -o nodebug.exe
