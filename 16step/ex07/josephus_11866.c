/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, *arr, index, cnt, j = 1;

    scanf("%d %d", &n, &k);

    arr = (int *)malloc(sizeof(int)* n);
    for (int i = 0; i < n; i ++) arr[i] = i + 1;
    printf("<%d", arr[k - 1]);

    arr[k - 1] = -1;
    index = k - 1;
    //printf("first------->arr[%d] = %d index = %d\n\n", k - 1, arr[k - 1], index);

    for (int i = 0; i < n - 1; i++) // 출력횟수
    {
        cnt = 0;
        while (cnt < 3) // 인덱스 조정
        {
            //printf("-----before change index = %d-----\n", index);
            index = (index + j) % n;
            //printf("change index = %d arr[%d] = %d\n", index, index, arr[index]);
            if (arr[index] != -1) cnt ++;
            //printf("cnt = %d\n", cnt);
            //if (cnt == 3) break;
        }
        //printf("\n\n-------###%d###print---------\n\n", i);
        printf(", %d", arr[index]);
        arr[index] = -1;
        //printf("\n\n");
    }
    printf(">");

    free(arr);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, *arr, index, cnt, j = 1;

    scanf("%d %d", &n, &k);

    arr = (int *)malloc(sizeof(int)* n);
    for (int i = 0; i < n; i ++) arr[i] = i + 1;
    printf("<%d", arr[k - 1]);

    arr[k - 1] = -1;
    index = k - 1;

    for (int i = 0; i < n - 1; i++)
    {
        cnt = 0;
        while (cnt < k)
        {
            index = (index + j) % n;
            if (arr[index] != -1) cnt ++;
        }
        printf(", %d", arr[index]);
        arr[index] = -1;
    }
    printf(">");

    free(arr);
    return 0;
}