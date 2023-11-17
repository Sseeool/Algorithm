#include <stdio.h>

long long recursive_factorial(int nb)
{
    long long rslt;

    rslt = 1;
    if (nb == 0)
        return 1;
    else
        rslt = nb * recursive_factorial(nb - 1);
    return rslt;
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%lld", recursive_factorial(n));
    return 0;
}