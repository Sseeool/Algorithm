// Linear Probing

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME 20
#define TABLE_SIZE 10
#define DELETED_NODE (Person *)(0xFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int student_num;
} Person;

Person *hash_table[TABLE_SIZE];

unsigned int make_idx(char *name)
{
    int len = strlen(name);
    unsigned int idx_value = 0;

    for (int i = 0; i < len; i++)
    {
        idx_value += name[i];
        idx_value = (idx_value * name[i]) % TABLE_SIZE;
    }
    return idx_value;
}

void init_hash_table()
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
        else if (hash_table[i] == DELETED_NODE)
            printf("\t<deleted>\t\n");
        else
            printf("\t%i\t%s\t\n", i, hash_table[i]->name);
    }
    printf("End\n");
}

bool insert_hash_table(Person *p)
{
    int idx = make_idx(p->name);

    if (p == NULL) return false;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + idx) % TABLE_SIZE;
        if (hash_table[try] == NULL || \
            hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
        
    }
    return false;
}

Person *lookup_hash_table(char *name)
{
    int idx = make_idx(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (idx + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return false; // not here
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strcmp(hash_table[try]->name, name) == 0)
            return hash_table[idx];
    }
    return NULL;
}

Person *delete_hash_table(char *name)
{
    int idx = make_idx(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (idx + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strcmp(hash_table[try]->name, name) == 0)
        {
            Person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}
