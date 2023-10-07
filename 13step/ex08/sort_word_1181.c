#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *first, const void *second)
{
    if (strlen((const char *)first) > strlen((const char *)second))
        return 1;
    else if (strlen((const char *)first) < strlen((const char *)second))
        return -1;
    else
        return strcmp((const char *)first, (const char *)second);
}

int main()
{
    int n;
    char arr[20001][51];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);
    
    qsort(arr, n, 51, compare);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], arr[i + 1]) != 0 || i == n - 1)
            printf("%s\n", arr[i]);
    }

    return 0;
}