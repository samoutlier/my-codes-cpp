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

vector<int> ZigZagTraversal(Node *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<Node *> q;
    q.push(root);

    bool LeftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // Level processing i.e. till queue is empty
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            int index = LeftToRight ? i : size - i - 1;

            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }

        // Changing Direction
        LeftToRight = !LeftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

// 7 9 7 8 8 6 -1 10 9 -1 -1 -1 -1 -1 -1  -1 -1

int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    vector<int> ans = ZigZagTraversal(root);

    cout << endl;
    cout << "ZigZagtraversal : ";
    // for(int i =0 ; i< ans.size() ; i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}