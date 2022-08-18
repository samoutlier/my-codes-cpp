#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 5, 6};
    char ch[6] = "abcde";
 
    cout << arr << endl;
    cout << ch << endl;

    char *c = &ch[0];
    cout << c << endl;

    char temp = 'h';
    char *ptr = &temp;

    cout << ptr << endl;
    return 0;
}