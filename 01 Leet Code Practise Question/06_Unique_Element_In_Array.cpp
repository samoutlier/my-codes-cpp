// // Unique Element
// #include <iostream>
// using namespace std;

// int unique(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         bool found = true;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i] == arr[j] && i != j)
//             {
//                 found = false;
//                 break;
//             }
//         }
//         if (found)
//         {
//             return arr[i];
//         }
//     }
// }
// int main()
// {
//     int n, m, test;
//     cout << "Enter The Number OF Test Cases : ";
//     cin >> test;

//     for (int j = 0; j < test; j++)
//     {
//         cout << "Enter The Number Of ELements : ";
//         cin >> n;
//         cout << "Enter The ELements : ";
//         int arr[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         cout << unique(arr, n);
//     }

//     return 0;
// }

// Optimised Solution

// Unique Element
#include <iostream>
using namespace std;

int unique(int arr[], int n)
{
        int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = ans ^ arr[j];
        }
    }
    return ans;
}
int main()
{
    int n, m, test;
    cout << "Enter The Number OF Test Cases : ";
    cin >> test;

    for (int j = 0; j < test; j++)
    {
        cout << "Enter The Number Of ELements : ";
        cin >> n;
        cout << "Enter The ELements : ";
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << unique(arr, n)<<endl<<endl;;
    }

    return 0;
}