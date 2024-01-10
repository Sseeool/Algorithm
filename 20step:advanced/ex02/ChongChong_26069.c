#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 2000
#define MAX_NAME 21
#define RABBIT "ChongChong"

typedef struct Person{
    char name[MAX_NAME];
    struct Person *next;
} Person;

Person *hash_table[TABLE_SIZE];

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

unsigned int make_idx(char *name)
{
    int len = strlen(name);
    unsigned int idx = 0;
    for (int i = 0; i < len; i++)
    {
        idx = (idx * 31 + name[i]) % TABLE_SIZE;
    }
    return idx;
}

bool insert_hash_table(Person *p)
{
    int idx = make_idx(p->name);

    if (p == NULL)
    {
        return false;
    }
    p->next = hash_table[idx];
    hash_table[idx] = p;
    return true;
}

Person *lookup_hash_table(char *name)
{
    int idx = make_idx(name);
    Person *temp = hash_table[idx];
    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    int n, count = 1, i = 0;
    char temp1[MAX_NAME], temp2[MAX_NAME];

    scanf("%d", &n);
    init_hash_table();

    Person ChongChong;
    strcpy(ChongChong.name, RABBIT);
    insert_hash_table(&ChongChong);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", temp1, temp2);
        if ((lookup_hash_table(temp1) != NULL && lookup_hash_table(temp2) == NULL))
        {
            count++;
            Person newPerson3;
            strcpy(newPerson3.name, temp2);
            insert_hash_table(&newPerson3);
        }
        else if ((lookup_hash_table(temp1) == NULL && lookup_hash_table(temp2) != NULL))
        {
            count++;
            Person newPerson4;
            strcpy(newPerson4.name, temp1);
            insert_hash_table(&newPerson4);
        }
    }
    printf("%d", count);
}