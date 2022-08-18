#include <iostream>
#include <vector>
using namespace std;

class Hero
{
    // Properties
    int health = 1;

public:
    char level = 'A';

    Hero()
    {
        cout<<"Calling Constructor"<<endl;
    }
    
    // Parameterised Constructor
    Hero (int health)
    {  
      cout<<"Address Of Current Object : "<<this<<endl;
      this->health = health;
    }
     // Getters
    int GetHealth()
    {
        return health;
    }

    char GetLevel()
    {
        return level;
    }

    // Setters

    void SetHealth(int h)
    {
        health = h;
    }

    void SetLevel(char l)
    {
        level = l;
    }
};

//Constructor 
// It is called by Default at the time of Object Creation
//

int main()
{  
    cout<<"Helllo Jiiiiii"<<endl;
    // Static Allocation In Meomry Of Obejects
    Hero H1(25), H2(63);
    cout<<"Bye  "<<endl;
    cout<<"Address Of H1 "<<&H1<<endl;
    cout<<"Value OF Health : "<< H1.GetHealth()<<endl;


   
    return 0;
}