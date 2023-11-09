#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    int *arr;
    int first;
    int top;
} Queue;

void init(Queue *q, int n)
{
    q->arr = (int *)calloc(n, sizeof(int));
    q->first = 0;
    q->top = -1;
}

int size(Queue *q)
{
    if (q->first > q->top) return 0;
    return (q->top) - (q->first) + 1;
}

int empty(Queue *q)
{
    if (size(q) == 0) return 1;
    return 0;
}

void enqueue(Queue *q, int value)
{
    q->arr[++(q->top)] = value;
}

int dequeue(Queue *q)
{
    if (empty(q) == 1) return -1;
    return q->arr[(q->first)++];
}

int front(Queue *q)
{
    if (empty(q) == 1) return -1;
    return q->arr[q->first];
}

int back(Queue *q)
{
    if (empty(q) == 1) return -1;
    return q->arr[q->top];
}

int main()
{
    int n, value;
    char command[6];
    Queue q;

    scanf("%d", &n);
    init(&q, n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%s", command);
        if (strcmp(command, "push") == 0)
        {
            scanf("%d", &value);
            enqueue(&q, value);
        }
        else if (strcmp(command, "pop") == 0)
            printf("%d\n", dequeue(&q));
        else if (strcmp(command, "size") == 0)
            printf("%d\n", size(&q));
        else if (strcmp(command, "empty") == 0)
            printf("%d\n", empty(&q));
        else if (strcmp(command, "front") == 0)
            printf("%d\n", front(&q));
        else if (strcmp(command, "back") == 0)
            printf("%d\n", back(&q));
    }
    free(q.arr);
    return 0;
}