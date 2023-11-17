#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    int cnt;
    int size;
    Node *front;
    Node *rear;
} Deque;

void init(Deque *d, int size)
{
    d->front = d->rear = NULL;
    d->cnt = 0;
    d->size = size + 1;
}

int is_full(Deque *d)
{
    return (d->cnt == d->size);
}

int is_empty(Deque *d)
{
    return (d->cnt == 0);
}

int push_front(Deque *d, int data)
{
    if (is_full(d)) return 0;
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (is_empty(d))
    {
        d->front = newNode;
        d->rear = newNode;
    }
    else
    {
        d->front->prev = newNode;
        newNode->next = d->front; 
        d->front = newNode; 
        d->front->prev = NULL;
    }
    d->cnt ++;
    return 1;
}

int push_rear(Deque *d, int data)
{
    if (is_full(d))
    {
        printf("%d", data);
        return 0;
    }
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (is_empty(d))
    {
        d->front = newNode;
        d->rear = newNode;
    }
    else
    {
        d->rear->next = newNode;
        newNode->prev = d->rear;
        d->rear = newNode;
        d->rear->next = NULL;
    }
    d->cnt++;
    return 1;
}

int pop_front(Deque *d)
{
    int pop;
    if (is_empty(d)) return -1;
    pop = d->front->data;
    d->front = d->front->next;
    d->cnt --;
    return pop;
}

int pop_rear(Deque *d)
{
    int pop;
    if (is_empty(d)) return -1;
    pop = d->rear->data;
    d->rear = d->rear->prev;
    d->cnt--;
    return pop;
}

int main()
{
    int n, tmp, *queuestack;
    Deque d;

    scanf("%d", &n);
    init(&d, n);

    queuestack = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &queuestack[i]);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (!queuestack[i])
            push_front(&d, tmp);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        push_rear(&d, tmp);
        printf("%d ", pop_front(&d));
    }
    return 0;
}