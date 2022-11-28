typedef struct list_node{
    struct list_node *next;
} list_node_t;

typedef struct string_item {
    struct list_node node;
    const char *string;
} string_item_t;