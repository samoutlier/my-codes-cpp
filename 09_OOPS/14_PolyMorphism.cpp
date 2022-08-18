#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    // COMPILE TIME OVERLOADING
    //  Function OverLoading with Different Number Of Arguments
    void SayHello()
    {
        cout << "Hello Abdul Samad " << endl;
    }
    void SayHello(string name)
    {
        cout << "Hello " << name << endl;
    }

    // Function OverLoading with Different Types Of Arguments
    int add(int num1, int num2)
    {
        return num1 + num2;
    }
    int add(int num1, int num2, int num3)
    {
        return num1 + num2 + num3;
    }

    // Default Argument
    int sum(int x, int y, int z = 0, int w = 0)
    {
        return (x + y + z + w);
    }
};

int main()
{
    A obj;

    obj.SayHello();
    obj.SayHello("Abdul Samad");

    cout << obj.add(100, 200) << endl;
    cout << obj.add(100, 200, 300) << endl;

    cout << obj.sum(10, 20) << endl;
    cout << obj.sum(10, 20, 30) << endl;
    cout << obj.sum(10, 20, 30, 40) << endl;
    return 0;
}