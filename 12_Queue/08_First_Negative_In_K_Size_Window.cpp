#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> Solution(int *arr, int k, int n)
{
    deque<int> store;
    vector<int> ans;
    int i;

    // Running Loop for first k sized window
    for (i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            store.push_back(i);
    }

    // Storing ans for first k sized window
    if (store.empty())
        ans.push_back(0);
    else
        ans.push_back(arr[store.front()]);

    // For remaing windows
    for (i = k; i < n; i++)
    {
        if (!store.empty() && i - store.front() >= k)
        {
            store.pop_front();
        }

        if (arr[i] < 0)
            store.push_back(i);
            
        if (store.empty())
            ans.push_back(0);
        else
            ans.push_back(arr[store.front()]);
    }

    return ans;
}

int main()
{
    int n, *arr, k;
    cout << "Enter The Number Of elements : ";
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter The size of Window : ";
    cin >> k;

    vector<int> ans = Solution(arr, k, n);

    cout << "Answer : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }

    return 0;
}