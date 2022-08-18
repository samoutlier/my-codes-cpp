#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;
    int size;
    int currentsize;

public:
    Stack(int size)
    {
        this->size = size;
        currentsize = 0;
    }

    bool isFull()
    {
        if (currentsize == size)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (q1.empty())
            return true;
        return false;
    }
    void push(int data)
    {
        if (isFull())
            cout << "Stack Overflow . " << endl;
        else
        {
            q2.push(data);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }

            queue<int> q;
            q = q1;
            q1 = q2;
            q2 = q;
            currentsize++;
        }
    }

    void pop(void)
    {
        if (isEmpty())
            cout << "Stack Underflow . " << endl;
        else
        {
            int ans = q1.front();
            q1.pop();
            currentsize--;
        }
    }

    int top(void)
    {
        if (isEmpty())
            return -1;
        return q1.front();
    }

    int Size(void)
    {
        return currentsize;
    }
};

int main()
{
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.Size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.Size()
         << endl;
    return 0;
}