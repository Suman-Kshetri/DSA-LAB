#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;
// insertion
void insert_at_beginning(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    NewNode->data = element;
    NewNode->next = NULL;
    if (first == NULL)
    {
        first = last = NewNode;
    }
    else
    {
        NewNode->next = first;
        first = NewNode;
    }
    printf("\n%d was inseted \n", first->data);
}

void insert_at_end(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    NewNode->data = element;
    NewNode->next = NULL;
    if (first == NULL)
    {
        first = last = NewNode;
    }
    else
    {
        last->next = NewNode;
        last = NewNode;
    }
    printf("\n%d was inseted \n", last->data);
}

void display()
{
    struct SLL *temp;
    if (first == NULL)
        printf("LIST IS EMPTY");
    else
    {
        temp = first;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insert_at_specific_position(int POS, int element)
{
    struct SLL *temp;
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    NewNode->data = element;
    NewNode->next = NULL;
    if (POS <= 0)
    {
        printf("Invalid Position..");
    }
    else if (POS == 1)
    {
        insert_at_beginning(element);
    }
    else
    {
        temp = first;
        for (int i = 1; (i < POS - 1) && (temp->next != NULL); i++)
        {
            temp = temp->next;
        }
        if (temp->next == last)
        {
            insert_at_end(element);
        }
        else
        {
            NewNode->next = temp->next;
            temp->next = NewNode;
        }
    }
    printf("\n%d was inserted at the position %d : \n", NewNode->data, POS);
}

// deletion
void delete_from_beginning()
{
    struct SLL *temp;
    temp = first;
    if (first == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        printf("\n%d is going to be deleted!!", temp->data);
        free(temp);
    }
}
void delete_from_end()
{
    struct SLL *temp;
    if (first == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        printf("\n%d is going to be deleted!!\n", temp->data);
        free(temp);
        last->next = NULL;
    }
}

void delete_from_specific_position(int POS)
{

    struct SLL *tempp;
    struct SLL *temp;
    if (POS <= 0 || first == NULL)
    {
        printf("Invalid deletion!!");
    }
    else if (POS == 1)
    {
        delete_from_beginning();
    }
    else
    {
        temp = first;
        for (int i = 1; (i < POS - 1) && (temp->next != last); i++)
        {
            temp = temp->next;
        }
        if (temp->next == last)
        {
            delete_from_end();
        }
        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            free(tempp);
        }
    }
}

int main()
{
    insert_at_beginning(100);
    insert_at_beginning(200);
    insert_at_beginning(300);
    insert_at_beginning(400);
    insert_at_beginning(500);
    insert_at_end(900);
    insert_at_end(800);
    insert_at_end(700);
    insert_at_end(600);
    display();
    insert_at_specific_position(4, 1996);
    display();
    delete_from_beginning();
    display();
    delete_from_end();
    display();
    delete_from_specific_position(3);
    display();
    return 0;
}