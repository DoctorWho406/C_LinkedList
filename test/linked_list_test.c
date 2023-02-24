#define CLOVE_SUITE_NAME LinkedListTest
#include "clove-unit.h"
#include "linked_list.h"
#include <stdlib.h>

typedef struct test_item {
    list_node_t node;
    int value;
} test_item_t;

test_item_t *new_test_item(const int value) {
    test_item_t *item = malloc(sizeof(test_item_t));
    if (!item) {
        return NULL;
    }
    item->value = value;
    return item;
}


CLOVE_TEST(CreateLinkedListWithOneItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);

    CLOVE_NOT_NULL(first);

    linked_list_append(&head, (list_node_t *)first);

    CLOVE_NOT_NULL(head);
    CLOVE_PTR_EQ(first, head);

    free(first);
}

CLOVE_TEST(CreateLinkedListWithTwoItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);
    test_item_t *second = new_test_item(2);

    CLOVE_NOT_NULL(first);
    CLOVE_NOT_NULL(second);

    linked_list_append(&head, (list_node_t *)first);
    linked_list_append(&head, (list_node_t *)second);

    CLOVE_NOT_NULL(head);
    CLOVE_PTR_EQ(first, head);
    CLOVE_PTR_EQ(second, head->next);

    free(first);
    free(second);
}

CLOVE_TEST(GetTailFromLinkedListWithZeroItem) {
    list_node_t *head = NULL;

    list_node_t *tail = linked_list_get_tail(&head);
    CLOVE_NULL(tail);
}

CLOVE_TEST(GetTailFromLinkedListWithOneItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);

    linked_list_append(&head, (list_node_t *)first);

    list_node_t *tail = linked_list_get_tail(&head);
    CLOVE_NOT_NULL(tail);
    CLOVE_PTR_EQ(first, tail);

    free(first);
}

CLOVE_TEST(GetTailFromLinkedListWithTwoItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);
    test_item_t *second = new_test_item(2);

    linked_list_append(&head, (list_node_t *)first);
    linked_list_append(&head, (list_node_t *)second);

    list_node_t *tail = linked_list_get_tail(&head);
    CLOVE_NOT_NULL(tail);
    CLOVE_PTR_EQ(second, tail);

    free(first);
    free(second);
}

CLOVE_TEST(PopFromLinkedListWithZeroItem) {
    list_node_t *head = NULL;

    list_node_t *popped = linked_list_pop(&head);
    CLOVE_NULL(popped);
}

CLOVE_TEST(PopFromLinkedListWithOneItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);

    linked_list_append(&head, (list_node_t *)first);

    list_node_t *popped = linked_list_pop(&head);
    CLOVE_NOT_NULL(popped);
    CLOVE_PTR_EQ(first, popped);
    CLOVE_NULL(popped->next);
    CLOVE_NULL(head);

    free(first);
}

CLOVE_TEST(PopFromLinkedListWithTwoItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);
    test_item_t *second = new_test_item(2);

    linked_list_append(&head, (list_node_t *)first);
    linked_list_append(&head, (list_node_t *)second);

    list_node_t *popped = linked_list_pop(&head);
    CLOVE_NOT_NULL(popped);
    CLOVE_PTR_EQ(first, popped);
    CLOVE_NULL(popped->next);
    CLOVE_PTR_EQ(second, head);

    free(first);
    free(second);
}

CLOVE_TEST(RemoveFromLinkedListWithZeroItem) {
    list_node_t *head = NULL;

    list_node_t *removed = linked_list_remove(&head, (list_node_t *)new_test_item(0), sizeof(int));
    CLOVE_NULL(removed);
}

CLOVE_TEST(RemoveItemFromLinkedListWithOneItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);

    linked_list_append(&head, (list_node_t *)first);

    list_node_t *removed = linked_list_remove(&head, (list_node_t *)first, sizeof(int));
    CLOVE_NOT_NULL(removed);
    CLOVE_PTR_EQ(first, removed);
    CLOVE_NULL(removed->next);
    CLOVE_NULL(head);

    free(first);
}

CLOVE_TEST(RemoveNewItemFromLinkedListWithOneItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);

    linked_list_append(&head, (list_node_t *)first);

    list_node_t *removed = linked_list_remove(&head, (list_node_t *)new_test_item(1), sizeof(int));
    CLOVE_NOT_NULL(removed);
    CLOVE_PTR_EQ(first, removed);
    CLOVE_NULL(removed->next);
    CLOVE_NULL(head);

    free(first);
}

CLOVE_TEST(RemoveItemFromLinkedListWithTwoItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);
    test_item_t *second = new_test_item(2);

    linked_list_append(&head, (list_node_t *)first);
    linked_list_append(&head, (list_node_t *)second);

    list_node_t *removed = linked_list_remove(&head, (list_node_t *)second, sizeof(int));
    CLOVE_NOT_NULL(removed);
    CLOVE_PTR_EQ(second, removed);
    CLOVE_NULL(removed->next);
    CLOVE_PTR_EQ(first, head);
    CLOVE_NULL(head->next);

    free(first);
}

CLOVE_TEST(RemoveNewItemFromLinkedListWithTwoItem) {
    list_node_t *head = NULL;
    test_item_t *first = new_test_item(1);
    test_item_t *second = new_test_item(2);

    linked_list_append(&head, (list_node_t *)first);
    linked_list_append(&head, (list_node_t *)second);

    list_node_t *removed = linked_list_remove(&head, (list_node_t *)new_test_item(2), sizeof(int));
    CLOVE_NOT_NULL(removed);
    CLOVE_PTR_EQ(second, removed);
    CLOVE_NULL(removed->next);
    CLOVE_PTR_EQ(first, head);
    CLOVE_NULL(head->next);

    free(first);
}