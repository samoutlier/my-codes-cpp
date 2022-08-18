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
void BubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int check = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                check++;
            }
        }
        PrintArray(arr, n);
        if (check == 0)
            break;
    }
}

//  Time Complexity = O(n square)
//  Space Complexity = O(1)
//  Best case = O(n)
// Worst Case = O(n square)
// Use Case = For every i th round ith elemnts gets placed correctly
// It is Stable //  8 2 -9 -9 6

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
    BubbleSort(arr, n);
    cout << "Sorted Array : ";
    PrintArray(arr, n);
    return 0;
}
