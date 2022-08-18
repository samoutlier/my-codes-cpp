#include <iostream>
#include <vector>
using namespace std;

class A
{
  public: 
  int a , b;

  public:
 
  //Operator OverLoading 
  //using + to substract
  void operator + (A &obj )
  {  int value1 = this->a;
     int value2 = obj.b;

     cout<<"Output "<<value1-value2<<endl;
  }

  void operator () ()
  {
      cout<<"I m called using bracket : "<<this->a<<endl;
  }

};

int main()
{
    A obj1 , obj2;
    
    obj1.a = 10;
    obj2.b = 6;
    obj1 + obj2;
    obj1();
    return 0;
}