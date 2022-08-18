#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void InsertAtBottom(stack<int> &store, int bottom_element)
{
    if (store.empty())
    {
        store.push(bottom_element);
        return;
    }
    int temp = store.top();
    store.pop();
    InsertAtBottom(store, bottom_element);
   
    store.push(temp);
};

void StackTraversal(stack <int> &store )
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

    cout << "Enter The element you want to start at Bottom : ";
    cin >> bottom;

    cout << endl<< "Before Insertion : ";
    StackTraversal(store);

    InsertAtBottom(store, bottom);

    cout << endl<< "After Insertion : ";
    StackTraversal(store);

    
    return 0;
}