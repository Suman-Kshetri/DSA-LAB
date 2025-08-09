#include<iostream>
using namespace std;

class DLL {
    public:
        float data;
        DLL* next;
        DLL* prev;
        DLL(float value){
            data = value;
            next = NULL;
            prev = NULL;
        }
};

class doubleLinkedList {
    private:
        DLL* first;
        DLL* last;
    public:
        doubleLinkedList(){
            first = last=  NULL;
        }
        void insertionAtBegining(float element);
        void insertionAtEnd(float element);
        void insertionAtSpecificPosition(int POS, float element);
        void deletionFromBegining();
        void deletionFromEnd();
        void deletionFromSpecificPosition(int POS);
        void display();
};

void doubleLinkedList::insertionAtBegining(float element){
    DLL* newnode = new DLL(element);
    if(first == NULL){
        first = last = newnode;
    }
    else{
        newnode->prev = NULL;
        newnode->next = first;
        first -> prev = newnode;
        first = newnode;
    }
    cout<<element <<" inserted at the begining of DLL"<<endl;
}
void doubleLinkedList::insertionAtEnd(float element){
    DLL* newnode = new DLL(element);
    if(first == NULL){
        first = last = newnode;
    }
    else{
        last->next = newnode;
        newnode -> prev = last;
        newnode -> next = NULL;
        last = newnode;
    }
    cout<<element<<" inserted at the end of DLL"<<endl;
}

void doubleLinkedList::insertionAtSpecificPosition(int POS, float element){
    DLL* newnode = new DLL(element);
    DLL* temp, *tempp;
    if(POS<= 0){
        cout<<"Invalid Position"<<endl;
    }
    else if(POS == 1 || first == NULL){
        insertionAtBegining(element);
    }
    else{
        temp = first;
        for(int i = 1; (i < POS-1)&&(temp->next != NULL); i++){
            temp = temp->next;
        }
        if(temp == last){
            insertionAtEnd(element);
        }
        else{
            tempp = temp->next;
            temp -> next = newnode;
            newnode -> prev = temp;
            newnode -> next = tempp;
            tempp -> prev = newnode; 
        }
        cout<<element<<" inserted at "<<POS<<" th position"<<endl;
    }
}
void doubleLinkedList::deletionFromBegining(){
    DLL* temp;
    if(first == NULL){
        cout<< "Linked List is Empty!!"<<endl;
    }
    else if(first-> next == NULL){
        temp = first;
        first = last = NULL;
        delete(temp);
    }
    else{
        temp = first;
        first = temp -> next;
        cout<<temp->data<<" is going to be deleted from begining"<<endl;
        delete(temp);
        temp -> prev = NULL;
    }
}
void doubleLinkedList::deletionFromEnd(){
    DLL* temp;
    if(first == NULL){
        cout<<"Linked List is Empty!!"<<endl;
    }
    else if(first -> next == NULL){
        temp = first;
        first = last = NULL;
        delete(temp);
    }
    else{
        temp = last;
        last = temp -> prev;
        last -> next =NULL;
        cout<<temp->data<<" is going to be deleted from end"<<endl;
        delete(temp);
    }
}

void doubleLinkedList::deletionFromSpecificPosition(int POS){
    DLL* temp, * delNode;
    if(first == NULL){
        cout<< "Link list is Empty!!";
    }
    else if(first -> next == NULL){
        deletionFromBegining();
    }
    else{
        temp = first;
        for(int i = 1; (i < POS - 1)&& (temp -> next !=NULL)&& (temp != NULL); i++){
            temp = temp -> next;
        }
        if(temp == NULL || temp->next == NULL){
            cout<<"Position out fo Bounds!!"<<endl;
        }
        else if(temp -> next == last){
            deletionFromEnd();
        }
        else{
            delNode = temp->next;
            temp-> next = delNode -> next;
            (delNode -> next)-> prev = temp;
            cout<<delNode->data<<" is going to be deleted from "<<POS<<" th position"<<endl;
            delete(delNode);
        }
    }
}

void doubleLinkedList::display(){
    DLL* temp;
    temp = first;
    if(first == NULL){
        cout<<"Linked List is Empty!!";
    }
    else{
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
         cout << "NULL" << endl;
         }
}

int main(){
    doubleLinkedList ls;
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
    ls.deletionFromBegining();
    ls.display();
    ls.deletionFromEnd();
    ls.display();
    ls.deletionFromSpecificPosition(3);
    ls.display();
    return 0;
}