#include <stdio.h>

int recursive_fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d", recursive_fibonacci(n));
    return 0;
}