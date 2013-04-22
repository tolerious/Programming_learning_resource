echo on 
mainmath < data\mainmath

for %%i in (cfcn_ex.exe conv-enums.exe count-calls.exe enum-match.exe 
	   fact.exe good_printmain.exe inline_shorter.exe 
	   mainret.exe mk_plural.exe pow_main.exe ref-fcn.exe 
	   refret-ex.exe rgcd.exe stl-arr-fcns.exe swapmain1.exe 
	   swapmain2.exe usefcnptr.exe useptrparms.exe useptrswap.exe 
	   vec-parms.exe vecprintmain.exe) do %%i
