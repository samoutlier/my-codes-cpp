#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool BellmanFord(vector<vector<int>> &edges, int n, int m, int src, int des, vector<int> &dist)
{

    dist[src] = 0;

    for (int i = 1; i < n-1; i++)
    {
        // traverse on each edge

        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + w) < dist[v]))
                dist[v] = dist[u] + w;
        }
    }

    // checking negative cycle

    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e9 && dist[u] + w < dist[v])
            return false;
    }

    return true;
};

//  3 3
// 1 3 2
// 1 2 2
// 2 3 -1

int main()
{

    int n, m, x, src, des;
    cout << "Enter Nodes and edges : ";
    cin >> n >> m;
    n++;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            cin >> x;
            temp.push_back(x);
        }

        edges.push_back(temp);
    }

    cout << "Enter the source : ";
    cin >> src;
    cout << "Enter the destination : ";
    cin >> des;

    vector<int> dist(n, 1e9);
    if (BellmanFord(edges, n, m, src, des, dist))
    {
        cout << "Shortest Dist from " << src << "->" << des << " is : " << dist[des];
    }
    else
        cout << "Negative Cycle is presnt, shortest distance can't  be determined";

    return 0;
}