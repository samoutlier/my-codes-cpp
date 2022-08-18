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

void DLLTraversal(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

void BST_To_LL(Node *root, Node *&head)
{
    if (!root)
        return;

    BST_To_LL(root->right, head);

    root->right = head;
    if (head)
        head->left = root;
    head = root;

    BST_To_LL(root->left, head);
}

int countNodes(Node *head)
{
    int count = 0;
    while (head)
    {
        head = head->right;
        count++;
    }
    return count;
}

Node *MergeLL(Node *root1, Node *root2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (root1 && root2)
    {
        if (root1->data < root2->data)
        {
            if (head == NULL)
            {
                head = root1;
                tail = root1;
                root1 = root1->right;
            }
            else
            {
                tail->right = root1;
                root1->left = tail;
                tail = tail->right;
                root1 = root1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = root2;
                tail = root2;
                root2 = root2->right;
            }
            else
            {
                tail->right = root2;
                root2->left = tail;
                tail = tail->right;
                root2 = root2->right;
            }
        }
    }
    while (root1)
    {
        tail->right = root1;
        root1->left = tail;
        tail = tail->right;
        root1 = root1->right;
    }

    while (root2)
    {

        tail->right = root2;
        root2->left = tail;
        tail = tail->right;
        root2 = root2->right;
    }

    return head;
}

Node *BuildBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;

    Node *left = BuildBST(head, n - n / 2 - 1);

    Node *root = head;

    root->left = left;

    head = head->right;

    root->right = BuildBST(head, n / 2 );

    return root;
}

Node *MergeTwoBST(Node *root1, Node *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    // 1. Converting BST Into Sorted LL respectively

    Node *head1 = NULL;
    Node *head2 = NULL;
    BST_To_LL(root1, head1);
    BST_To_LL(root2, head2);

    head1->left = NULL;
    head2->left = NULL;

    DLLTraversal(head1);
    DLLTraversal(head2);

    // 2. Merge Both Linked List

    Node *head = MergeLL(head1, head2);
    DLLTraversal(head);

    // 3. Make BST from this Merge LL
    int size = countNodes(head);

    head = BuildBST(head, size);

    return head;
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