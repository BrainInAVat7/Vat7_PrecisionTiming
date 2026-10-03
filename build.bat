@echo off
setlocal

set "CFLAGS=/std:c17 /Iinclude /W4 /WX /permissive-"

if "%1"=="" goto windows
if /I "%1"=="windows" goto windows
if /I "%1"=="sdl" goto sdl
if /I "%1"=="clean" goto clean

echo Usage: build.bat [windows^|sdl^|clean]
exit /b 1

:windows
if not exist bin mkdir bin
cl %CFLAGS% /Fobin\ /Febin\vt7_pt_windows_pattern_1_demo.exe ^
    src\vt7_pt_windows.c ^
    src\vt7_pt_pattern_1_demo.c
cl %CFLAGS% /Fobin\ /Febin\vt7_pt_windows_pattern_2_demo.exe ^
    src\vt7_pt_windows.c ^
    src\vt7_pt_pattern_2_demo.c
exit /b %ERRORLEVEL%

:sdl
if not exist bin mkdir bin
cl %CFLAGS% /Fobin\ /Febin\vt7_pt_windows_sdl_pattern_1_demo.exe ^
    src\vt7_pt_sdl.c ^
    src\vt7_pt_pattern_1_demo.c ^
    /link SDL3.lib
cl %CFLAGS% /Fobin\ /Febin\vt7_pt_windows_sdl_pattern_2_demo.exe ^
    src\vt7_pt_sdl.c ^
    src\vt7_pt_pattern_2_demo.c ^
    /link SDL3.lib
exit /b %ERRORLEVEL%

:clean
if exist bin rmdir /s /q bin
exit /b 0
