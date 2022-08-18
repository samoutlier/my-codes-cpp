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

// Left Part Traversal

void LeftPartTraversal(Node *&root, vector<int> &result)
{

    if (!root || (root->left == NULL && root->right == NULL))
        return;

    result.push_back(root->data);
    if (root->left)
        LeftPartTraversal(root->left, result);
    else
        LeftPartTraversal(root->right, result);
}

// Right Part Traversal

void RightPartTraversal(Node *&root, vector<int> &result)
{

    if (!root || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        RightPartTraversal(root->right, result);
    else
        RightPartTraversal(root->left, result);
    result.push_back(root->data);
}

// Leaf Part Traversal

void LeafPartTraversal(Node *&root, vector<int> &result)
{

    if (!root)
        return;
    else if (root->left == NULL && root->right == NULL)
    {
        result.push_back(root->data);
        return;
    }
    else
    {
        if (root->left)
            LeafPartTraversal(root->left, result);
        if (root->right)
            LeafPartTraversal(root->right, result);
    }
}

vector<int> Boundary_Traversal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    LeftPartTraversal(root, ans);

    LeafPartTraversal(root, ans);

    RightPartTraversal(root->right, ans);

    return ans;
}

// 1 2 4 3 5 -1 7 -1 -1 6 8 -1 9 -1 -1 -1 -1 10 11 -1 -1 -1 -1

int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    vector<int> ans = Boundary_Traversal(root);

    cout << endl;
    cout << "Boundary Traversal : ";
    // for(int i =0 ; i< ans.size() ; i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}