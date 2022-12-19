@echo off

set BAT_BASE_PATH=%~p0

if exist "%BAT_BASE_PATH%library" (
    RD /S /Q "%BAT_BASE_PATH%library"
)

MD "%BAT_BASE_PATH%library"

clang -shared -o "%BAT_BASE_PATH%library/linkedlist.dll" -I "%BAT_BASE_PATH%include" -I "%BAT_BASE_PATH%examples/include" "%BAT_BASE_PATH%src/LinkedList.c" "%BAT_BASE_PATH%examples/src/StringItem.c" "%BAT_BASE_PATH%examples/src/main.c"