# executable files for this directory
OBJECTS = QueueMain.exe QueueMain2.exe QueueMain3.exe \
	  newQueueMain.exe newQueueMain2.exe newQueueMain3.exe \
	  char_main.exe char_main_push.exe \
	  Queue-assign.exe  use-handle.exe Basket_main.exe \
	  spcl-max.exe compare.exe \
	  overcomp.exe overcomp2.exe nontype.exe swap.exe \
	  use-query-handle.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# one or more files in this directory includes a header
# defined in chapter 10
LOCFLAGS = -I. -I..\1 -I..\10

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
QueueMain.exe: QueueMain.cpp MS_Queue.h MS_Queue.cpp
QueueMain2.exe: QueueMain2.cpp MS_Queue.h MS_Queue.cpp
QueueMain3.exe: QueueMain3.cpp MS_Queue.h MS_Queue.cpp

#newQueue.h implements same Queue interface but builds it on top of std::list
newQueueMain.exe: newQueue.h
newQueueMain2.exe: newQueue.h
newQueueMain3.exe: newQueue.h 
use-handle.exe: use-handle.cpp Handle.h
Query.obj: Query.cpp Query.h 
Basket.obj Basket_main.obj: Basket.h

# version that specializes entire class
char_main.exe: char_queue.h char_queue.obj MS_Queue.h MS_Queue.cpp char_main.obj
	$(CPP) $(CPPFLAGS) char_main.obj char_queue.obj -o char_main.exe

# version that specializes just the push function
char_main_push.exe: MS_Queue.h MS_Queue.cpp char_main_push.obj 
	$(CPP) $(CPPFLAGS) char_main_push.obj -o char_main_push.exe

use-query-handle.exe: use-query-handle.cpp Handle.h Query.h Query.obj  \
	             ..\8\get_openfile.obj \
	             ..\10\TextQuery.h ..\15\get_print.obj
	$(CPP) $(CPPFLAGS) Query.obj use-query-handle.cpp \
	            ..\8\get_openfile.obj \
	            ..\15\get_print.obj ..\10\TextQuery.obj \
	                 -o use-query-handle.exe

Basket_main.exe: Basket_main.obj Basket.obj
	$(CPP) $(CPPFLAGS) Basket_main.obj Basket.obj -o Basket_main.exe

