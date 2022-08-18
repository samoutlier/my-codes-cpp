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

pair<int, int> Solve(Node *root, int element)
{
    if (!root)
        return make_pair(-1, -1);

    if (root->data == element)
    {
        pair<int, int> ans;
        ans.first = -1;
        ans.second = -1;
        if (root->left)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            ans.first = temp->data;
        }

        if (root->right)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            ans.second = temp->data;
        }

        return ans;
    }
    else if (root->data < element)
    {
        return Solve(root->right, element);
    }
    else
    {
        return Solve(root->left, element);
    }
}

// 13 3 4 12 14 10 5 1 8 2 7 9 11 6 18 -1

int main()
{
    Node *root = NULL;
    int e;

    cout << "Enter the data to insert into BST : ";
    takeInput(root);
    cout << "LeveL Order Traversal : ";
    LevelOrderTraversal(root);
    cout << endl;
    cout << "Enter The Elemnent to find its predecessor ans successor : ";
    cin >> e;

    pair<int, int> ans = Solve(root, e);
    cout << "Inorder Predecessor of " << e << " is : " << ans.first << endl;
    cout << "Inorder Successor of " << e << " is : " << ans.second;

    return 0;
}