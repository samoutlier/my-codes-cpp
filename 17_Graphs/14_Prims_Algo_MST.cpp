#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

class Graph
{
    int n, e;
    unordered_map<int, list<pair<int, int>>> adjlist;

public:
    Graph(int n, int e)
    {
        this->n = n ;
        this->e = e;
    }

    void AddEdge(int u, int v, int w)
    {
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    int PrimsMSTminCost(int source)
    {
        vector<int> dist(n + 1, INT16_MAX);
        vector<bool> inMST(n + 1, false);
        vector<int> parent(n + 1, -1);

        dist[source] = 0;

        for (int k = 1; k <= n; k++)
        {

            int mini = INT16_MAX-1;
            int x;

            for (int i = 1; i <= n; i++)
            {
                if (!inMST[i] && dist[i] < mini)
                {
                    mini = dist[i];
                    x = i;
                }
            }

            inMST[x] = true;

            for (auto it : adjlist[x])
            {
                int v = it.first;
                int w = it.second;

                if (!inMST[v] && dist[v] > w)
                {
                    parent[v] = x;
                    dist[v] = w;
                }
            }
        }

        vector<pair<pair<int, int>, int>> result;

        for (int i = 2; i <= n; i++)
        {
            pair<int, int> p = make_pair(parent[i], i);
            result.push_back(make_pair(p, dist[i]));
        }

        int cost = 0;
        for (auto i : result)
        {
            cost += i.second;
            cout << i.first.first << " " << i.first.second << " " << i.second << endl;
        }

        return cost;
    }
};

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
    int n, e, source;
    int u, v, w;
    cin >> n >> e;
    Graph g(n, e);
    
    cout << "Enter The Edges with distance : ";
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w;
        g.AddEdge(u, v, w);
    }

    cout << "Enter The Source : ";
    cin >> source;
    cout << "Minimum Cost is : " << g.PrimsMSTminCost(source);
    return 0;
}