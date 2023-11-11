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
