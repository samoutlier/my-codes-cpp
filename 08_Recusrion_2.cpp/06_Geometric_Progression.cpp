#include <iostream>
#include <vector>
using namespace std;

long long int Power(int base, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return base;

    if (n & 1)
        return base * Power(base, n / 2) * Power(base, n / 2);
    else
        return  Power(base, n / 2) * Power(base, n / 2);
}

long long int Solution(int a, int r, int n)
{
    if (n == 1)
        return a;
    return a * Power(r, n - 1);
}
int main()
{
    int n, a, r;
    cout << "ENter The Value Of a : ";
    cin >> a;
    cout << "ENter The Value Of r : ";
    cin >> r;
    cout << "ENter The Value Of n : ";
    cin >> n;

    cout << Solution(a, r, n);

    return 0;
}