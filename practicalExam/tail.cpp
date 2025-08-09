#include <iostream>
using namespace std;

int powerTail(int base, int exponent, int accumulator) {
    if (exponent == 0)
        return accumulator; 
    else
        return powerTail(base, exponent - 1, accumulator * base);
}

int power(int base, int exponent) {
    return powerTail(base, exponent, 1);
}

int main() {
    int base, exponent;
    
    cout << "Enter base: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    if (exponent < 0) {
        cout << "Exponent must be non-negative." << endl;
    } else {
        int result = power(base, exponent);
        cout << base << "^" << exponent << " = " << result << endl;
    }

    return 0;
}
