#include <iostream>
#include<array>

using namespace std;
int main()
{
    array<int, 4> arr = {1,2,3,4};

    cout<<"Length Of Array : "<<arr.size()<<endl;
    cout<<"Empty Or Not : "<<arr.empty()<<endl;
    cout<<"First Element : "<<arr.front()<<endl;
    cout<<"Last Element : "<<arr.back()<<endl;
    cout<<"Element at Index "<<2<<" is "<<arr.at(2)<<endl;

    return 0;
}