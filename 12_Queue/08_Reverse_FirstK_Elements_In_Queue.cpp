#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void QueueReversal(queue<int> &q, int k)
{

    stack<int> store;
    int size = q.size();

    for (int i = 0; i < k; i++)
    {
        store.push(q.front());
        q.pop();
    }

    while (!store.empty())
    {
        q.push(store.top());
        store.pop();
    }

    for (int i = 0; i < size-k ; i++)
    {
        q.push(q.front());
        q.pop();
    }
    

    
}

int main()
{
    queue<int> q;

    int n, x, k;
    cout << "Enter The Number Of elements : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    cout << "Enter The value of k : ";
    cin >> k;
    QueueReversal(q, k);

    cout << "Queue After Reversal : ";
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}