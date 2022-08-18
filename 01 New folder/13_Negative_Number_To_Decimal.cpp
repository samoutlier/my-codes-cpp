#include <iostream>
#include <math.h> 
using namespace std;

int main() {
    int n;
    cout << "Enter the decimal number: ";
    cin >> n;

    int ans = 0;
    int i = 0;
    if(n < 0) {
        n = -1 * n;
    }
    while (n != 0)
    {
        int bit = n & 1; //reads last bit
        ans = ans + (bit * pow(10, i));
        n = n >> 1; //helps to read the other bits by shifting it to the right
        i++; 
    }  
    cout<< "Binary equivalent: -" << ans <<endl;
    
}