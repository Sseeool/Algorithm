#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *q, front = 0, rear;

    scanf("%d", &n);
    q = (int *)malloc(sizeof(int)* n);
    for (int i = 0; i < n; i++)
        q[i] = i + 1;
    rear = n - 1;

    while (1)
    {
        front = (front + 1) % n;
        if (front == rear) break;
        rear = (rear + 1) % n;
        q[rear] = q[front];
        front = (front + 1) % n;
        if (front == rear) break;
    }
    printf("%d", q[front]);

    free(q);
    return 0;
}