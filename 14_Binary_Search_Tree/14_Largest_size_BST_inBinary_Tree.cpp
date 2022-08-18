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
    cout << endl;
}

pair<int, bool> LargestBST(Node *root)
{
    if (!root)
        return make_pair(0, true);
    if (!root->left && !root->right)
    {
        return make_pair(1, true);
    }

    if (root->right && root->left)
    {
        pair<int, bool> left = LargestBST(root->left);
        pair<int, bool> right = LargestBST(root->right);

        if (left.second && right.second)
        {
            if (root->left->data < root->data && root->right->data > root->data)
            {
                return make_pair(left.first + right.first + 1, true);
            }
        }
        
            return make_pair(max(right.first, left.first), false);
    }

    if (root->left)
    {
        pair<int, bool> p = LargestBST(root->left);
        if (p.second)
        {
            if (root->data > root->left->data)
            {
                return make_pair(p.first + 1, true);
            }
            else
            {
                return make_pair(p.first, false);
            }
        }
    }

    if (root->right)
    {
        pair<int, bool> p = LargestBST(root->right);
        if (p.second)
        {
            if (root->data < root->right->data)
            {
                return make_pair(p.first + 1, true);
            }
            else
            {
                return make_pair(p.first, false);
            }
        }
    }
}

// 1 3 5 7 11 17 20 15 19 4 1 -1 -1 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 2

// 5 4 6 3 -1 -1 7 2 -1 -1 8 1 -1 -1 -1 -1 -1
// 8

// 5 2 4 1 3 -1 -1 -1 -1 -1 -1 
// 3

// 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
// 2


int main()
{
    cout << "Enter the Root : ";
    Node *root = NULL;

    root = BuildTree(root);

    cout << endl
         << "Level Order traversal : " << endl;
    LevelOrderTraversal(root);

    cout << "Largest Size Of BST is : " << LargestBST(root).first;
    return 0;
}