#include <stdio.h>

int main()
{
    int n, ans = 1;

    scanf("%d", &n);
    while (n-- > 0)
    {
        ans *= 2;
    }
    printf("%d", ans);
    return 0;
}