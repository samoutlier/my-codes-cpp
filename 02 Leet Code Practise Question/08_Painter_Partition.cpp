#include <iostream>
using namespace std;

int Total(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int max(int arr[], int m)
{
    int max = arr[0];
    for (int i = 1; i < m; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

bool isPossible(int arr[], int n, int m, int mid)
{
    int pagesum = 0;
    int StudentCount = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + pagesum <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            StudentCount++;
            if (StudentCount > m || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}

int Solution(int arr[], int n, int m)
{
    int start = 0;
    int end = Total(arr, n);
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start < end)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter The Number Of Boards : ";
    cin >> n;
    int arr[n];
    cout << "Enter The Lenghts OF Boards : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Number OF Painters : ";
    cin >> m;
    cout << "The Minimum Time Taken is : " << Solution(arr, n, m);
    return 0;
}