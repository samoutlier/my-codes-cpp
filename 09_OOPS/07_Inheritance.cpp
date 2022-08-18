// #include <iostream>
// #include <vector>
// using namespace std;

// class Human
// {
// public:
//     int weight;
//     int height;
//     int age;

// public:
//     int getAge()
//     {
//         return this->age;
//     }
//     void setAge(int age)
//     {
//         this->age = age;
//     }
//     int getWeight()
//     {
//         return this->weight;
//     }
//     void setWeight(int w)
//     {
//         this->weight = w;
//     }
// };

// //Public Mode Of Inheritance
// class Male : public Human
// {
// public:
//     string color;
//     void sleep()
//     {
//         cout << "Male Sleeping " << endl;
//     }
// };

// int main()
// {
//     Male obj1; 
//     cout << obj1.age << endl;
//     cout << obj1.weight << endl;
//     cout << obj1.height << endl;
//     cout << obj1.color << endl;
//     obj1.setAge(25);
//     obj1.setWeight(70);
//     cout << obj1.age << endl;
//     cout << obj1.weight << endl;

//     obj1.sleep();

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// class Human
// {
// public:
//     int weight;
//     int height;
//     int age;


// };

// //Protected Mode Of Inheritance From public
// class Male : protected Human
// {
// public:
//     string color;
//     void sleep()
//     {
//         cout << "Male Sleeping " << endl;
//     }
//     int getAge()
//     {
//         return this->age;
//     }
// };

// int main()
// {
   
//     Male m1;
//     // cout<<m1.age<<endl; This wont work as it is inaccessible in protected

//     cout<< m1.getAge()<<endl;
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

class Human
{
public:
    int weight;
    int height;
    int age;

public:
    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getWeight()
    {
        return this->weight;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};

//Private Mode Of Inheritance
class Male : private Human
{
public:
    string color;
    void sleep()
    {
        cout << "Male Sleeping " << endl;
    }
     int getAge()
    {
        return this->age;
    }
};

int main()
{
 
    Male m1;
    // cout<<m1.age<<endl; This wont work as it is inaccessible in private

    cout<< m1.getAge()<<endl;

    return 0;
}