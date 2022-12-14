@echo off

if exist "library" (
    RD /S /Q "library"
)

MD "library"

clang -shared -o library/linkedlist.dll -I include -I examples/include src/LinkedList.c examples/src/StringItem.c examples/src/main.c