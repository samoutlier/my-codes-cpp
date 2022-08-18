// #include <iostream>
// #include <math.h>

// using namespace std;

// int main()
// {
//     int n, temp, mask = 0;
//     cout << "Enter The Integer to get its complement : ";
//     cin >> n;
//     bool b = true;
//     n = n - 1;

//     if (n < 0 )
//     {
//         cout << 0;
//         return 0;
//     }

//     temp = n;
//     while (temp != 0)
//     {
//         mask = (mask << 1) | 1;
//         temp = temp >> 1;
//     }

//     if (mask == n)
//         cout << b;
//     else
//         cout << false;

//     return 0;
// }

// ANothe Effective Method

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, count =0;
//     cout << "Enter The Number : ";
//     cin >> n;
//     int temp = n;
//     while(n!=0)
//     {
//       if (n&1==1)
//       {
//           count ++;
//       }
//      n = n>>1;
//     }
//     if(count==1)
//     cout<<temp<<" is a Power Of 2";
//     else
//     cout<<temp<<" is not a Power Of 2";
//     return 0;
// }

// For number greater than 0
#include <iostream>
using namespace std;
int main()
{
    int n, count = 0;
    cout << "Enter The Number : ";
    cin >> n;
    int temp = n;
   // n = n-1;

    while (n != 0)
    {
        if (n & 1 == 1)
        {
            count++;
        }
        n = n >> 1;
    }
    if (count == 1)
        cout << temp << " is a Power Of 2";
    else
        cout << temp << " is not a Power Of 2";
    return 0;
}