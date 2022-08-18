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

    return root;
}

void LevelOrderTraversal(Node *root)
{
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

int HeightOfBT(Node *root)
{
    if (root == NULL)
        return 0;

    return (1 + max(HeightOfBT(root->left), HeightOfBT(root->right)));
}

pair<int, int> DiameterFast(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> LeftAns = DiameterFast(root->left);
    pair<int, int> RightAns = DiameterFast(root->right);
    

    int x = LeftAns.first;
    int y = RightAns.first;
    int z = LeftAns.second  + RightAns.second + 1;
    
    pair<int, int> ans;
    ans.first =  max(max(x,y), z);
    ans.second = max(LeftAns.second , RightAns.second) + 1;
    return ans;

}

// 1 3 5 7 11 17 20 15 19 4 1 -1 -1 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    cout << "Enter the Root : ";
    Node *root = NULL;

    root = BuildTree(root);

    cout << endl
         << "Level Order traversal : " << endl;
    LevelOrderTraversal(root);

    cout<<endl;
    cout<<"Height Of Tree is : "<<HeightOfBT(root);

    cout<<endl;
    cout<<"Diameter Of Tree is : "<<DiameterFast(root).first;
    return 0;
}