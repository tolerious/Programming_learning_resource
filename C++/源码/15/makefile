# executable files for this directory
OBJECTS = Basket_main.exe scope.exe V2_Basket_main.exe \
	  bsk2.exe Query.exe main4.exe main5.exe 

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# one or more files in this directory includes a header
# defined in chapter 10
LOCFLAGS = -I..\10

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
bsk2.exe: Basket.obj bsk2.obj
	$(CPP) $(CPPFLAGS) bsk2.obj Basket.obj -o bsk2.exe

V2_Basket_main.cc V2_Basket.cc: Basket2.h Basket_main.cc Basket.cc mk_basket2
	mk_basket2

V2_Basket_main.exe: V2_Basket_main.obj V2_Basket.obj
	$(CPP) $(CPPFLAGS) V2_Basket_main.obj V2_Basket.obj \
	                 -o V2_Basket_main.exe

Query.obj querymain.obj main4.obj main5.obj: Query.h
Basket.obj Basket_main.obj: Basket.h

Basket_main.exe: Basket_main.obj Basket.obj
	$(CPP) $(CPPFLAGS) Basket_main.obj Basket.obj -o Basket_main.exe

get_print.obj ..\10\TextQuery.obj: ..\10\TextQuery.h 


main5.exe: Query.obj main5.obj Query.h ..\10\TextQuery.h ..\10\TextQuery.obj \
		get_print.obj  ..\8\get_openfile.obj
	$(CPP) $(CPPFLAGS) main5.obj Query.obj \
	        ..\10\TextQuery.obj get_print.obj \
		..\8\get_openfile.obj -o main5.exe

main4.exe: Query.obj main4.obj Query.h ..\10\TextQuery.h ..\10\TextQuery.obj \
		get_print.obj ..\8\get_openfile.obj
	$(CPP) $(CPPFLAGS) main4.obj Query.obj \
	        ..\10\TextQuery.obj get_print.obj \
		..\8\get_openfile.obj  -o main4.exe

Query.exe: Query.obj querymain.obj Query.h ..\10\TextQuery.h \
		..\10\TextQuery.obj get_print.obj ..\8\get_openfile.obj
	$(CPP) $(CPPFLAGS) querymain.obj Query.obj \
	        ..\10\TextQuery.obj get_print.obj \
		..\8\get_openfile.obj -o Query.exe

