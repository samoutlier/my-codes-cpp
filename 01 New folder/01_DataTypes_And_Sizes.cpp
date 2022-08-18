#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    char ch = 's';
    float f = 52.36663;
    double d = 25.6385858;
    bool b = true;

   cout<< a << endl; 
   cout<< ch << endl; 
   cout<< f << endl; 
   cout<< d << endl; 
   cout<< b << endl; 
   cout<<"Size Of int : " <<sizeof(a) << endl; 
   cout<<"Size Of character : " <<sizeof(ch) << endl; 
   cout<<"Size Of float : "  <<sizeof(f) << endl; 
   cout<<"Size Of double : " <<sizeof(d) << endl;
   cout<<"Size Of Bool : " <<sizeof(b) << endl;

   cout<< 6/5 << endl;
   cout<< a/d << endl;
   cout<< f/d << endl;
   cout<< 2.0/2.1 << endl;
   cout<< 2.0/5 << endl;
    
}