#include <iostream>
#include <vector>
using namespace std;

class KQueue
{

    int *arr, *front, *rear, *next;
    int size, freespot, k;

public:
    KQueue(int s, int n)
    {
        this->size = s;
        arr = new int[size];
        front = new int[n];
        rear = new int[n];
        rear = new int[n];
        next = new int[n];
        freespot = 0;
        this->k = n;

        // Front and rear Initialise
        for (int i = 0; i < n; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        // Next Initialise

        for (int j = 0; j < size - 1; j++)
        {
            next[j] = 1 + j;
        }
        next[size - 1] = -1;
    }

    bool isFull(void)
    {
        if (freespot == size)
            return true;
        return false;
    }

    bool isEmpty(void)
    {
        for (int i = 0; i < k; i++)
        {
            if (front[i] != -1)
                return false;
        }

        return true;
    }

    void Enqueue(int data, int m)
    {
        if (isFull())
        {
            cout << "Queue Overflow !!" << endl;
        }
        else
        {
            // Finding index to insert data
            int index = freespot;

            // Updating Freespot
            freespot = next[index];

            // Updating front
            if (front[m - 1] == -1)
                front[m - 1] = index;
            // Link New Element To prev element
            else
                next[rear[m - 1]] = index;

            // Updating rear
            rear[m - 1] = index;

            // Updating next

            next[index] = -1;

            // Pushing Data
            arr[index] = data;
            cout << "Pushed : " << data << endl;
            cout << "Freespot : " << freespot << endl;
        }
    }

    int Dequeue(int m)
    {
        if (isEmpty())
            return -1;
        else
        {
            // Finding Index
            int index = front[m - 1];

            // Finding ans
            int ans = arr[index];

            // Updating front
            if (front[m - 1] == rear[m - 1])
            {
                front[m - 1] = -1;
                rear[m - 1] = -1;
            }
            else
                front[m - 1] = next[index];

            // Updating Next
            // next[index] = freespot;

            // Updating Freespot
            freespot = index;

            return ans;
        }
    }
};

int main()
{
    KQueue q(10, 3);

    if (q.isEmpty())
        cout << "Empty " << endl;
    else
        cout << "Not Empty" << endl;
    q.Enqueue(10, 1);
    q.Enqueue(15, 1);
    q.Enqueue(20, 2);
    q.Enqueue(25, 1);

    if (q.isFull())
        cout << "FULL " << endl;
    else
        cout << "Not FULL" << endl;
    cout << "Dequeue from " << 1 << " : " << q.Dequeue(1) << endl;
    cout << "Dequeue from " << 2 << " : " << q.Dequeue(2) << endl;
    cout << "Dequeue from " << 1 << " : " << q.Dequeue(1) << endl;
    cout << "Dequeue from " << 1 << " : " << q.Dequeue(1) << endl;
    cout << "Dequeue from " << 1 << " : " << q.Dequeue(1) << endl;

    return 0;
}