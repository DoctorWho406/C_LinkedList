@echo off

IF EXIST "examples\bin" (
    RD /S /Q "examples\bin"
)

MD "examples\bin"

clang -o examples/bin/Example.exe -I include -I examples/include src/LinkedList.c examples/src/StringItem.c examples/src/main.c

IF EXIST "examples\bin\Example.exp" (
    DEL /Q "examples\bin\Example.exp"
)

IF EXIST "examples\bin\Example.lib" (
    DEL /Q "examples\bin\Example.lib"
)