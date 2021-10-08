#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int top = -1;
char s[MAX];
void push(char a)
{
      s[top] = a;
      top++;
}
void pop()
{
    if (top == -1)
    {
            printf("expression is invalid\n");
            exit(0);
    }
    else
    top--;
}
void check()
{
	char a[MAX];
	printf("\nEnter expression : ");
    scanf("%s",a);
    for (int i=0;a[i]!='\0';i++)
    {
        if (a[i] == '(')
        push(a[i]);
    	else if (a[i] == ')')
        pop();
    }
    if (top == -1)
    printf("Equal parenthesis");
    else
    printf("Not equal parenthesis");
}
int main ()
{
	int t;
	while(1)
	{
		printf("\n1.Check parenthesis\n2.Exit\nEnter your choice :- ");
		scanf("%d",&t);
		switch(t)
		{
			case 1:
				check();
				break;
			case 2:
				exit(0);
			default:
				printf("Wrong input");
		}
	}

    return 0;
}