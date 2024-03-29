# C_LinkedList
Simple implementation of LinkedList in C

# Usage

You could create a dll using `make.bat` (it require clang.exe).<br>
This will generate a ready-to-use directory called `linkedlist` containing the necessary libraries and includes.

## Command with clang.exe
```
clang -shared -o linkedlist/lib/linkedlist.dll -I include src/*.c
```
N.B.<br>
It requires that the `linkedlist/lib` folder exists

## Use it
You can copy the `linkedlist` folder into your project.

# API

First of all implement your structure with the data you want. This must contain list_node_t node;

### Example
```C
struct string_item {
    list_node_t node;
    const char *string;
};
```

## Functions

<table>
    <thead>
        <tr>
            <th>Function</th>
            <th colspan=2><center>Parametrs</center></th>
            <th colspan=2><center>Return</center></th>
            <th>Explanation</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=2>list_append</td>
            <td>list_node_t**</td>
            <td>Pointer to head of list.<br/>It could be NULL</td>
            <td rowspan=2 colspan=2><center>void</center></td>
            <td rowspan=2>Adds an item to the end of the list<br/>List is created if pointer is NULL</td>
        </tr>
        <tr>
            <td>list_node_t*</td>
            <td>Pointer to the item to be append</td>
        </tr>
        <tr>
            <td>list_get_tail</td>
            <td>list_node_t**</td>
            <td>Pointer to head of list.<br/>It could be NULL</td>
            <td>list_node_t*</td>
            <td>Pointer to the last item or NULL if none</td>
            <td>Returns the last item of the list if any</td>
        </tr>
        <tr>
            <td>list_pop</td>
            <td>list_node_t**</td>
            <td>Pointer to head of list.<br/>It could be NULL</td>
            <td>list_node_t*</td>
            <td>Pointer to the popped item or NULL on failure</td>
            <td>Removes the last item of the list and returns it</td>
        </tr>
        <tr>
            <td rowspan=3>list_remove</td>
            <td>list_node_t**</td>
            <td>Pointer to head of list.<br/>It could be NULL</td>
            <td rowspan=3>list_node_t*</td>
            <td rowspan=3>Pointer to the removed item or NULL on failure</td>
            <td rowspan=3>Remove a list item with the same value as the one passed in and return it</td>
        </tr>
        <tr>
            <td>list_node_t*</td>
            <td>Pointer to the item to be remove</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Size of the data to compare in the structure<br/>In the above example the length of the string</td>
        </tr>
        <tr>
            <td>list_reverse</td>
            <td>list_node_t**</td>
            <td>Pointer to head of list.<br/>It could be NULL</td>
            <td colspan=2 colspan=2><center>void</center></td>
            <td>Invert the list and update the head pointer</td>
        </tr>
    </tbody>
</table>

# Example

Create executable using `example.bat` (it require clang.exe)

## Command with clang.exe
```
clang -o examples/bin/example.exe -I include -I examples/include src/*.c examples/src/*.c -L linkedlist\lib -llinkedlist
```
N.B.<br>
It requires that the `examples/bin` folder exists.<br/>
Copy `linkedlist.dll` from `linkedlist\lib` folder to `examples/bin` folder

## Run it
```
./examples/bin/example.exe
```
