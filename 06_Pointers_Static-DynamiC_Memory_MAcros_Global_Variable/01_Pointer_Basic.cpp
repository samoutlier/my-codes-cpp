#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num = 55;
    int *ptr = &num;
    int *xyz; // These are two ways to store address of pointers
    xyz = &num;

    // Address Of Operator

    cout << "Address OF Num is : " << ptr << endl;
    cout << "Value At Num is : " << *ptr << endl;
    cout << "Size Of Int is  : " << sizeof(num) << endl;
    cout << "Size Of Pointer is  : " << sizeof(ptr) << endl;

    // Copying a pointer

    int *q = ptr;
    cout << "Address Of ptr is " << ptr << endl;
    cout << "Address Of q is " << q << endl;

    // Imp COncept

    int i = 3;
    int *t = &i;
    cout << (*t)++ << endl;
    cout << *t << endl;

    *t = *t + 1; // Increses the value which the pointer points.
    t = t + 1;   // Increases the pointer position next block
                 // suppose it stores address 100 then it will go to 104 as it is int

    // Pointers Addresses

    int arr[10] = {10, 12, 83, 44, 15, 46, 27, 87, 9, 10};
    int *newptr = arr;
    cout << "Address Of First Memory Block is : " << arr << endl;
    cout << "Address Of First Memory Block is : " << &arr << endl;
    cout << "Address Of First Memory Block is : " << &arr[0] << endl;
    cout << "Address Of First Memory Block is : " << newptr << endl;

    cout << "Address Of First Memory Block is : " << *(arr) << endl;
    cout << "Address Of First Memory Block is : " << *(&arr[0]) << endl;
    cout << "Address Of First Memory Block is : " << *(newptr) << endl;

    cout << "This increases value stored at First Memory block : " << *arr + 1 << endl;
    cout << "This takes to next block : " << *(arr + 1) << endl;

    cout << "Value at third Block : " << *(arr + 2) << endl;
    cout << "Value at third Block : " << arr[2] << endl;

    cout << "Value at fifth Block : " << *(4 +arr) << endl;
    cout << "Value at fifth Block : " << 4[arr] << endl;

    return 0;
}