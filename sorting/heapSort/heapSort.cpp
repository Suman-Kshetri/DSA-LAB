#include<iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

void maxHeapify(int arr[], int i , int n){
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    if(left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }
    if(i != largest){
        swap(arr[i], arr[largest]);
        maxHeapify(arr,largest, n);
    }

}

void buildMaxHeap(int arr[], int n){
    for(int i = n/2; i>=1 ; i--){
        maxHeapify(arr, i , n);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);
    int heapSize = n;
    for(int i = n ;i >= 2;i--){
        swap(arr[i], arr[1]);
        heapSize-- ;
        maxHeapify(arr, 1, heapSize);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n + 1];  // index 0 is unused

    cout << "Enter " << n << " elements:\n";
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted array:\n";
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
