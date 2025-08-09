#include<iostream>

using namespace std;

class SLL{
    public:
        float data;
        SLL* next;
    SLL(float element){
        data = element;
        next = NULL;
    }
};
class queue{
    private:
        SLL* front, *rear;
    public:
        queue() {
            front = rear = NULL;
        }
        void enqueue(float element);
        void dequeue();
        void display();
};

void queue::enqueue(float element){
    SLL* newnode = new SLL(element);
    if(front == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    cout<<rear->data<<" enqued to queue."<<endl;
}


void queue::dequeue(){
    SLL* temp;
    if(front == NULL){
        cout<<"Queue is Empty!!";
    }
    else if(front->next == NULL){
        temp = front;
        delete(temp);
        front = rear = NULL;
    }
    else{
        temp = front;
        front = temp->next;
        cout<<temp->data<<" dequed from queue."<<endl;
        delete(temp);
    }
}

void queue::display(){
    SLL* temp;
    if(front == NULL){
        cout<<"Queue is empty!!"<<endl;
    }
    else{
        temp = front;
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    queue q;
    int choice;
    float value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again!" << endl;
        }

    } while (choice != 4);

    return 0;
}
