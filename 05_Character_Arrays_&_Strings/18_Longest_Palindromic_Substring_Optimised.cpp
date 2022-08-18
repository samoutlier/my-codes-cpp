#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string longestPalindrome(string s)
{
    int start = 0, end = 0, curr = 0;

    int ans_start = 0, ans_end = 0, length = 0;
    while (curr < s.length())
    {
        while (start >= 0 && end < s.length() && s.at(start) == s.at(end))
        {
            cout<<"Checking for : "<<s.at(start)<<" and "<<s.at(end)<<endl;
            if (end - start + 1 > length)
            {
                length = end - start + 1;
                ans_start = start;
                ans_end = end;
            }

            start--;
            end++;
        }

        curr++;
        start = curr;
        end = curr+1;

    }

    
    string ans = "";
    for (int i = ans_start; i <= ans_end; i++)
    {
        ans.push_back(s.at(i));
    }

    return ans;
}

int main()
{
    string str, sub;
    cout << "Enter The String : ";
    cin >> str;

    cout << "Maximum Length Of Palindromic Substring is : " << longestPalindrome(str);

    return 0;
}