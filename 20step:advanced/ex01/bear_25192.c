#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21
#define ENTRY_SIGNAL "ENTER"

int compare(const void *s1, const void *s2)
{
    return strcmp((char *)s1, (char *)s2);
}

int main()
{
    char names[100001][21];
    char temp[MAX];
    int n, len, count = 0, j = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        if (strcmp(temp, ENTRY_SIGNAL) != 0)
        {
            strcpy(names[j], temp);
            j++;
        }
        if ((i != 0 && strcmp(temp, ENTRY_SIGNAL) == 0) || i == n - 1)
        {
            qsort(names, j, 21, compare);
            for (int k = 0; k < j; k++)
            {
                if ((k == 0 || strcmp(names[k], names[k - 1]) != 0))
				{
					count++;
				}
            }
            j = 0;
        }
    }
    printf("%d", count);

    return 0;
}
