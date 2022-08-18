#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter The Number Of Elements of both Arrays : ";
    cin >> n >> m;
    cout << "Enter The ELements Of first Array : ";
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter The ELements Of second Array : ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    int j = n - 1, k = m - 1, sum, carry = 0;
    vector<int> v;
    while (j >= 0 && k >= 0)
    {
        sum = arr1[j] + arr2[k] + carry;
        carry = sum / 10;
        v.push_back(sum % 10);
        j--;
        k--;
    }

    while (j >= 0)
    {
        sum = arr1[j] + carry;
        carry = sum / 10;
        v.push_back(sum % 10);
        j--;
    }

    while (k >= 0)
    {
        sum = arr2[k] + carry;
        carry = sum / 10;
        v.push_back(sum % 10);
        k--;
    }
    if(carry>0)
    {
        v.push_back(carry);
    }

   cout<<"The Sum Is : ";

    for(int z = v.size()-1 ; z>=0; z--)
    {
        cout<<v[z];
    }cout<<endl;

    return 0;
}