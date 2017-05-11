@echo off
if exist result.txt del result.txt
for %%i in (01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20) do call test %1 %%i