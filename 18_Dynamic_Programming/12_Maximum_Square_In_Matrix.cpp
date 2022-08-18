#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int SolveByRecursion(vector<vector<int>> &matrix, int m, int n, int i, int j, int &maxi)
{
    if (i == m || j == n)
        return 0;

    int diagonal = SolveByRecursion(matrix, m, n, i + 1, j + 1, maxi);
    int right = SolveByRecursion(matrix, m, n, i, j + 1, maxi);
    int down = SolveByRecursion(matrix, m, n, i + 1, j, maxi);

    if (matrix[i][j] == 1)
    {

        int ans = 1 + min(diagonal, min(right, down));

        maxi = max(maxi, ans);
        return ans;
    }

    return 0;
}

int SolveByMemoization(vector<vector<int>> &matrix, int m, int n, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i == m || j == n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int diagonal = SolveByMemoization(matrix, m, n, i + 1, j + 1, maxi, dp);
    int right = SolveByMemoization(matrix, m, n, i, j + 1, maxi, dp);
    int down = SolveByMemoization(matrix, m, n, i + 1, j, maxi, dp);

    if (matrix[i][j] == 1)
    {

        int ans = 1 + min(diagonal, min(right, down));

        maxi = max(maxi, ans);
        return dp[i][j] = ans;
    }

    return dp[i][j] = 0;
}

void SolveByTabulation(vector<vector<int>> &matrix, int m, int n, int &maxi)
{
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (matrix[i][j] == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));
                maxi = max(dp[i][j], maxi);
            }
        }
    }

}

// 4 9
// 1 0 1 0 0 0 0 0 1
// 1 0 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1
// 1 0 0 1 1 1 1 1 1

int main()
{
    int n= 0, m= 0;

    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[m-1][n-1] = matrix[m-1][n-1];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    int maxi = 0;
    SolveByRecursion(matrix, m, n, 0, 0, maxi);
    cout << "The Maximum Area Of Square using recursion is : " << maxi << endl;
    maxi = 0;
    SolveByMemoization(matrix, m, n, 0, 0, maxi, dp);
    cout << "The Maximum Area Of Square using memoization is : " << maxi << endl;

    maxi = 0;
    SolveByTabulation(matrix, m, n, maxi);
    cout << "The Maximum Area Of Square using Tabulation is : " << maxi << endl;

    return 0;
}