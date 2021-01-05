#include "main.h"

/**
 * Initialise the stack and all its fields. Return a pointer to it
 */
stack_t *create_stack() {
    stack_t *stack = malloc(sizeof(stack_t));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

/**
 * Inserts element e
 */
void push(stack_t *stack, void *e) {
    if (stack == NULL) {
        printf("Stack is NULL\n");
        return NULL;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->element = e;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

/**
 * Removes and returns the last inserted element
 */
void *pop(stack_t *stack) {
    if (stack == NULL) {
        printf("Stack is NULL\n");
        return NULL;
    }
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    node_t *rem_node = stack->top;
    void *rem_elem = rem_node->element;
    stack->top = rem_node->next;
    stack->size--;
    free(rem_node);
    return rem_elem;
}

/**
 * Returns the last inserted element without removing it
 */
void *top(stack_t *stack) {
    if (stack == NULL) {
        printf("Stack is NULL\n");
        return NULL;
    }
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return stack->top->element;
}

/**
 * Returns the number of elements stored
 */
int size(stack_t *stack) {
    if (stack == NULL) {
        printf("Stack is NULL\n");
        return 0;
    }
    return stack->size;
}

/**
 * Returns whether elements are stored or not
 */
bool is_empty(stack_t *stack) {
    if (stack == NULL) {
        printf("Stack is NULL\n");
        return true;
    }
}

/**
 * Free all memory associated with the stack
 */
void destroy_stack(stack_t *stack) {
    if (stack == NULL) {
        printf("Stack is NULL\n");
        return;
    }
    while (!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
}