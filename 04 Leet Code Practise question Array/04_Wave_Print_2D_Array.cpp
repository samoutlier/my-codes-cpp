#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter The Number Of Rows And Columns respectively : ";
    cin >> n >> m;
    cout << "Enter The ELements Of Array : "<<endl;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "The ELements Are In Sine Wave Pattern are : ";
    int i = 0;
    for (int j = 0; j < m; j++)
    {
        if (i == 0)
        {
            while (i < n)
            {
                cout << arr[i++][j] << " ";
            }
            i = n - 1;
        }
        else
        {
            while (i >= 0)
            {
                cout << arr[i--][j] << " ";
            }
            i=0;
        }
    }

    return 0;
}