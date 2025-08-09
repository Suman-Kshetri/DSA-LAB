#include <iostream>
using namespace std;


int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

// Counting sort based on the digit represented by exp (1s, 10s, 100s, ...)
void countingSort(int arr[], int n, int exp) {
    int* output = new int[n]; 
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);

    for(int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
