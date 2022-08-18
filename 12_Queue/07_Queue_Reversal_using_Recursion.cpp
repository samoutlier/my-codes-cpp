#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void QueueReversal(queue<int> &q)
{
    //base Case
    if(q.size()==0)
    return ;

    int x = q.front();
    q.pop();

    QueueReversal(q);

    q.push(x);
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