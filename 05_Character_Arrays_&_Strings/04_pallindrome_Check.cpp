#include <iostream>
#include <vector>
using namespace std;



bool PallindromeCheck(vector<char> word)
{
    int start =0 , end = word.size()-1;    
    while(start<end)
    {
       if(word[start]!=word[end])
       return false;
       start++;
       end--;
    }
    return true;
}

int main()
{
    vector<char> word;
    char name[80];
    cout << "Enter The Name : ";
    cin>>name;
    for (int i = 0; name[i] != '\0'; i++)
    { 
        word.push_back(name[i]);    
    }
    
    if(PallindromeCheck(word))
    cout<<name<<" is a pallndrome :) "<<endl;
    else
    cout<<name<<" is not a pallndrome :( "<<endl;
    
    
    return 0;
}