// Swap ALtenate

#include <iostream>
using namespace std;

void update(int arr[], int n)
{
    for (int i = 0; i < 2*(n/2) ; i=i+2)
    {
       swap(arr[i], arr[i + 1]);
    }
}
int main()
{
    int n, temp;
    cout << "Enter The Number Of ELements : ";
    cin >> n;
    cout << "Enter The ELements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    update(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}