#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
} Stack;

void init(Stack *s, int size)
{
    s->arr = (int *)calloc(size, sizeof(int));
    s->top = -1;
}

int is_empty(Stack *s)
{
    return (s->top == -1) ? 1 : 0;
}

void push(Stack *s, int value)
{
    s->arr[++(s->top)] = value;
}

void pop(Stack *s)
{
    (s->top)--;
}

int peek(Stack *s)
{
    return (is_empty(s) == 1) ? 0 : s->arr[s->top];
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);

    Stack s;
    init(&s, n);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);

        if (a != 0) push(&s, a);
        else pop(&s);
    }
    
    for (int i = s.top; i >= 0; i--)
        sum += s.arr[i];
    printf("%d", sum);

    free(s.arr);
    return 0;
}