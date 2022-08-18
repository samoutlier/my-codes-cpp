// It  stores only unique element if we give 5 same input
// it will store only one time only 
// it gives sorted order when we fetch them

#include <iostream>
#include<set>

using namespace std;
int main()
{
    set <int> s;
    s.insert(25);
    s.insert(25);
    s.insert(25);
    s.insert(15);
    s.insert(15);
    s.insert(15);
    s.insert(95);
    s.insert(95);
    s.insert(95);
    s.insert(95);
    s.insert(-58);
    s.insert(-58);
    s.insert(-58);
    s.insert(-558);
    s.insert(-558);
    s.insert(-58);
    s.insert(-558);
    s.insert(1000);

    for(auto i : s)
    {
        cout<<i<<" ";
    }cout<<endl;

    set<int> :: iterator it = s.begin();
    it++  ;

    s.erase(s.begin());
    for(auto i : s)
    {
        cout<<i<<" ";
    }cout<<endl;

// It tells whether this element is present or not the 
    cout<<"100 is present or not : "<<s.count(100)<<endl;
    cout<<"1000 is present or not : "<<s.count(1000)<<endl;


// it returns the iterator of given element
    set<int> :: iterator itr = s.find(95);

    for(auto it=itr ; it!=s.end() ; it++)
    {
        cout<<*it<<" ";
    }cout<<endl;
     return 0;
}