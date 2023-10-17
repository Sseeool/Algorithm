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
        
        if (a[mid] < key)
            low = mid + 1;
        else if (a[mid] > key)
            high = mid -1;
        else
            return 1;
    }
    return 0;
}

int main()
{
    int n1, n2, *a, *b;

    scanf("%d", &n1);
    a = (int *)malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    qsort(a, n1, sizeof(int), compare);

    scanf("%d", &n2);
    b = (int *)malloc(sizeof(int) * n2);
    for (int i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    for (int i = 0; i < n2; i++)
        printf("%d ", Bsearch(a, n1, b[i]));

    free(a);
    free(b);

    return 0;
}