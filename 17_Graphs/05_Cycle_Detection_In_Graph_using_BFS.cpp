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
        adjlist[v].push_back(u);
    }
}

bool CycleDetection(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, unordered_map<int, int> &Parent, int node)
{
    queue<int> q;

    q.push(node);
    visited[node] = true;
    Parent[node] = -1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (auto i : adjlist[current])
        {
            // if (!visited[i])
            // {
            //     q.push(i);
            //     visited[i] = true;
            //     Parent[i] = current;
            // }
            // else if (Parent[i] == node || Parent[node] == -1)
            // {
            //     continue;
            // }
            // else
            //     return true;

            if (visited[i] && i != Parent[current])
                return true;
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                Parent[i] = current;
            }
        }
    }
    return false;
}

// 4 3
// 0 1
// 0 3
// 1 3

int main()
{
    vector<vector<int>> edges;
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
    unordered_map<int, list<int>> adjlist(n);

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
    unordered_map<int, int> Parent;

    bool ans = false;
    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {
            ans = ans || CycleDetection(adjlist, visited, Parent, i);
        }
        if (ans)
            break;
    }
    if (ans)
        cout << "Cycle is Present .";
    else
        cout << "Cycle is NOT Present .";

    return 0;
}