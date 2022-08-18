// Remove Adjacent Same Letters
//  ex : azxxzy = ay

#include <iostream>
using namespace std;

string RemoveAdjacent(string str)
{
    int i = 0;
    while (i < str.length() - 1)
    {
        if (str[i] == str[i + 1])
        {
            str.erase(i, 2);
            i = 0;
        }
        else
        {
            i++;
        }
    }
    return str;
}

int main()
{
    string str, sub;
    cout << "Enter The String : ";
    cin >> str;

    cout << "String After Removing All adjacent Elements  : " << RemoveAdjacent(str) << endl;
    return 0;
}