#include <iostream>
using namespace std;

int fib ( int n )
{  if(n>=2)
   return fib(n-1) + fib(n-2);
   else if(n==1)
   return 1;
   else
   return 0;
}

int main()
{
    int n;
    cout<<"Enter The Term You want to know : ";
    cin>>n;
    int ans = fib( n);
    cout<<ans;
    return 0;
}