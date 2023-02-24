@echo off

set BAT_BASE_PATH=%~p0

IF EXIST "%BAT_BASE_PATH%bin" (
    RD /S /Q "%BAT_BASE_PATH%bin"
)

MD "%BAT_BASE_PATH%bin"

clang -o "%BAT_BASE_PATH%bin\test.exe" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%src\*.c" "%BAT_BASE_PATH%test\*.c"

IF EXIST "%BAT_BASE_PATH%bin\test.exp" (
    DEL /Q "%BAT_BASE_PATH%bin\test.exp"
)

IF EXIST "%BAT_BASE_PATH%bin\test.lib" (
    DEL /Q "%BAT_BASE_PATH%bin\test.lib"
)