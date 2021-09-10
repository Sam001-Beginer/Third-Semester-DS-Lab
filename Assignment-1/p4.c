#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *get_array(char *, int *);
void max_and_secmax(int *, int, int *, int *);

int main(void)
{
    printf("\n------ MAX AND SECOND MAX IN ARRAY ------\n");
    printf("-----------------------------------------\n");

    int n;
    int *arr = get_array(" Array: ", &n);
    
    int max, sec_max;
    max_and_secmax(arr, n, &max, &sec_max);
    
    printf(" Max Element: %d\n Second Max Element: %d\n\n", max, sec_max);
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

void max_and_secmax(int *arr, int n, int *max, int *sec_max)
{
    *max = arr[0];
    *sec_max = (int) -INFINITY;

    for (int i = 1, j = 0; i < n; ++i, ++j) {
        *max = arr[i] > *max ? arr[i] : *max;
        *sec_max = arr[j] >= *sec_max && arr[j] < *max ? arr[j] : *sec_max;
    }
}