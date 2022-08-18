#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Solution(string& digits, map<int, string>& temp, int index, string &output, vector<string>& ans)
{
  if (index >= digits.length() )
  {
    ans.push_back(output);
    return;
  }
  int number = digits[index] - '0';
  string value = temp[number];
  for (int i = 0; i < value.length(); i++)
  {
    output.push_back(value[i]);
    Solution(digits, temp, index+1, output, ans);
    output.pop_back();
  }
}

vector<string> LetterCombinations(string &digits)
{

  map<int, string> temp = {{0, ""}, {1, ""}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
  vector<string> ans;
  if (digits.length() == 0)
    return ans;
  string output = "";
  int index = 0;
  Solution(digits, temp, index, output, ans);
  return ans;
}

int main()
{
  string digits;
  cout << "Enter The digits combination : ";
  cin >> digits;

  vector<string> ans = LetterCombinations(digits);

  for (int i = 0; i < ans.size(); i++)
  {

    string vec = ans[i];
    cout << " [";
    for (int j = 0; j < vec.size(); j++)
    {
        cout << vec[j];
    }
    cout << "] " ;
    // cout << ans[i] << " ";
  }
  return 0;
}