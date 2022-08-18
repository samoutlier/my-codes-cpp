// To check pallindrome in string

#include <iostream>
#include <vector>
using namespace std;

bool Pallindrome(string &str, int start, int end)
{
    bool ans;
    if (start < end)
    {
        if (str[start] != str[end])
            return 0;
        else
            ans = Pallindrome(str, ++start, --end);
    }
    else
    {
        return true;
    }
    return ans;
}

int main()
{
    string str;
    cout << "Enter The String : ";
    cin >> str;
    if (Pallindrome(str, 0, str.length() - 1))
        cout << str << " is a Pallindrome ." << endl;
    else
        cout << str << " is not a Pallindrome .";

    return 0;
}