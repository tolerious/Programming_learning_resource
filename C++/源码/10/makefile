# executable files for this directory
OBJECTS = word_transform.exe multimap.exe \
	  3ed_query.exe word_count.exe erasemap.exe \
	  setexclusion.exe query.exe 

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# one or more files in this directory includes a header
# defined in chapter 9
LOCFLAGS=-I ..\9

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
setexclusion.exe: setexclusion.obj ..\8\get_openfile.obj
	$(CPP) $(CPPFLAGS) setexclusion.obj ..\8\get_openfile.obj \
			-o setexclusion.exe

3ed_query.exe: 3ed_query.obj 3ed_querymain.obj 3ed_query.h ..\8\get_openfile.obj
	$(CPP) $(CPPFLAGS) 3ed_querymain.obj 3ed_query.obj \
	                ..\8\get_openfile.obj -o 3ed_query.exe

query.exe: TextQuery.obj querymain.obj TextQuery.h \
	          ..\8\get_openfile.obj ..\7\mk_plural2.obj
	$(CPP) $(CPPFLAGS) querymain.obj TextQuery.obj ..\8\get_openfile.obj \
		        ..\7\mk_plural2.obj -o query.exe

word_transform.exe: word_transform.obj ..\8\get_openfile.obj
	$(CPP) $(CPPFLAGS) word_transform.obj \
	                ..\8\get_openfile.obj -o word_transform.exe
