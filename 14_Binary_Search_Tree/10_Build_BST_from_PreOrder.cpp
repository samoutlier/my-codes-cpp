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

Node *Build_BST_From_PreOrder(vector<int> &v, int start, int end)
{
    if (start > end)
        return NULL;

    Node *temp = new Node(v[start]);
    int index = start + 1;
    while (v[start] > v[index] && index <= end)
    {
        index++;
    }
    temp->left = Build_BST_From_PreOrder(v, start + 1, index - 1);
    temp->right = Build_BST_From_PreOrder(v, index, end);
    return temp;
}

// 13 3 4 12 14 10 5 1 8 2 7 9 11 6 18 -1

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

    root = Build_BST_From_PreOrder(v, 0, v.size() - 1);

    LevelOrderTraversal(root);

    return 0;
}