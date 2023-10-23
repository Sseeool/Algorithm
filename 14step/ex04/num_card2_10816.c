#include <stdio.h>
#include <stdlib.h>

int compare (const void *p1, const void *p2)
{
    const int *pa = p1;
    const int *pb = p2;
    return *pa - *pb;
}

int Bsearch(int a[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        key >= a[mid] ? (low = mid + 1) : (high = mid - 1);
    }
    int tmp = low;

    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        key > a[mid] ? (low = mid + 1) : (high = mid - 1);
    }
    return tmp - low;
}

int main()
{
    int n, m, *a, b, rslt = 0;

    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b);
        rslt = Bsearch(a, n, b);
        printf("%d ", rslt);
    }
    return 0;
}