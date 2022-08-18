#include <iostream>
#include <vector>
using namespace std;

int Length(string s)
{
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
}

bool CharacterCheck(char ch)
{
    if(( ch >= 'A' && ch<='Z') || ( ch >= 'a' && ch<='z') || ( ch >= '0' && ch<='9'))
    return true;
    else
    return false;
}

char ToLowerCase(char ch)
{
    if(ch >= 'A' && ch<='Z')
    ch = ch + 'a' - 'A';
    return ch;
}

bool PallindromeCheck(string s)
{
    int start = 0, end = Length(s) - 1;
    while (start < end)
    {   while(!CharacterCheck(s[start]))
        {
            start++;
        }

        while(!CharacterCheck(s[end]))
        {
            end--; 
        }
        if (ToLowerCase(s[start]) != ToLowerCase(s[end]) && start<end)
            return false;
        start++;
        end--;
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter The Name : ";
    getline(cin, s);

    if (PallindromeCheck(s))
        cout << s << " is a pallndrome :) " << endl;
    else
        cout << s << " is not a pallndrome :( " << endl;

    return 0;
}