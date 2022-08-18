#include <iostream>
#include <vector>
using namespace std;

void Print(int n, int k, int temp)
{
    if (n <= temp)
    {
    cout << n << " ";
        Print(n + k, k, temp);
    }
}

void PrintSeries(int n, int k, int temp)
{
    cout << n << " ";
    if (n > 0)
    {
        PrintSeries(n - k, k, temp);
    }
    else
    Print(n + k, k, temp);
}

int main()
{
    int n, k;
    cout << "ENter The Value Of n : ";
    cin >> n;
    cout << "ENter The Value Of k : ";
    cin >> k;

    PrintSeries(n, k, n);
    return 0;
}