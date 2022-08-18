

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *BuildTree(Node *root)
{
    int data, leftdata, rightdata;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new Node(data);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        cout << endl
             << "Enter the Left Node for " << frontNode->data << " : ";
        cin >> leftdata;

        if (leftdata != -1)
        {
            frontNode->left = new Node(leftdata);
            q.push(frontNode->left);
        }

        cout << endl
             << "Enter the Right Node for " << frontNode->data << " : ";
        cin >> rightdata;

        if (rightdata != -1)
        {
            frontNode->right = new Node(rightdata);
            q.push(frontNode->right);
        }
    }

    return root;
}

void LevelOrderTraversal(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (!frontNode)
        {
            cout << endl;
            {
                if (!q.empty())
                    q.push(NULL);
            }
        }
        else
        {

            cout << frontNode->data << " ";
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}

void Solve(Node *&root, int d, map<int, vector<int>> &Nodes)
{
    if (!root)
        return;

    Nodes[d].push_back(root->data);

    if (root->left)
        Solve(root->left, d + 1, Nodes);
    if (root->right)
        Solve(root->right, d, Nodes);
}

vector<int> Diagonal_Traverse(Node *&root)
{
    map<int, vector<int>> Nodes;
    vector<int> ans;

    if (!root)
        return ans;

    Solve(root, 0, Nodes);
    for (auto i : Nodes)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }

    return ans;
}

// Input :
//  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

// Output:
// 1 2 4 8

// input and output
// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// 8 10 14 3 6 7 13 1 4
int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    vector<int> ans;
    int level = 0;
    ans = Diagonal_Traverse(root);

    cout << endl;
    cout << "Diagonal Traversal : ";

    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}