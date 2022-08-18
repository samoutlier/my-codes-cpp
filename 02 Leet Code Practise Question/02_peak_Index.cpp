// To Give Peak In  A Mountain Array

#include <iostream>
using namespace std;

int PeakIndex(int arr[], int n)
{
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] >= arr[mid - 1] && arr[mid] <= arr[mid + 1])
        {
            start = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;

        // if(arr[mid] < arr[mid+1])
        // {
        //     start = mid+1;
        // }
        // else
        // {
        //     end = mid-1;
        // }
        // mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter The Size OF Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter The Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The Peak Is At Index : " << PeakIndex(arr, n);
    return 0;
}