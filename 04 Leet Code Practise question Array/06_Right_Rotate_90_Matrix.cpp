// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     int n, m;
//     cout << "Enter The Number Of Rows And Columns respectively : ";
//     cin >> n >> m;
//     cout << "Enter The ELements Of Array : " << endl;
//     int arr[n][m], copy[m][n];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     int d = (n > m) ? n - m : m - n;
//     cout << "The Matrix After 90 Degree Right Rotation is : " << endl;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             copy[j][n - i - d] = arr[i][j];
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << copy[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter The Number Of Rows And Columns respectively : ";
    cin >> n >> m;
    cout << "Enter The ELements Of Array : " << endl;
    int arr[n][m], copy[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "The Matrix After 90 Degree Right Rotation is : " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            copy[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int start = 0;
        int end = n-1;
        while(start<end)
        {
            swap(copy[i][start], copy[i][end]);
            start++;
            end--;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << copy[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}