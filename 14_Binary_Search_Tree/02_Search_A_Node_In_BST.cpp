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
    if(!root)
    return ;
    
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


void InsertIntoBST(Node * &root , int d)
{
    if(!root)
        root = new Node(d);
    else
    {
        if(root->data < d)
        InsertIntoBST(root->right , d);
        else
        InsertIntoBST(root->left , d);

    }
}

void takeInput(Node *& root)
{
    int data;
    cin>>data;
    while(data!= -1)
    {   
        InsertIntoBST(root, data);
        cin>>data;
    }
}
// 20 10 15 25 22 7 9 -1

// 10 8 21 7 27 5 4 3 -1

bool SearchInBST(Node * root, int &target)
{
     if(!root)
     return false;

     else if(root->data == target)
     return true;

     else if(root->data > target)
     {
         return SearchInBST(root->left, target);
     }
     return SearchInBST(root->right, target);
}

int main()
{
    Node * root = NULL;
    int target;
    cout<<"Enter the data to insert into BST : ";
    takeInput(root);

    cout<<"Enter The Target : ";
    cin>>target;
    cout<<"LeveL Order Traversal : ";
    LevelOrderTraversal(root);
    cout<<endl;

    if(SearchInBST(root,target))
        cout<<target<<" is present !!";
    else
        cout<<target<<" is NOT present !!";

    return 0;
}