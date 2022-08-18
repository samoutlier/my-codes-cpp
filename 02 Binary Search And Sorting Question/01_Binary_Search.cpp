#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    int mid = start + (end-start)/2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid-1;
        }
        else
        {
            start = mid + 1;
        }
        
            mid =start + (end-start)/2;
    }
    return -1 ;
}

int main()
{
    int n;
    cout << "Enter The Size OF Array : ";
    cin >> n;
    int arr[n], target;
    cout << "Enter The Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter The Element You want to Search : ";
    cin >> target;
    int index = BinarySearch(arr, n, target);

    cout<<"Index Of "<<target <<" is "<< index;
    return 0;
}