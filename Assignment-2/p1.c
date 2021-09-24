#include <stdio.h>
#include <stdlib.h>

int *get_array(char *, int *);
void display_array(int *, int);
int cmp_func(const void *, const void *);
int binary_search(int *, int, int, int, int *);

int main(void)
{
    printf("\n---------- BINARY SEARCH ----------\n");
    printf("-----------------------------------\n");

    int len;
    int *arr = get_array(" Array: ", &len);
    
    int key;
    printf(" Enter the key: ");
    scanf("%d", &key);

    qsort(arr, len, sizeof(int), cmp_func);
    printf("\n Sorted Array:\n");
    display_array(arr, len);

    int comparisons = 0;
    int i = binary_search(arr, 0, len - 1, key, &comparisons);

    printf("\n Number of comparisons: %d", comparisons);

    if (i == -1)
        printf("\n Could not find the element in the array.\n\n");
    else
        printf("\n Found %d at index %d.\n\n", key, i);

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

int cmp_func(const void *a, const void *b)
{
    return ( *(int *)a - *(int *)b );
}

void display_array(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf(" %d%s", arr[i], i + 1 == len ? "\n" : ",");
}

int binary_search(int *arr, int low, int high, int key, int *comp)
{
    if (low > high) return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == key) return mid;
    
    *comp = *comp + 1;
    if (arr[mid] > key) 
        return binary_search(arr, low, mid - 1, key, comp);
    else
        return binary_search(arr, mid + 1, high, key, comp);
}