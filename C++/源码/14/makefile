# executable files for this directory
OBJECTS = subscript.exe absInt.exe fcnobj.exe directcall.exe \
	  use_chckPtr.exe count-size.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# one or more files in this directory includes a header
# defined in chapter 11 or 12
LOCFLAGS = -I..\11 -I..\12

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
use_chckPtr.obj CheckedPtr.obj: CheckedPtr.h

use_chckPtr.exe: use_chckPtr.obj CheckedPtr.obj
	$(CPP) $(CPPFLAGS) use_chckPtr.obj CheckedPtr.obj -o use_chckPtr.exe

directcall.exe: directcall.obj Sales_item.obj
	$(CPP) $(CPPFLAGS) directcall.obj Sales_item.obj -o directcall.exe

