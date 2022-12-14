#include <stddef.h>
#include <string.h>

#include "LinkedList.h"


list_node_t *list_get_tail(list_node_t **head) {
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;
    while (current_node) {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

list_node_t *list_append(list_node_t **head, list_node_t *item) {
    list_node_t *tail = list_get_tail(head);
    if (!tail) {
        *head = item;
    } else {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

list_node_t *list_pop(list_node_t **head) {
    list_node_t *current_head = *head;
    if (!current_head) {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

list_node_t *list_remove(list_node_t **head, list_node_t *item, size_t size_of_value) {
    list_node_t *current_node = *head;
    list_node_t *prev_node = NULL;
    list_node_t *removed = NULL;

    while (current_node) {
        if (memcmp(current_node + 1, item + 1, size_of_value) == 0) {
            removed = current_node;
            if (prev_node) {
                prev_node->next = current_node->next;
            } else {
                *head = current_node->next;
            }
            removed->next = NULL;
            return removed;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }

    return removed;
}


void list_reverse(list_node_t **head) {
    list_node_t *curr_node = *head;
    list_node_t *prev_node = NULL;
    list_node_t *next_node = NULL;

    while (curr_node) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    *head = prev_node;
}