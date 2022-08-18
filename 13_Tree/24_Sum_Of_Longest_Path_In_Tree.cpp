

#include <iostream>
#include <vector>
#include <map>
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

pair<int, int> Solve(Node *root)
{
    if (!root)
    return make_pair(0, 0);
    
    pair<int, int> left = Solve(root->left);
    pair<int, int> right = Solve(root->right);

    return make_pair(1 + max(left.first, right.first) , root->data + ((left.first >= right.first) ? left.second : right.second ));

}

// 4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1

int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    cout<<" Sum of Longest Path is : "<<Solve(root).second;

    return 0;
}