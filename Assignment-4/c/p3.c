#include <stdio.h>

int main(void)
{
    printf("\n---------- EQUAL PARANTHESIS ----------\n");
    printf("---------------------------------------\n");

    int c;
    printf("Expression: ");
    int first = 0, second = 0, third = 0;
    while ((c = getchar()) != '\n' && c != '\0' && c != EOF) {
        if (c == '(') first++;
        else if (c == '{') second++;
        else if (c == '[') third++;
        else if (c == ')' && first) first--;
        else if (c == '}' && second) second--;
        else if (c == ']' && third) third--;
    }

    printf("%s Parenthesis\n", first || second || third ? "Unequal" : "Equal");
    return 0;
}