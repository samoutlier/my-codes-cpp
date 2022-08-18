
#include <iostream>
#include <vector>
#include <stack>
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
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new Node(data);

    cout << "Enter data For Inserting in left of " << data << " : " << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data For Inserting in right of " << data << " : " << endl;
    root->right = BuildTree(root->right);

    return root;
}

// 1 3 7 15 -1 -1 19 -1 -1 11 4 -1 -1 1 -1 -1 5 17 -1 -1 20 100 -1 -1 -1


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
     InOrderTraversal(root->left);
     InOrderTraversal(root->right);

}

void PostOrderTraversal(Node * &root)
{
     if(root == NULL)
     return ;

     InOrderTraversal(root->left);
     InOrderTraversal(root->right);
     cout<<root->data<<" ";

}

int main()
{
    cout << "Enter the Data : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    cout<<endl<<"In Order Traversal : ";
    InOrderTraversal(root);
    cout<<endl<<"Pre Order  Traversal : ";
    PreOrderTraversal(root);
    cout<<endl<<"Post Order Traversal : ";
    PostOrderTraversal(root);

    return 0;
}


