#include <iostream>
#include <vector>
using namespace std;

class Hero
{
    // Properties
    int health = 1;

public:
    char level = 'A';

    void print()
    {
        cout << "Level : " << level << endl;
        cout << "Health : " << health << endl;
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

// Size Of empty Class is 1 for rentification

// Three types of Access modifiers : Public , Private , Protected
// By Default Access Modifier is set to be private

// Public : can Be Accessed Anywhere
// Private : can be accessed in class only;

int main()
{  
    // Static Allocation In Meomry Of Obejects
    Hero H1, H2;

    H1.SetHealth(15);
    H1.SetLevel('I');
    H2.SetHealth(25);
    H2.SetLevel('G');

    cout << "H1 Level  : " << H1.GetLevel() << endl;
    cout << "H1 Health : " << H1.GetHealth() << endl;
    cout << "H2 Level  : " << H2.GetLevel() << endl;
    cout << "H2 Health : " << H2.GetHealth() << endl;

    H1.print();
    H2.print();

    cout<<"Size OF H1 is : "<<sizeof(H1)<<endl;

    // Dynamic Allocation In Meomry Of Obejects
    
    Hero * H3 = new Hero ;
    H3->print();

    // Setting Health And Level 
    H3->SetHealth(100);
    H3->SetLevel('P');

    cout<<"Level Of H3 is : "<<(*H3).level<<endl;
    cout<<"Health Of H3 is : "<<H3->GetHealth()<<endl;

    return 0;
}