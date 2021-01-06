#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    void *element;
    struct node_t *next;
} node_t;

typedef struct Stack_t {
    node_t *top;
    int size;
} Stack_t;

Stack_t *create_stack();

void push(Stack_t *stack, void *e);

void *pop(Stack_t *stack);

void *top(Stack_t *stack);

int size(Stack_t *stack);

bool is_empty(Stack_t *stack);

void destroy_stack();