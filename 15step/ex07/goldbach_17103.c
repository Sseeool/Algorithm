#include <stdio.h>
#include <math.h>

int main()
{
    int n, prime_arr[1000001] = {0, }, nb, cnt;

    prime_arr[0] = 1, prime_arr[1] = 1;
    for (int i = 2; i <= sqrt(1000001); i++)
    {
        if (prime_arr[i] == 1) continue;
        for (int j = i * i; j < 1000001; j += i)
            prime_arr[j] = 1;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nb);
        cnt = 0;
        for (int j = 2; j <= nb / 2; j++)
        {
            if (prime_arr[j] + prime_arr[nb - j] == 0)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}