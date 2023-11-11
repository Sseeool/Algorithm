#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct Deque {
    element data[MAX];
    int front, rear;
} Deque;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

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
    return (d->rear) + 1 % MAX == d->front;
}

void add_rear(Deque *d, element item)
{
    if (is_full(d)) error("Deque is full\n");
    d->rear = (d->rear + 1) % MAX;
    d->data[d->rear] = item;
}

element delete_front(Deque *d)
{
    if (is_empty(d)) error("Deque is empty\n");
    d->front = (d->front + 1) % MAX;
    return d->data[d->front];
}

void add_front(Deque *d, element item)
{
    if (is_full(d)) error("Deque is full\n");
    d->data[d->front] = item;
    d->front = (d->front - 1 + MAX) % MAX; // 원형 큐처럼 한바퀴 돌아야하므로 + MAX 를 해준다
}

element delete_rear(Deque *d)
{
    int prev = d->rear;
    if (is_empty(d)) error("Deque is empty\n");
    d->rear = (d->rear - 1 + MAX) % MAX;

    return d->data[prev];
}

element get_rear(Deque *d)
{
    if (is_empty(d)) error("Deque is empty\n");
    return d->data[d->rear];
}

element get_front(Deque *d)
{
    if (is_empty(d)) error("Deque is empty\n");
    return d->data[(d->front + 1) % MAX];
}

int main()
{
    Deque d;
    init(&d);

    for (int i = 0; i < 3; i++)
        add_front(&d, i);
    
    printf("get_front(&d) = %d\n", get_front(&d));
    printf("get_rear(&d) = %d\n", get_rear(&d));

    for (int i = 0; i < 3; i++)
        printf("delete_rear(&d) = %d\n", delete_rear(&d));

    return 0;
}