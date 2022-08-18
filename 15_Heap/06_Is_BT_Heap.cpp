#include <iostream>
#include <vector>
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
        Node *temp = q.front();
        q.pop();

        cout << endl
             << "Enter the Left Node for " << temp->data << " : ";
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << endl
             << "Enter the Right Node for " << temp->data << " : ";
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
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
        Node *temp = q.front();
        q.pop();

        if (!temp)
        {
            cout << endl;
            {
                if (!q.empty())
                    q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

bool isCBT(Node *root, int index, int n)
{
    if (!root)
        return true;
    if (index >= n)
        return false;

    if (isCBT(root->left, 2 * index + 1, n) && isCBT(root->right, 2 * index + 2, n))
    {
        return true;
    }
    return false;
}

bool isMaxOrder(Node *root)
{
    // Base Case
    if (!root)
        return true;

    // Leaf Node
    if (!root->right && !root->left)
        return true;

    // Both Child
    if (root->right && root->left)
    {
        if (root->data > root->left->data && root->data > root->right->data)
        {
            if (isMaxOrder(root->left) && isMaxOrder(root->right))
                return true;
        }
        return false;
    }

    // Left Child
    if (root->left)
    {
        return (root->data > root->left->data);
    }
}

int CountNodes(Node *root)
{
    if (!root)
        return 0;
    else
        return (1 + CountNodes(root->left) + CountNodes(root->right));
}

bool Is_BT_Heap(Node *root)
{
    int n = CountNodes(root);
    int index = 0;
    if (isCBT(root, index, n) && isMaxOrder(root))
        return true;
    return false;
}

// 1 3 5 7 11 17 20 15 19 4 1 -1 -1 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    cout << "Enter the Root : ";
    Node *root = NULL;

    root = BuildTree(root);

    cout << endl
         << "Level Order traversal : " << endl;
    LevelOrderTraversal(root);

    if (Is_BT_Heap(root))
        cout << "Given Binary tree is heap ." << endl;
    else
        cout << "Given Binary tree is NOT heap ." << endl;
    return 0;
}