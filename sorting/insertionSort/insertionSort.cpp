#include<iostream>

using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr; //placing current element in correct palce..
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout<<"The sorted array is: "<<endl;
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}