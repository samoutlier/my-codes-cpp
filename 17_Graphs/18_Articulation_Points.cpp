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

void PrintBridges(int node, int parent, int timer, vector<int> &disc, vector<int> &low, vector<int> &visited, vector<int> &ans)
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
            PrintBridges(it, node, timer, disc, low, visited, ans);
            low[node] = min(low[node], low[it]);

            //Checking AP point condition
            if (low[it] >= disc[node] && parent != -1)
                ans.push_back(node);
        }
        else
        {
            // Back Edge Case
            low[node] = min(low[node], disc[it]);
        }
    }

    if(adjlist[node].size() >1 && parent == -1)
    ans.push_back(node);
};

// 5 6
// 1 0 0 4 1 4 2 3 2 4 3 4
// Articulation Points : 4 

// 6 7
// 0 1 0 2 1 2 0 4 4 5 4 3 5 3
// Articulation Points : 4 0

// 12 14
// 0 1 0 3 1 2 2 3 3 4 4 5 5 6 5 8 6 7 8 7 7 9 9 10 9 11 11 10
// Articulation Points : 9 7 5 4 3 0 

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
    vector<int> ans;
  
    for (int i = 0; i < e; i++)
    {
        if(!visited[i])
        PrintBridges(i, -1, timer, disc, low, visited, ans); 
    }
     
     cout<<"Articulation Points : ";
    for(auto i : ans)
    {
        cout<<i<<" ";
    }

    return 0;
}
