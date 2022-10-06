@echo off

set /p teststring= You string (all same case please):
echo %teststring%

call :isPalindrom result %teststring%
if %result% == 1 echo %teststring% is palindrom
if %result% == 0 echo %teststring% is not palindrom

goto :end


:isPalindrom
	set %1=0
	set string=%2
	if "%string%"=="" (
		set %1=1
		goto :end
	)

	if "%string:~1,1%" == "" (
		set %1=1
		goto :end 
	)

	if "%string:~0,1%" == "%string:~-1%" (
		call :isPalindrom %1 %string:~1,-1% 
	)

:end
