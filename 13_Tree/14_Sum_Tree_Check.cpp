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

pair<bool, int> areSumBinaryTrees(Node *&root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if(root->left == NULL && root->right == NULL )
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = areSumBinaryTrees(root->left);
    pair<bool, int> right = areSumBinaryTrees(root->right);
    
    int sum =  left.second + right.second ;

    pair<bool, int> ans;

    if (left.first && right.first && sum ==  root->data)
        ans = make_pair(true, 2 * sum );
    else
        ans = make_pair(false, 2 * sum);

    return ans;
}

// 80 20 20 10 10 10 10 -1 -1 -1 -1 -1 -1 -1 -1 

int main()
{
    cout << "Enter the Root : ";
    Node *root = NULL;

    root = BuildTree(root);

    cout << endl
         << "Level Order traversal : " << endl;
    LevelOrderTraversal(root);

    if (areSumBinaryTrees(root).first)
        cout << "Binary Tree is a SUM Tree !! ";
    else
        cout << "Binary Tree is NOT a Sum Tree !! ";

    return 0;
}