#include <iostream>
using namespace std;

string StringCompression(string s)
{
    int i = 0;
    while(i<s.length())
    {   
        int count = 1;
        int j = i;

        while(s[j]==s[j+1] && j<s.length()-1)
        {
          count++;
          j++;
        }
        if(count>1)
        {  string temp = to_string(count);
           s.erase(i+1,count-1);
           s.insert(i+1,temp);
           i+=2;
        }
        else
        i++;
        
    }
    return s;
}

int main()
{
    string str, sub;
    cout << "Enter The String : ";
    cin >> str;

    cout << "String After Removing All adjacent Elements  : " << StringCompression(str) << endl;

    return 0;
}