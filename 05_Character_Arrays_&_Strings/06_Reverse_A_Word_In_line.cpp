

#include <iostream>
using namespace std;

string Reverse(string s, int start, int end)
{
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

string Solution(string s)
{
    int i = 0, count = 0;
    while (i < s.size())
    {
        count = i;
        while (i < s.size() && s[i] != ' ')
        {
            i++;
        }
        i--;
        s = Reverse(s, count, i);
        i = i + 2;
    }
    return s;
}

int main()
{
    string s;
    cout << "Enter The string : ";
    getline(cin, s);
    cout << s << endl;
    s = Solution(s);
    cout << "The reverse Of Letters in a word of string is : " << s;
    return 0;
}