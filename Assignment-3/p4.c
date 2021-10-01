#include <stdio.h>
#include <stdlib.h>

int *enqueue(int *, int*);
int *dequeue(int *, int*);
void display(int *, int);

int main(void)
{
    printf("\n---------- QUEUE USING ARRAY ----------\n");
    printf("---------------------------------------\n");

    printf(" Choose any of the following operations:\n");
    printf("  <1> To PUSH element inside stack.\n");
    printf("  <2> To POP element from the stack.\n");
    printf("  <3> To DISPLAY all the elements inside stack.\n");
    printf("  <0> To EXIT.\n\n");
    
    int *queue = NULL;
    int top = -1;

    int choice;
    printf(" Choice: ");
    while ( (scanf("%d", &choice)) && choice != 0 ) {
        switch (choice) {
            case 1:
            {
                int element;
                printf(" Enter the element to be pushed: ");
                scanf("%d", &element);
                queue = push(queue, &top, element);
                break;
            }

            case 2:
            {
                int popped;
                queue = pop(queue, &top);
                break;
            }

            case 3:
                display(queue, top);
                break;

            default:
                printf(" Invalid choice.\n");
                break;
        }
        printf("\n Choice: ");
    }
    
    free(queue);
    return 0;

    return 0;
}