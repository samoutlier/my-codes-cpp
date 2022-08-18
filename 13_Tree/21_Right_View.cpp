// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->right = NULL;
//         this->left = NULL;
//     }
// };

// Node *BuildTree(Node *root)
// {
//     int data, leftdata, rightdata;
//     cin >> data;

//     if (data == -1)
//         return NULL;

//     root = new Node(data);

//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         Node *frontNode = q.front();
//         q.pop();

//         cout << endl
//              << "Enter the Left Node for " << frontNode->data << " : ";
//         cin >> leftdata;

//         if (leftdata != -1)
//         {
//             frontNode->left = new Node(leftdata);
//             q.push(frontNode->left);
//         }

//         cout << endl
//              << "Enter the Right Node for " << frontNode->data << " : ";
//         cin >> rightdata;

//         if (rightdata != -1)
//         {
//             frontNode->right = new Node(rightdata);
//             q.push(frontNode->right);
//         }
//     }

//     return root;
// }

// void LevelOrderTraversal(Node *root)
// {
//     if (!root)
//         return;

//     queue<Node *> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty())
//     {
//         Node *frontNode = q.front();
//         q.pop();

//         if (!frontNode)
//         {
//             cout << endl;
//             {
//                 if (!q.empty())
//                     q.push(NULL);
//             }
//         }
//         else
//         {

//             cout << frontNode->data << " ";
//             if (frontNode->left)
//                 q.push(frontNode->left);
//             if (frontNode->right)
//                 q.push(frontNode->right);
//         }
//     }
// }

// vector<int> TopView_Traversal(Node *root)
// {
//     vector<int> ans;

//     if (!root)
//         return ans;

//     map<int, int> TopNodes;
//     queue<pair<Node *, pair<int, int>>> q;

//     q.push(make_pair(root, make_pair(0, 0)));

//     map<pair<int, int>, bool> check;

//     while (!q.empty())
//     {
//         pair<Node *, pair<int, int>> temp = q.front();
//         q.pop();

//         Node *frontNode = temp.first;
//         int distance = temp.second.first;
//         int level = temp.second.second;

//         pair<int, int> p = make_pair(distance, level);

//         if (!check[p])
//         {
//             TopNodes[distance] = frontNode->data;
//             check[p] = true;
//         }

//         if (frontNode->left)
//             q.push(make_pair(frontNode->left, make_pair(distance - 1, level + 1)));
//         if (frontNode->right)
//             q.push(make_pair(frontNode->right, make_pair(distance + 1, level + 1)));
//     }

//     for (auto i : TopNodes)
//     {
//         ans.push_back(i.second);
//     }

//     return ans;
// }

// // Input :
// //  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1-1 -1 -1 -1 -1 -1 -1 -1

// // Output:
// // 4 2 1 5 6 3 8 7 9

// int main()
// {
//     cout << "Enter the Root : " << endl;
//     Node *root = NULL;

//     root = BuildTree(root);

//     LevelOrderTraversal(root);

//     cout << endl;

//     vector<int> ans = TopView_Traversal(root);

//     cout << endl;
//     cout << "Top View Traversal : ";

//     for (int i : ans)
//     {
//         cout << i << " ";
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <map>
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
        Node *frontNode = q.front();
        q.pop();

        cout << endl
             << "Enter the Left Node for " << frontNode->data << " : ";
        cin >> leftdata;

        if (leftdata != -1)
        {
            frontNode->left = new Node(leftdata);
            q.push(frontNode->left);
        }

        cout << endl
             << "Enter the Right Node for " << frontNode->data << " : ";
        cin >> rightdata;

        if (rightdata != -1)
        {
            frontNode->right = new Node(rightdata);
            q.push(frontNode->right);
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
        Node *frontNode = q.front();
        q.pop();

        if (!frontNode)
        {
            cout << endl;
            {
                if (!q.empty())
                    q.push(NULL);
            }
        }
        else
        {

            cout << frontNode->data << " ";
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}

vector<int> TopView_Traversal(Node *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    map<int, int> TopNodes;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp;
        temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int level = temp.second;

        // If one value is present for a level , then do nothing

        TopNodes[level] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, level + 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, level + 1));
    }

    for (auto i : TopNodes)
    {
        ans.push_back(i.second);
    }

    return ans;
}

// Input :
//  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

// Output:
// 1 2 4 8

// input and output
// 1 2 5 3 4 -1 6 -1 -1 -1 7 -1 8 -1 -1 -1 9 -1 -1
// 1 2 3 7 9
int main()
{
    cout << "Enter the Root : " << endl;
    Node *root = NULL;

    root = BuildTree(root);

    LevelOrderTraversal(root);

    cout << endl;

    vector<int> ans = TopView_Traversal(root);

    cout << endl;
    cout << "Top View Traversal : ";

    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}