//          *
//        * *
//      * * *
//    * * * *
//  * * * * *

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter The Nuber Of Lines : ";
//     cin >> n;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << "  ";
//         }
//         for (int j = n - i+1; j <= n; j++)
//         {
//             cout << " *";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// *****
// ****
// ***
// **
// *

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter The Nuber Of Lines : ";
//     cin >> n;

//     for (int i = 0 ; i < n; i++)
//     {
//         for (int j = 0 ; j < n - i; j++)
//         {
//             cout << " *";
//         }
//         for (int j = n-i+1 ; j < n; j++)
//         {
//             cout << "  ";
//         }
//         cout << endl;
//     }
//     return 0;
// }



// * * * * * 
//   * * * *
//     * * *
//       * *
//         *

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter The Nuber Of Lines : ";
    cin >> n;

    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0 ; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = i ; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}