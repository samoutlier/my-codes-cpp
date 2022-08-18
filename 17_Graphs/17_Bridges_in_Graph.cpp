#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

vector<vector<int>> edges;
unordered_map<int, list<int>> adjlist;

void CreateAdjlist(int e)
{
    for (int i = 0; i < e; i++)
    {
        adjlist[edges[i][0]].push_back(edges[i][1]);
        adjlist[edges[i][1]].push_back(edges[i][0]);
    }
}

void PrintBridges(int node, int parent, int timer, vector<int> &disc, vector<int> &low, vector<int> &visited)
{

    disc[node] = timer;
    low[node] = timer++;
    visited[node] = 1;

    for (auto it : adjlist[node])
    {
        if (it == parent)
            continue;
        if (!visited[it])
        {
            PrintBridges(it, node, timer, disc, low, visited);
            low[node] = min(low[node], low[it]);
            if (disc[node] < low[it])
                cout << node << " " << it << endl;
        }
        else
        {
            // Back Edge Case
            low[node] = min(low[node], disc[it]);
        }
    }
};

// 5 4 0 1 3 1 1 2 3 4
// Bridges : 
// 3 4
// 1 3
// 1 2
// 0 1
 
// 6 7
// 0 1 0 2 1 2 0 4 4 5 4 3 5 3
// Bridges : 
// 0 4

// 12 14
// 0 1 0 3 1 2 2 3 3 4 4 5 5 6 5 8 6 7 8 7 7 9 9 10 9 11 11 10
// Bridges : 
// 7 9
// 4 5
// 3 4


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
    vector<int> disc(n, -1);
    vector<int> low(n, INT8_MAX);
    vector<int> visited(n, 0);

    cout<<"Bridges : "<<endl;

    for (int i = 0; i < e; i++)
    {
        if(!visited[i])
        PrintBridges(i, -1, timer, disc, low, visited);
    }

    return 0;
}
