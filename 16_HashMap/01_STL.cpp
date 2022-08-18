#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;

int main()
{   
   //Unordered Map m order preserve nahi hota hai

    // Creation
    unordered_map<string, int> m;

    // Insertion
    pair<string, int> pair1 = make_pair("Samad", 3);

    // 1 .
    m.insert(pair1);

    // 2.
    pair<string, int> pair2("Abdul", 2);
    m.insert(pair2);

    // 3.
    m["Khwaja"] = 1;

    // Searching
    cout << m["Khwaja"] << endl;
    cout << m.at("Abdul") << endl;
    cout << m.at("Samad") << endl;

    //cout << m.at("Random");
    // Above line will throw error of std out of range bcz it doesnt exist

    //Below line wont throw an error bcz it makes an entry = 0 for unknown value
    cout << m["Random"] << endl;

    cout<<"Size : "<<m.size()<<endl;

    //To check if Key is present
    cout<<m.count("Broooo")<<endl;
    cout<<m.count("Abdul")<<endl;

    //To erase
    m.erase("Khwaja");
    cout<<"Size : "<<m.size()<<endl;

   for(auto i: m)
   {
    cout<<i.first<<" "<<i.second<<endl;
   }

   //Iterator

   unordered_map<string , int> :: iterator it = m.begin();

   while(it != m.end())
   {
      cout<<it->first<< " "<<it->second <<endl;
      it++;
   }

    return 0;
}