# C_LinkedList
Simple implementation of LinkedList in C

# Usage

You could create a dll using `make.bat` (it require clang.exe)

## Command with clang.exe
```
clang -shared -o library/linkedlist.dll -I include -I examples/include src/LinkedList.c examples/src/StringItem.c examples/src/main.c
```
N.B.<br>
It requires that the `library` folder exists

## Use it
Copy the content of `library` and `include` folders wjere you want and use it in your code. 

# Example

Create executable using `example.bat` (it require clang.exe)

## Command with clang.exe
```
clang -o examples/bin/Example.exe -I include -I examples/include src/LinkedList.c examples/src/StringItem.c examples/src/main.c
```
N.B.<br>
It requires that the `examples/bin` folder exists

## Run it
```
./examples/bin/Example.exe
```