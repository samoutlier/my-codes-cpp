#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter The Integer to get its complement : ";
    cin >> n;

    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    int temp = n, mask = 0;

    while(temp != 0)
    {
        mask = (mask << 1) | 1;
        temp = temp >> 1;
    }

    int ans = (~n) & mask;

    cout << ans;

    return 0;
}