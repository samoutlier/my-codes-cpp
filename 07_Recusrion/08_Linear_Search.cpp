#include <iostream>
#include <vector>
using namespace std;

int Find(int *arr, int n, int key)
{
    if(n>0 && arr[n-1]==key)
    {
      return n-1;
    }
    else if(n>0 && arr[n-1] != key)
    {
        return Find(arr, n-1 , key);
    }
    else
    return -1 ;
}

int main()
{
    int key ,n;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The Elements : ";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter The Key To Search : ";
    cin>>key;
    cout<<key << " is present at : "<<Find(arr,n, key);
    return 0;
}