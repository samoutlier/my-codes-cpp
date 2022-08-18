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

void heapify(vector<int> &v, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[largest] < v[left])
    {
        largest = left;
    }
    if (right < n && v[largest] < v[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(v[largest], v[i]);
        heapify(v, largest, n);
    }
}

// 1 3 5 7 11 17 20 15 19 4 1 -1 -1 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{

    vector<int> v;
    int data, m, n;

    cout << "Enter The Number of m and n : ";
    cin >> m >> n;

    cout << "Enter The Elemnts of first heap : ";
    for (int i = 0; i < m; i++)
    {
        cin >> data;
        v.push_back(data);
    }

    cout << "Enter The Elemnts second heap : ";
    for (int i = 0; i < n; i++)
    {
        cin >> data;

        v.push_back(data);
    }

    for (int i = (m + n) / 2 - 1; i >= 0; i--)
    {
        heapify(v, i, m+n);
    }

    for (int i = 0; i < m + n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}