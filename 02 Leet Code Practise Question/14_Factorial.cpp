#include <iostream>
using namespace std;

int Fact(long long int x,long long int m)
{
    if(x>1)
    return (x * Fact(x-1, m))%m;
    else
    return 1;
}

int main()
{
    long long int x, m = 1000000007;
    cout << "ENter The Values oF X  : ";
    cin >> x ;

    cout<<Fact(x, m);
    return 0;
}