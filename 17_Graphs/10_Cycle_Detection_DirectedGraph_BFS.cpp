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

void TopoLogicalSort(unordered_map<int, list<int>> &adjlist, int node, stack<int> &store, unordered_map<int, bool> &visited)
{
    visited[node] = true;

    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            TopoLogicalSort(adjlist, i, store, visited);
        }
    }
    store.push(node);
}

// TC : O(N+E)
//  SC : O(2N)

// 5 5
// 1 2
// 1 3
// 2 5
// 3 5
// 5 4
// Topological Sort : 1 2 3 5 4

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

    // Storing INDEGREE
    vector<int> indegree(n + 1, 0);

    for (auto i : adjlist)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // BFS TOPOLOGICAL
    int count = 0;
    queue<int> q;

    // 0 Indegree wale ko q m push
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;
        
        for (auto i : adjlist[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

    cout << endl;
    if(count == n)
    cout<<"Cycle is NOT present .";
    else
    cout<<"Cycle is present .";

   
    return 0;
}
