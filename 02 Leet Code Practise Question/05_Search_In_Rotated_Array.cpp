// To Find Key in sorted rotated  array

#include <iostream>
using namespace std;

int PivotIndex(int arr[], int n)
{

    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] > arr[0] && arr[n - 1] < arr[0])
            start = mid + 1;
        else
            end = mid;
        mid = start + (end - start) / 2;
    }
    return start;
}

int BinarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;

    int pivot = PivotIndex(arr, n);
    if (arr[pivot] <= key && key <= arr[end])
        start = pivot;
    else
        end = pivot - 1;

    int mid = start + (end - start) / 2;
    
    while (start <= end)
    {
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int n, target;
    cout << "Enter The Size OF Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter The Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter The Element You want to search : ";
    cin >> target;
    cout << "The Index Of " << target << " is " << BinarySearch(arr, n, target);
    return 0;
}