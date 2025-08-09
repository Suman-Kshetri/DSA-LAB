#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int BinarySearch(int Arr[], int lb, int ub, int key) {
    if (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (Arr[mid] == key)
            return mid;
        else if (Arr[mid] > key)
            return BinarySearch(Arr, lb, mid - 1, key);
        else
            return BinarySearch(Arr, mid + 1, ub, key);
    }
    return -1;
}

int LinearSearch(int Arr[], int key, int n) {
    for (int i = 0; i < n; i++) {
        if (Arr[i] == key)
            return i;
    }
    return -1; 
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 10, 11, 12};
    int n = sizeof(A) / sizeof(A[0]);
    int key;

    cout << "Enter the value to search: ";
    cin >> key;

    // Binary Search timing
    auto start1 = high_resolution_clock::now();
    int result = BinarySearch(A, 0, n - 1, key);
    auto end1 = high_resolution_clock::now();

    if (result == -1)
        cout << "Key not found (Binary Search)\n";
    else
        cout << "The key is found at index " << result << " (Binary Search)\n";

    auto start2 = high_resolution_clock::now();
    int result1 = LinearSearch(A, key, n);
    auto end2 = high_resolution_clock::now();

    if (result1 == -1)
        cout << "Key not found (Linear Search)\n";
    else
        cout << "The key is found at index " << result1 << " (Linear Search)\n";

    duration<double> time_binary = end1 - start1;
    duration<double> time_linear = end2 - start2;

    cout << "The Binary Search completed in " << time_binary.count() << " seconds\n";
    cout << "The Linear Search completed in " << time_linear.count() << " seconds\n";

    return 0;
}
