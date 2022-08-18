#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <list>
using namespace std;

void CreateAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjlist, int &n, int &m)
{
    // creating Adj List;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }
}

bool CycleDetectionDFS(unordered_map<int, list<int>> &adjlist, int node,  unordered_map<int, bool> &dfsvisited , unordered_map<int, bool> &visited)
{
    visited[node] = true;
    dfsvisited[node] = true;

    bool ans = false;

    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            ans |= CycleDetectionDFS(adjlist, i, dfsvisited, visited);
            if (ans)
                return ans;
        }
        else if (dfsvisited[i])
        {
            return true;
        }
        
    }

    dfsvisited[node] = false;
    return ans;
}

// 8 9
// 1 2 2 3 3 7 3 8 8 7 2 4 4 5 5 6 6 4

int main()
{
    vector<vector<int>> edges;
    vector<int> temp;
    int n, m;

    cin >> n;
    cin >> m;
    cout << endl;
    int data;

    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 2; j++)
        {
            cin >> data;
            temp.push_back(data);
        }
        edges.push_back(temp);
    }

    // Creating Adj List
    unordered_map<int, list<int>> adjlist;

    CreateAdjList(edges, adjlist, n, m);

    for (auto i : adjlist)
    {
        cout << i.first << " ->> ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // BFS TRAVERSAL
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    bool ans = false;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans = ans || CycleDetectionDFS(adjlist, i, dfsvisited, visited);
        }
        if (ans)
            break;
    }

    if (ans)
        cout << "Cycle is Present .";
    else
        cout << "Cycle is NOT Present .";
    return 0;
}