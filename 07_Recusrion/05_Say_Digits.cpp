#include <iostream>
#include<vector>
using namespace std;

void SayDigits(int n)
{
   if(n>0)
   {
       SayDigits(n/10);
       if(n%10 == 9)
       cout<<"Nine ";
       else if(n%10 == 8)
       cout<<"Eight ";
       else if(n%10 == 7)
       cout<<"Seven ";
       else if(n%10 == 6)
       cout<<"Six ";
       else if(n%10 == 5)
       cout<<"Five ";
       else if(n%10 == 4)
       cout<<"Four ";
       else if(n%10 == 3)
       cout<<"Three ";
       else if(n%10 == 2)
       cout<<"Two ";
       else if(n%10 == 1)
       cout<<"One ";
       else
       cout<<"Zero ";
   }   
}

int main()
{
    int n ;
    cin >> n ;
    SayDigits(n);
    return 0;
}