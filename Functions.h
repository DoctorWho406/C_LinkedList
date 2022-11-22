#include <stddef.h>
#include "Item.h"

struct list_node *list_get_tail(struct list_node **head);

struct list_node *list_append(struct list_node **head, struct list_node *item);

struct list_node *list_pop(struct list_node **head);

struct string_item *string_item_new(const char *string);