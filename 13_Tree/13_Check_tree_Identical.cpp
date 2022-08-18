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

Node *BuildTree(Node *root1)
{
    int data, leftdata, rightdata;
    cin >> data;

    if (data == -1)
        return NULL;

    root1 = new Node(data);

    queue<Node *> q;
    q.push(root1);

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

    return root1;
}

void LevelOrderTraversal(Node *root1)
{
    if (!root1)
        return;
    queue<Node *> q;
    q.push(root1);
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

bool isIdentical(Node *&root1, Node * &root2)
{
    if(root1 == NULL && root2 == NULL)
    return true;

    if(root1 == NULL || root2 == NULL)
    return false;

    if(root1->data == root2->data)
    {
        bool check1 = isIdentical(root1->left , root2->left);
        bool check2 = isIdentical(root1->right , root2->right);
        
        if(check1 && check2)
        return true;
    }

    return false;
}

// 1 3 5 7 11 17 20 15 19 4 1 -1 -1 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    cout << "Enter the Root 1 : ";
    Node *root1 = NULL;

    root1 = BuildTree(root1);
    
    cout<<endl;
    cout << "Enter the Root 2 : ";
    Node *root2 = NULL;

    root2 = BuildTree(root2);

    cout << endl
         << "Level Order traversal of Root 1 : " << endl;
    LevelOrderTraversal(root1);
     
    cout << endl
         << "Level Order traversal of Root 2 : " << endl;
    LevelOrderTraversal(root2);
    cout<<endl;

    if (isIdentical(root1, root2))
        cout << "Binary Tree are IDENTICAL !! ";
    else
        cout << "Binary Tree is NOT Identical !! ";

    return 0;
}

// 1 2 3 -1 -1 4 -1 -1 -1