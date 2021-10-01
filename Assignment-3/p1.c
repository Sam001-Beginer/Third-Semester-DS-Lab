#include <stdio.h>
#include <stdlib.h>

int *get_array(char *, int *);
void display_common_el(int *, int, int *, int);

int main(void)
{
    printf("\n---------- COMMON ELEMENTS ----------\n");
    printf("-------------------------------------\n");

    int len_1, len_2;
    int *arr_1 = get_array(" Array-1: ", &len_1);
    int *arr_2 = get_array(" Array-2: ", &len_2);

    display_common_el(arr_1, len_1, arr_2, len_2);

    free(arr_1);
    free(arr_2);
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

void display_common_el(int *arr_1, int len_1, int *arr_2, int len_2)
{
    printf("\n Common Elements: ");
    for (int i = 0; i < len_1; i++) {
        for (int j = 0; j < len_2; j++) {
            if (arr_1[i] == arr_2[j]) {
                printf(" %d,", arr_1[i]);
                break;
            }
        }
    }
    printf("\n\n");
}