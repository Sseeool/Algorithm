#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int xpos;
    int ypos;
} Point;

Point sorted[100000];

void merge(Point a[], int beg, int middle, int end)
{
    int i = beg;
    int j = middle + 1;
    int k = beg;

    while (i <= middle && j <= end)
    {
        if (a[i].xpos < a[j].xpos)
            sorted[k++] = a[i++];
        else if (a[i].xpos > a[j].xpos)
            sorted[k++] = a[j++];
        else
        {
            if (a[i].ypos < a[j].ypos)
                sorted[k++] = a[i++];
            else
                sorted[k++] = a[j++];
        }
    }
    if (i > middle)
    {
        for (int t = j; t <= end; t++)
        {
            sorted[k++] = a[t];
        }
    }
    else
    {
        for (int t = i; t <= middle; t++)
            sorted[k++] = a[t];
    }

    for (int t = beg; t <= end; t++)
        a[t] = sorted[t];
}

void mergeSort(Point a[], int beg, int end)
{
    if (beg < end)
    {
        int middle = (beg + end) / 2;
        mergeSort(a, beg, middle);
        mergeSort(a, middle + 1, end);
        merge(a, beg, middle, end);
    }
}

int main()
{
    int n;
    Point *a;

    scanf("%d", &n);
    a = (Point*)malloc(sizeof(Point) * n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &(a[i].xpos), &(a[i].ypos));

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d %d\n", a[i].xpos, a[i].ypos);

    free(a);

    return 0;
}