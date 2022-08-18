#include <iostream>
#include<vector>
using namespace std;

class Animal 
{
    public :
    int age ;
    int weight;
    public :
    void speak()
    {
        cout<<"Barking "<<endl;
    }
};

class Human 
{
  public :
   string color;

   public :
   void speak()
   {
       cout<<"Speaking"<<endl;
   }
};

//Ambiguity in Inheritance 
//In case Of Multiple Inheritance when both parent classes have same name to their function their comes the ambiguity.   

class Hybrid : public Animal , public Human
{
  
};


int main()
{
    Hybrid obj;
    obj.Animal::speak();
    obj.Human::speak();
    return 0;
}