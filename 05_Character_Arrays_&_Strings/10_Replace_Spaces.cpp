#include <iostream>
#include <vector>
using namespace std;

string ReplaceSpace(string s)
{
    string temp = {""};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    return temp;
}

int main()
{
    cout << "Enter The String : ";
    string s;
    getline(cin, s);
    cout << "The Replaced Spaces string is : " << ReplaceSpace(s) << endl;
    return 0;
}