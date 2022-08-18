#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define mod 1000000007

// Top Down Approach

// long long int BottomUp(int n, vector<long long int> dp)
// {
//     if (n < 2)
//         return 0;
//     if (n == 2)
//         return 1;

//     if (dp[n] != -1)
//         return dp[n];

//     return dp[n] = (n - 1) *  (BottomUp(n - 2, dp) % mod + BottomUp(n - 1, dp) % mod);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<long long int> dp(n+1, -1);

//     cout << "Number Of Dearrangements are : " << BottomUp(n, dp);
//     return 0;
// }

//Bottom Up Approach

long long int BottomUp(int n)
{

    vector<long long int> dp(n + 1, -1);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] % mod + dp[i - 2] % mod);
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << "Number Of Dearrangements are : " << BottomUp(n);
    return 0;
}

// Bottom Up Approach

// long long int Solve(int n)
// {
//     if (n == 1)
//         return 0;

//     long long int prev2 = 0;
//     long long int prev1 = 1;

//     for (int i = 3; i <= n; i++)
//     {
//         long long int ans = (i - 1) * (prev1 % mod + prev2 % mod);
//         prev2 = prev1;
//         prev1 = ans;
//     }

//     return prev1;
// }

// int main()
// {
//     int n, t;
//     cin >> t;

//     for (int i = 0; i < t; i++)
//     {
//         cin >> n;
//         cout << "Number Of Dearrangements are : " << Solve(n) << endl;
//     }
//     return 0;
// }