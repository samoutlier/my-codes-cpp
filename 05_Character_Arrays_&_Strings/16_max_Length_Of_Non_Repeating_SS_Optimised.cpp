#include <iostream>
#include <vector>
using namespace std;

int Max_length_OF_Substring(string s)
{

    vector<int> check(256, -1);
    int start = -1, ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (check[c] > start)
        {
            start = check[c];
        }
        ans = max(ans, i - start);
        check[c] = i;
    }

    return ans;
}

int main()
{
    string str, sub;
    cout << "Enter The String : ";
    cin >> str;

    cout << "Maximum Length Of Non Repeating Substring is : " << Max_length_OF_Substring(str);

    return 0;
}