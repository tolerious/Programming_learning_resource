# executable files for this directory
OBJECTS = manips.exe prec.exe point.exe sci_dec.exe \
	  buf.exe setw.exe seek.exe  sstream.exe \
	  use-getopen.exe main-proto.exe badgetc.exe \
	  skipws.exe no-skipws.exe getput.exe getc.exe \

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
main-proto.exe: main-proto.obj get_openfile.obj
	$(CPP) $(CPPFLAGS) main-proto.obj get_openfile.obj \
	               -o main-proto.exe

use-getopen.exe: use-getopen.obj get_openfile.obj
	$(CPP) $(CPPFLAGS) use-getopen.obj get_openfile.obj \
	               -o use-getopen.exe
