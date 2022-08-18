#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s.at(start) == s.at(end))
        {
            start++;
            end--;
        }
        else
            return false;
    }
    return true;
}


string longestPalindrome(string s)
{

    int size = s.length();
    while (size > 0)
    {
        int start = 0;
        int end = size - 1;

        while (end < s.length())
        {
            if (isPalindrome(s, start, end))
            {
                string ans;
                for (int i = start; i <= end; i++)
                {
                    ans.push_back(s.at(i));
                }
                return ans;
            }
            else
            {
                start++;
                end++;
            }
        }

        size--;
    }
    return "";
}

int main()
{
    string str, sub;
    cout << "Enter The String : ";
    cin >> str;

    cout << "Maximum Length Of Palindromic Substring is : " << longestPalindrome(str);

    return 0;
}