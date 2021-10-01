#include <stdio.h>
#include <stdlib.h>

int *push(int *, int *, int);
int *pop(int *, int *);
void display(int *, int);

int main(void)
{
    printf("\n---------- STACK USING ARRAY ----------\n");
    printf("--------------------------------------\n");

    int *stack = NULL;
    int top = -1;

    printf(" Choose any of the following operations:\n");
    printf("  <1> To PUSH element inside stack.\n");
    printf("  <2> To POP element from the stack.\n");
    printf("  <3> To DISPLAY all the elements inside stack.\n");
    printf("  <0> To EXIT.\n\n");
    
    int choice;
    printf(" Choice: ");
    while ( (scanf("%d", &choice)) && choice != 0 ) {
        switch (choice) {
            case 1:
            {
                int element;
                printf(" Enter the element to be pushed: ");
                scanf("%d", &element);
                stack = push(stack, &top, element);
                break;
            }

            case 2:
            {
                int popped;
                stack = pop(stack, &top);
                break;
            }

            case 3:
                display(stack, top);
                break;

            default:
                printf(" Invalid choice.\n");
                break;
        }
        printf("\n Choice: ");
    }
    
    free(stack);
    return 0;
}

int *push(int *stack, int *top, int element) {
    if ( stack == NULL ) *top = 0;

    int *my_stack = realloc(stack, ( (*top) + 1 ) * sizeof(int));
    if ( my_stack == NULL ) {
        printf("\n !!! STACK OVERFLOW !!!\n");
        return stack;
    }
    my_stack[(*top)++] = element;
    return my_stack;
}

int *pop(int *stack, int *top) {
    if ( stack == NULL ) {
        printf("\n !!! STACK UNDERFLOW !!!\n");
        return stack;
    }

    printf("\n Popped element: %d\n", stack[--(*top)]);
    stack = realloc(stack, (*top) * sizeof(int));
    return stack;
}

void display(int *stack, int top) {
    printf("\n Stack Content:");
    for ( int i = top - 1; i >= 0; i-- )
        printf(" %d,", stack[i]);
}