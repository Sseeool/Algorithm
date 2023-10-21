#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (Person *)(0xFFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
    // ... add other stuff later, maybe
} Person;

Person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hash_table[i] = NULL;
    // table is empty
}

void print_table() {
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
            printf("\t%i\t---\n", i);
        else if (hash_table[i] == DELETED_NODE)
            printf("\t%i\t---<deleted>\n", i);
        else
            printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
    printf("End\n");
}

bool hash_table_insert(Person *p)
{
    if (p == NULL) return false;
    int index = hash(p->name);
    // go until find an open sapce in the table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            hash_table[try] = p;
            return true;
    }
    return false;
}

// find a person in the table by their name
Person *hash_table_lookup(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return false; // not here
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
            return hash_table[try];
    }
    return NULL;
}

Person *hash_table_delete(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) %TABLE_SIZE;
        if (hash_table[try] == NULL)
            return NULL; // not here
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE)== 0) {
                Person *tmp = hash_table[try]; // find the location we save pointer to it
                hash_table[try] = DELETED_NODE; // then remove it from the table
                return tmp; // return the pointer that I saved to the caller so the caller can free the pointer
            }
    }
    return NULL;
}

int main() {

    init_hash_table();
    print_table();

    Person jacob = {.name="Jacob", .age=256};
    Person kate = {.name = "Kate", .age=27};
    Person mpho = {.name="Mpho", .age=14};
    Person natalie= {.name="Natalie", .age=25};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    print_table();

    Person *tmp = hash_table_lookup("Mpho");
    if (tmp == NULL)
            printf("Not found!\n");
    else
        printf("Found %s.\n", tmp->name);

    tmp = hash_table_lookup("George");
    if (tmp == NULL)
            printf("Not found!\n");
    else
        printf("Found %s.\n", tmp->name);

    hash_table_delete("Mpho");
    tmp = hash_table_lookup("Mpho");
    if (tmp == NULL)
        printf("Not found!\n");
    else
        printf("Found %s.\n", tmp->name);

    print_table();

    /*printf("Jacob => %u\n", hash("Jacob"));
    printf("Natalie => %u\n", hash("Natalie"));
    printf("Sara => %u\n", hash("Sara"));
    printf("Mpho => %u\n", hash("Mpho"));
    printf("Tebogo => %u\n", hash("Tebogo"));
    printf("Maren => %u\n", hash("Maren"));
    printf("Bill => %u\n", hash("Bill"));*/

    return 0;
}