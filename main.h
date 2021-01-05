#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    void *element;
    struct node_t *next;
} node_t;

typedef struct stack_t {
    node_t *top;
    int size;
} stack_t;

stack_t *create_stack();

void push(stack_t *stack, void *e);

void *pop(stack_t *stack);

void *top(stack_t *stack);

int size(stack_t *stack);

bool is_empty(stack_t *stack);

void destroy_stack();