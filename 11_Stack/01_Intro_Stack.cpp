#include <iostream>
#include <vector>
//#include<stack>

using namespace std;

class Stack
{

    // Properties
public:
    int *arr;
    int top;
    int size;

    // behaviour

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int value)
    {
        if (top >= size)
        {
            cout << "Stack Overflow Can't Push " << value << endl;
        }
        else
        {
            arr[++top] = value;
            cout << "Pushed : " << value << endl;
        }
    }

    void pop(void)
    {
        if (top == -1)
            cout << "Stack Underflow , can't pop " << endl;
        else
        {
            cout << "Popped : " << arr[top]<<endl;
            top--;
        }
    }

    int peek(void)
    {
        if (top == -1)
        {
            cout << "Stack is Empty !!" << endl;
            return -1;
        }
        else
           return arr[top];
    }

    bool IsEmpty(void)
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void StackTraversal(void)
    {
        if(top== -1 )
        cout<<"Stack underflow , can't traverse"<<endl;
        else
        {
            int i = top;
            while(i!=-1)
            {
                cout<<arr[i--]<<" ";
            }
            cout<<endl;
        }
    }
};
 
int main()
{
    Stack s(2);

    s.push(22);
    s.push(64);
    s.push(97);
    s.push(19);

    s.StackTraversal();

    cout << "Top : " << s.peek()<<endl;

    s.pop();
    cout << "Top : " << s.peek()<<endl;

    s.pop();
    cout << "Top : " << s.peek()<<endl;
     
   

    if(s.IsEmpty())
    cout<<"Stack is Empty "<<endl;
    else
    cout<<"Stack is not Empty "<<endl;

    return 0;
}