#include <iostream>
using namespace std;

int SquareRoot(int n)
{
    int start = 0;
    int end = n;
    long long int mid = start + (end - start) / 2;
    long long int ans;
    while (start <= end)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        if (mid * mid < n)
        {
            ans = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

float DecimalSquareRoot(int n)
{
    double ans = SquareRoot(n);
    double factor = 1;
    int precision = 3;
    for (int i = 0; i < precision; i++)
    {   factor/=10;
        for (double j = ans ; j*j<n ; j+=factor)
        {
            ans = j;
        }
        
    }
    return ans;

}

int main()
{
    int n;
    cout << "Enter The Number To get its square root : ";
    cin >> n;
    cout << "The Square Root Of " << n << " is " << DecimalSquareRoot(n);
    return 0;
}