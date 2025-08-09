#include <iostream>

using namespace std;

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int least = arr[i];
        int minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < least)
            {
                least = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int n;
    cout << "Enter the number of array element: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    cout << "The sorted element is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}