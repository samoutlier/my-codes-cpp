// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
// using namespace std;

// int Solve(int n, int x, int y, int z, vector<int> &dp)
// {
//     if (n == 0)
//         return 0;
//     if (n < 0)
//         return INT16_MIN;

//     if (dp[n] != -1)
//         return dp[n];

//     int op1 = 1 + Solve(n - x, x, y, z, dp);
//     int op2 = 1 + Solve(n - y, x, y, z, dp);
//     int op3 = 1 + Solve(n - z, x, y, z, dp);

//     return dp[n] = max(op1, max(op2, op3));
// }

// int main()
// {
//     int target, x, y, z;

//     cin >> target;
//     cin >> x >> y >> z;

//     vector<int> dp(target + 1, -1);

//     int ans = Solve(target, x, y, z, dp);
//     if (ans == INT16_MIN)
//         ans = -1;
//     cout << "Maximum Number of segments are : " << ans;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int Solve(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT16_MIN;

    vector<int> dp(n + 1, INT16_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x]  + 1 );

        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);

        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return dp[n] ;
}

int main()
{
    int target, x, y, z;

    cin >> target;
    cin >> x >> y >> z;

    int ans = Solve(target, x, y, z);
    if (ans == INT16_MIN)
        ans = -1;
    cout << "Maximum Number of segments are : " << ans;

    return 0;
}