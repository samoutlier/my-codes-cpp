#include <iostream>
#include <vector>
using namespace std;

class Queue
{
    int front, rear;
    int *arr;
    int size;

public:
    Queue(int s)
    {
        this->size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Push In Front
    void Push_Front(int data)
    {
        if (IsFull())
        {
            cout << "Can't , Enqueue : " << data << endl;
        }
        else if (front == -1) // first elemnt to push
        {
            rear++;
            arr[++front] = data;
        }
        else if (front == 0)
        {
            front = size - 1;
            arr[front] = data;
        }
        else
        {
            arr[--front] = data;
        }
    }

    // Push At Back
    void Push_Back(int data)
    {
        if (IsFull())
        {
            cout << "Can't , Enqueue : " << data << endl;
        }
        else if (front == -1) // first elemnt to push
        {
            front++;
            arr[++rear] = data;
        }
        else if (rear == size - 1)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            arr[++rear] = data;
        }
    }

    // Pop AT Front
    int Pop_Front(void)
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty , can't Dequeue " << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return ans;
    }

    // Pop AT Back
    int Pop_Back(void)
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty , can't Dequeue " << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;

        return ans;
    }

    int qfront(void)
    {
        if (front == -1)
            return -1;
        return arr[front];
    }

    bool IsEmpty(void)
    {
        if (front == -1)
            return true;
        return false;
    }

    bool IsFull(void)
    {
        if ((front == 0 && rear == size - 1) || (front - rear == 1))
            return true;
        return false;
    }

    void DEQueueTraversal(void)
    {
        if (IsEmpty())
        {
            cout << "Doubly Ended Queue is Empty . " << endl;
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            if (i == size - 1)
                i = 0;
            else
                i++;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    Queue q(5);

    q.Push_Front(25);
    cout << "Empty : " << q.IsEmpty() << endl;
    cout << "Pop Backed : " << q.Pop_Back() << endl;
    cout << "Empty : " << q.IsEmpty() << endl;

    q.DEQueueTraversal();
    q.Push_Back(10);
    q.Push_Back(20);
    q.Push_Back(30);
    q.Push_Front(5);
    q.Push_Front(0);

    q.DEQueueTraversal();
    cout << "Full : " << q.IsFull() << endl;

    cout << "Pop Front : " << q.Pop_Front() << endl;
    cout << "Pop Front : " << q.Pop_Front() << endl;
    q.DEQueueTraversal();

    q.Push_Back(40);
    q.Push_Front(2);
    q.DEQueueTraversal();
    q.Push_Back(40);
    q.Push_Front(2);

    cout << "Full : " << q.IsFull() << endl;

    return 0;
}