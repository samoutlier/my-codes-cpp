#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
 
void Solve(string s , int &ans, int index)
{
    if(index == s.length())
        return ;

    stack<char> store ;
    int i = index;
    cout<<"Checking for index : "<<i<<endl;

    while(i<s.length())
    {
        if(!store.empty() && s.at(i) == ')')
        {
            store.pop();
            if(store.empty())
            {
                ans =max(ans, i-index+1);
            }
        }
        else if(store.empty() && s.at(i) == ')')
        {
            break;
        }

        else
        {
            store.push(s.at(i));
        }
        i++;
    }

    cout<<"Current Ans : "<<ans<<endl;
    if(ans <s.length()-index-1)
        Solve(s,ans,index+1);

}

int longestValidParentheses(string s) {

    stack<char> store ;
    int ans = 0;
    int index = 0;

    Solve(s,ans, index);
    return ans;
}

int main()
{

    string s;
    cout << "Enter your string : ";
    cin >> s;

    cout<<"Ans : "<<longestValidParentheses(s);
}