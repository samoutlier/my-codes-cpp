#include <iostream>
#include <vector>
using namespace std;

bool IsSorted(int * arr , int n)
{
    if(n==0 || n==1)
    {
       return true ;
    }
    if(arr[n-1] < arr[n-2])
    {
        return false;
    }
    else
    {
        return IsSorted(arr, n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if( IsSorted(arr, n))
    cout <<"Array SOrted ;) ";
    else
    cout <<"Array is not SOrted :( ";


    return 0;
}