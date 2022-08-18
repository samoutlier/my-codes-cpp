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
void Solve(Node *root, int k, int &index, int &ans)
{

}

void InOrderTraversal(Node * root, vector<Node *> &ans)
{
     if(root == NULL)
     return ;

     InOrderTraversal(root->left, ans);
     ans.push_back(root);
     InOrderTraversal(root->right, ans);

}

Node * flatten (Node * root)
{    
    if(!root)
    return root;
    vector<Node *> ans;
    InOrderTraversal(root, ans);
    
    for(int i = 0 ; i< ans.size()-1; i++)
    {
        ans[i]->left = NULL;
        ans[i]->right = ans[i+1];
    }

    ans[ans.size()-1]->left = NULL;
    ans[ans.size()-1]->right = NULL;
    return ans[0];
}

void flattenTraversal(Node * root)
{     
    cout<<endl<<"Flatten Traversal OF BST : ";
        while(root)
        {
            cout<<root->data<<" ";
            root = root->right;
        }
        cout<<endl;
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
    root = flatten(root);
    flattenTraversal(root);

    
    return 0;
}