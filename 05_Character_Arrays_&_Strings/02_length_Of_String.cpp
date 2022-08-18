#include <iostream>
using namespace std;

int Length(char name[])
{
    int count = 0;
    while(name[count]!='\0')
    {
        count++;
    }
    return count;
}

int main()
{
    char name[20];
    cout<<"Enter The Name : ";
    cin>>name;
    
    cout<<"The Length of "<<name<<" is : "<<Length(name);
    
    return 0;
}