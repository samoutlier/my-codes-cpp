#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    // Properties
    Stack *link ;
    int data;

    // Constructor
    Stack(int value)
    {
        this->data = value;
        this->link = NULL;
    }

    // Destructor
    ~Stack()
    {
        int value = this->data;
        // Memory Free
        if (this->link != NULL)
        {
            this->link = NULL;
            delete link;
        }
        cout << "Deleted Node : " << value << endl;
    }
};

Stack *top = NULL;
Stack *top2 = NULL;

// Push function
void push(Stack *&top, int value)
{
    Stack *temp = new Stack(value);
    if (!temp)
        cout << "Stack Overflow !!";
    else
    {
        temp->link = top;
        top = temp;
    }
}

// Pop Function
void pop(void)
{
    if (!top)
    {
        cout << "Stack Underflow ,can't Pop" << endl;
        return;
    }
    
    Stack *temp = top;
    top = top->link;
    cout<<"Popped : "<<temp->data<<endl;
    delete temp;
}

// Empty Functioin
bool IsEmpty(void)
{
    if (top == NULL)
        return true;
    else
        return false;
}

int peek(void)
{
    if (top == NULL)
        return -1;
    else
        return top->data;
}

void StackTraversal(Stack * top)
{
    if(top == NULL)
    cout<<"Stack Underflow !!"<<endl;
    else
    {
        while (top!=NULL)
        {
            cout<<top->data<<" ";
            top = top->link;
        }
    cout<<endl;        
    }
}



int main()
{
    cout<<IsEmpty()<<endl;
    push(top, 25);
    push(top, 26);
    push(top, 96);
    StackTraversal(top);

    pop();
    pop();
    StackTraversal(top);
    cout<<IsEmpty()<<endl;
    cout<<"Peek : "<<peek()<<endl<<endl ; 

    cout<<IsEmpty()<<endl;
    push(top2, 25);
    push(top2, 26);
    push(top2, 96);
    StackTraversal(top2);


}