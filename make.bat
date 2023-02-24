@echo off

set BAT_BASE_PATH=%~p0

if exist "%BAT_BASE_PATH%linkedlist" (
    RD /S /Q "%BAT_BASE_PATH%linkedlist"
)

MD "%BAT_BASE_PATH%linkedlist\lib"

clang -shared -o "%BAT_BASE_PATH%linkedlist/lib/linkedlist.dll" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%src/*.c"

IF %ERRORLEVEL% EQU 0 (
    MD "%BAT_BASE_PATH%linkedlist\include"

    COPY /Y "%BAT_BASE_PATH%include\*.h" "%BAT_BASE_PATH%linkedlist\include"
)
