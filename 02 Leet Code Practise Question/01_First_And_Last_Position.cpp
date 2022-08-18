// To Give First & LAst Occurence OF Element In A Sorted Array

#include <iostream>
using namespace std;

int FirstOccur(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {   
            // while (arr[mid-1] == key)
            // {
            //     mid--;
            // }
            // return mid;
            ans =mid;
            end = mid-1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid-1;
        }
            mid = start + (end-start)/2;
    }
    return ans ;
}

int LastOccur(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {   
            // while (arr[mid+1] == key)
            // {
            //     mid++;
            // }
            // return mid;

            ans = mid ;
            start =mid + 1;
            
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid-1;
        }
            mid = start + (end-start)/2;
    }
    return ans ;
}

int main()
{
    int n;
    cout << "Enter The Size OF Array : ";
    cin >> n;
    int arr[n], target;
    cout << "Enter The Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter The Element You want to Search : ";
    cin >> target;
    int first = FirstOccur(arr, n, target);
    int last = LastOccur(arr, n, target);

    cout<<"First Index Of "<<target <<" is "<< first<<endl;
    cout<<"Last Index Of "<<target <<" is "<< last<<endl;
    return 0;
}