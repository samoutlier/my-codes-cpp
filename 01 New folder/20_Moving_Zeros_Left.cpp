#include <iostream>
using namespace std;

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
    int i = 0, j = n - 1;
    while (i < j)
    {  //One Method 

        // if(arr[i]==0 )
        // i++;
        // else if(arr[i]==1)
        // {
        //     swap(arr[i],arr[j]);
        // }

        // if(arr[j]==1 )
        // j--;
        // else if(arr[j]==0)
        // {
        //     swap(arr[i],arr[j]);
        // }

        //Second Method

        // if (arr[i] == 0)
        //     i++;

        // if (arr[j] == 1)
        //     j--;

        // if (arr[i] == 1 && arr[j] == 0)
        // {
        //     swap(arr[i], arr[j]);
        //     i++;
        //     j--;
        // }

        //Third Method
        while (arr[i] == 0 && i<j)
            i++;

        while (arr[j] == 1 && i<j )
            j--;

        // if (arr[i] == 1 && arr[j] == 0)
        // {
            swap(arr[i], arr[j]);
            i++;
            j--;
        //}



    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}