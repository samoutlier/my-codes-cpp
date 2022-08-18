#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;



void QueueReversal(queue<int> &q)
{
    stack<int> store;
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
           store.push(q.front());
           q.pop();
    }

    for (int i = 0; i < size ; i++)
    {
           
           q.push(store.top());
           store.pop();
    }

  
}

int main()
{
    queue<int> q;

    int n, x;
    cout << "Enter The Number Of elements : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);

    }
     
    QueueReversal(q);

    cout<<"Queue After Reversal : ";
    for (int i = 0; i < n ; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}