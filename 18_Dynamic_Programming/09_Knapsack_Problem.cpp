#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// int KnapSackRecursion(int index, int capacity, vector<int> &weights, vector<int> &values)
// {
//     if (index == 0)
//     {
//         if (weights[0] <= capacity)
//             return values[0];
//         return 0;
//     }

//     int include = 0;
//     if (weights[index] <= capacity)
//     {
//         include = values[index] +  KnapSackRecursion(index - 1, capacity - weights[index], weights, values);
//     }

//     int exclude = KnapSackRecursion(index - 1, capacity, weights, values);

//     return  max(include, exclude);
// }

// // 4 5
// // 1 2 4 5
// // 5 4 8 6

// // 3 50
// // 15 30 40
// // 60 100 150

// // 4 15
// // 2 4 6 9
// // 10 10 12 18
// // ans : 38

// int main()
// {
//     int n;
//     int capacity;
//     cin >> n >> capacity;
//     vector<int> weights(n), value(n);

//     for (int i = 0; i < n; i++)
//         cin >> weights[i];

//     for (int i = 0; i < n; i++)
//         cin >> value[i];

//     cout << "Maximum value : " << KnapSackRecursion(n - 1, capacity, weights, value);

//     return 0;
// }

int KnapSack(int index, int capacity, vector<int> &weights, vector<int> &values, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weights[0] <= capacity)
            return values[0];
        return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if (weights[index] <= capacity)
    {
        include = values[index] + KnapSack(index - 1, capacity - weights[index], weights, values, dp);
    }

    int exclude = KnapSack(index - 1, capacity, weights, values, dp);

    return dp[index][capacity] = max(include, exclude);
}

// int main()
// {
//     int n;
//     int capacity;
//     cin >> n >> capacity;
//     vector<int> weights(n), value(n);
//     vector<vector<int>> dp(n, vector<int>(capacity+1, -1));

//     for (int i = 0; i < n; i++)
//         cin >> weights[i];

//     for (int i = 0; i < n; i++)
//         cin >> value[i];

//     cout << "Maximum value : " << KnapSack(n - 1, capacity, weights, value, dp);

//     return 0;
// }

// int KnapSackByTabulation(int n, int capacity, vector<int> &weights, vector<int> &values)
// {
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

//     // Base Case
//     for (int w = weights[0]; w <= capacity; w++)
//     {
//         if (weights[0] <= capacity)
//             dp[0][w] = values[0];
//         else
//             dp[0][w] = 0;
//     }

//     // Recursive calls

//     for (int index = 1; index < n; index++)
//     {
//         for (int w = 1; w <= capacity; w++)
//         {
//             int include = 0;

//             if (weights[index] <= w)
//                 include = values[index] + dp[index - 1][w - weights[index]];

//             int exclude = dp[index - 1][w];

//             dp[index][w] = max(exclude, include);
//         }
//     }

//     return dp[n - 1][capacity];
// }

// int main()
// {
//     int n;
//     int capacity;
//     cin >> n >> capacity;
//     vector<int> weights(n), value(n);
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

//     for (int i = 0; i < n; i++)
//         cin >> weights[i];

//     for (int i = 0; i < n; i++)
//         cin >> value[i];

//     cout << "Maximum value : " << KnapSackByTabulation(n, capacity, weights, value);

//     return 0;
// }

int KnapSackBestSolution(int n, int capacity, vector<int> &weights, vector<int> &values)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // Base Case
    for (int w = weights[0]; w <= capacity; w++)
    {
        if (weights[0] <= capacity)
            prev[w] = values[0];
        else
            prev[w] = 0;
    }

    // Recursive calls

    for (int index = 1; index < n; index++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            int include = 0;

            if (weights[index] <= w)
                include = values[index] + prev[w - weights[index]];

            int exclude = prev[w];

            curr[w] = max(exclude, include);
        }

        prev = curr;
    }

    return prev[capacity];
}

int main()
{
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> weights(n), value(n);
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    for (int i = 0; i < n; i++)
        cin >> weights[i];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Maximum value : " << KnapSackBestSolution(n, capacity, weights, value);

    return 0;
}