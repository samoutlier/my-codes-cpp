#include <iostream>
using namespace std;
int main()
{
    char ch = '1';
    cin >> ch ;
    int a = ch;
    if(a >=48 && a<=57)
    cout<<" Character is in Between 1-9 "<<endl;
    else if (a>=65  && a<=90)
    cout<<" Character is in Between A-Z (Upper Case)"<<endl;
    else if (a>=97  && a<=122)
    cout<<" Character is in Between a-z (Lower Case)"<<endl;
    else
    cout<<"It is a special Character ";
    return 0;
}