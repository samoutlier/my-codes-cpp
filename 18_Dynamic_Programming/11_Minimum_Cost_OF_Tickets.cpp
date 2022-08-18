#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> cost(3);

int SolveByRecursion(vector<int> &days, int index, int n)
{
    if (index == n)
        return 0;

    int mini = cost[2] * n;

    // Choosing 1 day
    mini = min(mini, cost[0] + SolveByRecursion(days, index + 1, n));

    // Choosing 7 days

    int val = days[index];
    int i = index + 1;
    while (i < n && days[i] - days[index] < 7)
        i++;

    mini = min(mini, cost[1] + SolveByRecursion(days, i, n));

    // Choosing 7 days
    while (i < n && days[i] - days[index] < 30)
        i++;

    mini = min(mini, cost[2] + SolveByRecursion(days, i, n));

    return mini;
}

int SolveByTopDown(vector<int> &days, int index, int n, vector<int> &dp)
{
    if (dp[index] != -1)
        return dp[index];

    int mini = INT32_MAX;

    // Choosing 1 day
    mini = min(mini, cost[0] + SolveByTopDown(days, index + 1, n, dp));

    // Choosing 7 days

    int val = days[index];
    int i = index;
    while (i < n && days[i] - days[index] < 7)
        i++;

    mini = min(mini, cost[1] + SolveByTopDown(days, i, n, dp));

    // Choosing 7 days
    while (i < n && days[i] - days[index] < 30)
        i++;

    mini = min(mini, cost[2] + SolveByTopDown(days, i, n, dp));

    return dp[index] = mini;
}

int SolveByTabulation(vector<int> &days, int n)
{
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    dp[n - 1] = min(cost[0], min(cost[1], cost[2]));

    for (int i = n - 2; i >= 0; i--)
    {
        // Choosing 1 day
        int op1 = cost[0] + dp[i + 1];

        // Choosing 7 days

        int j = i + 1;
        while (j < n && days[j] - days[i] < 7)
            j++;

        int op2 = cost[1] + dp[j];

        // Choosing 30 days

        while (j < n && days[j] - days[i] < 30)
            j++;

        int op3 = cost[2] + dp[j];

        dp[i] = min(op1, min(op2, op3));
    }
    return dp[0];
}

int SolveByBestApproach(vector<int> &days, int n)
{
    queue<pair<int, int>> week;
    queue<pair<int, int>> month;

    int ans = 0;

    for (auto day : days)
    {
        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();

        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();

        week.push(make_pair(day, ans + cost[1]));
        month.push(make_pair(day, ans + cost[2]));

        
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}

// 7
// 1 3 4 5 7 8 10
// 2 7 20
// Ans : 11

// 6
// 1 4 6 7 8 20
// 2 7 15
// Ans : 11

// 12
// 1 2 3 4 5 6 7 8 9 10 30 31
// 2 7 15
// Ans : 17

int main()
{
    int n;
    cin >> n;

    vector<int> days(n);
    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = 0; i < n; i++)
        cin >> days[i];

    cin >> cost[0];
    cin >> cost[1];
    cin >> cost[2];

    cout << "Minimum Cost to Travel using Recursion is : " << SolveByRecursion(days, 0, n) << endl;
    cout << "Minimum Cost to Travel using TopDown is : " << SolveByTopDown(days, 0, n, dp) << endl;
    cout << "Minimum Cost to Travel using Tabulation is : " << SolveByTabulation(days, n) << endl;
    cout << "Minimum Cost to Travel using Queue is : " << SolveByBestApproach(days, n);

    return 0;
}