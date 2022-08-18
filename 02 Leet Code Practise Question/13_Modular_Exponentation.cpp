#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int x, n, m, result = 1;
    cout << "ENter The Values oF X and n : ";
    cin >> x >> n >> m;

    while (n > 0)
    {
        if (n & 1)
        {
            result = (result * x) % m;
        }
        x = ((x % m) * (x % m)) % m;
        n = n >> 1;
    }
    cout << result;
    return 0;
}