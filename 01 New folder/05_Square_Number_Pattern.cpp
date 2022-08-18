// 1 1 1 1 1
// 2 2 2 2 2
// 3 3 3 3 3
// 4 4 4 4 4
// 5 5 5 5 5

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n ;
//     cout << "Enter The Nuber OF Lines : ";
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         for(int j=0 ; j<n; j++)
//         {
//             cout<< i+1 <<" ";
//         }
//             cout<< endl;
//     }

//     return 0;
// }

// 1 1 1 1 1
//   2 2 2 2
//     3 3 3
//       4 4
//         5

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter The Nuber OF Lines : ";
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0 ; j < i ; j++)
//         {
//             cout << "  ";
//         }
//         for (int j = i ; j < n ; j++)
//         {
//             cout << i + 1 << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }

//         5
//       4 4
//     3 3 3
//   2 2 2 2
// 1 1 1 1 1

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter The Nuber OF Lines : ";
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << "  ";
//         }
//         for (int j = n - i-1; j < n; j++)
//         {
//             cout << n - i << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }

// 1 2 3 4 5
//   2 3 4 5
//     3 4 5
//       4 5
//         5

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter The Nuber OF Lines : ";
//     cin >> n;
//     int x;

//     for (int i = 0; i < n; i++)
//     {
//         x = i+1;
//         for (int j = 0; j < i; j++)
//         {
//             cout << "  ";
//         }
//         for (int j = i; j < n; j++)
//         {
//             cout << x << " ";
//             x++;
//         }

//         cout << endl;
//     }

//     return 0;
// }

//             1
//         2   3
//     4   5   6
// 7   8   9   10

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter The Nuber OF Lines : ";
//     cin >> n;
//     int x = 1;

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << "    ";
//         }
//         for (int j =n- i-1; j < n; j++)
//         {
//             cout << x << "   ";
//             x++;
//         }

//         cout << endl;
//     }

//     return 0;
// }

//                 1
//               1 2 1
//             1 2 3 2 1
//           1 2 3 4 3 2 1
//         1 2 3 4 5 4 3 2 1
//       1 2 3 4 5 6 5 4 3 2 1
//     1 2 3 4 5 6 7 6 5 4 3 2 1
//   1 2 3 4 5 6 7 8 7 6 5 4 3 2 1
// 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, x;
//     cout << "Enter The Nuber OF Lines : ";
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         x = 1;
//         for (int j = 1; j < n - i; j++)
//         {
//             cout << "  ";
//         }
//         for (int j = n - i; j <= n; j++)
//         {
//             cout << x << " ";
//             x++;
//         }
//         x--;
//         for (int j = 1; j <= i; j++)
//         {
//             x--;
//             cout << x << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }

// 1 2 3 4 5 5 4 3 2 1
// 1 2 3 4 * * 4 3 2 1
// 1 2 3 * * * * 3 2 1
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, x;
//     cout << "Enter The Nuber OF Lines : ";
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         x = 1;
//         for (int j = 0; j < n - i; j++)
//         {
//             cout << x << " ";
//             x++;
//         }
//         for (int j = 0; j < 2 * i; j++)
//         {
//             cout << "* ";
//         }
//         x--;
//         for (int j = 0; j < n - i; j++)
//         {
//             cout << x << " ";
//             x--;
//         }
//         cout << endl;
//     }
//     return 0;
//}


// * * * * * * *
//  * * * * * *
//   * * * * *
//    * * * *
//     * * * 
//      * *
//       *

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter The Nuber OF Lines : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0 ; j < n-i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
