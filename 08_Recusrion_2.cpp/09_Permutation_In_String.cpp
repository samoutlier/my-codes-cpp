#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void Permutation(string &str, int index, string &output, vector<string> &ans)
{
    if (index >= str.length())
    {
        ans.push_back(output);
        return;
    }
    for (int i = index; i < str.length(); i++)
    {
        swap(str[index], str[i]);
        output.push_back(str[index]);
        Permutation(str, index + 1, output, ans);
        output.pop_back();
        swap(str[index], str[i]);
    }
}

vector<string> Solution(string str)
{
    vector<string> ans;
    string output;
    int index = 0;
    Permutation(str, index, output, ans);
    return ans;
}

int main()
{
    string str = "ASIF";
    cout << "Enter The String : ";
    cin >> str;
    cout << "All Permutation of " << str << " are : " << endl;

    vector<string> ans = Solution(str);

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] <<" ";
    }
    return 0;
}