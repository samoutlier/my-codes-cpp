

#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The ELements : ";
    int arr[n], copy[n], k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter The number By which you want to rotate : ";
    cin >> k;

    // 0 2 0 2 0
    // 1 2 0 0 0
    // 8 0 5 0 6 5 8 4 0
    // 8 4 0 8 0 5 0 6 5 
    for (int j = 0; j < n; j++)
    {
        copy[j] = arr[(j + k) % n];
    }
    for (int i = 0; i < n; i++)
    {
        cout << copy[i] << " ";
    }

    return 0;
}