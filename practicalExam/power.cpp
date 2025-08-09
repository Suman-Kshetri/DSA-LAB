#include <iostream>
using namespace std;


int power(int base, int exponent) {
    if (exponent == 0)
        return 1;  
    else
        return base * power(base, exponent - 1);
}

int main() {
    int base, exponent;
    
    cout << "Enter base: ";
    cin >> base;

    cout << "Enter exponent : ";
    cin >> exponent;

    if (exponent < 0) {
        cout << "Exponent must be non-negative." << endl;
    } else {
        int result = power(base, exponent);
        cout << base << "^" << exponent << " = " << result << endl;
    }

    return 0;
}
