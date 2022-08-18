#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int Solve(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> min;

    for (int i = 0; i < n; i++)
    {
        min.push(arr[i]);
    }

    int cost = 0, rope1, rope2;

    while (min.size() > 1)
    {
        rope1 = min.top();
        min.pop();
        rope2 = min.top();
        min.pop();

        cost += rope1 + rope2;
        min.push(rope1 + rope2);
    }
    
    return cost;
}

int main()
{
    int arr[] = {4, 3, 2, 6};

    int n = (sizeof(arr)) / sizeof(int);

    cout << "Minimum Cost to joina all ropes is : " << Solve(arr, n);
    return 0;
}