#include <iostream>
#include<queue>
using namespace std;
int main()
{
    queue <string> q;

    q.push("Khwaja ");
    q.push("Abdul ");
    q.push("Samad");

   cout<<"First Element : "<<q.front()<<endl;
   cout<<"Size Before Pop : "<<q.size()<<endl;
   q.pop();
   cout<<"First Element After Pop: "<<q.front()<<endl;
   cout<<"Size After Pop : "<<q.size()<<endl;
    return 0;
}