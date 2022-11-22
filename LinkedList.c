#include <stddef.h>
#include <stdio.h>
#include "Functions.h"

int main() {
    struct string_item *my_linked_list = NULL;
    struct string_item *item = string_item_new("Test001");
    list_append((struct list_node **)&my_linked_list, (struct list_node *)string_item_new("Hello World"));
    list_append((struct list_node **)&my_linked_list, (struct list_node *)item);
    list_append((struct list_node **)&my_linked_list, (struct list_node *)string_item_new("Test002"));
    list_append((struct list_node **)&my_linked_list, (struct list_node *)string_item_new("Last Item of the Linked List"));
    struct string_item *string_item = my_linked_list;
    printf("==========LIST BEFORE REMOVE==========\n");
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = (struct string_item *)string_item->node.next;
    }
    
    list_remove((struct list_node **)&my_linked_list, (struct list_node *)item);
    string_item = my_linked_list;
    printf("==========LIST AFTER REMOVE==========\n");
    while (string_item) {
        printf("%s\n", string_item->string);
        string_item = (struct string_item *)string_item->node.next;
    }
    return 0;
}