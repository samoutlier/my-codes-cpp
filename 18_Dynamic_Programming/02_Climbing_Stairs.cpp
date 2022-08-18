#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int climbStairs(int n)
{

    if (n == 1 || n == 2)
        return n;
    int prev1 = 2;
    int prev2 = 1;
    int ans;

    for (int i = 3; i <= n; i++)
    {
        ans = prev1 + prev2;
        prev2 = prev1;
        prev1 = ans;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << climbStairs(n);
    return 0;
}