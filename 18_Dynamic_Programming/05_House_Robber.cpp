#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Bottom Up Approach
int rob1(vector<int> &nums)
{

    if (nums.size() == 1)
        return nums[0];
    int n = nums.size();
    vector<int> dp(nums.size(), -1);

    dp[n - 1] = nums[n - 1];
    dp[n - 2] = max(nums[n - 1], nums[n - 2]);

    for (int i = n - 3; i >= 0; i--)
    {
        dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
    }

    return dp[0];
}

// Top Down Approach
int Solve(vector<int> &nums, int index, vector<int> &dp)
{
    if (index == nums.size() - 1)
        return nums[index];

    if (index == nums.size() - 2)
        return max(nums[index], nums[index + 1]);

    if (dp[index] != -1)
        return dp[index];

    return dp[index] = max(nums[index] + Solve(nums, index + 2, dp), Solve(nums, index + 1, dp));
}

// Best Approach
int rob2(vector<int> &nums)
{

    if (nums.size() == 1)
        return nums[0];
    int n = nums.size();

    int prev2 = nums[n - 1];
    int prev1 = max(nums[n - 1], nums[n - 2]);

    for (int i = n - 3; i >= 0; i--)
    {
        int ans = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the Input : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(arr.size(), -1);

    cout << "Minimum Number of coins to get the sum is : " << rob2(arr);
    return 0;
}