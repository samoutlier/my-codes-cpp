#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int n;
    cout << "Enter The Decimal Number To Get its Bianry Number : ";
    cin >> n;

    int temp = n;

    int bit ;
    int ans = 0;

    for (int i = 0; n != 0; i++)
    {
        bit = n & 1;
        n = n >> 1;
        ans = ans + (bit * pow(10, i));
    }
    cout << "Binary Of " << temp << " is : " << ans;

    return 0;
}