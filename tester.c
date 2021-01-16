#include <stdio.h>
#include <stdlib.h>
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

    if (top(stack) == NULL) {
        printf("The top of the stack is NULL because the stack is empty\n"); // This should print
    }
    else {
        printf("The top of the stack isn't NULL, but it should be");
    }
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 0
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 1 (True);
    print_stack(stack); // Prints nothing
    
    // Insert 2
    int *a = create_push_element(stack, 2);
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 2
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 1
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 2 - 

    // Insert 5
    int *b = create_push_element(stack, 5);
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 5
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 2
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 5 - 2 - 

     // Insert 3
    int *c = create_push_element(stack, 3);
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 3
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 3
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 3 - 5 - 2 - 

    // Remove 3
    int *rem_elem = (int*) pop(stack);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 3
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 5
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 2
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 5 - 2 - 

    // Remove 5
    rem_elem = (int*) pop(stack);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 5
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 2
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 1
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 2 - 

    // Remove 2
    rem_elem = (int*) pop(stack);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 2
    if (top(stack) == NULL) {
        printf("The top of the stack is NULL because the stack is empty\n"); // This should print
    }
    else {
        printf("The top of the stack isn't NULL, but it should be");
    }
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 0
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 1 (True);
    print_stack(stack); // Nothing prints

    // Try to pop from empty stack
    if (pop(stack) == NULL) {
        printf("Pop is NULL because the stack is empty\n"); // This should print
    }
    else {
        printf("Pop should be NULL, but it isn't");
    }

    // Add back in to ensure destroy_stack frees all nodes and the stack itself
    printf("Adding a back in now\n");
    push(stack, a);
    print_stack(stack); // 2 - 

    free(a);
    free(b);
    free(c);
    destroy_stack(stack);
}

int main() {

    test_all_functions_regular_cases();

}