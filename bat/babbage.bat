@echo off
set /a i = 0

:begin
set /a i = i + 1
set /a pow = i * i
set /a ost = %pow% %% 1000
if %ost% equ 296 (goto end296) else (goto begin)



:end296
echo %i% the end is 296 = %pow%
goto begin1


:begin1 
set /a i = i + 1
set /a pow = i * i
set /a ost = %pow% %% 1000
if %ost% equ 696 (goto end696) else (goto begin1)

:end696
echo %i% the end is 696 = %pow%

