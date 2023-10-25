#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 500001

typedef struct Person {
    char name[21];
    struct Person *next;
} Person;

Person *hash_table[TABLE_SIZE];

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        hash_table[i] = NULL;
}

unsigned int make_index(char *name)
{
    int len = strlen(name);
    unsigned int idx = 0;
    
    for (int i = 0; i < len; i++)
    {
        idx += name[i];
        idx = (idx * name[i]) % TABLE_SIZE;
    }
    return idx;
}

bool insert_hash_table(Person *p)
{
    if (p == NULL) return false;
    
    int idx = make_index(p->name);
    p->next = hash_table[idx];
    hash_table[idx] = p;
    return true;
}

Person *lookup_hash_table(char *name)
{
    int idx = make_index(name);
    Person *tmp = hash_table[idx];

    while (tmp != NULL)
    {
        if (strcmp(tmp->name, name) == 0)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

int compare (const void *p1, const void *p2)
{
    const Person *pa = p1;
    const Person *pb = p2;

    return strcmp(pa->name, pb->name);
}

int main()
{
    int n, m,idx, cnt = 0;
    char tmp[21];
    init_hash_table();

    scanf("%d %d", &n, &m);
    Person *a = (Person *)calloc(n, sizeof(Person));
    Person *rslt = (Person *)calloc(m, sizeof(Person));

    for (int i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        strcpy(a[i].name, tmp);
        insert_hash_table(&a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%s", tmp);
        Person *lookup_rslt = lookup_hash_table(tmp);
        if (lookup_rslt != NULL)
        {
            strcpy(rslt[cnt].name, lookup_rslt->name);
            cnt++;
        }
    }
    qsort(rslt, cnt, sizeof(Person), compare);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%s\n", rslt[i].name);
    free(a);
    free(rslt);
    return 0;
}