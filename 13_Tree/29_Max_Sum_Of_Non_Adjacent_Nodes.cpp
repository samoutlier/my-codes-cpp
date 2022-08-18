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

pair<int, int> MaxSumOFNonAdjacentNodes(Node * root )
{
    if(!root)
    return (make_pair(0,0));

    pair<int, int> left = MaxSumOFNonAdjacentNodes(root->left);
    pair<int, int> right = MaxSumOFNonAdjacentNodes(root->right);

    return (make_pair(left.second + right.second , left.first + right.first + root->data)) ;
}

// 1 2 3 1 -1 4 5 -1 -1 -1 -1 -1 -1
// 11


//1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
//16


int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    pair<int, int> ans = MaxSumOFNonAdjacentNodes(root);

    cout<<endl<<"Maximum Sum Of Non Adjacent Nodes is : "<<max(ans.first, ans.second);


    return 0;
}