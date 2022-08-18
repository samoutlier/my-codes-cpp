#include <iostream>
#include <vector>
#include <map>
using namespace std;

string RemoveUnwanted(string &s)
{

    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if ((c >= 'A' && c <= 'Z'))
            {
                c = c + 32;
            }
            ans.push_back(c);
        }
    }
    return ans;
}

bool isPalindrome(string s)
{

    // Remove Unwanted Characters
    string ans = RemoveUnwanted(s);

    int start = 0;
    int end = ans.length() - 1;
    cout<<ans<<endl;
    cout<<ans<<endl;
    cout<<end<<endl;
    while (start <= end)
    {
        if (s.at(start) == s.at(end))
        {
            cout << "Checked : " << s.at(start) << " " << s.at(end) << endl;
            start++;
            end--;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    string str = "A man, a plan, a canal: Panama";

    cout << isPalindrome(str);

    return 0;
}