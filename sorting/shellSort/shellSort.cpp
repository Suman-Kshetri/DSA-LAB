#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void shellSort(int arr[], int n){
    for(int gap = n / 2; gap >= 1; gap /= 2){
        for(int j = gap; j < n; j++){
            for(int i = j - gap; i >= 0 && arr[i + gap] < arr[i]; i -= gap){
                swap(arr[i + gap], arr[i]);
            }
        }
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    shellSort(arr, n);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
