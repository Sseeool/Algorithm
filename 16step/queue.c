#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { // 연결리스트
    int data;
    struct Node *next;
} Node;

typedef struct Queue { // 큐
    Node *front;
    Node *rear;
} Queue;

void init(Queue *q) // 큐 초기화
{
    q->front = q->rear = NULL;
}

int empty(Queue *q)
{
    if (q->front == NULL) return 1;
    return 0;
}

void Enqueue(Queue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (empty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode; // q->rear->next 에 newNode 할당
        q->rear = newNode; // q->rear 이 새로운 노드를 가리키도록 함
    }
    newNode->next = q->front; // 원형큐이므로
    printf("#Insert OK\n");
}

int dequeue(Queue *q)
{
    if (empty(q)) return -1;

    int data = q->front->data;

    if (q->front == q->rear) init(q);
    else
    {
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    return data;
}

int peek(Queue *q)
{
    if (empty(q)) return -1;
    return q->front->data;
}

void printQ(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty !\n");
        return;
    }
    Node *cur = q->front;
    printf("#data = %d\n", cur->data);
    cur = cur->next;

    while (cur != q->front)
    {
        printf("#data = %d\n", cur->data);
        cur = cur->next;
    }
    printf("\n\n-------All data is printed-------\n\n");
}

void delete(Queue *q)
{
    if (empty(q)) return;

    if (q->front == q->rear) init(q);    // 큐 초기화
    else 
    {
        q->front = q->front->next;  // front를 다음 노드로 이동
        q->rear->next = q->front;   // 원형 큐이므로 rear가 front를 가리키도록
    }
}

int main()
{
    Queue q;
    init(&q);

    char command[10];
    int data;
    int res;

    while (1)
    {
        printf("\n");
        scanf("%s", command);
        if (!strcmp(command, ".")) break;
        else if (!strcmp(command, "enqueue"))
        {
            printf("#Insert Data : ");
            scanf("%d", &data);
            Enqueue(&q, data);
            continue;
        }
        else if (!strcmp(command, "dequeue")) res = dequeue(&q);
        else if (!strcmp(command, "delete"))
        {
            delete(&q);
            continue;
        }
        else if (!strcmp(command, "peek")) res = peek(&q);
        else if (!strcmp(command, "empty")) res = empty(&q);
        else
        {
            printf("###Error####\n");
            continue;
        }
        printf("#res: %d#\n\n", res);

        if (empty(&q) == 0) printQ(&q);
    }
}