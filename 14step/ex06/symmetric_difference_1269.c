#include <stdio.h>
#include <stdlib.h>

int compare (const void *p1, const void *p2)
{
    const int *pa = p1;
    const int *pb = p2;
    return *pa - *pb;
}

int main()
{
    int n, m, *num, cnt = 0;

    scanf("%d %d", &n, &m);
    num = (int *)malloc(sizeof(int)* (n + m));
    for (int i = 0; i < n + m; i++)
        scanf("%d", &num[i]);
    qsort(num, n + m, sizeof(int), compare);

    for (int i = 0; i < n + m; i++)
    {
        if (i == 0)
        {
            if (num[i] != num[i + 1])
                cnt++;
        }
        else if (i < n + m - 1)
        {
            if (num[i - 1] != num[i] && num[i] != num[i + 1])
                cnt++;
        }
        else if (num[n + m - 2] != num[n + m - 1])
            cnt++;
    }

    printf("%d", cnt);
    free(num);
    return 0;
}