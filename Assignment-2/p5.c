#include <stdio.h>
#include <stdlib.h>

int *get_array(char *, int *);
void display_array(int *, int);
void insertion_sort(int *, int);

int main(void)
{
    printf("\n---------- INSERTION SORT ----------\n");
    printf("------------------------------------\n");

    int len;
    int *arr = get_array(" Array: ", &len);

    insertion_sort(arr, len);
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

void insertion_sort(int *arr, int len)
{
    printf("\n Sorting...\n");
    for (int i = 1, count = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        if (key > arr[j]) {
            printf(" %d) ", count);
            display_array(arr, len);
            count++;
        }
    }
}