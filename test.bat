@echo off

set BAT_BASE_PATH=%~p0

IF EXIST "%BAT_BASE_PATH%test\bin" (
    RD /S /Q "%BAT_BASE_PATH%test\bin"
)

MD "%BAT_BASE_PATH%test\bin"

clang -o "%BAT_BASE_PATH%test\bin\test.exe" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%src\*.c" "%BAT_BASE_PATH%test\*.c"

IF %ERRORLEVEL% EQU 0 (
    IF EXIST "%BAT_BASE_PATH%test\bin\test.exp" (
        DEL /Q "%BAT_BASE_PATH%test\bin\test.exp"
    )

    IF EXIST "%BAT_BASE_PATH%test\bin\test.lib" (
        DEL /Q "%BAT_BASE_PATH%test\bin\test.lib"
    )
)