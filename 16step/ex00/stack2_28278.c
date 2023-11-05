#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
} Stack;

void init(Stack *s, int size) {
    s->top = -1;
    s->arr = (int *)calloc(size, sizeof(int));
}

int is_empty(Stack *s) {
    if (s->top == -1) return 1;
    return 0;
}

void push(Stack *s, int value) {
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (is_empty(s) == 1) {
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (is_empty(s) != 1)
        return s->arr[s->top];
    return -1;
}

int main() {
    int n;

    scanf("%d", &n);

    Stack s;
    init(&s, n);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        switch (a) {
            case 1: {
                int value;
                scanf("%d", &value);
                push(&s, value);
                break;
            }
            case 2:
                printf("%d\n", pop(&s));
                break;
            case 3:
                printf("%d\n", s.top + 1);
                break;
            case 4:
                printf("%d\n", is_empty(&s));
                break;
            case 5:
                printf("%d\n", peek(&s));
                break;
        }
    }
    free(s.arr);
    return 0;
}