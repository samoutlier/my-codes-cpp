#include <iostream>
using namespace std;
int main()
{
    int n, temp;
    cout<<"Enter The Number Of ELements : ";
    cin>>n;
    cout<<"Enter The ELements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    for (int i = 0; i < n/2; i++)
    {
    //     temp = arr[n-i-1];
    //     arr[n-i-1] = arr[i];
    //     arr[i] = temp;

       swap(arr[i], arr[n-i-1]);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
       
    return 0;
}