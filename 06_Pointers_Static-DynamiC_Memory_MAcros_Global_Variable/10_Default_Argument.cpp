#include <iostream>
#include<vector>
using namespace std;

void PrintArray(int arr[ ] , int n , int start = 0 ) //start is a default Argument
{
    for(int i = start ; i< n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{ 
    int arr [6] = {1, 4  , 7 , 8 , 9 , 52};

    PrintArray(arr, 6, 2);
    PrintArray(arr, 6);
    

    return 0;
}