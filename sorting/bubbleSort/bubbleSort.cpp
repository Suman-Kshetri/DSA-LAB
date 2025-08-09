#include<iostream>

using namespace std;

void bubbleSort(int arr[],int n){
    int temp;
    for(int i = 0 ;i < n-1; i++){
        bool isSwap = false;
        for(int j = 0; j < n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
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
    bubbleSort(arr, n);
    cout<<"The sorted array is: "<<endl;
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}