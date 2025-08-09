#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void linearSearch(const vector<int>& a, int key) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

int main() {
    int n, key;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> key;
    auto start = high_resolution_clock::now();
    linearSearch(a, key);
    auto end = high_resolution_clock::now();
    duration<float> diff = end - start;
    cout << "Time taken for linear search is " << diff.count() << " seconds\n";

    return 0;
}
