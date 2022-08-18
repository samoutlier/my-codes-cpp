#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000007

// int TopDownApproach(int n, int &k, vector<int> &dp)
// {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return k * k;

//     if (dp[n] != -1)
//         return dp[n];

//     return dp[n] = (k - 1) * (TopDownApproach(n - 1, k, dp) % mod + TopDownApproach(n - 2, k, dp) % mod) % mod;
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> dp(n + 1, -1);

//     cout << "No of ways to paint Such that at most two consecutive fence have same color are : " << TopDownApproach(n, k, dp);
//     return 0;
// }

// int BottomUp(int n, int &k)
// {
//     vector<int> dp(n + 1);

//     dp[0] = 0;
//     dp[1] = k;
//     dp[2] = k * k;

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = (k - 1) * (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
//     }

//     return dp[n];
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     cout << "No of ways to paint Such that at most two consecutive fence have same color are : " << BottomUp(n, k);
//     return 0;
// }

int BestSolution(int n, int &k)
{

    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    int prev2 = k;
    int prev1 = k * k;

    for (int i = 3; i <= n; i++)
    {
        int ans = (k - 1) * ((prev1 % mod + prev2 ) % mod);
        prev2 = prev1 ;
        prev1 = ans;
    }

    return prev1;
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << "No of ways to paint Such that at most two consecutive fence have same color are : " << BestSolution(n, k);
    return 0;
}