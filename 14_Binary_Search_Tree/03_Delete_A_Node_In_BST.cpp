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

Node *MinVal(Node *root)
{
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }

    return temp;
}

Node *DeleteFromBST(Node *root, int value)
{
    // Base Case
    if (!root)
        return root;

    else if (root->data < value)
        root->right = DeleteFromBST(root->right, value);
    else if(root->data > value)
        root->left = DeleteFromBST(root->left, value);

    else 
    {
        // 0 Child Case :
        cout << "Deleteing : " << root->data << endl;

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 Child Case :
        //  Left Child Only
        else if (root->left && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Right Child Only
        else if (root->left == NULL && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            // 2 Child Case :
            int mini = MinVal(root->right)->data;
            root->data = mini;
            root->right = DeleteFromBST(root->right, mini);
        }
    }

    return root;
}

// 13 3 4 12 14 10 5 1 8 2 7 9 11 6 18 -1

int main()
{
    Node *root = NULL;
    int target;
    cout << "Enter the data to insert into BST : ";
    takeInput(root);

    cout << "Enter The Target : ";
    cin >> target;
    cout << "LeveL Order Traversal : ";
    LevelOrderTraversal(root);
    cout << endl;

    root = DeleteFromBST(root, target);

    cout << endl;
    LevelOrderTraversal(root);
    cout << endl;

    return 0;
}