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
void Solve(Node* root, int k, int &index, int &ans)
    {   
        if(!root)
            return ;
        if(root->left)
        {
            Solve(root->left, k , index,ans);
        }
        if(ans != -1)
            return ;
        index++;
        if(k == index)
        {
            ans = root->data;
            return ;
        }   
        if(root->right)
        {
             Solve(root->right, k , index, ans);
        }
    
        
    }
    
    int kthSmallest(Node* root, int k) {
     
        int index = 0 , ans = -1;
         Solve(root, k , index, ans);
        return ans;
    }

// 13 3 4 12 14 10 5 1 8 2 7 9 11 6 18 -1

int main()
{
    Node *root = NULL;
    int index;
    cout << "Enter the data to insert into BST : ";
    takeInput(root);

    cout << "Enter The Index : ";
    cin >> index;
    cout << "LeveL Order Traversal : ";
    LevelOrderTraversal(root);
    cout << endl;

    cout<<index<<"th smallest element in BST is : "<<kthSmallest(root, index);

  

    return 0;
}