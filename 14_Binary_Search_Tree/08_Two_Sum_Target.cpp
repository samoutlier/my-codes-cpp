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


void InOrderTraversal(Node * &root, vector<int> &ans)
{
     if(root == NULL)
     return ;

     InOrderTraversal(root->left, ans);
     ans.push_back(root->data);
     InOrderTraversal(root->right, ans);

}


bool findTarget(Node *root, int target)
{
    vector<int> ans;
    InOrderTraversal(root, ans);
    int start = 0,sum ;
    int end = ans.size()-1;

    while(start<end)
    {
        sum = ans[start]+ans[end];
        if(sum ==target)
        return true;

        else if(sum <target)
        start++;
        else
        end--;
    }
    return false;
    
}

// 13 3 4 12 14 10 5 1 8 2 7 9 11 6 18 -1

int main()
{
    Node *root = NULL;
    int target;
    cout << "Enter the data to insert into BST : ";
    takeInput(root);

    cout << "Enter The target : ";
    cin >> target;
    cout << "LeveL Order Traversal : ";
    LevelOrderTraversal(root);
    cout << endl;

    if (findTarget(root, target))
        cout << target << " present hai wai !!" << endl;
    else
        cout << target << " present nahh hai wai !!" << endl;
    return 0;
}