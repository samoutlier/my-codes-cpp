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

void InOrderTraversal(Node * &root)
{
     if(root == NULL)
     return ;

     InOrderTraversal(root->left);
     cout<<root->data<<" ";
     InOrderTraversal(root->right);

}

void PreOrderTraversal(Node * &root)
{
     if(root == NULL)
     return ;

     cout<<root->data<<" ";
     PreOrderTraversal(root->left);
     PreOrderTraversal(root->right);

}

void PostOrderTraversal(Node * &root)
{
     if(root == NULL)
     return ;

     PostOrderTraversal(root->left);
     PostOrderTraversal(root->right);
     cout<<root->data<<" ";

}


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
// 20 10 15 25 2 2 7 9 -1

// 10 8 21 7 27 5 4 3 -1

int main()
{
    Node * root = NULL;

    cout<<"Enter the data to insert into BST : ";
    takeInput(root);

    cout<<"Level Order traversal : ";
    LevelOrderTraversal(root);
    cout<<endl;
    cout<<"Pre Order traversal : ";
    PreOrderTraversal(root);
    cout<<endl;
    cout<<"Post Order traversal : ";
    PostOrderTraversal(root);
    cout<<endl;
    cout<<"In Order traversal : ";
    InOrderTraversal(root);
   
    return 0;
}