#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[6];
    char log[6];
} Employee;

int compare (const void *p1, const void *p2)
{
    Employee pa = *(Employee*)p1;
    Employee pb = *(Employee*)p2;

    if (strcmp(pa.name, pb.name) > 0) return -1;
    else if (strcmp(pa.name, pb.name) < 0) return 1;
    else return 0;
}

int main()
{
    int n;

    scanf("%d", &n);
    Employee *record = (Employee *)malloc(sizeof(Employee) * (n + 1));
    for (int i = 0; i < n; i++)
        scanf("%s %s", record[i].name, record[i].log);
    qsort(record, n, sizeof(Employee), compare);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(record[i].name, record[i + 1].name) != 0 && \
            strcmp(record[i].log, "enter") == 0)
            printf("%s\n", record[i].name);
    }
    free(record);

    return 0;
}
