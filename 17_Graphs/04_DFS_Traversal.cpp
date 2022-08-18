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

void DFSTraversal(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &temp, int node)
{

    visited[node] = true;
    temp.push_back(node);

    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            DFSTraversal(adjlist, visited, temp, i);
        }
    }
}

// 9 7
// 0 1
// 0 2
// 0 5
// 3 6
// 7 4
// 4 8
// 7 8

// Printing : 0 1 2 5
// Printing : 3 6
// Printing : 4 7 8

int main()
{
    vector<vector<int>> edges, ans;
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

    // BFS TRAVERSAL
    unordered_map<int, bool> visited;
    int node = 0;
    cout << "BFS Traversal from : ";

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFSTraversal(adjlist, visited, temp, i);
            ans.push_back(temp);
        }
        temp.clear();
    }

    for (auto i : ans)
    {
        cout << endl
             << "Printing : ";
        for (auto j : i)
        {
            cout << j << " ";
        }
    }

    return 0;
}