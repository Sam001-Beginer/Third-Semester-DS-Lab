#include <stdio.h>

int main(void)
{
    printf("\n---------- EVEN POSITION CHARS ----------\n");
    printf("-----------------------------------------\n");

    int c;
    printf(" String: ");
    for (int i = 1; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i == 1) printf(" Reduced String: ");
        if (i % 2 == 0) putchar(c);
    }
    printf("\n\n");

    return 0;
}