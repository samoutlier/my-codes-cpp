#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(int *arr, int start, int end, int key)
{

    int mid = start + (end - start) / 2;
    if (start < end)
    {
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
        {
            return BinarySearch(arr, mid + 1 ,end , key);
        }
        else
        {
            return BinarySearch(arr, start, mid-1,  key);
        }
    }
    else
    return 0;
}

int main()
{
    int key, n;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The Elements : ";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter The Key To Search : ";
    cin >> key;
    cout << key << " is present at : " << BinarySearch(arr, 0, n - 1, key);
    return 0;
}