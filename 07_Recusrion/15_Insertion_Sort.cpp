#include <iostream>
#include <vector>
using namespace std;

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int *arr, int start, int n)
{
    int k = start;
    if(start>=n)
    return;
    while(arr[k]<arr[k-1] && k>=1)
    {   
        swap(arr[k], arr[k-1]);
        k--;
    }
    InsertionSort(arr,++start, n);
}

int main()
{
    int n;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The Elements : ";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    InsertionSort(arr, 1, n);
    PrintArray(arr, n);
    return 0;
}