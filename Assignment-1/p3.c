#include <stdio.h>
#include <stdlib.h>

int *get_array(char *, int *);
void display_arr(int *, int);
int insert_at_n(int *, int *, int, int);

int main(void)
{
    printf("\n------ INSERT OPERATION IN ARRAY ------\n");
    printf("---------------------------------------\n");

    int n;
    int *arr = get_array(" Array: ", &n);

    int shift, value;
    printf(" Insert at Index: ");
    scanf("%d", &shift);
    printf(" Insert Value: ");
    scanf("%d", &value);

    shift = insert_at_n(arr, &n, shift, value);
    if (shift < 0)
        printf(" Index larger than than the array size.\n\n");
    else {
        display_arr(arr, n);
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

int insert_at_n(int *arr, int *n, int idx, int val)
{
    if (idx >= *n) return -1;
    
    *n = *n + 1;
    if (idx < 0) idx = *n + idx;
    
    int shift = 0;
    arr = realloc(arr, *n * sizeof(int));
    for (int i = *n - 1; i > idx; --i, ++shift)
        arr[i] = arr[i - 1];
    arr[idx] = val;
    return shift;
}