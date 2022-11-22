#include <stddef.h>
#include "Item.h"

struct list_node *list_get_tail(struct list_node **head) {
    struct list_node *current_node = *head;
    struct list_node *last_node = NULL;
    while (current_node) {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

struct list_node *list_append(struct list_node **head, struct list_node *item) {
    struct list_node *tail = list_get_tail(head);
    if (!tail) {
        *head = item;
    } else {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

struct list_node *list_pop(struct list_node **head) {
    struct list_node *current_head = *head;
    if (!current_head) {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

struct list_node *list_remove(struct list_node **head, struct list_node *item) {
    struct list_node *current_node = *head;
    while(current_node->next != item) {
        current_node = current_node->next;
    }
    if(!current_node) { // scroll all and not find item
        return NULL;
    }
    struct list_node *removed = current_node->next;
    current_node->next = current_node->next->next;
    return removed;
}


struct list_node *list_reverse(struct list_node **head) {
    struct list_node *curr_node = *head;
    struct list_node *prev_node = NULL;
    struct list_node *next_node = NULL;

    while(curr_node) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    return prev_node;
}