// To Find Pivot In Array which shows equal Sum to RHS ans LHS 

#include <iostream>
using namespace std;

int PivotIndex(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k1 = 0, k2 = j + 1;
            int sum1 = 0, sum2 = 0;
            while (k1 < j)
            {
                sum1 += arr[k1];
                k1++;
            }
            while (k2 < n)
            {
                sum2 += arr[k2];
                k2++;
            }
            if (sum1 == sum2)
            {
                return j;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter The Size OF Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter The Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The Pivot is : " << PivotIndex(arr, n);
    return 0;
}