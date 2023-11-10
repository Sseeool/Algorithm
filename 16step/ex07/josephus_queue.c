/*#include <stdio.h>
#include <stdlib.h>

#define SIZE 1001

typedef struct Queue {
    int queue[SIZE];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = 0;
}

int is_full(Queue *q)
{
    return ((q->rear + 1) % SIZE == q->front);
}

int is_empty(Queue *q)
{
    return (q->front == q->rear);
}

void push(Queue *q, int value)
{
    if (is_full(q)) return;
    q->rear = (q->rear + 1) % SIZE;
    q->queue[q->rear] = value;
}

int pop(Queue *q)
{
    if (is_empty(q)) return -1;
    q->front = (q->front + 1) % SIZE;
    return q->queue[q->front];
}

int size(Queue *q)
{
    if (q->front < q->rear) return q->rear - q->front;
    return SIZE - q->front + q->rear;
}

int main()
{
    Queue q;
    init(&q);

    int n, k, tmp;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++)
        push(&q, i + 1);
    printf("<");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            tmp = pop(&q);
            printf("tmp = pop(&q) = %d\n", tmp);
            push(&q, tmp);
            printf("push(&q, %d) ---> q->queue[%d] = %d\n", tmp, q.rear, q.queue[q.rear]);
        }
        if (size(&q) == 1) break;
        tmp = pop(&q);
        printf("%d, ", tmp);
    }
    printf("----------size = %d\n--------", size(&q));
    printf("%d>", pop(&q));

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1001

typedef struct Queue {
    int queue[SIZE];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = 0;
}

int is_full(Queue *q)
{
    return ((q->rear + 1) % SIZE == q->front);
}

int is_empty(Queue *q)
{
    return (q->front == q->rear);
}

void push(Queue *q, int value)
{
    if (is_full(q)) return;
    q->rear = (q->rear + 1) % SIZE;
    q->queue[q->rear] = value;
}

int pop(Queue *q)
{
    if (is_empty(q)) return -1;
    q->front = (q->front + 1) % SIZE;
    return q->queue[q->front];
}

int size(Queue *q)
{
    if (q->front < q->rear) return q->rear - q->front;
    return SIZE - q->front + q->rear;
}

int main()
{
    Queue q;
    init(&q);

    int n, k, tmp;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++)
        push(&q, i + 1);
    printf("<");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            tmp = pop(&q);
            push(&q, tmp);
        }
        if (size(&q) == 1) break;
        tmp = pop(&q);
        printf("%d, ", tmp);
    }
    printf("%d>", pop(&q));

    return 0;
}