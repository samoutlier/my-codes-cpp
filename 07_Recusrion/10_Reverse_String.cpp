#include <iostream>
#include <vector>
using namespace std;

void ReverseString(string &str, int start, int end)
{
    if (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
        ReverseString(str, start, end);
    }
}

int main()
{
    string str;
    cout << "Enter The String : ";
    cin >> str;
    ReverseString(str, 0, str.length() - 1);
    cout << "The Reverse Of Given String is : " << str;
    return 0;
}