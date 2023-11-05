#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct StackType {
    int arr[SIZE]; // int 형 데이터 100개
    int top;
} StackType;

void init(StackType *s)
{
    s->top = -1; // 배열은 0부터 index 0부터 시작: top 이 0이면 데이터가 1개 있고, -1 이면 데이터가 없는 상황 
}

int is_empty(StackType * s)
{
    if (s->top == -1) return 1;
    return 0;
}

int is_full(StackType *s)
{
    if (s->top == SIZE - 1) return 1;
    return 0;
}

void push(StackType *s, int value)
{
    if (is_full(s) == 1)
    {
        printf("Stack is full\n");
        exit(1);
    }
    printf("pushed: %d\n", value);
    s->arr[++(s->top)] = value; // top 을 먼저 하나 증가시키고 value 로 선언
}

int pop(StackType *s)
{
    if (is_empty(s) == 1)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->arr[(s->top)--]; // top 의 데이터를 return 한 후 감소
}

// 맨 위 데이터가 뭔지만 확인해주는 함수
int peek(StackType *s)
{
    if (is_empty(s) == 1)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->arr[s->top];
}

int main()
{
    StackType s;
    init(&s); // stack 초기화

    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printf("peek : %d\n", peek(&s));
    printf("pop : %d\n", pop(&s));
    printf("pop : %d\n", pop(&s));
    printf("pop : %d\n", pop(&s));

    printf("pop : %d\n", pop(&s)); // err

    return 0;
}