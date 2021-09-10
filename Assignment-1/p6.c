#include <stdio.h>
#include <stdlib.h>

int *get_array(char *, int *);
int linear_search(int *, int, int, int *);

int main(void)
{
    printf("\n------ SEARCHING IN ARRAY ------\n");
    printf("--------------------------------\n");

    int n;
    int *arr = get_array(" Array: ", &n);

    int el;
    printf(" Search for: ");
    scanf("%d", &el);

    int idx = 0;
    int comp = linear_search(arr, n, el, &idx);
    if (comp < 0)
        printf("\n Element %d not found.\n\n", el);
    else {
        printf("\n Element %d found at index %d.\n", el, idx);
        printf(" Total comparisons done: %d\n\n", comp);
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

int linear_search(int *arr, int n, int el, int *idx)
{
    int comp = 1;
    for (*idx = 0; *idx < n; ++(*idx), ++comp)
        if (arr[*idx] == el) return comp;
    return -1;
}