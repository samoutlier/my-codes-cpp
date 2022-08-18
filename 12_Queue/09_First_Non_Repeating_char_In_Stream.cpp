// #include <iostream>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <map>
// using namespace std;

// string Solution(string s)
// {
//     queue<char> store;
//     map<char, bool> count;
//     char ch = 'a';

   

//     string ans = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         char c = s.at(i);
//         if (!count[c])
//         {
//             store.push(c);
//             ans.push_back(store.front());
//             count[c] = true;
//         }
//         else
//         {
//             if (!store.empty())
//             {
//                 store.pop();
//             }

//             if (store.empty())
//                 ans.push_back('#');
//             else
//                 ans.push_back(store.front());
//         }
//     }
//     return ans;
// }
// //jdaskhfkd
// int main()
// {
//     string s;
//     cin >> s;
   
//     cout << Solution(s);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

string Solution(string s)
{
    queue<char> store;
    map<char, int > count;
    char ch = 'a';

     string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        count[c] ++;

        store.push(c);

        while (!store.empty())
        {
           if(count[store.front()]>1)
           store.pop();
           else
           {
               ans.push_back(store.front());
               break;
           }
        }
        if(store.empty())
        ans.push_back('#');

            
    }
    return ans;
}
//jdaskhfkd
int main()
{
    string s;
    cin >> s;
   
    cout << Solution(s);

    return 0;
}


