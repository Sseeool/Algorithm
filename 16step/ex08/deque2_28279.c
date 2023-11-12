#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

typedef struct Deque {
    int data[MAX];
    int front, rear;
} Deque;

void init(Deque *d)
{
    d->front = d->rear = 0;
}

int is_empty(Deque *d)
{
    return (d->front == d->rear);
}

int is_full(Deque *d)
{
    return ((d->rear + 1) % MAX) == d->front;
}

void add_front(Deque *d, int value)
{
    if (is_full(d)) return;
    d->data[d->front] = value;
    d->front = (d->front + MAX - 1) % MAX;
}

void add_rear(Deque *d, int value)
{
    if (is_full(d)) return;
    d->rear = (d->rear + 1) % MAX;
    d->data[d->rear] = value;
}

int pop_front(Deque *d)
{
    if (is_empty(d)) return -1;
    d->front = (d->front + 1) % MAX;
    return d->data[d->front];
}

int pop_rear(Deque *d)
{
    if (is_empty(d)) return -1;
    int prev = d->rear;
    d->rear = (d->rear - 1 + MAX) % MAX;
    return d->data[prev];
}

int size(Deque *d)
{
	return (d->rear - d->front + MAX) % MAX;
}

int peek_front(Deque *d)
{
    if (is_empty(d)) return -1;
    return d->data[(d->front + 1) % MAX];
}

int peek_rear(Deque *d)
{
    if (is_empty(d)) return -1;
    return d->data[d->rear];
}

int main()
{
    Deque d;
    init(&d);
    int n, cmd, nb;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cmd);
        if (cmd == 1)
        {
            scanf("%d", &nb);
            add_front(&d, nb);
        }
        else if (cmd == 2)
        {
            scanf("%d", &nb);
            add_rear(&d, nb);
        }
        else if (cmd == 3)
            printf("%d\n", pop_front(&d));
        else if (cmd == 4)
            printf("%d\n", pop_rear(&d));
        else if (cmd == 5)
            printf("%d\n", size(&d));
        else if (cmd == 6)
            printf("%d\n", is_empty(&d));
        else if (cmd == 7)
            printf("%d\n", peek_front(&d));
        else if (cmd == 8)
            printf("%d\n", peek_rear(&d));
    }
    return 0;
}