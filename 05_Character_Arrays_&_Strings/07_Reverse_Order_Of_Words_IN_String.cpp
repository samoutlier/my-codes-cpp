
#include <iostream>
using namespace std;

string Reverse(string s, int start, int end)
{
    string copy = {""};
    int i;
    for (i = start; i <= end; i++)
    {
        copy[i] = s[i];
    }
    return copy;
}

string Solution(string s)
{
    int i = 0;
    int j;
    string copy = {""};
    while (i < s.length())
    {
        j = i;
        while (i < s.length() && s[i] != ' ')
        {
            i++;
        }
        i--;
        copy = Reverse(s, j, i) + copy;
        i = i + 2;
    }
    return copy;
}

int main()
{
    string s;
    cout << "Enter The string : ";
    getline(cin, s);

    s = Solution(s);
    cout << s << endl;

    return 0;
}