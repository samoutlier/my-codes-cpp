#include <iostream>
#include <vector>
using namespace std;

class Queue
{

public:
    Queue *next;
    int data;
    Queue(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};

bool IsEmpty(Queue *&front, Queue *&rare)
{
    if (front == NULL)
        return true;
    return false;
}

void Enqueue(Queue *&front, Queue *&rare, int data)
{
    Queue *temp = new Queue(data);
    if (rare == NULL)
    {
        rare = temp;
        front = rare;
    }
    else
    {
        rare->next = temp;
        rare = temp;
    }
}

int Dequeue(Queue *&front, Queue *&rare)
{
    if (IsEmpty(front, rare))
    {
        cout << "Queue is Empty , can't Dequeue " << endl;
        return -1;
    }
    int ans = front->data;
    Queue *temp = front;
    front = front->next;
    delete temp;

    if (front == NULL)
        rare = NULL;
        return ans;
}

int qfront(Queue *&front)
{
    if (front == NULL)
        return -1;
    return front->data;
}

void QueueTraversal(Queue *front, Queue *rare)
{
    while (front != rare && front != NULL)
    {
        cout << front->data << " ";
        front = front->next;
    }
    cout <<rare->data<< endl;
}

int main()
{
    Queue *front = NULL;
    Queue *rare = NULL;

    cout<<"Empty : "<<IsEmpty(front, rare)<<endl;
    Enqueue(front, rare, 25);
    Enqueue(front, rare, 32);
    Enqueue(front, rare, 3);

    QueueTraversal(front, rare);
    Enqueue(front, rare, 37);
    Enqueue(front, rare, 37);
    QueueTraversal(front, rare);

    cout<<"Dequeue : "<<Dequeue(front, rare)<<endl;
    QueueTraversal(front, rare);

    cout<<"Front : "<<qfront(front);

    return 0;
}