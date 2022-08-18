// // C++ program to illustrate macros
// #include <iostream>
// using namespace std;

// // Macro definition
// #define limit 5 //(Object Macro)

// // Driver Code
// int main()
// {
//     // Print the value of macro defined
//     cout << "The value of LIMIT"
//          << " is " << limit;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// // Macro definition
// #define AREA(l, b) (l * b)

// int main()
// {
//     // Given lengths l1 and l2
//     int l1 = 10, l2 = 5, area;

//     // Find the area using macros
//     area = AREA(l1, l2);

//     // Print the area
//     cout << "Area of rectangle"
//          << " is: "<<
//         area;

//     return 0;
// }

#include <iostream>
using namespace std;

// Macro definition
#define INSTAGRAM FOLLOWERS // (CHAIN MACROS)
#define FOLLOWERS 138

// Driver Code
int main()
{
    // Print the message
    cout << "Geeks for Geeks have " << INSTAGRAM << "K followers on Instagram!";

    return 0;
}

// #include <iostream>
// using namespace std;

// // Multi-line Macro definition
// #define ELE 1, \
//             2, \
//             3
// int main()
// {
//     // Array arr[] with elements
//     // defined in macros
//     int arr[] = {ELE};

//     // Print elements
//     printf("Elements of Array are:\n");

//     for (int i = 0; i < 3; i++)
//     {
//         cout << arr[i] << ' ';
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// #define min(a, b) ((a > b) ? b : a)

// int main()
// {
//     int a = 10, b = 5;
//     cout << "Minimum is : " << min(a, b);
//     return 0;
// }