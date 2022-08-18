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

Node *Build_BST_From_PreOrder(vector<int> &v, Node *p, Node *q, int &index)
{
    if (index >= v.size())
        return NULL;

        if((p && p->data > v[index])  || (q && q->data < v[index]) )
        return NULL;


        Node * temp = new Node(v[index++]);

        temp->left = Build_BST_From_PreOrder(v, p, temp, index);
        temp->right = Build_BST_From_PreOrder(v,temp, q, index);

        return temp;
}

// 20 10 5 15 13 35 30 42 -1

int main()
{
    Node *root = NULL;

    vector<int> v;
    int data = 0;
    while (data != -1)
    {
        cin >> data;
        v.push_back(data);
    }
    v.pop_back();
    int index = 0;
    root = Build_BST_From_PreOrder(v, NULL, NULL, index);

    LevelOrderTraversal(root);

    return 0;
}