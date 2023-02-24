@echo off

set BAT_BASE_PATH=%~p0

if exist "%BAT_BASE_PATH%outputs" (
    RD /S /Q "%BAT_BASE_PATH%outputs"
)

MD "%BAT_BASE_PATH%outputs"

clang -shared -o "%BAT_BASE_PATH%outputs/linkedlist.dll" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%src/*.c"

