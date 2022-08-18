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
    map<Node *, bool> visited;

    while (curr)
    {
        // to set predecessor of left part to curr
        if (curr->left && !visited[curr->left])
        {
            Node *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            temp->right = curr;
            curr = curr->left;
        }

        // to set predecessor of left part to NULL
        else if (curr->left)
        {
            Node *temp = curr->left;
            while (temp->right != curr)
            {
                temp = temp->right;
            }
            temp->right = NULL;
            visited[curr] = true;
            cout << curr->data<<" ";
            curr = curr->right;
        }

        //to print curr and go to right part
        else
        {
            visited[curr] = true;
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

// 1 2 5 3 4 -1 6 -1 -1 -1 7 -1 -1 -1 8 -1 9 -1 -1
// 3 2 4 7 8 9 1 5 6

int main()
{
    cout << "Enter the Root : ";
    Node *root = NULL;

    root = BuildTree(root);

    cout << endl
         << "Level Order traversal : " << endl;
    LevelOrderTraversal(root);

    cout << endl;
    cout<<"Morris Traversal : ";
    MorrisTraversal(root);
    cout << endl;
    cout<<"Inorder Traversal : ";
    
    InOrderTraversal(root);

    return 0;
}