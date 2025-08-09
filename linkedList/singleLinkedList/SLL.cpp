#include <iostream>
using namespace std;

class SLL
{
public:
    float data;
    SLL *next;
    SLL(float value)
    {
        data = value;
        next = NULL;
    }
};

class linkList
{
private:
    SLL *first;
    SLL *last;

public:
    linkList()
    {
        first = last = NULL;
    }
    void insertionAtBegining(float element);
    void insertionAtEnd(float elemet);
    void insertionAtSpecificPosition(int POS, float element);
    void display();
    void deleteFromBegining();
    void deleteFromEnd();
    void deleteFromSpecificPosition(int POS);
};

void linkList ::insertionAtBegining(float element)
{
    SLL *newnode = new SLL(element);
    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        newnode->next = first;
        first = newnode;
    }
    cout << element << " Inserted at the begining of SLL" << endl;
}
void linkList::insertionAtEnd(float element)
{
    SLL *newnode = new SLL(element);
    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }
    cout << element << " Inseted at the end of SLL" << endl;
}
void linkList::insertionAtSpecificPosition(int POS, float element)
{
    int i;
    SLL *newnode = new SLL(element);
    SLL *temp = first;
    if (POS <= 0)
    {
        cout << "Invalid Position !!!!" << endl;
    }
    else if (POS == 1)
    {
        insertionAtBegining(element);
    }
    else
    {
        temp = first;
        for (i = 1; (i < POS - 1) && (temp->next != NULL); i++)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            insertionAtEnd(element);
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }

        cout << element << " inseted into " << ++i << " th palace" << endl;
    }
}

void linkList ::display()
{
    SLL *temp;
    if (first == NULL)
        cout << "List is Empty !!!" << endl;
    else
    {
        temp = first;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void linkList ::deleteFromBegining()
{
    SLL *temp;
    temp = first;
    if (temp == NULL)
    {
        cout << "List is Empty!!" << endl;
    }
    else if (temp->next == NULL)
    {
        temp = first;
        first = last = NULL;
        delete (temp);
    }
    else
    {
        temp = first;
        first = temp->next;
        cout << temp->data << " deleted from begining " << endl;
        delete (temp);
    }
}
void linkList::deleteFromEnd()
{
    if (first == NULL)
    {
        cout << "List is Empty!!" << endl;
        return;
    }
    else if (first == last)
    {
        cout << first->data << " deleted from end" << endl;
        delete first;
        first = last = NULL;
        return;
    }
    else
    {
        SLL *temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        cout << last->data << " deleted from end" << endl;
        delete last;
        last = temp;
        last->next = NULL;
    }
}
void linkList::deleteFromSpecificPosition(int POS)
{
    if (first == NULL || POS <= 0)
    {
        cout << "List is Empty or Invalid Position!" << endl;
        return;
    }

    else if (POS == 1)
    {
        deleteFromBegining();
        return;
    }
    else
    {
        SLL *temp = first;
        for (int i = 1; (i < POS - 1)&& (temp != NULL && temp->next != NULL); i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }
        if (temp->next == last)
        {
            deleteFromEnd();
            return;
        }
        SLL *delNode = temp->next;
        temp->next = delNode->next;
        cout << delNode->data << " deleted from position " << POS << endl;
        delete delNode;
    }
}

int main()
{
    linkList ls;
    ls.insertionAtBegining(100);
    ls.insertionAtBegining(200);
    ls.insertionAtBegining(300);
    ls.insertionAtBegining(400);
    ls.insertionAtBegining(500);
    ls.insertionAtEnd(900);
    ls.insertionAtEnd(800);
    ls.insertionAtEnd(700);
    ls.insertionAtEnd(600);
    ls.insertionAtSpecificPosition(3, 12121);
    ls.display();
    ls.deleteFromBegining();
    ls.display();
    ls.deleteFromEnd();
    ls.display();
    ls.deleteFromSpecificPosition(3);
    ls.display();
    return 0;
}