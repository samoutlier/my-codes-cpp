#include <iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> Solution(int * arr, int n)
{
    map<int, bool> check;
    vector<int> ans;

    // for (int i = 0; i < n ; i++)
    // {
    //      check[arr[i]]= false;
    // }

    for (int i = 0; i < n ; i++)
    {
        if(check[arr[i]])
        ans.push_back(arr[i]);
        check[arr[i]] = true;
    }
    
    return ans ;
       
}

int main()
{
    int n, temp;
    cout << "Enter The Number Of ELements : ";
    cin >> n;
    cout << "Enter The ELements : ";

    int * arr = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = Solution(arr, n);

    for (int i = 0; i < ans.size() ; i++)
    {
       cout<<ans.at(i)<<" ";
    }
    return 0;
}