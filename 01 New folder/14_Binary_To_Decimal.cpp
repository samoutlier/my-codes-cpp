#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int n, bit,ans =0;
    cout << "Enter The Binary Number To Get its Decimal Number : ";
    cin >> n;
    

    for (int i = 0;  n!=0 ; i++)
    {
        bit = n%10 ; // To Get Last Digit
        ans = ans + bit * pow(2, i);
        n=n/10;
    }
    
    cout<<"Decimal : "<<ans;
    

    return 0;
}