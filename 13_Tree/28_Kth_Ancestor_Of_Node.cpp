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

void Solve(Node *&root, Node *&node, int k, vector<Node *> path, Node *&ans)
{
    if (!root)
        return;

    if (root == node)
    {
        path.push_back(root);
        cout << "Found" << endl;
        while (!path.empty() && k > 0)
        {
            cout << "Popped : " << path.back()->data << endl;
            path.pop_back();
            k--;
        }
        if (path.empty())
            ans = NULL;
        else
            ans = path.back();
    }

    path.push_back(root);

    Solve(root->left, node, k, path, ans);
    Solve(root->right, node, k, path, ans);
};

Node *Kth_Ancestor(Node *&root, Node *node, int k)
{   
    //As k >1
    if(root == node)
    return NULL;


    vector<Node *> path;
    int temp = k;
    Node *ans = NULL;
    Solve(root, node, temp, path, ans);
    return ans;
}

//1 2 3 4 5 -1 -1 -1 -1 -1 -1
//k = 2
// Ans 1

int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    int k;
    cout << "Enter The value of k ";
    cin >> k;

    Node *ans = Kth_Ancestor(root, root->left->left, k);

    if (!ans)
        cout << " Element doesn't have " << k << "th ancestor !!";
    else
        cout << ans->data;

    return 0;
}