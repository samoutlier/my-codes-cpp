#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NextSmallerElement(vector<int> &input, int n)
{
    stack<int> store;
    store.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (store.top() != -1 && input[store.top()] >= input[i])
        {
            store.pop();
        }

        ans[i] = store.top();
        store.push(i);
    }
    return ans;
}

vector<int> PrevSmallerElement(vector<int> &input, int n)
{
    stack<int> store;
    store.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (store.top() != -1 && input[store.top()] >= input[i])
        {
            store.pop();
        }

        ans[i] = store.top();
        store.push(i);
    }
    return ans;
}

int MaxAreaOfHistogram(vector<int> &input, int n)
{
    vector<int> prev = PrevSmallerElement(input, n);
    vector<int> next = NextSmallerElement(input, n);
    int area = -1;

    for (int i = 0; i < n; i++)
    {
        if (next[i] == -1) 
            next[i] = n;
        int newarea = input[i] * (next[i] - prev[i] - 1);

        area = max(area, newarea);
    }

    return area;
}

int main()
{

    int n, x;
    cout << "Enter The Number Of elements : ";
    cin >> n;
    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        input[i] = x;
    }

    cout << "Input Heights : ";
    for (int i = 0; i < n; i++)
    {
        cout << input.at(i) << " ";
    }

    cout << "\nMaximum Area In Histogram : " << MaxAreaOfHistogram(input, n);

    return 0;
}