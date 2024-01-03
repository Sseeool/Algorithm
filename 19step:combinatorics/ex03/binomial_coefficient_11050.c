#include <stdio.h>

int main()
{
    int n, m, ans = 1;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        ans *= (n - m + i);
        ans /= i;
    }
    printf("%d", ans);

    return 0;
}