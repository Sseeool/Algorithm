#include <stdio.h>
#include <string.h>

int main()
{
    int a = 0, b = 0, n;
    char parenthesis[51];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a = 0;
        b = 0;
        scanf("%s", parenthesis);
        for (int j = 0; j < strlen(parenthesis); j++)
        {
            if (parenthesis[j] == '(') a++;
            else if (parenthesis[j] == ')') b++;
            if (b > a) break;
        }
        if (b > a) printf("NO\n");
        else if (a == b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}