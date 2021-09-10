#include <stdio.h>
#include <stdlib.h>

int get_sum(int *, int);
int *get_array(char *, int *);

int main(void)
{
    printf("\n------ SUM OF ARRAY ELEMENTS ------\n");
    printf("-----------------------------------\n");

    int i;
    int *arr = get_array(" Array: ", &i);

    printf(" Sum of all the elements: %d\n\n", get_sum(arr, i));
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

int get_sum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += arr[i];
    return sum;
}