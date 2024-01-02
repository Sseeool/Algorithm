#include <stdio.h>

int recursive_factorial(int n)
{
    if (n == 0)
        return 1;
    else
        n *= recursive_factorial(n - 1);
    return n;
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d", recursive_factorial(n));
    return 0;
}