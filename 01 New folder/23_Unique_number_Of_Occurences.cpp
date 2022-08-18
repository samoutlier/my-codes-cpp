#include <iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> CheckingOccurences(map<int, int> count , int * arr , int n)
{
    vector<int> ans;
    map<int, bool> check;

    for (int i = 0; i < n ; i++)
    {
       check[count[arr[i]]]= false;
    }
    

    for (int i = 0; i < count.size() ; i++)
    {
        if(check[count[i]])
        ans.push_back(count[arr[i]]) ;
        check[count[arr[i]]] = true ;
    }
    
    return ans ;
       
}

bool Solution(int * arr, int n)
{
    map<int, int> count;
    vector<int> ans;

    for (int i = 0; i < n ; i++)
    {
         count[arr[i]]= 0 ;
    }

    for (int i = 0; i < n ; i++)
    {
        count[arr[i]]++ ; 
    } 
    for (int i = 1; i <= 4; i++)
    {
        cout<<count[i]<<" ";
    }
    cout<<endl;
    

    ans = CheckingOccurences(count, arr, n);
    
     for (int i = 0; i < ans.size() ; i++)
    {
       cout<<ans.at(i)<<" ";
    } 
    cout<<endl;
    if(ans.empty())
    return true;
    return false;

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

   cout<<" unique Solution : "<<Solution(arr, n);
    return 0;
}