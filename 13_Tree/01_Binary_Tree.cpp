#include <iostream>
#include <vector>
#include <stack>
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


    cout << "Enter data For Inserting in left of " << data << " : ";
    root->left = BuildTree(root->left);
    cout << "Enter data For Inserting in right of " << data << " : ";
    root->right = BuildTree(root->right);

    return root;
}

int main()
{
    cout << "Enter the Data : ";
    Node *root = NULL;

    root = BuildTree(root);
    return 0;
}