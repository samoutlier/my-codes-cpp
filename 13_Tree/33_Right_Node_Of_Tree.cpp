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
    Node * next;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
        this->next = NULL;
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
        Node *temp = q.front();
        q.pop();

        cout << endl<< "Enter the Left Node for " << temp->data<<" : ";
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }


        cout << endl<<"Enter the Right Node for " << temp->data<<" : ";
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }

    return root;
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



  Node* connect(Node* root) {
        if(!root || root->right == NULL)
            return root;
        
        queue<Node * > q;
       
        q.push(root);
        q.push(NULL);
       
        while(!q.empty())
        {
            Node * temp = q.front();
            q.pop();
            if(temp)
            {
                temp->next = q.front();
                if(temp->left)
                 q.push(temp->left);
                if(temp->right)
                 q.push(temp->right);
            }   
            else if(!q.empty() )
            {
                q.push(NULL);
            }
        }
        return root;
}

void NodeRight (Node * root)
{
    if(!root)
    return ;

    if(root->right)
    cout<<root->right->data<<" ";
    else
    cout<<-1<<" ";

    NodeRight(root->left);
    NodeRight(root->right);
    
}

// 1 2 3 4 5 6 7  -1 -1 -1 -1 -1 -1 -1 -1 


int main()
{
    cout << "Enter the Root : ";
    Node *root = NULL;

    root = BuildTree(root);

    cout<<endl<<"Level Order traversal : "<<endl;
    LevelOrderTraversal(root);
    root = connect(root);

    cout<<endl;
    NodeRight(root);

    return 0;
}