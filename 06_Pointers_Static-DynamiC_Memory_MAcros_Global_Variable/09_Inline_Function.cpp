#include <iostream>
#include <vector>
using namespace std;

inline int GetMax(int &a, int &b)
{
    return (a > b) ? a : b;
}

// INline Function
// It reduces Extra memory usage during function call
// it replaces the line from function to where it is called
int main()
{
    int a, b;
    cout << "Eneter The Values OF A and B : ";
    cin >> a >> b;

    cout << "Greater is " << GetMax(a, b) << endl;

    a = a + 10;
    b = b + 8;
    cout << "Greater is " << GetMax(a, b) << endl;

    return 0;
}