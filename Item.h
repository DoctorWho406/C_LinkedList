struct list_node{
    struct list_node *next;
};

struct string_item {
    struct list_node node;
    const char *string;
};