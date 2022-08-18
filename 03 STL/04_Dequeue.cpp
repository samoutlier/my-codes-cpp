#include <iostream>
#include <deque>

using namespace std;
int main()
{
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_front(3);
    d.push_front(4);
    d.push_front(5);
    d.push_front(6);

    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    d.pop_front();
    for (int i : d)
    {
        cout << i << " ";
    }cout<<endl;
    
    cout<<"Element At Index 1 : "<<d.at(1)<<endl;

    cout<<"size Before Erase : "<<d.size()<<endl;
    d.erase(d.begin(), d.begin()+3);
    cout<<"size After Erase : "<<d.size()<<endl;
    
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    
    return 0;
}