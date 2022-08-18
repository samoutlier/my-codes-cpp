#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
    int size;
    int * arr;
    int front, end;
public:
   
    MyCircularQueue(int k) {
        this->size = k;
        arr = new int[size];
        this->front = -1;
        this->end = -1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(front == -1)
        {
            front++;
             arr[++end] = value;
             
        }
        else if(end == size-1)
        {
            end= 0;
            arr[end] = value;
        }
        else
        {
            arr[++end] = value;
        }
           
        
        return true;
    }
    
    bool deQueue() {
        if(front == -1 && end == -1)
            return false;
        if(front == end)
         {
             front = -1;
             end = -1;
         }
        else if(end == 0)
        {
            end = size-1;
        }
        else
        {
            end--;
        }
       return true;      
      
    }
    
    int Front() {
        if(front == -1)
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return arr[end];
    }
    
    bool isEmpty() {
          if(front == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((front == 0 && end == size-1) || (front-end) == 1)
            return true;
        return false;
    }
};
int main()
{
    MyCircularQueue q(8);

    cout<<"Enqueue : "<<q.enQueue(3)<<endl;
    cout<<"Rear : "<<q.Rear()<<endl;
    cout<<"Enqueue : "<<q.enQueue(9)<<endl;
    cout<<"Rear : "<<q.Rear()<<endl;
    cout<<"Enqueue : "<<q.enQueue(5)<<endl;
    cout<<"Rear : "<<q.Rear()<<endl;
    cout<<"Enqueue : "<<q.enQueue(0)<<endl;
    cout<<"Rear : "<<q.Rear()<<endl;
    cout<<"Dequeue : "<<q.deQueue()<<endl;
    cout<<"Rear : "<<q.Rear()<<endl;
    cout<<"Dequeue : "<<q.deQueue()<<endl;
    cout<<"Rear : "<<q.Rear()<<endl;
    
    return 0;
}