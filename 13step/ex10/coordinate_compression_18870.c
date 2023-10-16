#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int cnt;
} Arr;


int compare(const void *pa, const void *pb)
{
    const Arr *p1 = pa;
    const Arr *p2 = pb;

    return p1->num - p2->num;
}

int Bsearch(Arr arr[], int size, int target)
{
    int low = 0;
    int high = size -1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid].num < target)
            low = mid + 1;
        else if (arr[mid].num > target)
            high = mid - 1;
        else return mid;
    }
    return -1;
}

int main()
{
    int n, *a, cnt = 0;

    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    Arr *b = (Arr *)malloc(sizeof(Arr) * n);
    for (int i = 0; i< n; i++)
    {
        scanf("%d", &a[i]);
        b[i].num = a[i];
    }

    qsort(b, n, sizeof(Arr), compare);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && b[i].num != b[i - 1].num)
        {
            cnt++;
        }
        b[i].cnt = cnt;
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = Bsearch(b, n + 1, a[i]);
        printf("%d ", b[tmp].cnt);
    }

    free(a);
    free(b);
    return 0;
}