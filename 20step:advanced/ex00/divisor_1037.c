#include <stdio.h>

int main()
{
    int t, n, min = 1000000, max = 2;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        if (n < min) min = n;
        if (n > max) max = n;
    }
    printf("%d", min * max);
    return 0;
}