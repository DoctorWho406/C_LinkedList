#include <stddef.h>
#include <stdlib.h>
#include "Functions.h"

struct string_item *string_item_new(const char *string) {
    struct string_item *item = malloc(sizeof(struct string_item));
    if (!item) {
        return NULL;
    }
    item->string = string;
    return item;
}