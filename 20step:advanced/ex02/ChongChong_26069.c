#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10007
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

bool insert_hash_table(char *name)
{
    int idx = make_idx(name);
    Person *temp = hash_table[idx];
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return false;
        }
        temp = temp->next;
    }
    Person *newPerson = (Person *)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    newPerson->next = hash_table[idx];
    hash_table[idx] = newPerson;
    return true;
}

bool lookup_hash_table(char *name)
{
    int idx = make_idx(name);
    Person *temp = hash_table[idx];
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    int n, count = 1;
    char temp1[MAX_NAME], temp2[MAX_NAME];

    scanf("%d", &n);
    init_hash_table();
    insert_hash_table(RABBIT);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", temp1, temp2);
        if (lookup_hash_table(temp1) || lookup_hash_table(temp2))
        {
            if (insert_hash_table(temp1))
            {
                count++;
            }
            if (insert_hash_table(temp2))
            {
                count++;
            }
        }
    }
    printf("%d", count);
}