#include <iostream>

using namespace std;

class SLL {
    public: 
        float data;
        SLL* next;
    SLL(float element){
        data = element;
        next = NULL;
    }
};
class stack {
    private:
        SLL* top;
    public:
        stack() {
            top = NULL;
        }
    void push(float element);
    void pop();
    bool isEmpty();
    void display();

};

void stack::push(float element){
    SLL* newnode = new SLL(element);
    if(top == NULL){
        top = newnode;
    }
    else{
        newnode-> next =top;
        top = newnode;
    }
    cout<<top->data<<" is pushed into stack."<<endl;
}
void stack::pop(){
    SLL* temp;
    if(top == NULL){
        cout<<"Stack Underflow!";
    }
    else if(top-> next ==NULL){
        temp = top;
        delete(temp);
        top = NULL;
    }
    else{
        temp = top;
        top = top->next;
        cout<<temp->data<<" is poped from stack"<<endl;
        delete(temp);
    }
}
bool stack::isEmpty(){
    return top == NULL;
}

void stack::display() {
    if (top == NULL) {
        cout << "Stack is Empty." << endl;
        return;
    }

    SLL* temp = top;
    cout << "Stack elements : ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    stack s;
    int choice;
    float value;

    do {
        cout << "\nMenu:\n 1. Push\n 2. Pop\n 3. Display\n 4. Check if Empty\n 5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}

