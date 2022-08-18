#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(2);
    l.push_front(1);
    l.push_back(3);
    l.push_back(4);
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    l.erase(l.begin());
    cout << "After Erase ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout<<"Size Of List : "<<l.size()<<endl;

    list <int> n(5,100);
    for (int i : n)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}