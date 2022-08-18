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
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new Node(data);

    cout << "Enter data For Inserting in left of " << data << " : " << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data For Inserting in right of " << data << " : " << endl;
    root->right = BuildTree(root->right);

    return root;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

void LevelOrderTraversal(Node *root, int level)
{   
    if(!root)
    return ;

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

int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root, 0);
    return 0;
}