echo on
string_io < data\string_io
string_io2 < data\string_io
word_echo < data\word_echo
getline < data\word_echo
add_using <data\add_using

for %%i in (bits cctype str_vers2 str_vers3 strcompare string_add 
	   string_size vec_assign) do %%i
