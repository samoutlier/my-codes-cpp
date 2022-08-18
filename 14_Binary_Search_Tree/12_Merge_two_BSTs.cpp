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

Node *Solve(vector<Node *> &ans, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;

    Node *temp = ans[mid];
    temp->left = Solve(ans, start, mid - 1);
    temp->right = Solve(ans, mid + 1, end);
    return temp;
}

void InOrderTraversal(Node *root, vector<Node *> &ans)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left, ans);
    ans.push_back(root);
    InOrderTraversal(root->right, ans);
}

void MergeTwoInorder(vector<Node *> &inorder1, vector<Node *> &inorder2, vector<Node *> &inorderMerged)
{
    int i = 0, j = 0;
    while (i < inorder1.size() && j < inorder2.size())
    {

        if (inorder1[i]->data < inorder2[j]->data)
            inorderMerged.push_back(inorder1[i++]);
        else
            inorderMerged.push_back(inorder2[j++]);
    }

    while (i < inorder1.size())
        inorderMerged.push_back(inorder1[i++]);
    while (j < inorder2.size())
        inorderMerged.push_back(inorder2[j++]);
}

Node *MergeTwoBST(Node *root1, Node *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    vector<Node *> inorder1, inorder2, inorderMerged;

    InOrderTraversal(root1, inorder1);
    InOrderTraversal(root2, inorder2);

    MergeTwoInorder(inorder1, inorder2, inorderMerged);

   return Solve(inorderMerged, 0 , inorderMerged.size()-1);
}

//  25 15 30 14 17 28 32 -1
// 29 24 35 12 26 33 42 -1

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;

    cout << "Enter the data to insert into BST1 : ";
    takeInput(root1);

    cout << "LeveL Order Traversal of first: ";
    LevelOrderTraversal(root1);
    cout << endl;

    cout << "Enter the data to insert into BST2 : ";
    takeInput(root2);

    cout << "LeveL Order Traversal of second : ";
    LevelOrderTraversal(root2);
    cout << endl;

    Node *ans = MergeTwoBST(root1, root2);

    cout << "LeveL Order Traversal after Merging : ";
    LevelOrderTraversal(ans);
    cout << endl;

    return 0;
}