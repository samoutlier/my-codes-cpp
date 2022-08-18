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

vector<int> Vertical_Traversal(Node *root)
{
    map<int, map<int, vector<int>>> Nodes;
    queue<pair<Node *, pair<int, int>>> q;

    vector<int> ans;

    if (!root)
        return ans;

    // pair<Node *, pair<int, int>> p;
    // p.first = root;
    // p.second = make_pair(0, 0);

    q.push(make_pair(root, make_pair(0,0)));

    
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int distance = temp.second.first;
        int level = temp.second.second;

        Nodes[distance][level].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(distance - 1, level + 1)));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(distance + 1, level + 1)));
    }

    for (auto i : Nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

//Input : 
// 1 2 4 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9  -1 -1 -1 -1 

//Output:
//8 4 2 9 10 12 1 5 6 3 11 13 14 7 15

int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    vector<int> ans = Vertical_Traversal(root);

    cout << endl;
    cout << "Vertical Traversal : ";

    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}