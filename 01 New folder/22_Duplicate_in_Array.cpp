#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    cout << "Enter The Number Of ELements : ";
    cin >> n;
    cout << "Enter The ELements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

   
   //Input : 2 4 6 1 3 6
   // Output : 6
    int ans = 0 ;

    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        ans = ans ^ i;
    }

    

    cout<<ans;

    return 0;
}