# executable files for this directory
OBJECTS = swapmain1.exe swapmain2.exe enum-match.exe conv-enums.exe \
	  vecprintmain.exe rgcd.exe fact.exe useptrswap.exe \
	  ref-fcn.exe cfcn_ex.exe \
	  count-calls.exe pow_main.exe mk_plural.exe \
	  good_printmain.exe stl-arr-fcns.exe refret-ex.exe \
	  usefcnptr.exe mainret.exe inline_shorter.exe \
	  useptrparms.exe vec-parms.exe mainmath.exe mk_plural2.obj

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
cfcn_ex.exe: cfcn_ex.c
	$(CC) cfcn_ex.c -o cfcn_ex.exe

swapmain1.exe: badswap.obj decl1.h swapmain1.obj swapmain.pgm
	$(CPP) $(CPPFLAGS) swapmain1.obj badswap.obj -o swapmain1.exe

swapmain2.exe: swap.obj decl2.h swapmain2.obj swapmain.pgm
	$(CPP) $(CPPFLAGS) swapmain2.obj swap.obj -o swapmain2.exe

mainmath.exe: mathstuff.obj mainmath.obj localMath.h
	$(CPP) $(CPPFLAGS) mainmath.obj mathstuff.obj -o mainmath.exe

vecprintmain.exe: vecprintmain.obj vecprint.obj
	$(CPP) $(CPPFLAGS) vecprintmain.cpp vecprint.obj \
	                                  -o vecprintmain.exe

pow_main.exe: pow_fcn.obj pow_main.obj
	$(CPP) $(CPPFLAGS) pow_main.obj pow_fcn.obj -o pow_main.exe

mk_plural2.obj: mk_plural2.cpp
	$(CPP) $(CPPFLAGS) -c mk_plural2.cpp -o mk_plural2.obj
