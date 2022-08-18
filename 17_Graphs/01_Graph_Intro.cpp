#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<T>> adj;

public:
    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);

        if (!direction)
            adj[v].push_back(u);
    }
  
    void PrintArray(void)
    {
        for (auto i : adj)
        {
            cout << i.first << " ->> ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph<int> g ;

    // g.addEdge(0,1,false);
    // g.addEdge(1,2,false);
    // g.addEdge(2,3,false);
    // g.addEdge(3,4,false);
    // g.addEdge(3,1,false);
    // g.addEdge(0,4,false);

    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 1, false);
    g.addEdge(3, 4, false);
    g.addEdge(0, 4, false);

    g.PrintArray();
    return 0;
}