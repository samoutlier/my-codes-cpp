// //Reverse Array after mth Position

// #include <iostream>
// using namespace std;

// void PrintArray(int arr[], int n )
// {
//     for (int i = 0; i < n ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }cout<<endl;

// }

// void ReverseArray(int arr[],int n , int index)
// {
//    int start = index;
//    int end= n-1;

//    while(start<end)
//    {
//        swap(arr[start],arr[end]);
//        start++;
//        end--;
//    }
// }

// int main()
// {
//     int n, index;
//     cout<<"Enter The Number OF elements : ";
//     cin>>n;
//     cout<<"Enter The ELements : ";
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }

//     cout<<"Enter The Index to Revers the array : ";
//     cin>>index;
//     ReverseArray(arr,n,index);
//     PrintArray(arr,n);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> ReverseArray(vector<int> v, int index)
{
    int start = index;
    int end = v.size() - 1;

    while (start < end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    }
    return v;
}

int main()
{
    vector<int> vec;
    vec.push_back(15);
    vec.push_back(195);
    vec.push_back(19);
    vec.push_back(-96);
    vec.push_back(1);
    vec.push_back(105);
    vec.push_back(148);
    vec.push_back(14);
    vec.push_back(178);

    int index;
    cout<<"Enter The Index to Revers the Vector : ";
    cin>>index;
    cout<<"Before Reverse : ";
    PrintVector(vec);
    vector<int> ans = ReverseArray(vec,index);
    cout<<endl<<"After Reverse : ";
    PrintVector(ans);


    
    return 0;
}