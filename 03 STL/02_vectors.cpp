#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> vec;

    cout << "Capacity : " << vec.capacity() << endl;

    vec.push_back(123);
    cout << "Capacity : " << vec.capacity() << endl;
    vec.push_back(10);
    cout << "Capacity : " << vec.capacity() << endl;
    vec.push_back(15);
    cout << "Capacity : " << vec.capacity() << endl;
    cout << "Size : " << vec.size() << endl;

    cout << "Element At Index 2 : " << vec.at(2) << endl;
    cout << "Element At Front : " << vec.front() << endl;
    cout << "Element At Last : " << vec.back() << endl;

    cout<<"Before Pop : ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;

    vec.pop_back(); //To take Out Last element

    cout<<"After Pop : ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec.at(i)<<" ";
    }


    cout<<endl<<"Before Clear : "<<vec.size()<<endl;
    vec.clear();
    cout<<"After Clear : "<<vec.size()<<endl;
    
    cout << "Capacity : " << vec.capacity() << endl;



    return 0;
}