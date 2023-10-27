#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *pa, const void *pb)
{
    return strcmp(*(char**)pa, *(char**)pb);
}

int main()
{
    char a[1001], **word;
    scanf("%s", a);

    int len = strlen(a), k = 0, cnt = 0;
    int size = len * (len + 1) / 2;
    word = (char **)calloc(size + 1, sizeof(char *));

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            word[k] = (char *)calloc(sizeof(char), (i + 2));
            strncpy(word[k], &a[j], i + 1);
            k++;
        }
    }
    qsort(word, size, sizeof(char *), compare);
    for (int i = 0; i < size - 1; i++)
    {
        if (strcmp(word[i], word[i + 1]) == 0)
            cnt ++;
        free(word[i]);
    }
    free(word);
    printf("%d", size - cnt);
    return 0;
}