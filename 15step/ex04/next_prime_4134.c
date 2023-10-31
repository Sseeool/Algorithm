#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(long long a)
{
    long long i = 2;

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
    int n, j;
    long long *arr;

    scanf("%d", &n);
    arr = (long long *)calloc(n, sizeof(long long));

    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    for (int i = 0; i < n; i++)
    {
        j = 0;
        while (1)
        {
            if (arr[i] <= 2)
            {
                printf("2\n");
                break;
            }
            else if (is_prime(arr[i] + j) == 1)
            {
                printf("%lld\n", arr[i] + j);
                break;
            }
            else
                j++;
        }
    }

    free(arr);
    return 0;
}