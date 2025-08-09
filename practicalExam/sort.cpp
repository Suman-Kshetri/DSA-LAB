#include<iostream>

using namespace std;

void bubbleSort(float arr[],int n){
    float temp;
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
    float arr[] = {-1.5, 7, 3.5, -2, 37, 13.1, 22.9};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "The sorted array is: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}