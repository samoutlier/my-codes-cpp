#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool safe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &arr)
{
    if ((x < n && x >= 0) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1)
        return true;
    else
        return false;
}

void Solve(vector<vector<int>> &arr, int n, vector<string> &ans, int x, int y,
           vector<vector<int>> &visited, string & path)
{
    if (x == n - 1 && y == n - 1)
    {   visited[x][y] = 0;
        ans.push_back(path);
        return;
    }
    

    visited[x][y] = 1;

    // 4 Choices from here
    // DOWN
    int newx = x + 1;
    int newy = y;

    // Check if safe t
    if (safe(newx, newy, n, visited, arr))
    {
        path.push_back('D');
        Solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // RIGHT
    newx = x;
    newy = y + 1;
    if (safe(newx, newy, n, visited, arr))
    {
        path.push_back('R');
        Solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // LEFT
    newx = x;
    newy = y - 1;
    if (safe(newx, newy, n, visited, arr))
    {
        path.push_back('L');
        Solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // UP
    newx = x - 1;
    newy = y;
    if (safe(newx, newy, n, visited, arr))
    {
        path.push_back('U');
        Solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> FindPath(vector<vector<int>> &arr, int n)
{
    vector<string> ans;

    if (arr[0][0] == 0 || arr[n-1][n-1]==0)
        return ans;

   

    vector<vector<int>> visited = arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = "";
    Solve(arr, n, ans, 0, 0, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> m;
    int n=4;
    cin>>n;
    vector<int> temp;
    int value;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cout<<"Enter The ELement at "<<i<<" "<<j<<" : ";
            cin>>value;
            temp.push_back(value);
        }
        m.push_back(temp);
        temp.clear();
    }
    
    // m[0].push_back(1);
    // m[0].push_back(0);
    // m[0].push_back(0);
    // m[0].push_back(0);
    // m[1].push_back(1);
    // m[1].push_back(1);
    // m[1].push_back(0);
    // m[1].push_back(1);
    // m[2].push_back(1);
    // m[2].push_back(1);
    // m[2].push_back(0);
    // m[2].push_back(0);
    // m[3].push_back(0);
    // m[3].push_back(1);
    // m[3].push_back(1);
    // m[3].push_back(1);

    vector<string> ans = FindPath(m, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}