#include <stdio.h>

long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main()
{
    long long a, b;

    scanf("%lld %lld", &a, &b);
    printf("%lld", lcm(a, b));
}