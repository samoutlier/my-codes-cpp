#include <iostream>
#include <vector>
using namespace std;

class Complex
{
private:
    int real, imaginary;

public:
    // Constructor call
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }

    Complex operator+(Complex &temp)
    {
        Complex xyz;
        xyz.real = real + temp.real;
        xyz.imaginary = imaginary + temp.imaginary;
        return xyz;
    }
    void print()
    {
        cout << real << " + i" << imaginary << endl;
    }
};

int main()
{
    Complex C1(25, 36), C2(63, 48), C3;

    C3 = C1 + C2;
    C3.print();
    return 0;
}