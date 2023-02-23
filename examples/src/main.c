#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "linked_list_string_item.h"

#define to_list (list_node_t **)
#define to_node (list_node_t *)
#define to_string_item (string_item_t *)

int main() {
    string_item_t *my_linked_list = NULL;
    list_append(to_list & my_linked_list, to_node string_item_new("Hello World"));
    list_append(to_list & my_linked_list, to_node string_item_new("Test001"));
    list_append(to_list & my_linked_list, to_node string_item_new("Test002"));
    list_append(to_list & my_linked_list, to_node string_item_new("Last Item of the Linked List"));
    string_item_t *string_item = my_linked_list;
    printf("==========LIST==========\n");
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = to_string_item string_item->node.next;
    }

    string_item_t *item_to_search = string_item_new("Test001");
    string_item_t *removed_item = to_string_item list_remove(to_list & my_linked_list, to_node item_to_search, 8);
    string_item = my_linked_list;
    printf("==========LIST AFTER REMOVE==========\n");
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = to_string_item string_item->node.next;
    }
    // Free items
    free(item_to_search);
    free(removed_item);

    printf("==========REVERSED LIST==========\n");
    list_reverse(to_list & my_linked_list);
    string_item = my_linked_list;
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = to_string_item string_item->node.next;
    }

    // Free list
    while (my_linked_list) {
        removed_item = to_string_item list_pop(to_list & my_linked_list);
        free(removed_item);
    }

    return 0;
}