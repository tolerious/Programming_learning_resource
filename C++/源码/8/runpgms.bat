echo on
no-skipws < data\chars
skipws < data\chars
getput < data\chars
getc < data\chars
badgetc < data\badgetc

main-proto main-proto.cpp
REM get fresh copy of the data file
copy data\seek copyOut           
seek copyOut

for %%i in (buf manips point prec sci_dec setw sstream use-getopen) do %%i
