#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

typedef struct Deque {
    int data[MAX];
    int point;
} Deque;

void init(Deque *d)
{
    d->point = 0;
}

int delete_front(Deque *d, int move, int n)
{
    int pop = d->point;
    int i = 0;
    d->data[pop] = 0;

    while (i < move)
    {
        d->point = (d->point + 1) % n;

        if (d->data[d->point] != 0) i++;
    }
    return pop + 1;
}

int delete_rear(Deque *d, int move, int n)
{
    int pop = d->point;
    int i = 0;
    d->data[pop] = 0;

    while (move < 0)
    {
        d->point = (d->point - 1 + n) % n;
        if (d->data[d->point] != 0) move++;
    }
    return pop + 1;
}

int main()
{
    int n, cnt = 0, i = 0;
    scanf("%d", &n);

    Deque d;
    init (&d);
    
    for (int i = 0; i < n; i ++) 
        scanf("%d", &d.data[i]);

    while (cnt < n - 1)
    {
        if (d.data[i] < 0)
        {
            printf("%d ", delete_rear(&d, d.data[i], n));
            i = d.point;
        }
        else
        {
            printf("%d ", delete_front(&d, d.data[i], n));
            i = d.point;
        }
        cnt++;
    }
    printf("%d", d.point + 1);
    
    return 0;
}