#include <iostream>
#include <queue>
using namespace std;
int main()
{   
    // Max heap
    priority_queue<int> maxi;
    

    //Min Heap
    priority_queue <int, vector<int>, greater<int> > mini;

    maxi.push(259);
    maxi.push(29);
    maxi.push(59);
    maxi.push(9); 
    cout<<maxi.size()<<endl;
    for(int i = 0 ; i<4; i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;


    mini.push(259);
    mini.push(59);
    mini.push(9); 
    mini.push(29);
    cout<<mini.size()<<endl;
    for(int i = 0 ; i<4; i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

    return 0;
}