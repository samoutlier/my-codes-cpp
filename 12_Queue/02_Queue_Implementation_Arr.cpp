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
        front = 0;
        rear = 0;
    }

    void Enqueue(int data)
    {
        if (IsFull())
        {
            cout << "can't , Enqueue : " << data << endl;
        }
        else
        {  
            arr[rear++] = data;
        }
    }

    int Dequeue(void)
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty , can't Dequeue " << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front++] = -1;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        return ans;
    }

    int qfront(void)
    {
        if (front == rear)
            return -1;
        return arr[front];
    }

    bool IsEmpty(void)
    {
        if (front == rear)
            return true;
        return false;
    }

    bool IsFull(void)
    {
        if (rear == size)
            return true;
        return false;
    }
};

int main()
{
    Queue q(5);


    q.Enqueue(25);
    cout<<"Empty : "<<q.IsEmpty()<<endl;
    cout<<"Dequeued : "<<q.Dequeue()<<endl;
    cout<<"Empty : "<<q.IsEmpty()<<endl;

    q.Enqueue(36);
    q.Enqueue(37);
    q.Enqueue(38);
    q.Enqueue(39);
    q.Enqueue(100);
    q.Enqueue(100);

    cout<<"Dequeue : "<<q.Dequeue()<<endl;
    q.Enqueue(100);
    return 0;
}