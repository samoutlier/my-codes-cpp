#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> maxheap;

    int n, k;
    cout << "Enter The Number OF Elements : ";
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter The Value of k : ";
    cin >> k;

    //k = k % n;
    for (int i = 0; i < k; i++)
    {
        maxheap.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < maxheap.top())
        {
            maxheap.pop();
            maxheap.push(arr[i]);
        }
    }

    cout << maxheap.top();
    return 0;
}