#include <stdio.h>
#include <math.h>

int main()
{
    int n, *arr, frequency[8001] = {0, }, f_max = 0, f_max_n, count = 0;
    double sum = 0;
    int num, M = -4000, m = 4000;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        sum += (double)num;
        frequency[num + 4000] += 1;
        if (frequency[num + 4000] >= f_max)
        {
            f_max = frequency[num + 4000];
        }
        if (num > M)
        {
            M = num;
        }
        if (num < m)
        {
            m = num;
        }
    }
    for (int i = 0; i < 8001; i++)
    {
        if (frequency[i] == f_max && f_max_n!= frequency[i])
        {
            f_max_n = i - 4000;
            count++;
        }
        if (count == 2)
        {
            break;
        }
    }
    count = 0;
    for (int i = 0; count < n / 2 + 1; i++)
    {
        if (frequency[i] != 0)
        {
            count += frequency[i];
            num = i - 4000;
        }
    }
    printf("%d\n", (int)round(sum / n));
    printf("%d\n", num);
    printf("%d\n", f_max_n);
    printf("%d", M - m);
}