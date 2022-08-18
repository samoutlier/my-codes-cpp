#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{   
    int x;
    cout<<"Enter The Money : ";
    cin >> x;
    int n = 1;
    switch(n)
    {
        case 1 :
        cout<<"No. oF 100 Rs "<< x/100 <<endl;
        x=x%100;

        case 2 : 
        cout<<"No. oF 50 Rs "<< x/50 <<endl;
        x=x%50 ;

        case 3 :
        cout<<"No. oF 10 Rs "<< x/10 <<endl;
        x=x%10;

        cout<<"No. oF 100 Rs "<< x <<endl;
               
    }
}