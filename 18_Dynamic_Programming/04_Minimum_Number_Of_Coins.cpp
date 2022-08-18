#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// //Simple Recursion Method

// int MinimumCoins(vector<int> &arr, int target, int n)
// {
//     if (target == 0)
//         return 0;
//     if (target < 0)
//         return INT16_MAX;

//     int mini = INT16_MAX;

//     for (int i = 0; i < n; i++)
//     {
//         int ans = MinimumCoins(arr, target - arr[i], n);
//         if (ans != INT16_MAX)
//             mini = min(ans + 1, mini);
//     }

//     return mini;
// }

// int main()
// {
//     int n, target;
//     cin >> n;
//     vector<int> arr(n);

//     cout << "Enter the Input : ";
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     cout << "Enter the Target : ";
//     cin >> target;

//     cout << "Minimum Number of coins to get the sum is : " << MinimumCoins(arr, target, n);
//     return 0;
// }

// // Simple Recursion + Memoization Method

// int MinimumCoins(vector<int> &arr, int target, vector<int> &dp)
// {
//     if (target == 0)
//         return 0;
//     if (target < 0)
//         return INT16_MAX;

//     if (dp[target] != -1)
//         return dp[target];

//     int mini = INT16_MAX;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int ans = MinimumCoins(arr, target - arr[i], dp);
//         if (ans != INT16_MAX)
//             mini = min(ans + 1, mini);
//     }

//     return dp[target] = mini;
// }

// int main()
// {
//     int n, target;
//     cin >> n;
//     vector<int> arr(n);

//     cout << "Enter the Input : ";
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     cout << "Enter the Target : ";
//     cin >> target;
//     vector<int> dp(target + 1, -1);

//     cout << "Minimum Number of coins to get the sum is : " << MinimumCoins(arr, target, dp);
//     return 0;
// }

// Simple Recursion + Memoization Method


int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the Input : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the Target : ";
    cin >> target;
    vector<int> dp(target + 1, INT32_MAX);

    dp[0] = 0;

    for(int i = 1 ; i<= target ; i++)
    {
        for(int j = 0; j< arr.size() ; j++)
        {
            if(i -arr[j] >=0 && dp[i-arr[j]] < INT16_MAX)
            dp[i] = min(dp[i] , dp[i-arr[j]] + 1);
        }
    }


    cout << "Minimum Number of coins to get the sum is : " << dp[target];
    return 0;
}