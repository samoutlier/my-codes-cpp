#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    int arr[] = {5, 3, 8};
    int n = sizeof(arr) / sizeof(int);

    vector<float> ans;

    for (int i = 0; i < n; i++)
    {
        // Condition  whether to push in Maxheap or minheap
        if (maxHeap.size() - minHeap.size() == 0)
        {
            if (maxHeap.empty() || minHeap.top() > arr[i])
                maxHeap.push(arr[i]);
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }

        else
        {
            if (minHeap.empty() || maxHeap.top() < arr[i])
                minHeap.push(arr[i]);
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }

        if (maxHeap.size() == minHeap.size() && !minHeap.empty())
        {
            ans.push_back((minHeap.top() + maxHeap.top()) / 2.0);
        }
        else
        {
            ans.push_back(maxHeap.top() * 1.0);
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}