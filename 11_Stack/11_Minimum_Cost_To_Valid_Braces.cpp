#include <iostream>
#include <stack>
using namespace std;

int Solve(string s)
{
    if (s.size() & 1)
        return -1;

    stack<char> store;

    for (int i = 0; i < s.size(); i++)
    {

        char c = s.at(i);

        if (c == '{')
        {
            store.push(c);
        }

        else if (c == '}')
        {
            if (store.empty() || store.top() == '}')
                store.push('}');

            else
            {
                store.pop();
            }
        }
    }

    if (store.empty())
        return 0;

    int cost = store.size();

    char c = store.top();
 

    while (!store.empty() && c == store.top())
    {
        store.pop();
    }

    if (store.empty())
        return (cost / 2);
    else
        return cost;
}

int main()
{

    string s;
    cout << "Enter your string : ";
    cin >> s;

    int cost = Solve(s);
    if (cost == -1)
        cout << "It is not possible to Validate Braces ";
    else if (cost == 0)
        cout << "It is already valid therefore zero cost ";
    else
        cout << "Cost to validate braces is : " << cost;
}