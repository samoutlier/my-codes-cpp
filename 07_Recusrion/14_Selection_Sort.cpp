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

void SelectionSort(int *arr, int start, int n)
{
    if (start != n - 1)
    {
        for (int i = start + 1; i < n; i++)
        {
            if (arr[start] > arr[i])
            {
                swap(arr[start], arr[i]);
            }
        }
        SelectionSort(arr, ++start, n);
    }
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
    SelectionSort(arr, 0, n);
    PrintArray(arr, n);
    return 0;
}