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

int main()
{
    /*int n1, n2;
    char a[256];

    scanf("%d %d", &n1, &n2);
    person *man = (person *)malloc(sizeof(person)*(n1 + 1));
    for (int i = 0; i < n1; i++)
    {
        scanf("%s", a);
        strcpy(man[i].name, a);
        man[i].student_num = i;
        insert_hash_table(&man[i]);
    }*/

    person jacob = {.name = "Jacob", .student_num = 123};
    person natalie = {.name = "Natalie", .student_num = 932};
    person mpho = {.name = "Mpho", .student_num = 321};
    person ryan = {.name = "Ryan", .student_num = 678};
    person asick = {.name = "Asick", .student_num = 555};
    person sara = {.name = "Sara", .student_num = 321};
    person tebago = {.name = "Tebago", .student_num = 678};
    person maren = {.name = "Maren", .student_num = 555};

    insert_hash_table(&jacob);
    insert_hash_table(&natalie);
    insert_hash_table(&mpho);
    insert_hash_table(&ryan);
    insert_hash_table(&asick);
    insert_hash_table(&sara);
    insert_hash_table(&tebago);
    insert_hash_table(&maren);

    print_table();
    
    delete_hash_table("Natalie");
    delete_hash_table("Ryan");
    
    print_table();

    /*for (int i = 0; i < n2; i++)
    {
        scanf("%s", a);
        if (a[0] >= '0' && a[0] <= '9')
        {
            int idx = atoi(a);
            printf("%s", hash_table[idx]->name);
            continue;
        }
        Person *tmp = lookup_hash_table(a);
        if (tmp == NULL)
            continue;
        else
            printf("%d\n", tmp->student_num);
    }*/

}