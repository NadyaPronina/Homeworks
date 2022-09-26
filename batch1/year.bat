@echo off
set /a nul = 0
set /a B = %1
set /a four=%B% %% 4
set /a fh=%B% %% 400
set /a hund=%B% %% 100

if %four% equ %nul% (goto level3) else (goto no)

:level2
if %fh% equ %nul% (goto yes) else (goto no)

:level3
if %hund% neq %nul% (goto yes) else (goto level2)

:yes
echo %1 is a leap year
goto break

:no
echo %1 is NOT a leap year

:break

pause
