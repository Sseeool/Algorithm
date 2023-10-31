#include <stdio.h>

int gcd(int b, int d)
{
    if (d == 0) return b;
    else return gcd(d, b % d);
}

int lcm(int b, int d)
{
    int k = gcd(b, d);
    return b * d / k;
}

int main()
{
    int a, b, c, d, deno, g, numer;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    deno = lcm(b, d);
    g = gcd(b, d);
    a = a * d / g, c = c * b / g;
    numer = a + c;

    g = gcd(numer, deno);
    numer /= g;
    deno /= g;

    printf("%d %d", numer, deno);

    return 0; 
}