#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void InsertAtBottom(stack <int> &store, int temp)
{
    if(store.empty())
    {
        store.push(temp);
        return;
    }

    int xyz = store.top();
    store.pop();
    InsertAtBottom(store,temp);
    store.push(xyz);
}

void ReverseStackByRecursion(stack<int> &store)
{
    if (store.empty())
    {
        return;
    }
    int temp = store.top();
    store.pop();
    ReverseStackByRecursion(store);

    InsertAtBottom(store, temp);
};

void StackTraversal(stack <int> store )
{
    if(store.empty())
    return ;

    int temp = store.top();
    store.pop();
    StackTraversal(store);
    cout<<temp<<" ";
    store.push(temp);

}

int main()
{
    stack<int> store;
    int n, bottom;
    cout << "Enter The Number Of elements : ";
    cin >> n;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        store.push(x);
    }

    cout << endl<< "Before Insertion : ";
    StackTraversal(store);

    ReverseStackByRecursion(store);

    cout << endl<< "After Insertion : ";
    StackTraversal(store);

    
    return 0;
}