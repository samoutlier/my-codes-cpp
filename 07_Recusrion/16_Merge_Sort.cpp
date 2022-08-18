#include <iostream>
#include <vector>
using namespace std;

//Time Complexity = O(nLogn)

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int MainArrayIndex = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[MainArrayIndex++];
    }
    MainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[MainArrayIndex++];
    }
    int index1 = 0;
    int index2 = 0;

    MainArrayIndex = start;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] > second[index2])

            arr[MainArrayIndex++] = first[index1++];
        else
            arr[MainArrayIndex++] = second[index2++];
    }
    while (index1 < len1)
    {
        arr[MainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[MainArrayIndex++] = second[index2++];
    }
    delete [ ]first;
    delete [ ]second;
}

void MergeSort(int *arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    MergeSort(arr, start, mid);

    MergeSort(arr, mid + 1, end);

    Merge(arr, start, end);
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
    MergeSort(arr, 0, n - 1);
    PrintArray(arr, n);
    delete []arr; 
    return 0;
}