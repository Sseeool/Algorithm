#include <stdio.h>
#include <math.h>

int main()
{
    int n, arr[246913] = {0, };

    arr[0] = 1, arr[1] = 1;

    for (int i = 2; i < sqrt(246913); i++)
    {
        if (arr[i] == 1) continue;
        for (int j = i * i; j < 246913; j += i)
        {
            arr[j] = 1;
        }
    }

    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (arr[i] == 0) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}