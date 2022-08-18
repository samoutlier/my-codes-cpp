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
        adjlist[v].push_back(u);
    }
}

void BFSTraversal(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, int node)
{
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (auto i : adjlist[current])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// Note : Graoph is undirected
// 3 3
// 0 1
// 1 2
// 2 0

// 4 3
// 1 2
// 0 3
// 2 3

// 4 3
// 0 1
// 0 3
// 1 3

// 8 9
// 1 2
// 1 3
// 1 4
// 2 5
// 3 8
// 5 8
// 4 6
// 6 7
// 7 8

int main()
{
    vector<vector<int>> edges;
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
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            BFSTraversal(adjlist, visited, i);
    }

    return 0;
}