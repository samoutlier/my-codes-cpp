#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int SOlveByTabulation(vector<int> &nums, int n, int target)
{
    vector<int> dp(target + 1, -1);

    dp[0] = 1;

    for (int i = 1; i <= target; i++)
    {
        int ans = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
                ans += dp[i - nums[j]];
        }

        dp[i] = ans;
    }

    return dp[target];
}

int main()
{
    vector<int> nums = {1, 2, 5};
    int n = nums.size();

    int target;
    cin >> target;

    cout << "No of Ways to get " << target << " is " << SOlveByTabulation(nums, n, target);

    return 0;
}