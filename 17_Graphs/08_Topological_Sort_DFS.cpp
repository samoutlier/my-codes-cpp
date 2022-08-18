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

// 6 7
// Topological Sort : 1 3 2 4 5 6

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
    stack<int> store;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            TopoLogicalSort(adjlist, i, store, visited);
        }
    }


   cout<<endl;
   cout<<"Topological Sort : ";
    while(!store.empty())
    {
        cout<<store.top()<<" ";
        store.pop();
    }
    cout<<endl;


    return 0;
}