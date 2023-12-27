#include <stdlib.h>
#include <stdio.h>

int check_duplicate(int *arr, int row)
{
    int i = 0;

    while (i < row)
    {
        if (arr[i] == arr[row])
            return 0;
        if (row - i == arr[row] - arr[i])
            return 0;
        if (row - i == -arr[row] + arr[i])
            return 0;
        i++;
    }
    return 1;
}

void recursive_nqueen(int row, int column, int n, int *arr, int *cnt)
{
    if (row == n)
    {
        (*cnt)++;
        return ;
    }
    while (column < n)
    {
        arr[row] = column;
        if (check_duplicate(arr, row) == 1)
        {
            recursive_nqueen(row + 1, 0, n, arr, cnt);
        }
        column++;
    }
}

int main()
{
    int cnt = 0, *arr, n;

    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    recursive_nqueen(0, 0, n, arr, &cnt);
    printf("%d", cnt);
    free(arr);
}