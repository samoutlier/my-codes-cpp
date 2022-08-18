// // To Check If Array is Sorted or not even after Rotation

// #include <iostream>
// using namespace std;

// bool SortedCheck(int arr[],int n )
// {
//     for (int i = 0; i < n-1 ; i++)
//     {
//         if(arr[i]>arr[i+1])
//         return false;
//     }
//     return true;
// }

// void PrintArray(int arr[],int n)
// {
//      for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }cout<<endl;
// }

// bool Rotate(int arr[], int n, int k)
// {
//     int copy[n];
//     for (int j = 0; j < n; j++)
//     {
//         copy[j] = arr[(j + k) % n];
//     }
//     PrintArray(copy,n);
//    return SortedCheck(copy, n);
// }

// bool Answer(int arr[], int n)
// {
//     for (int i = 0; i <= n ; i++)
//     {
//         if(Rotate(arr,n,i))
//         return true;
//     }
//     return false;
    
// }

// int main()
// {
//     int n;
//     cout << "Enter The Number Of Elements : ";
//     cin >> n;
//     cout << "Enter The ELements : ";
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     if(Answer(arr,n))
//     cout<<"The Array is Rotated Sorted ";
//     else
//     cout<<"The Array is not Rotated Sorted ";

//     return 0;
// }

// Another Method 

// To Check If Array is Sorted or not even after ROtation

#include <iostream>
using namespace std;

bool Answer(int arr[], int n)
{  int count  = 0;
    for (int i = 0; i < n-1 ; i++)
    {
        if(arr[i]>arr[i+1])
        count++;
    }
  
  if(count <= 1)
  return true;
  else
  return false;
    
}

int main()
{
    int n;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The ELements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if(Answer(arr,n))
    cout<<"The Array is Rotated Sorted ";
    else
    cout<<"The Array is not Rotated Sorted ";

    return 0;
}