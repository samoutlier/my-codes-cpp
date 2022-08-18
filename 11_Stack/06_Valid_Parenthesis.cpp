#include <iostream>
#include <stack>
using namespace std;

bool IsBalanced(string s)
{
    stack<char> store;

    for (int i = 0; i < s.size(); i++)
    {

        // For Opening Brackets
        char c = s.at(i);
        if (c == '(' || c == '[' || c == '{')
        {
            store.push(c);
        }
        // For Closing Brackets
        else if (c == ')' || c == ']' || c == '}')
        {
            if (store.empty())
            {
                return false;
            }
            else if (c == ')')
            {

                if (store.top() == '(')
                {
                    store.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (c == ']')
            {
                if (store.top() == '[')
                {
                    store.pop();
                }
                else
                {
                    return false;
                }
            }

            else if (c == '}')
            {
                if (store.top() == '{')
                {
                    store.pop();
                }
                else
                {
                    return false;
                }
            }
            else
                continue;
        }
    }
    if (store.empty())
        return true;
    else
        return false;
}

int main()
{

    string s;
    cout << "Enter your string : ";
    cin >> s;

    if (IsBalanced(s))
        cout << "BALANCED :) ";
    else
        cout << "NOT BALANCED :) ";
}