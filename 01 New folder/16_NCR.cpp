#include <iostream>
#include<stdlib.h>
using namespace std;


float fac (float x)
{   

    if(x==0)
    return 1;

    int ans = 1;
    for (int i = 1 ; i <= x; i++)
    {
        ans = ans * i;
    }
    return ans;   
}


int main()
{   
    float n , r;
    cout<<"Enter The Value Of n : ";
    cin>>n;
    cout<<"Enter The Value Of r : ";
    cin>>r;

    float ans =  (fac(n))/(fac(n-r)*fac(r));

    cout<<"Result : "<<ans;    
    return 0;
}