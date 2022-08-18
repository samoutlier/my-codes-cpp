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

void InOrderTraversal(Node *&root, vector<Node *> &inorder)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left, inorder);
    inorder.push_back(root);
    InOrderTraversal(root->right, inorder);
    root->left = NULL;
    root->right = NULL;
}

void PreOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
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

void InsertIntoBST(Node *&root, int d)
{
    if (!root)
        root = new Node(d);
    else
    {
        if (root->data < d)
            InsertIntoBST(root->right, d);
        else
            InsertIntoBST(root->left, d);
    }
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        InsertIntoBST(root, data);
        cin >> data;
    }
}

void FillPReORder(vector<Node *> &v, Node *root, int &index, int position)
{
    int n = v.size();
    if (index >= n)
        return;
    if (position * 2 + 1 < n)
    {
        cout << "Pushed : " << endl;
        root->left = v[index++];
        FillPReORder(v, root->left, index, position * 2 + 1);
    }
    if (index >= n)
        return;
    if (position * 2 + 2 < n)
    {
        {
            cout << "Pushed : " << endl;
            root->right = v[index++];
            FillPReORder(v, root->right, index, position * 2 + 2);
        }
    }
}

Node *BST_To_MIn_Heap(Node *root)
{

    if (!root || (!root->left && !root->right))
        return root;
    vector<Node *> inorder;
    InOrderTraversal(root, inorder);

    int i = 0, n = inorder.size(), pos = 0;
    int index = 1;

    root = inorder[0];

    FillPReORder(inorder, root, index, pos);
    return root;
}

// 4 2 6 1 3 5 7 -1

int main()
{
    Node *root = NULL;

    cout << "Enter the data to insert into BST : ";
    takeInput(root);

    cout << "Level Order traversal : ";
    LevelOrderTraversal(root);

    root = BST_To_MIn_Heap(root);

    cout << endl;
    LevelOrderTraversal(root);
    return 0;
}