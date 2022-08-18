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

Node *Solve(int *in, int *post, map<int, int> &m, int &index, int instart, int inend, int n)
{
    if (instart > inend || index < 0)
        return NULL;

    int element = post[index--];

    Node *root = new Node(element);
    int pos = m[element];

    root->right = Solve(in, post, m, index, pos + 1, inend, n);
    root->left = Solve(in, post, m, index, instart, pos - 1, n);

    return root;
}

void PreOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

Node *BuildTree(int *in, int *post, int n)
{
    int index = n - 1;
    map<int, int> m;
    CreateMapping(in, m, n);

    return Solve(in, post, m, index, 0, n - 1, n);
}

// Input:
// N = 6
// PostOrder[] = {3 1 4 0 5 2}
// Postorder[] = {0 1 3 4 2 5}
// Output: 3 4 1 5 2 0
// Explanation: The tree will look like
//        0
//     /     \
//    1       2
//  /   \    /
// 3    4   5

int main()
{
    int n;
    cout << " Enter The size Of Tree : ";
    cin >> n;

    int *in = new int[n];
    int *post = new int[n];

    cout << "Enter The InOrder Traversal : ";

    for (int i = 0; i < n; i++)
        cin >> in[i];

    cout << "Enter The PostOrder Traversal : ";

    for (int i = 0; i < n; i++)
        cin >> post[i];

    Node *root = BuildTree(in, post, n);

    LevelOrderTraversal(root);
    PreOrderTraversal(root);

    return 0;
}