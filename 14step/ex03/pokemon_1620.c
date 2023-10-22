#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 30

typedef struct Pokemon {
    char name[21];
    int num;
    struct Pokemon *next;
} Pokemon;

Pokemon *hash_table[TABLE_SIZE];

int make_idx(char *name)
{
    int len = strlen(name);
    int idx = 0;

    for (int i = 0; i < len; i++)
    {
        idx += name[i];
        idx = (idx * name[i]) % TABLE_SIZE;
    }
    return idx;
}

void init_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        hash_table[i] = NULL;
}

void print_table()
{
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
            printf("\t%i\t---\n", i);
        else
        {
            printf("\t%i\t", i);
            Pokemon *tmp = hash_table[i];
            while (tmp != NULL)
            {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

bool insert_hash_table(Pokemon *p)
{
    int idx = make_idx(p->name);

    if (p == NULL) return false;
    p->next = hash_table[idx];
    hash_table[idx] = p;
    return true;
}

Pokemon *lookup_hash_table(char *name)
{
    int idx = make_idx(name);
    Pokemon *tmp = hash_table[idx];
    while (tmp != NULL && strcmp(tmp->name, name) != 0) 
        tmp = tmp->next;
    return tmp;
}

int main()
{
    int n1, n2;
    char tmp[21];

    scanf("%d %d", &n1, &n2);
    Pokemon *record = (Pokemon *)malloc(sizeof(Pokemon) * (n1 + 1));
    for (int i = 0; i < n1; i++)
    {
        scanf("%s", tmp);
        strcpy(record[i].name, tmp);
        record[i].num = i + 1;
        insert_hash_table(&record[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        scanf("%s", tmp);
        if (tmp[0] >= '0' && tmp[0] <= '9')
        {
            int idx = atoi(tmp);
            printf("%s\n", record[idx - 1].name);
        }
        else
        {
            Pokemon *rslt = lookup_hash_table(tmp);
            printf("%d\n", rslt->num);
        }
    }

    free(record);
    return 0;
}