#include <stdio.h>
#include <math.h>

int is_prime(int a)
{
    int i = 2;

    if (a < 2)
        return 0;

    while (i <= sqrt(a))
    {
        if (a % i == 0) return 0;
        else i++;
    }
    return 1;
}

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
        if (is_prime(i) == 1)
            printf("%d\n", i);
    return 0;
}