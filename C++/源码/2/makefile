# executable files for this directory
OBJECTS = pow2.exe pow2_try2.exe pow_tbl.exe twosome.exe \
	  scope_levels.exe ref-ex.exe scope_levels2.exe \
	  print_enum.exe print_enum2.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# by default, make recompiles a source file any time it changes
# this rule says that decls2.cpp should also be recompiled if
# the file ..\1\Sales_item.h changes 
decls2.obj: decls2.cc ..\1\Sales_item.h

# rule to make pow_tbl.exe, which differs from the default rule
# in the makefile template.  pow_tbl must be linked with the
# pow_fcn.obj file --- the code in pow_tbl.cpp calls a function
# defined in pow_fcn.cpp and so both files must be used to
# generate an executable
pow_tbl.exe: pow_tbl.obj pow_fcn.obj
	$(CPP) $(CPPFLAGS) pow_tbl.obj pow_fcn.obj -o pow_tbl.exe

