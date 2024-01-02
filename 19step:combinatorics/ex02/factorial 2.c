#include <stdio.h>

int recursive_factorial(int n)
{
    return (n == 0) ? 1 : n * recursive_factorial(n - 1);
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d", recursive_factorial(n));
    return 0;
}