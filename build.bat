@echo off

if exist "bin" (
    RD /S /Q "bin"
)

MD "bin"

clang -o bin/LinkedList.exe -I include src/LinkedList.c src/StringItem.c src/List.c