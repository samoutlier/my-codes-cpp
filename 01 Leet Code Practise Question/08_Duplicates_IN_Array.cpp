// Unique Element
#include <iostream>
using namespace std;

void duplicate(int arr[], int n)
{   int copy[n], k=0 ;

    for (int i = 0; i < n-1 ; i++)
    {
        for (int j = i+1 ; j < n; j++)
        {
            if (arr[i] == arr[j] )
            {
                copy[k] =arr[i];
                k++;
                break;
            }
        }   
    }
    copy[k]=k;
    cout<<"[ ";
    for(int i=0; i< k ; i++)
    {
        cout<<copy[i]<<" ";
    }
    cout<<"]"<<endl;
}
int main()
{
    int n, m, test;
    cout << "Enter The Number OF Test Cases : ";
    cin >> test;

    for (int j = 0; j < test; j++)
    {
        cout << "Enter The Number Of ELements : ";
        cin >> n;
        cout << "Enter The ELements : ";
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        duplicate(arr , n);
    }

    return 0;
}