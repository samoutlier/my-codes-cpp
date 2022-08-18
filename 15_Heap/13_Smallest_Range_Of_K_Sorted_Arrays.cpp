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

    // vector<vector<int>> input = {{2 , 4 , 5}, {5 , 6 , 7 }};
    vector<vector<int>> input = {{1, 1}, {9, 12}, {4, 9}};
    vector<int> ans;

    int start, end, mini, maxi = INT16_MIN;

    int k = input.size(), n = input[0].size();

    for (int i = 0; i < k; i++)
    {
        maxi = max(maxi, input[i][0]);
        Node *temp = new Node(input[i][0], i, 0);
        minheap.push(temp);
    }

    mini = minheap.top()->data;

    start = mini;
    end = maxi;

    // Step 2

    while (!minheap.empty())
    {
        Node *temp = minheap.top();
        minheap.pop();
        mini = temp->data;

        if ((maxi - mini) < (end - start))
        {
            start = mini;
            end = maxi;
        }

        if (temp->j < n - 1)
        {
            maxi = max(maxi, input[temp->i][temp->j + 1]);
            minheap.push(new Node(input[temp->i][temp->j + 1], temp->i, temp->j + 1));
        }
        else
            break;
    }

    cout << start << endl;
    cout << end << endl;
    cout << "The Smallest range is : " << end - start + 1;

    return 0;
}