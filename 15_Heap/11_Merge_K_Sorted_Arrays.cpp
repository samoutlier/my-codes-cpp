#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int i, j, data;

    Node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

int main()
{
    priority_queue<Node *, vector<Node *>, compare> minheap;

    vector<vector<int>> input = {{2 , 5 , 10}, {1 , 8 , 20 } , {-2 , 0 , 30}};
    vector<int> ans;

    int data = 0;

    int k;
    cin>>k;

    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(input[i][0], i, 0);
        minheap.push(temp);
    }

    // Step 2

    while (!minheap.empty())
    {
        ans.push_back(minheap.top()->data);
        int row = minheap.top()->i;
        int col = minheap.top()->j;

        minheap.pop();
        if(col < input[0].size()-1)
        {
            Node * temp = new Node (input[row][col+1], row, col+1);
            minheap.push(temp);
        }
    }

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}