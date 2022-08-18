#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

vector<vector<int>> edges;
unordered_map<int, list<int>> adjlist;

void CreateAdjlist(int e)
{
    for (int i = 0; i < e; i++)
    {
        adjlist[edges[i][0]].push_back(edges[i][1]);
    }
}

void dfs(int node, stack<int> &store, vector<int> &visited)
{
    visited[node] = 1;

    for (auto i : adjlist[node])
    {
        if (!visited[i])
            dfs(i, store, visited);
    }

    store.push(node);
}

void StronglyconnectedComps(unordered_map<int, list<int>> &transposelist, int node, vector<int> &visited)
{
    visited[node] = 0;
    cout << " " << node;

    for (auto i : transposelist[node])
    {
        if (visited[i])
            StronglyconnectedComps(transposelist, i, visited);
    }
}

// 5 5
// 0 1 1 2 2 0 1 3 3 4
// 3 ->> 4 
// 2 ->> 0
// 1 ->> 2 3
// 0 ->> 1
// Strongly Connected Components :
//  0 2 1
//  3
//  4

// 5 6
// 0 1
// 1 2
// 1 4
// 2 3
// 3 2
// 4 0

// TC : O(N+E)

int main()
{
    int u, v, w, n, e, timer = 0;
    cout << "Enter The Input : ";
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        edges.push_back({u, v});
    }

    CreateAdjlist(e);

    for (auto i : adjlist)
    {
        cout << i.first << " ->> ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // Storing Topological Sort
    stack<int> store;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, store, visited);
    }

    // Transposing Graph
    unordered_map<int, list<int>> transposelist;

    for (auto i : adjlist)
    {
        for (auto j : i.second)
        {
            transposelist[j].push_back(i.first);
        }
    }

    cout << "Strongly Connected Components : " << endl;
    
    while(!store.empty())
    {
        int top = store.top();
        store.pop();

        if (visited[top])
        {
            StronglyconnectedComps(transposelist, top, visited);
            cout << endl;
        }
    }
    return 0;
}
