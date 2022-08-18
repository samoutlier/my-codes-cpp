#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addEdge(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        adjlist[u].push_back(p);
    }

    void PrintAdjacentList(void)
    {

        for (auto i : adjlist)
        {
            cout << i.first << " : ";

            for (auto j : i.second)
            {
                cout << " (" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }

    void dfsTopological(int node, unordered_map<int, bool> &visited, stack<int> &store)
    {

        visited[node] = true;

        for (auto j : adjlist[node])
        {
            if (!visited[j.first])
                dfsTopological(j.first, visited, store);
        }

        store.push(node);
    }

    void TopologicalTraversal(stack<int> store)
    {
        cout << "Topological Sort : ";
        while (!store.empty())
        {
            cout << store.top() << " ";
            store.pop();
        }
        cout << endl;
    }

    void Shortest_Path(int source, vector<int> dist, stack<int> store)
    {
        dist[source] = 0;

        while (!store.empty())
        {
            int curr = store.top();
            store.pop();
            if (dist[curr] != INT32_MAX)
            {
                for (auto i : adjlist[curr])
                {
                    if (dist[i.first] > dist[curr] + i.second)
                        dist[i.first] = dist[curr] + i.second;
                }
            }
        }

        for (int i = 0; i < dist.size(); i++)
        {
            cout << "SD " << source << "->"<<i<<" is : ";
            if(dist[i] == INT32_MAX)
            cout<<"INFINITE"<<endl;
            else
            cout << dist[i]<<endl;
        }
    }
};

int main()
{

    Graph g;

    // Creating Adjacent List
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.PrintAdjacentList();

    // Topological Sort
    int n = 6;
    stack<int> store;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            g.dfsTopological(i, visited, store);
    }

    // Topological Traversal
    g.TopologicalTraversal(store);

    vector<int> dist(n, INT32_MAX);

    g.Shortest_Path(3, dist, store);
    return 0;
}