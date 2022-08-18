#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int climbStairs(int n, vector<int> &cost)
{

    vector<int> dp(n, -1);

    dp[n - 1] = cost[n - 1];
    dp[n - 2] = cost[n - 2];

    for (int i = n - 3; i >= 0; i--)
    {
        dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
    }

    return min(dp[0], dp[1]);
}

int minCostClimbingStairs2(int n, vector<int> &cost)
{

    int prev2 = cost[0];
    int prev1 = cost[1];
    int ans;

    for (int i = 2; i < n; i++)
    {
        ans = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = ans;
    }

    return min(prev2, prev1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> costs(n);

    cout << "Enter The Costs : ";
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }

    cout << climbStairs(n, costs);
    return 0;
}