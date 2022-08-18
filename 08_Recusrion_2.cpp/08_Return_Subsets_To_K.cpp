#include <iostream>
#include <vector>
using namespace std;

void Input(vector<int> &nums)
{
    int temp;
    cin >> temp;
    nums.push_back(temp);
};

int Sum(vector<int> output)
{
    int sum = 0;
    for (int i = 0; i < output.size(); i++)
    {
        sum += output[i];
    }
    return sum;
}

void Solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans, int k)
{
    if (index >= nums.size())
    {
        if (Sum(output) == k)
        {
            ans.push_back(output);
            return;
        }
        return;
    }

    // Exclusion
    Solve(nums, output, index + 1, ans, k);

    // Inclusion
    int element = nums[index];
    output.push_back(element);
    Solve(nums, output, index + 1, ans, k);
}

vector<vector<int>> Subsets(vector<int> &nums, int k)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    Solve(nums, output, index, ans, k);
    return ans;
}

int main()
{
    vector<int> nums;
    int n, k;
    cout << "Enter The number of Elements : ";
    cin >> n;
    cout << "Enter The Elements : ";
    for (int i = 0; i < n; i++)
    {
        Input(nums);
    }
    cout << "Enter The value of k : ";
    cin >> k;

    vector<vector<int>> ans = Subsets(nums, k);

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
