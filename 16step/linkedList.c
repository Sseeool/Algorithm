#include <stdio.h>
#include <stdlib.h>

void input(), print(), delete();

struct Node {
    int ID;
    int value;
    struct Node *next; // new defined type
} *head, *tail, *ptr;

int main()
{
    head = NULL;
    int idx, flag = 0;

    while (flag == 0)
    {
        printf("Enter (1)input (2)print (3)update (4)delete (5)exit");
        scanf("%d", &idx);

        if (idx == 1) input();
        else if (idx == 2) print();
        else if (idx == 3) update();
        else if (idx == 4) delete();
        else if (idx == 5) {printf("Exit this program\n"); flag = 1;}
        else printf("Enter Again\n");
    }
    return 0;
}

void input()
{
    int in_ID, in_value;
    printf("\tID, value: "); scanf("%d %d", &in_ID, &in_value);
    ptr = (struct Node *)malloc(sizeof(struct Node));
    // int 형 4 2개, pointer 8 바이트 한 개의 메모리를 할당하여 시작주소를 ptr 에 넘겨준다.
    if (head == NULL) {head = ptr;} else {tail->next = ptr;}
    ptr->ID = in_ID;
    ptr->value = in_value;
    ptr->next = NULL;
    tail = ptr;
    print();
}

void print()
{
    ptr = head;
    printf("(ID, Values): ");
    while (ptr != NULL)
    {
        printf("(%d, %d)", ptr->ID, ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void update()
{
    int update_ID, update_value;
    printf("\tID for update: "); scanf("%d", &update_ID);
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->ID == update_ID)
        {
            printf("\tEnter the value for this ID: ");
            scanf("%d", &update_value);
            ptr->value = update_value;
            print();
            return;
        }
        ptr = ptr->next;
    }
}

void delete()
{
    int delete_ID;
    printf("\tID for delete: "); scanf("%d", &delete_ID);
    ptr = head;
    if (ptr->ID == delete_ID)
    {
        head = ptr->next;
        free(ptr);
        print();
        return;
    }
    struct Node *tmp;
    while (ptr != NULL)
    {
        tail = ptr;
        ptr = ptr->next;
        if (ptr->ID == delete_ID)
        {
            tail->next = ptr->next;
            tmp = tail;
            free(ptr);
            while (tail->next != NULL)
            {
                tail = tmp;
                tmp = tmp->next;
            }
            print();
            return;
        }
    }
}