#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int h){
    int size = h - l + 1;       
    int* tempArr = new int[size];
    int i = l, j = m, k = 0;

    while (i < m && j <= h){
        if (arr[i] < arr[j]){
            tempArr[k++] = arr[i++];
        } else {
            tempArr[k++] = arr[j++];
        }
    }

    for (; i < m; i++, k++){
        tempArr[k] = arr[i];
    }

    for (; j <= h; j++, k++){
        tempArr[k] = arr[j];
    }

    for (int p = l; p <= h; p++){
        arr[p] = tempArr[p-l];
    }

    delete[] tempArr;
}

void mergeSort(int arr[], int l, int h){
    if(l < h){
        int m = (l + h) / 2;
        mergeSort(arr, l , m);
        mergeSort(arr , m + 1, h);
        merge(arr, l , m + 1, h);
    }
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
