#include<iostream>

using namespace std;

void swap(int &a , int &b){
    int temp = b;
    b = a;
    a = temp;
}

int partition(int arr[], int start, int end){
    int indx = start - 1;
    int j = start;
    int pivot = arr[end];
    for(j = start; j < end; j++){
        if(arr[j] <= pivot){
            indx++;
            swap(arr[j], arr[indx]);
        }
    }
    indx++;
    swap(arr[end], arr[indx]);
    return indx;
}

void quickSort(int arr[],int start, int end){
    if(start<end){
        int  pivotIdx = partition(arr,start, end);
        quickSort(arr, start, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1,end);
    }
}


int main(){
    int n ;
    cout<<"Enter the number of array elements : ";
    cin >> n;
    cout<<"\n Enter the elements : ";
    int * arr = new int[n];
    for(int i = 0 ;i < n; i++){
        cin>>arr[i];
    }

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}