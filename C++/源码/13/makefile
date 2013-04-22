# executable files for this directory
OBJECTS = Foldermain.exe smart-ptr.exe value-ptr.exe \
	  plain-ptr.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
Folder.obj Foldermain.obj: Folder.h

Foldermain.exe: Folder.obj Foldermain.obj
	$(CPP) $(CPPFLAGS) Folder.obj Foldermain.obj -o Foldermain.exe
