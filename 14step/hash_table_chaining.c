#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME 20
#define TABLE_SIZE 10

// Gonna make "Person" type arr. it should contain the information of the person's name & age.
// The name's max size is 20
// 1. make hash table -> make bucket, init hash table, print hash table
// 2. make insert_table func
// 3. find look_up_table func: find the person in the table by their name

typedef struct person{
    char name[MAX_NAME];
    int student_num;
    struct person *next; // create node to connect to the hash_table[idx]
} person;

person *hash_table[TABLE_SIZE];

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
        else
        {
            printf("\t%i\t", i);
            person *tmp = hash_table[i];
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

bool insert_hash_table(person *p)
{
    int idx = make_idx(p->name);

    if (p == NULL) return false;
    p->next = hash_table[idx];
    hash_table[idx] = p;
    return true;
}

person *lookup_hash_table(char *name)
{
    int idx = make_idx(name);
    person *tmp = hash_table[idx];
    while (tmp != NULL && strcmp(tmp->name, name) != 0) // go through the nodes as long as not null (linked list)
        tmp = tmp->next;
    return tmp;
}

person *delete_hash_table(char *name)
{
    int idx = make_idx(name);
    person *tmp = hash_table[idx];
    person *prev = NULL;
    while (tmp != NULL && strcmp(tmp->name, name) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL) // deleting the head
        hash_table[idx] = tmp->next;
    else
        prev->next = tmp->next;
    return tmp;
}
