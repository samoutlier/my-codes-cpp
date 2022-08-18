#include <iostream>
#include <vector>
using namespace std;

int Ways(int n)
{
    if (n > 2)
    {
        return Ways(n - 2) + Ways(n-1);
    }
    else if (n==2 )
    {
        return 2 ;
    }
    else if(n==1 || n==0 )
    {
      return 1;
    }
    else
    return 0;
    
}

int main()
{
    int n;
    cout << "Enter The Number OF Stairs : ";
    cin >> n;
    int ans = Ways(n);
    cout << ans;
    return 0;
}