#include <stdio.h>
#include <stdlib.h>

int *get_array(char *, int *);
void display_arr(char *, int *, int);
void custom_swap(int *, int);

int main(void)
{
    printf("\n------ SWAP CONSECUTIVE ELEMENTS IN ARRAY ------\n");
    printf("------------------------------------------------\n");

    int n;
    int *arr = get_array(" Array: ", &n);

    display_arr(" Array Before Swap: ", arr, n);
    custom_swap(arr, n);
    printf("\n");
    
    display_arr(" Array After Swap: ", arr, n);
    printf("\n\n");

    free(arr);
    return 0;
}

int *get_array(char *label, int *i)
{
    printf("%s", label);
    *i = 0;
    int c;
    int *arr = NULL;
    do {
        int temp;
        scanf("%d", &temp);
        arr = realloc( arr, (*i + 1) * sizeof(int) );
        arr[(*i)++] = temp;
        c = getchar();
    } while (c != '\n');
    
    return arr;
}

void display_arr(char *label, int *arr, int n)
{
    printf("%s", label);
    for (int i = 0; i < n; ++i)
        printf("%d, ", arr[i]);
    printf("\n");
}

void custom_swap(int *arr, int n)
{
    for (int i = 0; i < n - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}