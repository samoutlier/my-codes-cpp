#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NextSmallerElement(vector<int> input)
{
    stack<int> store;
    store.push(-1);
    vector<int> ans(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
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

vector<int> PreviousSmallerElement(vector<int> input)
{
    stack<int> store;
    store.push(-1);
    vector<int> ans(input.size());
    for (int i = 0; i < input.size(); i++)
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

int MaxAreaOfHistogram(vector<int> input)
{
    vector<int> prev = PreviousSmallerElement(input);
    vector<int> next = NextSmallerElement(input);

    int area = INT16_MIN;

    for (int i = 0; i < input.size(); i++)
    {
        if (next[i] == -1)
            next[i] = input.size();

        // Area  = Length * Bredth
        int newarea = (next[i] - prev[i] - 1) * input[i];

        area = max(area, newarea);
    }

    return area;
}

int MaxAreaRectangle(vector<vector<int>> input)
{
    vector<int> temp;
    for (int i = 0; i < input[0].size(); i++)
    {
        temp.push_back(input[0][i]);
    }

    int area = MaxAreaOfHistogram(temp);
    int count = 1;

    while (count < input.size())
    {
        for (int i = 0; i < input[0].size(); i++)
        {
            if (input[count][i] == 0)
            {
                temp[i] = 0;
            }
            else
            {
                temp[i]++;
            }
        }

        int newarea = MaxAreaOfHistogram(temp);

        area = max(area, newarea);
        count++;
    }
    return area;
}

int main()
{
    vector<vector<int>> input;
    int n, m, xyz;
    cout << "Enter The Number Of Rows : ";
    cin >> n;
    cout << "Enter The Number Of Columns : ";
    cin >> m;
    cout << "Enter The detail : " << endl;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            cin >> xyz;
            temp.push_back(xyz);
        }
        input.push_back(temp);
    }

    cout<<"Area Of Max rectangle possible is : "<<MaxAreaRectangle(input);

    return 0;
}