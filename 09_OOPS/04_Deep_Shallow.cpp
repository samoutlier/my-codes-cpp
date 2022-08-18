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

    // Default COnstructor
    // Agar isko nahi banate to yeh tab bhi rehta pehle se hi
    Hero()
    {
        cout << "Calling Constructor" << endl;
    }

    // Copy constructor 
    Hero (Hero & temp)
    {
        this->health = temp.health;
        this->level = temp.level;
        strcpy(this->str , temp.str);
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
};

int main()
{
    Hero H1;
    H1.SetHealth(12);
    H1.SetLevel('K');
    char name[] = "Samad";
    H1.SetName(name);

    H1.Print();

    Hero H2 = H1;

    H2.Print();

    H1.str[0] = 'Z'; //Default Copy Constructor does Shallow Copy

    H1.Print();
    H2.Print();
    return 0;
}