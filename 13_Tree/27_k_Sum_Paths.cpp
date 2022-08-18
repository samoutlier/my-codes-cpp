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

void Solve (Node * root, int k, int &count , vector<int> path)
{
    if(!root)
    return ;

    path.push_back(root->data);
    
    Solve(root->left , k , count, path);
    Solve(root->right , k , count, path);
    
    int size = path.size(), sum = 0;
    for (int i = size-1  ; i>=0 ; i--)
    {
        sum+= path[i];

        if(sum == k)
        count++;
    } 

}

int K_Sum_To_Path(Node *&root, int k)
{   
    int count = 0;
    vector<int> path;

    Solve(root, k , count, path);

    return count;

}

// 1 2 3 6 -1 4 5 -1 8 -1 -1 21 -1 -1 -1 -1

int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    int k;
    cout << " Enter The value of k : ";
    cin >> k;
    cout << K_Sum_To_Path(root, k);

     return 0;
}