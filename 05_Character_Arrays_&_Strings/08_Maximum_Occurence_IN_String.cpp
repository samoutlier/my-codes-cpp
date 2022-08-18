
#include <iostream>
using namespace std;

int GetMax(string s)
{
    int arr[26] = {0};
    char ch;
    for (int i = 0; i < s.length(); i++)
    {
        int num = 0;
        ch = s[i];
        if (ch == ' ')
            continue;
        if (ch >= 'a' && ch <= 'z')
        {
            num = ch - 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            num = ch - 'A';
        }
        arr[num]++;
    }
 
    int max = -1 , ans = 0;
    for(int i = 0 ; i< 26 ; i++)
    {
        if(max<arr[i])
        {
            ans = i;
            max = arr[i];
        }
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter The string : ";
    getline(cin, s);
    char ch = 'a' + GetMax(s);
    cout << ch << endl;

    return 0;
}