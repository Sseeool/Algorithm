#include <stdio.h>

int main()
{
    int n, cnt = 1;

    scanf("%d", &n);
    
    for (int i = 2; i * i < n + 1; i++)
        cnt ++;

    printf("%d", cnt);

    return 0;
}