#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int age;
    int sign_in_num;
    char name[101];
} Member_m;

int compareMem(const void *pa, const void *pb)
{
    const Member_m *p1 = pa;
    const Member_m *p2 = pb;

    if (p1->age > p2->age)
        return 1;
    else if (p1->age < p2->age)
        return -1;
    else
        return p1->sign_in_num - p2->sign_in_num;
}

int main()
{
    int n;

    scanf("%d", &n);
    Member_m *member = (Member_m *)malloc(sizeof(Member_m) * n + 1);
    for (int i = 0; i < n; i++)
    {
        member[i].sign_in_num = i;
        scanf("%d %s", &(member[i].age), member[i].name);
    }

    qsort(member, n, sizeof(Member_m), compareMem);

    for (int i = 0; i < n; i++)
        printf("%d %s\n", member[i].age, member[i].name);

    free(member);
    return 0;
}