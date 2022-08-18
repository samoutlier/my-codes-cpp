#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class SpecialStack
{
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {

                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop(void)
    {
        if (s.empty())
            return -1;
        else
        {
            int curr = s.top();
            s.pop();
            if (curr > mini)
            {
                return curr;
            }
            else
            {
                int prevMin = mini;

                int val = 2 * mini - curr;

                mini = val;

                return prevMin;
            }
        }
    }

    int top(void)
    {
        if (s.empty())
            return -1;
        else
        {
            int curr = s.top();

            if (curr < mini)
                return mini;

            else
                return curr;
        }
    }

    bool isEmpty(void)
    {
        if (s.empty())
            return true;
        return false;
    }

    int GetMin(void)
    {
        if (s.empty())
            return -1;
        return mini;
    }
};

int main()
{
    SpecialStack st;

    cout << "Min : " << st.GetMin() << endl;

    st.push(5);
    cout << "top : " << st.top() << endl;
    cout << "Min : " << st.GetMin() << endl;
    cout << endl;

    st.push(2);
    cout << "top : " << st.top() << endl;
    cout << "Min : " << st.GetMin() << endl;
    cout << endl;

    st.push(3);
    cout << "top : " << st.top() << endl;
    cout << "Min : " << st.GetMin() << endl;
    cout << endl;

    st.push(1);
    cout << "top : " << st.top() << endl;
    cout << "Min : " << st.GetMin() << endl;
    cout << endl;

    st.push(25);
    cout << "top : " << st.top() << endl;
    cout << "Min : " << st.GetMin() << endl;
    cout << endl;

    cout << "Popped : " << st.pop() << endl;
    cout << "Popped : " << st.pop() << endl;
    cout << "Popped : " << st.pop() << endl;

    st.push(0);
    cout << "top : " << st.top() << endl;
    cout << "Min : " << st.GetMin() << endl;
    cout << endl;
    cout << "Popped : " << st.pop() << endl;
    cout << "Min : " << st.GetMin() << endl;
    return 0;
}