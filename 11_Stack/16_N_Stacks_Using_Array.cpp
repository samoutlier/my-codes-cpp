#include <iostream>
#include <vector>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;
    int size, n, freespot;

public:
    // Initialising NStack
    NStack(int S, int N)
    {
        n = N;
        size = S;
        arr = new int[size];
        top = new int[n];
        next = new int[size];

        // Top Initialise
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        // Next Initialise
        for (int i = 0; i < size - 1; i++)
        {
            next[i] = i + 1;
        }
        // Update Last Index of next
        next[size - 1] = -1;

        // Initialise Freespot

        freespot = 0;
    }

    bool push(int x, int m)
    {
        // Checking StackOverflow
        if (freespot == -1)
            return false;

        // Find index
        int index = freespot;

        // Update Freespot
        freespot = next[index];

        // Insert element
        arr[index] = x;

        // Update next
        next[index] = top[m - 1];

        //Update top 
        top[m-1] = index;

        return true;
    }

    int pop(int m)
    {
        // Checking StackUnderflow
        if (top[m - 1] == -1)
            return -1;

        // Find index
        int index = top[m - 1];

        // Update Freespot
        top[m - 1] = next[index];

        // Update Next
        next[index] = freespot;

        // Update next
        freespot = index;

        return arr[index];
    }
};

int main()
{
    NStack st(4, 2);

    cout << "Pushed In Stack 1 : " << st.push(10, 1) << endl;
    cout << "Pushed In Stack 2 : " << st.push(20, 2) << endl;
    cout << "Pushed In Stack 1 : " << st.push(30, 1) << endl;
    cout << "Pushed In Stack 2 : " << st.push(40, 2) << endl;
    // cout << "Pushed In Stack 3 : " << st.push(21, 3) << endl;
    // cout << "Pushed In Stack 3 : " << st.push(21, 3) << endl;
    // cout << "Pushed In Stack 4 : " << st.push(21, 4) << endl;
    // cout << "Pushed In Stack 4 : " << st.push(21, 4) << endl;
    // cout << "Pushed In Stack 5 : " << st.push(26, 5) << endl;
    // cout << "Pushed In Stack 5 : " << st.push(36, 5) << endl;
    // cout << "Pushed In Stack 5 : " << st.push(36, 5) << endl;
    cout << "Pushed In Stack 2 : " << st.push(21, 2) << endl;
    cout << "Popped From Stack 1 : " << st.pop(1) << endl;
    cout << "Popped From Stack 2 : " << st.pop(2) << endl;
    cout << "Popped From Stack 2 : " << st.pop(2) << endl;
    cout << "Popped From Stack 2 : " << st.pop(2) << endl;
    return 0;
}