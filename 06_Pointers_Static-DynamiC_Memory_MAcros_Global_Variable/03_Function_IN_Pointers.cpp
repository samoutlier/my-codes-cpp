#include <iostream>
#include <vector>
using namespace std;

void update(int *ptr)
{
    *ptr = *ptr + 1;
    ptr = ptr + 1;
    cout << "Inside Address : " << ptr << endl;
}

void update1(int arr[])
{
    cout<<"Size Of Arr : "<<sizeof(arr)<<endl;
}

int main()
{
    int num = 5;
    int *ptr = &num;
    // cout << ptr << endl;
    // cout << *ptr << endl;
    // ptr = ptr + 1;
    // cout << ptr << endl;
    // cout << *ptr << endl;
    cout << "Before Address : " << ptr << endl;
    cout << "Before Value : " << *ptr << endl;
    update(ptr);
    cout << "After Address : " << ptr << endl;
    cout << "After Value : " << *ptr << endl;


    int arr[5]= {1,2,3,4,5,};

    update1(arr);

    return 0;
}

 