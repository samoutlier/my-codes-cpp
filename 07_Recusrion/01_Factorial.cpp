#include <iostream>
#include<vector>
using namespace std;

long long int fac(int n)
{   cout<<"Calling : "<<n<<endl;
    if(n>0)
    return n * fac(n-1);
    else
    return 1;
}

int main()
{
    int n ;
    cin>>n;
    long long int ans = fac(n);
    cout<<ans;
    return 0;
}