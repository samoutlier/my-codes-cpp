// #include <iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int i = 5 ; 
//     int &j = i;  //Refernce Variable Two Name for same block
//     i++;
//     j++;
//     cout<<i<<endl;
//     return 0;
// }

#include <iostream>
#include<vector>
using namespace std;


int update1(int n)
{
    n++;
}
int update2(int & n)
{
    n++;
}
int main()
{
    int n = 5 ; 

    cout<<"Before : "<<n<<endl;
    update2(n);
    cout<<"After : "<<n<<endl;
    
    return 0;
}