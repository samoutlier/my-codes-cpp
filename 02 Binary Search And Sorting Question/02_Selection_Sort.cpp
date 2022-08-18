#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {   int check = 0;                    
        for (int j = i + 1; j < n; j++)
        {
            int minIndex = i;
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
                check++;
            }
            swap(arr[minIndex], arr[i]);
        }
        if(check==0)
        break;
    }
}

//Time Complexity = O(n square)
// Space Complexity = O(1)
// Best case = 
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
    SelectionSort(arr, n);
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

