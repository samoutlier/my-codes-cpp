#include <iostream>
#include <vector>
using namespace std;

class Hero
{
    // Properties
    int health = 1;

public:
    char level = 'A';

    // Default COnstructor
    // Agar isko nahi banate to yeh tab bhi rehta pehle se hi
    Hero()
    {
        cout << "Calling Constructor" << endl;
    }

    // Parameterised Constructor
    Hero(int health, char level )
    {   
        this->level = level;
        this->health = health;
    }

    //Copy Constructor 
    Hero (Hero &temp)
    {   
        cout<<"Copy Constructor Called "<<endl;
        this->health = temp.health;
        this->level = temp.level;
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

    void Print()
    {
        cout << "Health : " << health << endl;
        cout << "Level : " << level << endl;
    }
};


// Default Copy Construcutor copies Shallow Copy

int main()
{
    Hero H1, H2(25, 'K'), H4(H2) ; //Copy Constructor
    Hero H3 = H2;  //This is Default Copy Constructor only if we dont define copy constructor ourselves
    Hero H5(33,'U');
    H1.Print();
    H2.Print();
    H3.Print();
    H4.Print();
    H5.Print();

    cout<<"Current Level : "<<H3.level<<endl;

    return 0;
}