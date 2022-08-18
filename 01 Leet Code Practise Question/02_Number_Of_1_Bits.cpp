// first Method

// #include <iostream>
// using namespace std;
// int main()
// {
//     unsigned int n, count =0;
//     cout << "Enter The Number : ";
//     cin >> n;
    
//     while(n>0)
//     {
//       if (n%2==1)
//       {
//           count ++;
//       }
//       n=n/2;      
//     }
//     cout<<"Number Of 1's Bits are : "<<count;
//     return 0;
// }


// another Method

#include <iostream>
using namespace std;
int main()
{
    int n, count =0;
    cout << "Enter The Number : ";
    cin >> n;
    
    while(n!=0)
    {
      if (n&1==1)
      {
          count ++;
      }
     n = n>>1;     
    }
    cout<<"Number Of 1's Bits are : "<<count;
    return 0;
}