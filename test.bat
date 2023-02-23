@echo off

set BAT_BASE_PATH=%~p0

IF EXIST "%BAT_BASE_PATH%bin" (
    RD /S /Q "%BAT_BASE_PATH%bin"
)

MD "%BAT_BASE_PATH%bin"

clang -o "%BAT_BASE_PATH%bin\Test.exe" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%test\*.c"