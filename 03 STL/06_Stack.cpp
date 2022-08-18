#include <iostream>
#include<stack>
using namespace std;
int main()
{
    stack<string> s;
    s.push("Khwaja");
    s.push("Abdul");
    s.push("Samad");

    for(int i= 0 ; i<3 ; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}