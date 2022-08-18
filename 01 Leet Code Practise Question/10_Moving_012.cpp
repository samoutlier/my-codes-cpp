// #include <iostream>
// using namespace std;

// void printarray(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     int n, temp;
//     cout << "Enter The Number Of ELements : ";
//     cin >> n;
//     cout << "Enter The ELements : ";
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int i = 0, j = n - 1;
//     while (i < j)
//     {

//         while (arr[i] == 0 && i<j)
//             i++;

//         while (arr[j] == 2 && i<j )
//             j--;

//         if (arr[i] == 2 && arr[j] == 0 && i<j )
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//         else if (arr[i] == 2 && arr[j] == 1  && i<j )
//         {
//             swap(arr[i], arr[j]);
//             j--;
//         }
//         else if (arr[i] == 1 && arr[j] == 0 && i<j)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//         }
//         else if (arr[i] == 1 && arr[j] == 1 && i<j)
//         {   //while()
//             swap(arr[i], arr[i+1]);
//             swap(arr[j], arr[j-1]);
//         }

//         printarray(arr, n);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// ANother Method

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

    int count1=0, count2=0, count3=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count1++;
        else if (arr[i] == 1)
            count2++;
        else
            count3++;
    }
    for (int i = 0; i < count1 ; i++)
    {
        cout<< 0 <<" ";
    }
    for (int i = 0 ; i < count2 ; i++)
    {
        cout<< 1 <<" ";
    }
    for (int i = 0; i < count3 ; i++)
    {
        cout<< 2 <<" ";
    }
    cout<<endl;
    return 0;
}