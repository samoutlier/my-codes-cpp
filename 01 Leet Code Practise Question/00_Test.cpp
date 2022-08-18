#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
 
 
 
int main()
{
    int arr[] = {1,2,3,4,5};
    int *ptr1 = &arr[0];
    int * ptr2 = arr + 3;
    // cout<<ptr2-ptr1<<endl;
    // cout<<ptr1<<endl;
    // cout<<ptr2<<endl;
    int x = &arr[2] - &arr[0];
    cout<<x;
    return 0;
}