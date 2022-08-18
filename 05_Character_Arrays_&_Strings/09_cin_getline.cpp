#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char name[1000], s[1000];
    cin.getline(name, 1000);
    cout << name << endl;
    cin.getline(s, 1000);
    cout << endl;
    cout << "Length Of name : " << strlen(name) << endl;
    cout << "Two String Equal Or Not : " << strcmp(name, s) << endl;
    strcpy(s, name);
    cout << "Two String Equal Or Not : " << strcmp(name, s) << endl;
    return 0;
}