#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sorted[500000];

void merge(int a[], int m, int middle, int n)
{
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i <= middle && j <= n)
    {
        if (a[i] < a[j])
        {
            sorted[k] = a[i];
            i++;
        }
        else
        {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > middle)
    {
        for (int t = j; t <= n; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }
    else
    {
        for (int t = i; t <= middle; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }
    for (int t = m; t <= n; t++)
    {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int m, int n)
{
    if (m < n)
    {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}

int main()
{
    int n, *arr, frequency[8001] = {0, }, max = 0, max_n, count = 0;
    double sum = 0;

    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += (double)arr[i];
        frequency[arr[i] + 4000] += 1;
        if (frequency[arr[i] + 4000] >= max)
        {
            max = frequency[arr[i] + 4000];
        }
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (frequency[arr[i] + 4000] == max && max_n != arr[i])
        {
            max_n = arr[i];
            count++;
        }
        if (count == 2)
        {
            break;
        }
    }
    printf("%d\n", (int)round(sum / n));
    printf("%d\n", arr[n / 2]);
    printf("%d\n", max_n);
    printf("%d", arr[n - 1] - arr[0]);
    free(arr);
}