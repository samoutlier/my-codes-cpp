#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "Enter The Integer : ";
    cin >> n;

    int temp = n, digit, rev = 0;

    for (int i = 0; temp != 0; i++)
    {
        digit = temp % 10;
        
        if(rev > (INT32_MAX/10) || rev < (INT32_MIN/10))
        {
            cout<< 0 ;
            return 0;
        }
        rev = rev * 10 + digit;
        temp = temp / 10;

    }

        cout << rev;

    return 0;
}