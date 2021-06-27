#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "main.h"

/**
 * This helper method prints each element in the stack.
 * Note it assumes that elements stored are of type int*
 */
void print_stack(Stack_t *stack) {
    printf("\n");

    node_t *current_node = stack->top;
    while (current_node != NULL) {
        int *address = (int*) current_node->element;
        printf("%d - ", *address);
        current_node = current_node->next;
    }

    printf("\n\n");
}

/**
 * Helper function to heap allocate an integer, push the integer to the stack 
 * and return a pointer to the integer
 */
int *create_push_element(Stack_t *stack, int e) {
    int *p = malloc(sizeof(int));
    *p = e;
    push(stack, p);
    return p;
}

void test_all_functions_regular_cases() {
    Stack_t *stack = create_stack();
    assert(top(stack) == NULL);
    assert(size(stack) == 0);
    assert(is_empty(stack) == true);
    print_stack(stack); // Prints nothing
    
    // Insert 2
    int *a = create_push_element(stack, 2);
    assert(*(int*) top(stack) == 2);
    assert(size(stack) == 1);
    assert(is_empty(stack) == false);
    print_stack(stack); // 2 - 

    // Insert 5
    int *b = create_push_element(stack, 5);
    assert(*(int*) top(stack) == 5);
    assert(size(stack) == 2);
    assert(is_empty(stack) == false);
    print_stack(stack); // 5 - 2 - 

     // Insert 3
    int *c = create_push_element(stack, 3);
    assert(*(int*) top(stack) == 3);
    assert(size(stack) == 3);
    assert(is_empty(stack) == false);
    print_stack(stack); // 3 - 5 - 2 - 

    // Remove 3
    int *rem_elem = (int*) pop(stack);
    assert(*rem_elem == 3);
    assert(*(int*) top(stack) == 5);
    assert(size(stack) == 2);
    assert(is_empty(stack) == false);
    print_stack(stack); // 5 - 2 - 

    // Remove 5
    rem_elem = (int*) pop(stack);
    assert(*rem_elem == 5);
    assert(*(int*) top(stack) == 2);
    assert(size(stack) == 1);
    assert(is_empty(stack) == false);
    print_stack(stack); // 2 - 

    // Remove 2
    rem_elem = (int*) pop(stack);
    assert(*rem_elem == 2);
    assert(top(stack) == NULL);
    assert(size(stack) == 0);
    assert(is_empty(stack) == true);
    print_stack(stack); // Nothing prints

    // Try to pop from empty stack
    assert(pop(stack) == NULL);

    // Add back in to ensure destroy_stack frees all nodes and the stack itself
    push(stack, a);
    assert(*(int*) top(stack) == 2);
    assert(size(stack) == 1);
    assert(is_empty(stack) == false);
    print_stack(stack); // 2 - 

    free(a);
    free(b);
    free(c);
    destroy_stack(stack);
}

int main() {

    test_all_functions_regular_cases();

}