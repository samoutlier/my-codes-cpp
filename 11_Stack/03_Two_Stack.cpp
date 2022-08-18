#include <iostream>
#include <vector>
using namespace std;

class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialising TwoSTack
    TwoStack(int s)
    {
        arr = new int[s];
        this->size = s;
        this->top1 = -1;
        this->top2 = s;
    }

    // Push In Stack 1
    void push1(int d)
    {
        if (top2 - top1 > 0)
            arr[++top1] = d;
        else
            cout << "Stack Overflow " << endl;
    }

    // Push In Stack 2
    void push2(int d)
    {
        if (top2 - top1 > 0)
            arr[--top2] = d;
        else
            cout << "Stack Overflow " << endl;
    }

    // Pop In Stack 1
    int pop1(void)
    {
        if (top1 == -1)
        {
            cout << "Stack underflow , can't Pop " << endl;
            return -1;
        }
        else
        {
            return arr[top1--];
        }
    }

    // Pop In Stack 2
    int pop2(void)
    {
        if (top2 == size)
        {
            cout << "Stack underflow , can't Pop " << endl;
            return -1;
        }
        else
        {
            return arr[top2++];
        }
    }

    // Stack traverse 1
    void Stack1traverse(void)
    {
        int temp = top1;
        if (temp == -1)
            cout << "Stack UnderFlow , can't Traverse " << endl;
        else
        {
            while (temp >= 0)
                cout << arr[temp--] << " ";
            cout << endl;
        }
    }

    // Stack traverse 2
    void Stack2traverse(void)
    {
        int temp = top2;
        if (temp == size)
            cout << "Stack UnderFlow , can't Traverse " << endl;
        else
        {
            while (temp != size)
                cout << arr[temp++] << " ";
            cout << endl;
        }
    }
};

int main()
{
    TwoStack st(10);

    st.push1(25);
    st.push1(30);
    st.push1(40);
    st.push1(45);

    st.push2(10);
    st.push2(20);
    st.push2(30);
    st.push2(40);

    st.Stack1traverse();
    st.Stack2traverse();

    cout << "Popped From Stack 1 : " << st.pop1() << endl;
    cout << "Popped From Stack 1 : " << st.pop1() << endl;
    cout << "Popped From Stack 2 : " << st.pop2() << endl;
    cout << "Popped From Stack 2 : " << st.pop2() << endl;

    st.Stack1traverse();
    st.Stack2traverse();

    return 0;
}