#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minheap;

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

    // k = k % n;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (minheap.size() < k)
                minheap.push(sum);
            else
            {
                if (minheap.top() < sum)
                {
                    minheap.pop();
                    minheap.push(sum);
                }
            }
        }
    }

    cout << minheap.top();
    return 0;
}