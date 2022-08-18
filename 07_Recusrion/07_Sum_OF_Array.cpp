#include <iostream>
#include <vector>
using namespace std;

int Sum(int *arr, int n)
{
    if(n>0)
    {
      return arr[n-1] + Sum(arr, n-1);
    }
    else
    return 0;
}

int main()
{
    int n;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The Elements : ";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<endl<<"The sum is : "<<Sum(arr,n);
    return 0;
}