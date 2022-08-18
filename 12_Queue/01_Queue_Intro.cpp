#include <iostream>
#include<vector>
#include<queue>
using namespace std;
 
 
 
int main()
{
    queue <int> q;

    q.push(25);
    q.push(36);
    q.push(31);
    q.push(0);

    cout<<"Size : "<<q.size()<<endl;
    q.push(85);
    cout<<"Size : "<<q.size()<<endl;

    cout<<"Front Of Queue is : "<<q.front()<<endl;
    q.pop();
    cout<<"Front Of Queue is : "<<q.front()<<endl;

    return 0;
}