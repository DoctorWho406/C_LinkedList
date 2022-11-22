#include <stddef.h>
#include <stdio.h>
#include "Functions.h"

#define toList (struct list_node **)
#define toNode (struct list_node *)
#define toStringItem (struct string_item *)

int main() {
    struct string_item *my_linked_list = NULL;
    struct string_item *new_item = string_item_new("Test001");
    list_append(toList&my_linked_list, toNode string_item_new("Hello World"));
    list_append(toList&my_linked_list, toNode new_item);
    list_append(toList&my_linked_list, toNode string_item_new("Test002"));
    list_append(toList&my_linked_list, toNode string_item_new("Last Item of the Linked List"));
    struct string_item *string_item = my_linked_list;
    printf("==========LIST BEFORE REMOVE==========\n");
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = toStringItem string_item->node.next;
    }

    list_remove(toList&my_linked_list, toNode new_item);
    string_item = my_linked_list;
    printf("==========LIST AFTER REMOVE==========\n");
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = toStringItem string_item->node.next;
    }

    printf("==========REVERSED LIST==========\n");
    string_item = toStringItem list_reverse(toList&my_linked_list);
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = toStringItem string_item->node.next;
    }

    return 0;
}