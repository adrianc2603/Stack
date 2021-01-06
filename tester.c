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
    
    int *a = malloc(sizeof(int));
    *a = 2;
    push(stack, a);
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 2
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 1
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 2 - 

    int *b = malloc(sizeof(int));
    *b = 5;
    push(stack, b);
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 5
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 2
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 5 - 2 - 

    int *c = malloc(sizeof(int));
    *c = 3;
    push(stack, c);
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 3
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 3
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 3 - 5 - 2 - 

    int *rem_elem = (int*) pop(stack);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 3
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 5
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 2
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 5 - 2 - 

    rem_elem = (int*) pop(stack);
    printf("The removed element is %d\n", *rem_elem); // The removed element is 5
    printf("The element at the top of the stack is %d\n", *(int*) top(stack)); // The element at the top of the stack is 2
    printf("The size of the stack is %d\n", size(stack)); // The size of the stack is 1
    printf("Is the stack empty? %d\n", is_empty(stack)); // Is the stack empty? 0 (False);
    print_stack(stack); // 5 - 2 - 

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

    if (pop(stack) == NULL) {
        printf("Pop is NULL because the stack is empty\n"); // This should print
    }
    else {
        printf("Pop should be NULL, but it isn't");
    }

    free(a);
    free(b);
    free(c);
    destroy_stack(stack);
}

int main() {

    test_all_functions_regular_cases();

}