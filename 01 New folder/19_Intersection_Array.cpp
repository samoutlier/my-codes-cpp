// INTERSECTION Of TWO ARRAYS

// Arrays are Sorted
#include <iostream>
using namespace std;

int *intersection(int arr1[], int arr2[], int n, int m)
{
    int copy[n];
    int k = 0, i = 0, j = 0;
    while (i<n && j<m)
    {
        if(arr1[i] == arr2[j])
        {
            copy[k] = arr1[i];
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else
        j++;
    }
    
    return copy;
}
int main()
{
    int n, m, test;
    cout << "Enter The Number OF Test Cases : ";
    cin >> test;

    for (int j = 0; j < test; j++)
    {
        cout << "Enter The Number Of ELements OF Array 1: ";
        cin >> n;
        cout << "Enter The Number Of ELements OF Array 2: ";
        cin >> m;
        int arr1[n], arr2[m];
        cout << "Enter The ELements Of Array 1 : ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        cout << "Enter The ELements Of Array 2 : ";
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        int *xyz = intersection(arr1, arr2, n, m);

        for (int z = 0; z < 2; z++)
        {
            cout << "Hello ";
            cout << *(xyz + z) << " ";
        }
    }

    return 0;
}