// #include <iostream>
// #include <vector>
// using namespace std;

// class Stack
// {
// public:
//     // Properties
//     Stack *link;
//     char ch;

//     // Constructor
//     Stack(char c)
//     {
//         this->ch = c;
//         this->link = NULL;
//     }

//     // Destructor
//     ~Stack()
//     {
//         char letter = this->ch;
//         // Memory Free
//         if (this->link != NULL)
//         {
//             this->link = NULL;
//             delete link;
//         }
//         cout << "Deleted Node : " << letter << endl;
//     }
// };

// Stack *top = NULL;

// // Push function
// void push(Stack *&top, char letter)
// {
//     Stack *temp = new Stack(letter);
//     if (!temp)
//         cout << "Stack Overflow !!";
//     else
//     {
//         temp->link = top;
//         top = temp;
//     }
// }

// // Pop Function
// char pop(Stack * &top)
// {
//     if (!top)
//     {
//         cout << "Stack Underflow ,can't Pop" << endl;
//         return '0';
//     }

//     Stack *temp = top;
//     top = top->link;
//     char letter = temp->ch;
//     // cout << "Popped : " << temp->ch << endl;
//     delete temp;
//     return letter;
// }

// // Empty Functioin
// bool IsEmpty(void)
// {
//     if (top == NULL)
//         return true;
//     else
//         return false;
// }

// char peek(void)
// {
//     if (top == NULL)
//         return '0';
//     else
//         return top->ch;
// }

// void StackTraversal(Stack *top)
// {
//     if (top == NULL)
//         cout << "Stack Underflow !!" << endl;
//     else
//     {
//         while (top != NULL)
//         {
//             cout << top->ch << " ";
//             top = top->link;
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     string s;
//     cout << "Enter your string : ";
//     cin >> s;

//     for (char i = 0; i < s.length(); i++)
//     {
//         push(top, s.at(i));
//     }

//     string ans = "";

//     for (char i = 0; i < s.length(); i++)
//     {
//         ans = ans + pop(top);
//     }

//     cout<<"Reverse String is : "<<ans<<endl;
// }


#include <iostream>
#include<vector>
#include<stack>
using namespace std;
 
int main()
{   stack<char> store ;
   
    string s;
    cout << "Enter your string : ";
    cin >> s;

    for (char i = 0; i < s.length(); i++)
    {
        store.push(s.at(i));
    }

    string ans = "";

    for (char i = 0; i < s.length(); i++)
    {
       ans.push_back(store.top());
       store.pop();
    }

    cout<<"Reverse String is : "<<ans<<endl;
}