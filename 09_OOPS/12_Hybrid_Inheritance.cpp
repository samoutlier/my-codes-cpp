#include <iostream>
#include<vector>
using namespace std;
 
class A
{
   public :
   void func1()
   {
       cout<<"Inside Function A "<<endl;
   }
};

class D
{
   public :
   void func4()
   {
       cout<<"Inside Function D "<<endl;
   }
};

class B : public A
{
   public :
   void func2()
   {
       cout<<"Inside Function B "<<endl;
   }
};

class C: public A, public D
{
   public :
   void func3()
   {
       cout<<"Inside Function C "<<endl;
   }
};

//Hybrid Inheritance is when we use any two types of Inheritance simultaneously


int main()
{
    A ob1;
    cout<<"Called from Class A : ";
    ob1.func1();

    B ob2;
    cout<<"Called from Class B : ";
    ob2.func1();
    cout<<"Called from Class B : ";
    ob2.func2();

    C ob3;
    cout<<"Called from Class C : ";
    ob3.func1();
    cout<<"Called from Class C : ";
    ob3.func3();
    cout<<"Called from Class C : ";
    ob3.func4();


    return 0;
}