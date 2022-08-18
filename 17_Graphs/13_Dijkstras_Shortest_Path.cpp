#include <iostream>
#include <vector>
#include <set>
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
        pair<int, int> p1 = make_pair(v, w);
        pair<int, int> p2 = make_pair(u, w);
        adjlist[u].push_back(p1);
        adjlist[v].push_back(p2);
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

    void Shortest_Path(int source, vector<int> dist)
    {
        dist[source] = 0;
        set<pair<int, int>> s;

        s.insert(make_pair(0, source));

        while (!s.empty())
        {
            auto top = *(s.begin());

            s.erase(s.begin());

            for (auto i : adjlist[top.second])
            {
                if (dist[i.first] > top.first + i.second)
                {
                    auto record = s.find(make_pair(dist[i.first], i.first));

                    if(record != s.end())
                    {
                        s.erase(record);
                    }

                    dist[i.first] = top.first + i.second;
                    s.insert(make_pair(top.first + i.second, i.first));
                }
            }
        }

        for (int i = 0; i < dist.size(); i++)
        {
            cout << "SD " << source << "->" << i << " is : ";
            if (dist[i] == INT32_MAX)
                cout << "INFINITE" << endl;
            else
                cout << dist[i] << endl;
        }
    }
};

// 4 5
// 0 1 5
// 0 2 8
// 1 2 9
// 1 3 2
// 2 3 6
// 0
// ans : 0 5 8 7

// 5 7
// 0 1 7
// 0 2 1
// 0 3 2
// 1 2 3
// 1 3 5
// 1 4 1
// 3 4 7
// 0
// ans : 0 4 1 2 5

// 5 7
// 0 1 7
// 0 2 3
// 1 2 1
// 1 3 2
// 1 4 6
// 2 3 4
// 3 4 4
// 0
// ans : 0 4 3 6 10

int main()
{

    Graph g;
    int n, m, u, v, w, source;
    cout << "Enter The Number of Nodes And Edges : " << endl;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    // Printing Adjacent List
    g.PrintAdjacentList();

    vector<int> dist(n, INT32_MAX);
    cout << endl
         << "Enter Source : ";
    cin >> source;

    g.Shortest_Path(source, dist);
    return 0;
}