#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> m;

    int arr[] = {1, 2, 3 , 1 , 2, 2};
    int n = sizeof(arr) / sizeof(int);
    int maxi = 0;
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        if (maxi < m[arr[i]])
        {
            maxi = m[arr[i]];
            ans = arr[i];
        }
    }

    cout << ans << endl;

    return 0;
}