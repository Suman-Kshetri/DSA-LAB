#include <iostream>
#define MAX 5
using namespace std;

class Queue{
    private:
        int FRONT;
        int REAR;
        float queue[MAX];
    public:
        Queue(){
            FRONT = 0;
            REAR = -1;
        }
        void enqueue(float element);
        void dequeue();
        bool isFull();
        bool isEmpty();
};

void Queue::enqueue(float element){
    if(REAR == MAX -1){
        cout<<"Queue is Full"<<endl;
        return;
    }
    else{
        REAR = REAR+1;
        queue[REAR] = element;
        cout<<element<<" enqueued."<<endl;
    }
}
void Queue::dequeue(){
    if(FRONT > REAR){
        cout<<"Queue is Empty";
        return;
    }
    else{
        float element = queue[FRONT];
        FRONT++;
        cout<<element<<" is dequed from queue"<<endl;
    }
}

bool Queue::isFull(){
    if(REAR == MAX-1){
        return true;
    }
    return false;
}
bool Queue::isEmpty(){
    if(FRONT > REAR){
        return true;
    }
    return false;
}
int main() {
    Queue q;
    int choice;
    float value;

    do {
        cout << "\n1. Enqueue \n2. Dequeue \n3. isEmpty \n4. isFull \n5. Exit" << endl;
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
                cout << (q.isEmpty() ? "Queue is Empty" : "Queue is NOT Empty") << endl;
                break;

            case 4:
                cout << (q.isFull() ? "Queue is Full" : "Queue is NOT Full") << endl;
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
