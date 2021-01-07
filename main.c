#include "main.h"

/**
 * Initialise the stack and all its fields. Return a pointer to it
 * Time Complexity: O(1)
 */
Stack_t *create_stack() {
    Stack_t *stack = malloc(sizeof(Stack_t));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

/**
 * Inserts element e
 * Time Complexity: O(1)
 */
void push(Stack_t *stack, void *e) {
    if (stack == NULL) {
        return;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->element = e;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

/**
 * Removes and returns the last inserted element
 * Time Complexity: O(1)
 */
void *pop(Stack_t *stack) {
    if (stack == NULL) {
        return NULL;
    }
    if (is_empty(stack)) {
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
 * Time Complexity: O(1)
 */
void *top(Stack_t *stack) {
    if (stack == NULL) {
        return NULL;
    }
    if (is_empty(stack)) {
        return NULL;
    }
    return stack->top->element;
}

/**
 * Returns the number of elements stored
 * Time Complexity: O(1)
 */
int size(Stack_t *stack) {
    if (stack == NULL) {
        return 0;
    }
    return stack->size;
}

/**
 * Returns whether elements are stored or not
 * Time Complexity: O(1)
 */
bool is_empty(Stack_t *stack) {
    if (stack == NULL) {
        return true;
    }
    return (stack->size == 0);
}

/**
 * Free all memory associated with the stack
 * Time Complexity: O(n)
 */
void destroy_stack(Stack_t *stack) {
    if (stack == NULL) {
        return;
    }
    while (!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
}