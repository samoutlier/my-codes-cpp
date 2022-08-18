// Moving Zeros To Right Most

#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The ELements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int nonZero = 0;
    
    // 0 2 0 2 0

    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[j], arr[nonZero]);
            nonZero++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}