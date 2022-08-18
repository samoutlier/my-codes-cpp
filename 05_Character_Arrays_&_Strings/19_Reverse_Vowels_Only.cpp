#include <iostream>
#include <vector>
using namespace std;

bool IsVowel(char c)
{
    if(c == 'a' || c == 'e' || c =='i'  || c == 'o' || c =='u')
    return true;
    else if(c == 'A' || c == 'E' || c =='I'  || c == 'O' || c =='U')
    return true;
    return false;
}

string Reverse(string name)
{
    int start = 0;
    int end = name.size()-1;
    while(start<end)
    {  
        bool check1 = IsVowel(name[start]);
        bool check2 = IsVowel(name[end]);
       if(check1 && check2)
       {
          swap(name[start], name[end]);
          start++;
          end--;
       }
       else if(check1 )
       {
           end--;
           while(start < end && !IsVowel(name[end]))
           {
             end--;
           }
       }
       else if(check2 )
       {
           start++;
           while(start < end && !IsVowel(name[start]))
           {
             start++;
           }
       }
       else
       {
           start++;
           end--;
       }
    }
    return name;
   
}

int main()
{
    string name;
    cout << "Enter The Name : ";
    cin>>name;
    name = Reverse(name);
    cout<<"After reverse : "<<name<<endl;
    
    return 0;
}