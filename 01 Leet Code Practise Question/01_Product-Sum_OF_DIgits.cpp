#include <iostream>
using namespace std;
int main()
{
    int n, product = 1 , sum=0;
    cout << "Enter The Number : " ;
    cin>> n;
    
    int temp = n;

    while(temp>0)
    {
       product*= (temp%10);
       sum += (temp%10);
       temp /=10;
    }
    
    cout << "Result Of P-S : "<<product-sum<<endl;
    
    return 0;
}