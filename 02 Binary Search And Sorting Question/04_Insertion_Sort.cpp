#include <iostream>
using namespace std;
void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool check = 0;
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                check = true;
            }
            else
                break;
        }

        PrintArray(arr, n);
        if(!check)
        break;
    }
}

//  Time Complexity = O(n square)
//  Space Complexity = O(1)
//  Best case = O(n)
// Worst Case = O(n square)
// Use Case = very Adaptable
// It is Stable

int main()
{
    int n;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The Elements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    InsertionSort(arr, n);
    cout << "Sorted Array : ";
    PrintArray(arr, n);
    return 0;
}
