#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter The Number Of Rows And Columns respectively : ";
    cin >> n >> m;
    cout << "Enter The ELements Of Array : " << endl;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "The ELements in Spiral Pattern are : ";

    int count = 0, StartingRow = 0, StartingColumn = 0, EndingRow = n - 1, EndingColumn = m - 1;

// 1 2 3 4
// 5 6 7 8 
// 9 10 11 12
// 13 14 15 16



    while (count < m * n)
    {
        for (int index = StartingColumn; count < m * n && index <= EndingColumn; index++)
        {
            cout << arr[StartingRow][index] << " ";
            count++;
        }
        StartingRow++;
        
        for (int index = StartingRow; count < m * n && index <= EndingRow; index++)
        {
            cout << arr[index][EndingColumn] << " ";
            count++;
        }
        EndingColumn--;

        for (int index = EndingColumn; count < m * n && index >= StartingColumn; index--)
        {
            cout << arr[EndingRow][index] << " ";
            count++;
        }
        EndingRow--;

        for (int index = EndingRow; count < m * n && index >= StartingRow; index--)
        {
            cout << arr[index][StartingColumn] << " ";
            count++;
        }
        StartingColumn++;
    }
    return 0;
}