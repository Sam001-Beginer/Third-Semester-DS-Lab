#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *get_array(char *, int *);
void display_array(int *, int);
void selection_sort(int *, int);

int main(void)
{
    printf("\n---------- SELECTION SORT ----------\n");
    printf("------------------------------------\n");

    int len;
    int *arr = get_array(" Array: ", &len);

    selection_sort(arr, len);
    printf("\n Final Array:");
    display_array(arr, len);
    printf("\n");

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

void display_array(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf(" %d%s", arr[i], i + 1 == len ? "\n" : ",");
}

void selection_sort(int *arr, int len)
{
    printf("\n Sorting...\n");
    for (int i = 0, count = 1; i < len; i++) {
        int min_idx = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            printf(" %d) ", count);
            display_array(arr, len);
            count++;
        }
    }
}