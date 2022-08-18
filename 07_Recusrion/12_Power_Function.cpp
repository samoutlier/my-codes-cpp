// a raise to the power b

#include <iostream>
#include <vector>
using namespace std;

double Solve(double x, long n)
{
    if (n == 0)
        return 1.0;
    if (n == 1)
        return x;
    if (x == 1.0)
        return 1;

    double ans = Solve(x, n / 2);
    return (n % 2) ? x * ans * ans : ans * ans;
}
double myPow(double x, int n)
{   

    bool check = false;
    double ans ;
    if(n<0)
    {
     check = true;
     ans = Solve(x , -n);
    }

    else
    ans = Solve( x, n) ;

    return (check) ? (1/ans) : ans;  
}

int main()
{
    double a;
    long b;
    cout << "Enter The Base : ";
    cin >> a;

    cout << "Enter The Power : ";
    cin >> b;

    double ans = myPow(a, b);
    cout << ans;
    return 0;
}