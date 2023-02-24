@echo off

set BAT_BASE_PATH=%~p0

CALL "%BAT_BASE_PATH%make.bat"

IF EXIST "%BAT_BASE_PATH%examples\bin" (
    RD /S /Q "%BAT_BASE_PATH%examples\bin"
)

MD "%BAT_BASE_PATH%examples\bin"

clang -o "%BAT_BASE_PATH%examples/bin/example.exe" -I "%BAT_BASE_PATH%include" -I "%BAT_BASE_PATH%examples/include" "%BAT_BASE_PATH%examples/src/*.c" -L "%BAT_BASE_PATH%linkedlist\lib" -llinkedlist

IF %ERRORLEVEL% EQU 0 (
    IF EXIST "%BAT_BASE_PATH%examples\bin\example.exp" (
        DEL /Q "%BAT_BASE_PATH%examples\bin\example.exp"
    )

    IF EXIST "%BAT_BASE_PATH%examples\bin\example.lib" (
        DEL /Q "%BAT_BASE_PATH%examples\bin\example.lib"
    )

    COPY /Y "%BAT_BASE_PATH%linkedlist\lib\*.dll" "%BAT_BASE_PATH%examples\bin"
)