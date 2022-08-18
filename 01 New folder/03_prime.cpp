#include <iostream>
using namespace std;
int main()
{
    int x;
    bool b = true;
    cout << "Enter The number : ";
    cin >> x;
    for (int i = 2; i < x / 2 + 1; i++)
    {
        if (x % i == 0)
        {
            cout << x << " is a Not Prime" << endl;
            b=false;
            break;
        }
    }
    if ((b == true || x==2) && x!=1)
        cout << x << " is a Prime" << endl;
    if(x==1)
        cout << x << " is neither Prime Nor Composite " << endl;
    return 0;
}