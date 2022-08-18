#include <iostream>
using namespace std;
int main()
{
    int a = 4, b = 6;

    cout << "a&b " << (a & b) << endl;
    cout << "a|b " << (a | b) << endl;
    cout << "a^b " << (a ^ b )<< endl;
    cout << "~a " << (~a) << endl;
    cout << "!a " << (!a) << endl;

    cout<< "Left Shift Of 19 one time " <<(19>>1) <<endl;
    cout<< "Left Shift Of 19 two time " <<(19>>2) <<endl;
    cout<< "Right Shift Of 17 one time " << (17>>1) <<endl;
    cout<< "Right Shift Of 17 two times " << (17>>2) <<endl;
    return 0;
}