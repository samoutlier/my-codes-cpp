#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void Solution(queue<int> &q,stack<int> &store)
{
    if(store.empty())
    return ;
    int x = store.top();
    store.pop();
    Solution(q,store);
    q.push(x);
    q.push(q.front());
    q.pop();

}

void InterLeave(queue<int> &q)
{
    stack<int> store;
    int size = q.size();

    for (int i = 0; i < size/2; i++)
    {
        store.push(q.front());
        q.pop();
    }

    Solution(q,store);
    
}

int main()
{
    queue<int> q;
    int x, n;

    cout << "Enter the Number of elements : ";
    cin >> n;
    cout << "Enter the elements : ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }
    
    InterLeave(q);
    cout << "Elements after interleaving : ";

    for (int i = 0; i < n; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}