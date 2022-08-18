#include <iostream>
#include<map>
using namespace std;

int Max_length_OF_Substring(string s)
{
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        map<char, bool> check;
        string temp = "";
        for (int j = i; j < s.size(); j++)
        {
            if (!check[s[j]])
            {
                temp = temp + s[j];
                check[s[j]] = true;
            }

            else
                break;
        }

        ans = (ans.size() > temp.size()) ? ans : temp;
    }

    return ans.size();
}

int main()
{
    string str, sub;
    cout << "Enter The String : ";
    cin >> str;

    cout << "Maximum Length Of Non Repeating Substring is : " << Max_length_OF_Substring(str);

    return 0;
}