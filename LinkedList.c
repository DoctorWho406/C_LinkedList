#include <stddef.h>
#include <stdio.h>
#include "Functions.h"

#define to_list (list_node_t **)
#define to_node (list_node_t *)
#define to_string_item (string_item_t *)

int main() {
    string_item_t *my_linked_list = NULL;
    string_item_t *new_item = string_item_new("Test001");
    list_append(to_list&my_linked_list, to_node string_item_new("Hello World"));
    list_append(to_list&my_linked_list, to_node new_item);
    list_append(to_list&my_linked_list, to_node string_item_new("Test002"));
    list_append(to_list&my_linked_list, to_node string_item_new("Last Item of the Linked List"));
    string_item_t *string_item = my_linked_list;
    printf("==========LIST BEFORE REMOVE==========\n");
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = to_string_item string_item->node.next;
    }

    list_remove(to_list&my_linked_list, to_node new_item);
    string_item = my_linked_list;
    printf("==========LIST AFTER REMOVE==========\n");
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = to_string_item string_item->node.next;
    }

    printf("==========REVERSED LIST==========\n");
    string_item = to_string_item list_reverse(to_list&my_linked_list);
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = to_string_item string_item->node.next;
    }

    return 0;
}