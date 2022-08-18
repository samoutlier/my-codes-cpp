// Unique Element
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> TripletSum(int arr[], int n, int target)
{
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    // cout << arr[i] << " + " << arr[j] << " + " << arr[k]<<endl;
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                }
            }
        }
    }

    return ans;
}
int main()
{
    int target, n;
    cout << "Enter The Number Of ELements : ";
    cin >> n;
    cout << "Enter The ELements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter The Target : ";
    cin >> target;

    vector<vector<int>> ans = TripletSum(arr, n, target);
    for (int i = 0; i < ans.size(); i++)
    {
        vector<int> temp = ans.at(i);
        for (int j = 0; j < 3; j++)
            cout << temp.at(j) << " ";
        cout<<endl;
    }

    return 0;
}