echo on
cnt_found < data\find
find_word <data\find

for %%i in (andtest arraysizeof assignment cond cond2 incr int-div oknew 
	   overflow prec shift-prec sizeof_arr sizeof_pgm vec_init 
	   warn_dbltoint) do %%i
