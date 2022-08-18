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

Node *NodeToParentMap(Node *root, map<Node *, Node *> &ParentNode, int target)
{
    Node *ans = NULL;
    queue<Node *> q;
    if (root->data == target)
        ans = root;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->data == target)
        {
            ans = temp;
        }

        if (temp->left)
        {
            ParentNode[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            ParentNode[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return ans;
}

int BurnTreeTime(Node *root, int target)
{
    map<Node *, Node *> ParentNode;
    map<Node *, bool> visited;
    queue<Node *> q;

    // Storing Parent Node Address for each  node
    ParentNode[root] = NULL;
    Node *t = NodeToParentMap(root, ParentNode, target);
    cout << endl
         << t->data << endl;

    int time = 0;
    q.push(t);
    visited[t] = true;

    while (!q.empty())
    {
        int size = q.size();

        bool check = false;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
                check = true;
            }
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
                check = true;
            }
            if (ParentNode[temp] && !visited[ParentNode[temp]])
            {
                q.push(ParentNode[temp]);
                visited[ParentNode[temp]] = true;
                check = true;
            }
        }

        if (check)
            time++;
    }

    
    return time;
}

// 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
// 7



int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;
    int target;
    cout << "Enter The target : " << endl;
    cin >> target;

    cout << "Minimum time to burn tree is : " << BurnTreeTime(root, target);
    return 0;
}