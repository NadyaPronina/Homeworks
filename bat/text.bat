@echo off
set /a nstrok=%1%
:begin
set /a n = nstrok - 1
set /a nstrok = nstrok + 1
for /f "tokens=1 delims=: " %%a in ('more  +%n% "myfile.txt"') do goto cout1 if %n% equ 3 (goto cout) else (goto begin)
for /f "usebackq" %%b in ('+%n% "myfile.txt"') do goto cout1 if %n% equ 3 (goto cout) else (goto begin)

:cout1 
echo %%a >> out.txt
echo %%b >> out.txt
goto begin
:cout
for /f "tokens=*" %%s in (out.txt) do (
  echo %%s
)
PAUSE
