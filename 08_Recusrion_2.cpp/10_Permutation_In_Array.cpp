#include <iostream>
#include <vector>
using namespace std;

void Input(vector<int> & arr)
{   int temp ;
    cin>>temp;
    arr.push_back(temp);
} 

void Permutation(vector<int>& arr, int index, vector<int> & output,vector<vector<int>>  &ans)
{
    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        output.push_back(arr[index]);
        Permutation(arr, index + 1, output, ans);
        output.pop_back();
        swap(arr[index], arr[i]);
    }
}

vector<vector<int>>  Solution(vector<int> arr)
{
    vector<vector<int>>  ans;
    vector<int> output;
    int index = 0;
    Permutation(arr, index, output, ans);
    return ans;
}

int main()
{
    int n;
    cout << "Enter The Number Of ELements : ";
    cin >> n;
    cout << "Enter The ELements : ";

    vector<int> arr;
    for(int i = 0 ; i<n ; i++)
    {
        Input(arr);
    }

    vector<vector<int>> ans = Solution(arr);

    cout<<"The Permutations are : "<<endl;

    for (int i = 0; i < ans.size(); i++)
    {
       vector<int> temp = ans[i];
       for (int j = 0 ; j<temp.size() ; j++)
       {
           cout<<temp[j]<<" ";
       }cout<<endl;
       
    }
    return 0;
}