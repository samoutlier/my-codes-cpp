#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int Solution(vector<int> nums1, vector<int> nums2)
{
    vector<int> ans;

    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
            ans.push_back(nums1[i++]);

        else
            ans.push_back(nums2[j++]);
    }

    while (i < nums1.size())
        ans.push_back(nums1[i++]);

    while (j < nums2.size())
        ans.push_back(nums2[j++]);

    int s = ans.size();

    if (s % 2 == 1)
    {
        return ans[s / 2];
    }
    else
    {
        cout << "Ans : " << ans[s / 2] <<" "<< ans[(s / 2 - 1)] << endl;
        return ((float)ans[s / 2] + ans[(s / 2 - 1)]) / (2.0);
    }
}

int main()
{
    int n, m;
    cout << "Enter The sizes Of two arrays : ";
    cin >> n >> m;
    vector<int> vec1, vec2;

    cout << "Enter The Elements OF First array : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec1.push_back(temp);
    }
    cout << endl;
    cout << "Enter The Elements OF Second array : ";
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        vec2.push_back(temp);
    }
    cout << endl;

    cout<<Solution(vec1, vec2);

    return 0;
}