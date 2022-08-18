#include <iostream>
#include <vector>
using namespace std;

string RemoveOccurence(string str, string sub)
{
    while (str.length() != 0 && str.find(sub) < str.length())
    {
        str.erase(str.find(sub), sub.length());
    }
    return str;
}

int main()
{
    cout << "Enter The String : ";
    string str, sub;
    cin >> str;
    cout << "Enter The Sub String : ";
    cin >> sub;
    cout << "The Replaced Spaces string is : " << RemoveOccurence(str, sub) << endl;
    return 0;
}