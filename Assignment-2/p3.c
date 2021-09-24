#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *get_array(char *, int *);
void display_array(int *, int);
void bubble_sort(int *, int);

int main(void)
{
    printf("\n---------- MODIFIED BUBBLE SORT ----------\n");
    printf("------------------------------------------\n");

    int len;
    int *arr = get_array(" Array: ", &len);

    bubble_sort(arr, len);
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

void bubble_sort(int *arr, int len)
{
    printf("\n Sorting...\n");
    for (int i = 0, count = 1; i < len; i++) {
        bool swapped = false;
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                printf(" %d) ", count);
                display_array(arr, len);
                count++;
            }
        }
        if (!swapped) break;
    }
}