// Binary Search IN 2D Array

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter The Number Of Rows And Columns respectively : ";
    cin >> n >> m;
    cout << "Enter The ELements Of Array : " << endl;
    int arr[n][m], target;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Enter The Element To Search : ";
    cin >> target;

    int start = 0;
    int end = m * n - 1;
    int mid = start + (end - start) / 2;

    int pos1 = -1, pos2 = -1;

    while (start <= end)
    {

        if (arr[mid / m][mid % m] == target)
        {
            pos1 = mid / m;
            pos2 = mid % m;
            break;
        }
        else if (arr[mid / m][mid % m] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    cout << pos1 << " " << pos2;

    return 0;
}

