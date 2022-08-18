#include <iostream>
#include <vector>
using namespace std;

void PrintCounting(int n)
{
    if (n > 1)
        PrintCounting(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;
    PrintCounting(n);
    return 0;
}