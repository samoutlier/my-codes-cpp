// //Recusrion + Memoization  or Top Down Approach

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
// using namespace std;

// int fib(int n, vector<int> &dp)
// {
//     if (n < 2)
//         return n;

//     if (dp[n] != -1)
//         return dp[n];

//     return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> dp(n + 1, -1);
//     cout << fib(n, dp);
//     return 0;
// }

// // Tabulation Method or Bottom UP Approach
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> dp(n + 1, -1);

//     dp[0] = 0;
//     dp[1] = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     cout << dp[n];
//     return 0;
// }

// Tabulation Method or Bottom UP Approach
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;
    int ans;
    for (int i = 2; i <= n; i++)
    {
        ans = prev1 + prev2;
        prev2 = prev1;
        prev1 = ans;
    }

    if (n == 0)
        cout << 0;
    else if (n == 1)
        cout << 1;
    else
        cout << ans;
    return 0;
}