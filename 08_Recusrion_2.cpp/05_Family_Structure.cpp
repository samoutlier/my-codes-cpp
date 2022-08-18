#include <iostream>
#include <vector>
using namespace std;

long long int Power(int a, int b)
{
    if (b == 1)
        return a;
    else if (b == 0)
    {
        return 1;
    }
    else
    {
        if (b & 1)
        {
            return a * Power(a, b - 1);
        }
        else
        {
            return Power(a, b >> 1) * Power(a, b >> 1);
        }
    }
}

char FamilyStructure(char root_gender, int n, long long int k)
{
    if (n == 1 && k == 1)
        return root_gender;
    if (n == 1 && k != 1)
    {
        cout << "Wrong Input : ";
        return 'X';
    }
    long long int c = Power(2, n - 1);

    if (k <= c / 2)
    {
        if (root_gender == 'M')
            return FamilyStructure('M', n - 1, k);
        else
            return FamilyStructure('F', n - 1, k);
    }
    else if (k <= c)
    {
        if (root_gender == 'M')
            return FamilyStructure('F', n - 1, k - (c / 2));
        else
            return FamilyStructure('M', n - 1, k - (c / 2));
    }
}

int main()
{
    int n, k;
    cout << "Enter The generation number : ";
    cin >> n;
    cout << "Enter The family member : ";
    cin >> k;
    char ans = FamilyStructure('M', n, k);
    cout << ans;
    return 0;
}