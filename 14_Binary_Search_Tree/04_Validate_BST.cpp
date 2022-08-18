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

void InsertIntoBST(Node *&root, int d)
{
    if (!root)
        root = new Node(d);
    else
    {
        if (root->data < d)
            InsertIntoBST(root->right, d);
        else
            InsertIntoBST(root->left, d);
    }
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        InsertIntoBST(root, data);
        cin >> data;
    }
}

bool Solve(Node * root, int min ,int max)
{
    if (!root)
        return true;

     if(root->data <= max && root->data>= min)
    {
       bool check1 = Solve(root->left, min, root->data-1);
       bool check2 = Solve(root->right, root->data+1, max);
       if(check1 && check2)
           return true;
    }
    return false;
}

bool isValidBST(Node *root)
{
    int min = INT16_MIN;
    int max = INT16_MAX;

    return Solve(root, min , max);
}

// 13 3 4 12 14 10 5 1 8 2 7 9 11 6 18 -1

int main()
{
    Node *root = NULL;
 
    cout << "Enter the data to insert into BST : ";
    takeInput(root);

    
    cout << "LeveL Order Traversal : ";
    LevelOrderTraversal(root);
    cout << endl;

    if (isValidBST(root))
        cout << "BST hai wai !!" << endl;
        else 
        cout << "BST nahi hai wai !!" << endl;


    return 0;
}