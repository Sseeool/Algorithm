#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *line, n, snack_top = 1, a, top = -1;

    scanf("%d", &n);
    line = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &a);
        if (a == snack_top){
            snack_top++;
            while (line[top] == snack_top)
            {
                snack_top++;
                top--;
            }
        }
        else
            line[++top] = a;
        
    }
    puts (top == -1 ? "Nice" : "Sad");

    free(line);
    return 0;
}

/*#include <stdio.h>

int stack[1001];
int top = -1;

void push(int data)
{
    stack[++top] = data;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int N;
    int possible = 1;
    int num;

    scanf("%d", &N);    

    while (N--) {
        scanf("%d", &num);
        printf("num = %d possible = %d\n\n", num, possible);
        if (num == possible) {
            possible++;
            while (top >= 0 && stack[top] == possible) {
                printf("top = %d stack[%d] = %d possible = %d\n", top, top, stack[top], possible);
                pop();
                possible++;
                printf("top = %d stack[%d] = %d possible = %d\n", top, top, stack[top], possible);
            }
        }
        else {
            push(num);
        }
    }

    if (top == -1)
        printf("Nice");
    else
        printf("Sad");

    return 0;
}*/