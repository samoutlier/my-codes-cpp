#include <iostream>
#include <vector>
using namespace std;

void Solve(string str, string output, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }

    // Exclusion
    Solve(str, output, index + 1, ans);

    // Inclusion
    char element = str[index];
    output.push_back(element);
    // output = output + element;
    Solve(str, output, index + 1, ans);
}

vector<string> SubSequence(string &str)
{
    vector<string> ans;
    string output;
    int index = 0;
    Solve(str, output, index, ans);
    return ans;
}

int main()
{
    string str;

    cout << "Enter The String : ";
    cin >> str;

    vector<string> ans = SubSequence(str);

    for (int i = 0; i < ans.size(); i++)
    {

        // string vec = ans[i];
        // cout << "[ ";
        // for (int j = 0; j < vec.size(); j++)
        // {
        //     cout << vec[j];
        // }
        // cout << " ]" << endl;
        cout << ans[i] << " ";
    }
    return 0;
}
