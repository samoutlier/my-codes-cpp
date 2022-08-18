#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool safe(int x, int y, int n, map<pair<int, int>, bool> &visited, vector<vector<int>> &arr)
{
    if (x < n && y < n && x >= 0 && y >= 0)
    {
        if (arr[x][y] == 1 && !visited[make_pair(x, y)])
            return true;
    }
    return false;
}

void Solve(vector<vector<int>> &arr, int n, vector<string> &ans, int x, int y,
           map<pair<int, int>, bool> &visited, string &path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    int newx, newy;

    // DOWN
    newx = x + 1, newy = y;
    if (safe(newx, newy, n, visited, arr))
    {
        visited[make_pair(newx, newy)] = true;
        path.push_back('D');
        Solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
        visited[make_pair(newx, newy)] = false;
    }

    // LEFT
    newx = x, newy = y - 1;
    if (safe(newx, newy, n, visited, arr))
    {
        visited[make_pair(newx, newy)] = true;
        path.push_back('L');
        Solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
        visited[make_pair(newx, newy)] = false;
    }

    // RIGHT
    newx = x, newy = y + 1;
    if (safe(newx, newy, n, visited, arr))
    {
        visited[make_pair(newx, newy)] = true;
        path.push_back('R');
        Solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
        visited[make_pair(newx, newy)] = false;
    }

    // UP
    newx = x - 1, newy = y;
    if (safe(newx, newy, n, visited, arr))
    {
        visited[make_pair(newx, newy)] = true;
        path.push_back('U');
        Solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
        visited[make_pair(newx, newy)] = false;
    }
}

vector<string> FindPath(vector<vector<int>> &input, int n)
{
    vector<string> ans;

    if(input[0][0] == 0)
    return ans;

    map<pair<int, int>, bool> mp;
    string path = "";
    int x = 0;
    int y = 0;

    mp[make_pair(0,0)] = true;

    Solve(input, n, ans, x, y, mp, path);
    return ans;
}

// 4
// 1 0 0 0
// 1 1 1 0
// 1 1 1 0
// 0 1 1 1

int main()
{
    vector<vector<int>> input;
    int n;
    cin >> n;
    vector<int> temp;
    int value;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> value;
            temp.push_back(value);
        }
        input.push_back(temp);
        temp.clear();
    }

    vector<string> ans = FindPath(input, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}