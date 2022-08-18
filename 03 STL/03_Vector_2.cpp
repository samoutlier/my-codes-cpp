#include <iostream>
#include<vector>

using namespace std;
int main()
{
    vector <int> vect(5,25); //This Command will initialise A vector of size 5 with all elemnts with 1
    vector <int> last(vect); //This Command will copy vect as it is;
    cout<<"Printing Vect : ";
    for(int i:vect)
    {
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Printing Last : ";
    for(int i:last)
    {
        cout<<i<<" ";
    }


    return 0;
}