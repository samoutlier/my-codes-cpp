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

void CreateMapping(int *in, map<int, int> &m, int n)
{
    for (int i = 0; i < n; i++)
    {
        m[in[i]] = i;
    }
}

Node *Solve(int *in, int *pre, map<int, int> &m, int &index, int instart, int inend, int n)
{
    if (instart > inend || index >= n)
        return NULL;

    int element = pre[index++];

    Node *root = new Node(element);
    int pos = m[element];

    root->left = Solve(in, pre, m, index, instart, pos - 1, n);
    root->right = Solve(in, pre, m, index, pos + 1, inend, n);

    return root;
}

void PostOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

Node *BuildTree(int *in, int *pre, int n)
{
    int index = 0;
    map<int, int> m;
    CreateMapping(in, m, n);

    return Solve(in, pre, m, index, 0, n - 1, n);
}

int main()
{
    int n;
    cout << " Enter The size Of Tree : ";
    cin >> n;

    int *pre = new int[n];
    int *in = new int[n];

    cout << "Enter The InOrder Traversal : ";

    for (int i = 0; i < n; i++)
        cin >> in[i];

    cout << "Enter The pre Traversal : ";

    for (int i = 0; i < n; i++)
        cin >> pre[i];

    Node *root = BuildTree(in, pre, n);

    LevelOrderTraversal(root);
    PostOrderTraversal(root);

    return 0;
}