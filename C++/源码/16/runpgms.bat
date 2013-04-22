echo on
use-query-handle data\Alice_story <data\query_in
swap <data\swap

for %%i in (Basket_main Queue-assign QueueMain QueueMain2 QueueMain3 
           char_main char_main_push compare newQueueMain newQueueMain2 
	   newQueueMain3 nontype overcomp overcomp2 spcl-max use-handle) do %%i
