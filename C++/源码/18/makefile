# executable files for this directory
OBJECTS = MS_statmem.exe QueueMain.exe QueueMain2.exe QueueMain3.exe \
	  typeid.exe dyn_cast.exe vec.exe vec-opnew.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# -GR needed to enable the RTTI operators
CPPFLAGS = -GR $(CPPFLAGS) 

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
QueueMain.exe: QueueMain.cpp MS_Queue.h MS_Queue.cpp
QueueMain2.exe: QueueMain2.cpp MS_Queue.h MS_Queue.cpp
QueueMain3.exe: QueueMain3.cpp MS_Queue.h MS_Queue.cpp

