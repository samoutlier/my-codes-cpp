#include <iostream>
#include <vector>
using namespace std;

void Input(vector<int> &nums)
{
    int temp;
    cin >> temp;
    nums.push_back(temp);
}

void Solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclusion
    Solve(nums, output, index + 1, ans);

    // Inclusion
    int element = nums[index];
    output.push_back(element);
    Solve(nums, output, index + 1, ans);
}

vector<vector<int>> Subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    Solve(nums, output, index, ans);
    return ans;
}

int main()
{
    vector<int> nums;
    int n;
    cout << "Enter The number of Elements : ";
    cin >> n;
    cout << "Enter The Elements : ";
    for (int i = 0; i < n; i++)
    {
        Input(nums);
    }

    vector<vector<int>> ans = Subsets(nums);

    for (int i = 0; i < ans.size(); i++)
    {

        vector<int> vec = ans[i];
        cout << "[ ";
        for (int j = 0; j < vec.size(); j++)
        {
            cout << vec[j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
