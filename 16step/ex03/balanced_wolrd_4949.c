#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 101

int main()
{
    while (1)
    {
        char str[MAX], check[MAX];
        int i = 0;
        int top = -1;

        gets(str);
        if (strcmp(str, ".") == 0)
            break;
        while(str[i])
        {
            if (str[i] == '(' || str[i] == '[')
            {
                check[++top] = str[i];
            }
            else if (str[i] == ')')
            {
                if (top != -1 && check[top] == '(') top--;
                else
                {
                    top = -2;
                    break;
                }
            }
            else if (str[i] == ']')
            {
                if (top != -1 && check[top] == '[') top--;
                else
                {
                    top = -2;
                    break;
                }
            }              
            i++;
        }
        puts(top == -1 ? "yes" : "no");
    }
}