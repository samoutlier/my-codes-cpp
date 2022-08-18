#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Note : Graoph is undirected

// 3 3
// 0 1
// 1 2
// 2 0

// ANS 
// 0 1 2 
// 1 0 2
// 2 1 0

// 4 3
// 1 2
// 0 3
// 2 3

//ANS
// 0 3 
// 1 2
// 2 1 3
// 3 0 2



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
            cin>>data;
            temp.push_back(data);
        }
        edges.push_back(temp);
    }

    // vector<vector<int>> ans(m);

    // for (int i = 0; i < m; i++)
    // {
    //     int u = edges[i][0];
    //     int v = edges[i][1];

    //     ans[u].push_back(v);
    //     ans[v].push_back(u);
    // }

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        for (int j = 0; j < edges[i].size(); j++)
        {   
            
            adj[i].push_back(edges[i][j]);
        }
    }


    for (auto i : adj)
    {   
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}