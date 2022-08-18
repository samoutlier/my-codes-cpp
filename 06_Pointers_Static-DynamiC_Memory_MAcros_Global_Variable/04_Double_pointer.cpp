#include <iostream>
#include <vector>
using namespace std;

void update(int **p2)
{
    *p2 = *p2 + 1;
}

int main()
{
    int i = 5;
    int *ptr = &i;
    int **ptr2 = &ptr;

    // cout << "Address of i : " << &i << endl;
    // cout << "Address of i : " << ptr << endl;
    // cout << "Address of i : " << *ptr2 << endl;

    // cout << "Value of i is : " << i << endl;
    // cout << "Value of i is : " << *(&i) << endl;
    // cout << "Value of i is : " << *ptr << endl;
    // cout << "Value of i is : " << **ptr2 << endl;
    cout<<"Before : ";
    cout<<i<<endl;
    cout<<ptr<<endl;
    cout<<ptr2<<endl;

    update(ptr2);
    cout<<"After : ";
    cout<<i<<endl;
    cout<<*ptr<<endl;
    cout<<ptr2<<endl;
    return 0;
}