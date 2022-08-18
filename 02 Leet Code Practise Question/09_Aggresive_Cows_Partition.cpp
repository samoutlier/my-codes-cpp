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
    int CowCount = 1;
    int j = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[j] >= mid)
        {
            CowCount++;
            j = i;
        }
        if (CowCount == m)
            return true;
    }
    return false;
}

int Solution(int arr[], int n, int m)
{
    Sort(arr, n);
    int start = 0;
    int end = arr[n - 1] - arr[0];

    int mid = start + (end - start) / 2;

    int ans = -1;

    if (m > n)
        return ans;
    else
    {
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
    }
    return ans ;
}

int main()
{
    int n, m;
    cout << "Enter Number Of Position : ";
    cin >> n;
    int arr[n];
    cout << "Enter The Positions : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter The Number Of cows : ";
    cin >> m;

    cout << "The Maximum Distance Between cows is : " << Solution(arr, n, m);
    return 0;
}