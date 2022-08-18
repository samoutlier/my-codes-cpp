
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve(stack<int> &store, int size, int count)
{
    if (count == size / 2 )
    {
        store.pop();
        return;
    }

    int temp = store.top();
    store.pop();
    solve(store, size, count + 1);
    store.push(temp);
}

void DeleteMiddleNode(stack<int> &store, int size)
{
    int count = 0;

    solve(store, size, count);
}

int main()
{
    stack<int> store;
    int n;
    cout << "Enter The Number OF elements : ";
    cin >> n;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        store.push(x);
    }

    DeleteMiddleNode(store, n);
    cout<<"After deletion : ";

    for (int i = 0; i < n-1; i++)
    {
        cout << store.top() << " ";
        store.pop();
    }

    return 0;
}