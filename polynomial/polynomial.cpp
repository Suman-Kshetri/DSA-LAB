#include <iostream>
using namespace std;

class Polynomial {
public:
    int power;
    float coefficient;
    Polynomial* next;

    Polynomial(int power, float coeff) {
        this->power = power;
        this->coefficient = coeff;
        this->next = nullptr;
    }
};

class PolynomialList {
private:
    Polynomial* head;

public:
    PolynomialList() {
        head = nullptr;
    }

    void insert(int power, float coeff) {
        Polynomial* newNode = new Polynomial(power, coeff);

        if (head == nullptr || power > head->power) {
            newNode->next = head;
            head = newNode;
        } else {
            Polynomial* temp = head;
            while (temp->next != nullptr && temp->next->power > power) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void create() {
        int n;
        float coeff;
        int power;

        cout << "Enter the number of terms: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cout << "Enter the coefficient for term " << i + 1 << ": ";
            cin >> coeff;
            cout << "Enter the power for term " << i + 1 << ": ";
            cin >> power;
            insert(power, coeff);
        }
    }

    void print() {
        if (head == nullptr) {
            cout << "No Polynomial\n";
            return;
        }

        Polynomial* temp = head;
        cout << "The Polynomial is:\n";
        while (temp != nullptr) {
            cout << "(" << temp->coefficient << ")x^" << temp->power;
            temp = temp->next;
            if (temp != nullptr)
                cout << " + ";
        }
        cout << endl;
    }

    Polynomial* getHead() {
        return head;
    }

    static PolynomialList add(PolynomialList& p1, PolynomialList& p2) {
        Polynomial* t1 = p1.getHead();
        Polynomial* t2 = p2.getHead();
        PolynomialList result;

        while (t1 != nullptr && t2 != nullptr) {
            if (t1->power == t2->power) {
                result.insert(t1->power, t1->coefficient + t2->coefficient);
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->power > t2->power) {
                result.insert(t1->power, t1->coefficient);
                t1 = t1->next;
            } else {
                result.insert(t2->power, t2->coefficient);
                t2 = t2->next;
            }
        }

        while (t1 != nullptr) {
            result.insert(t1->power, t1->coefficient);
            t1 = t1->next;
        }

        while (t2 != nullptr) {
            result.insert(t2->power, t2->coefficient);
            t2 = t2->next;
        }

        return result;
    }
};

int main() {
    PolynomialList p1, p2;
    cout << "Enter Polynomial 1:\n";
    p1.create();
    cout << "\nEnter Polynomial 2:\n";
    p2.create();

    cout << "\nPolynomial 1:\n";
    p1.print();
    cout << "\nPolynomial 2:\n";
    p2.print();

    PolynomialList result = PolynomialList::add(p1, p2);
    cout << "\nResultant Polynomial after addition:\n";
    result.print();

    return 0;
}
