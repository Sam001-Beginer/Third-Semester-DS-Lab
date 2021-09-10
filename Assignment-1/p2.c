#include <stdio.h>
#include <stdlib.h>

int *get_array(char *, int *);
void display_arr(int *, int);
int delete_at_n(int *, int *, int);

int main(void)
{
    printf("\n------ DELETE OPERATION IN ARRAY ------\n");
    printf("---------------------------------------\n");

    int i;
    int *arr = get_array(" Array: ", &i);

    int shift;
    printf(" Del from Index: ");
    scanf("%d", &shift);

    shift = delete_at_n(arr, &i, shift);
    if (shift < 0)
        printf(" Index larger than than the array size.\n\n");
    else {
        display_arr(arr, i);
        printf(" Total Shifts: %d\n\n", shift);
    }
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

void display_arr(int *arr, int n)
{
    printf("\n Array: ");
    for (int i = 0; i < n; ++i)
        printf("%d, ", arr[i]);
    printf("\n");
}

int delete_at_n(int *arr, int *n, int i)
{
    if (i >= *n) return -1;
    if (i < 0) i = *n + i;
    
    int shift = 0;
    for (int j = i; j < *n - 1; ++j, ++shift)
        arr[j] = arr[j + 1];
    *n = *n - 1;
    return shift;
}