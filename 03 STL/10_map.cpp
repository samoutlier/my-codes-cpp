#include <iostream>
#include<map>

using namespace std;


//Time Complexity is O(Log(n))
int main()
{
    map <int, string> m;

    m[1]="khwaja";
    m[2]="Abdul";
    m[13]="Samad";

    m.insert({5, "Hello"});

    for(auto i : m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<< "Before Erase Finding 13 : "<<m.count(13)<<endl;
    m.erase(13);
    cout<< "After Erase Finding 13 : "<<m.count(13)<<endl<<endl;
    for(auto i : m)
    {
        cout<<i.first<<" "<<i.second<<endl<<endl;
    }
    auto it = m.find(1);
    for(auto i=it; i!=m.end(); i++)
    {
        cout<<(*i).first<<endl;
    }
    return 0;
}