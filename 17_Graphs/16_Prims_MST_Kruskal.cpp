#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

int n , e;

int FindParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = FindParent(parent, parent[node]);
}

void UnionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = FindParent(parent, u);
    v = FindParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }

    else
    {
        parent[u] = v;
        rank[u]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int PrimsMSTminCost(vector<vector<int>> &edges)
{
    vector<int> rank(n, 0);
    vector<int> parent(n, 0);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < e; i++)
    {
        int u = FindParent(parent, edges[i][0]);
        int v = FindParent(parent, edges[i][1]);

        if (u != v)
        {
            UnionSet(u, v, parent, rank);
            cost += edges[i][2];
        }
    }

    return cost;
}

// 5 15
// 1 2 21
// 1 4 16
// 2 1 12
// 2 3 13
// 2 4 18
// 2 5 15
// 3 2 13
// 3 5 17
// 4 1 16
// 4 2 18
// 4 5 19
// 5 1 18
// 5 2 15
// 5 3 17
// 5 4 19

// 5 14
// 1 2 2
// 1 4 6
// 2 1 2
// 2 3 3
// 2 4 8
// 2 5 5
// 3 2 3
// 3 5 7
// 4 1 6
// 4 2 8
// 4 5 9
// 5 2 5
// 5 3 7
// 5 4 9

int main()
{
    int u, v, w;
    cin >> n >> e;

    n++;
    vector<vector<int>> edges;

    cout << "Enter The Edges with distance : ";
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    cout << "Minimum Cost is : " << PrimsMSTminCost(edges);
    return 0;
}