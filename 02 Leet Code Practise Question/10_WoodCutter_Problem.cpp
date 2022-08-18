#include <iostream>
using namespace std;

void Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool isPossible(int arr[], int n, int m, int mid)
{
    int sum = 0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]>=mid)
        {
            sum = sum + (arr[i] - mid);
        }
    }
    if(sum>=m)
    {
       return true;
    }
    else
    return false;
}

int Solution(int arr[], int n, int m)
{
    Sort(arr, n);
    int start = 0;
    int end = arr[n - 1];

    int mid = start + (end - start) / 2;

    int ans = -1;

    while (start <= end)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter Number Of Trees : ";
    cin >> n;
    int arr[n];
    cout << "Enter The Length Of Trees : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter The Minimum Length Of Wood required : ";
    cin >> m;

    cout << "The Maximum height Of Saw is : " << Solution(arr, n, m);
    return 0;
}