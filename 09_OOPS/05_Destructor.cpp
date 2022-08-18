#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Hero
{
    // Properties
    int health = 1;

public:
    char level = 'A';
    char *str = new char[100];
    static int time;

    // Default COnstructor
    // Agar isko nahi banate to yeh tab bhi rehta pehle se hi
    Hero()
    {
        cout << "Calling Constructor" << endl;
    }

    // Copy constructor
    Hero(Hero &temp)
    {
        this->health = temp.health;
        this->level = temp.level;
        strcpy(this->str, temp.str);
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

    void SetName(char str[])
    {
        strcpy(this->str, str);
    }

    void Print()
    {

        cout << "[ Name : " << str << " , ";
        cout << "Health : " << health << " , ";
        cout << "Level : " << level << " ] " << endl;
        cout << endl;
    }

    static int random()
    {
       return time;
       // return health; it will dispay error
    }

    ~Hero()
    {
        cout << "Destructor called " << endl;
    }
};

int Hero ::time = 10;

int main()
{
    Hero H1; // iske liye des. auto called ho gaya hai
    Hero *H2 = new Hero();

    cout << Hero::time << endl; // No need to make the objeect for static keyword
                                // as it doesnt belong to object it belongs to class
    H2 -> time = 20;
    cout << H1.time << endl;
    cout << H2->time << endl;


    //Static Function
    // Object Creation ki need nahi access k liye
    //  They dont have this keyword bcz they dont have any object so they dont need this keyword
    // static function can only access static members 

    cout<<Hero::random()<<endl;

    return 0;
}