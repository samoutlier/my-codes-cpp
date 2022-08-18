#include <iostream>
#include <stack>
using namespace std;

bool IsRedundant(string s)
{
    stack<char> store;

    for (int i = 0; i < s.size(); i++)
    {

        // For Opening Brackets
        char c = s.at(i);

        if (c == '(' || c == '*' || c == '+' || c == '-' || c == '/')
        {
            store.push(c);
        }
        // For Closing Brackets
        else if (c == ')')
        {
            if (store.empty() || store.top() == '(')
                return true;

            else
            {
                while (store.top() != '(' && !store.empty())
                {
                    store.pop();
                }

                if (store.empty())
                    return true;
                else
                    store.pop();
            }
        }
    }

    if (store.empty())
        return false;
    else
        return true;
}

int main()
{

    string s;
    cout << "Enter your string : ";
    cin >> s;

    if (IsRedundant(s))
        cout << "Brackets are Redundant :( ";
    else
        cout << "Not Redundant Brackets  :) ";
}