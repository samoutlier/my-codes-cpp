#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
        this->next = NULL;
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

void MorrisTraversal(Node *root)
{
    Node *curr = root;

    while (curr)
    {

        if (curr->left)
        {
            Node *temp = curr->left;
            while (temp->right && temp->right != curr)
            {
                temp = temp->right;
            }

            if (temp->right)
            {
                temp->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
            else
            {
                temp->right = curr;
                curr = temp;
            }
        }
        else
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

void InOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

// 1 2 3 4 5 -1 6 -1 7 -1 -1 -1 -1 -1 -1
// 4 7 2 5 1 3 6

// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
// 4 2 5 1 3

int main()
{
    cout << "Enter the Root : ";
    Node *root = NULL;

    root = BuildTree(root);

    cout << endl
         << "Level Order traversal : " << endl;
    LevelOrderTraversal(root);

    cout << endl;
    InOrderTraversal(root);
    cout << endl;
    // MorrisTraversal(root);

    return 0;
}