#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "Deleted Node : " << value << endl;
    }
};

void InsertAtTail(Node *&tail, int d)
{
    // If Empty List
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
        return;
    }

    // New Node Creation
    Node *NewNode = new Node(d);
    NewNode->next = tail->next;
    tail->next = NewNode;
    tail = NewNode;
}

// Getting length Of Linked List
int GetLength(Node *tail)
{
    if (tail == NULL)
        return 0;
    else if (tail->next == NULL)
        return 1;
    else
    {
        Node *temp = tail;
        int len = 0;

        do
        {
            temp = temp->next;
            len++;
        } while (temp != tail);
        return len;
    }
}

void InsertAtIndex(Node *&tail, int index, int d)
{
    if (index < 0 || index > GetLength(tail))
    {
        cout << "Invalid Index can't insert " << d << endl;
        return;
    }
    else if (index == GetLength(tail))
    {
        InsertAtTail(tail, d);
        return;
    }
    else
    {
        Node *current = tail;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        Node *NewNode = new Node(d);
        NewNode->next = current->next;
        current->next = NewNode;
    }
}

void DeleteByValue(Node * &tail, int value )
{  

   //Empty list check
   if(tail==NULL)
       cout<<"List is Empty can't delete "<<value<<endl;
   else if(tail->next == tail) 
   {
       if(tail->data == value)
        {
            Node * temp = tail;
            temp ->next = NULL;
            tail = NULL;
            delete temp;
        }
        else
        {
            cout<<"Value Not present "<<endl;
        }
   }
    else
    {
        //Assuming Value is present 
         Node * prev = tail;
         Node * current = prev->next;
         while(current->data != value)
         {
             prev = current;
             current = current->next;
         }
         if(current==tail)
         {
             tail = prev;
         }
         prev->next = current->next;
         current->next = NULL;
         delete(current);
    }

}

void PrintArray(Node *tail)
{   
     if(tail == NULL)
     {
         cout<<"list Is Empty "<<endl;
     }

    if (tail->next == tail)
    {
        cout << tail->data << " " << endl;
        return;
    }

    Node *temp = tail;
    do
    {
        temp = temp->next;
        cout << temp->data << " ";
    } while (temp != tail);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    InsertAtTail(tail, 10);
    PrintArray(tail);
    cout << "Tail -> " << tail->data << endl;
    cout << "Length : " << GetLength(tail) << endl;
    cout<<endl;

    // InsertAtTail(tail, 20);
    // PrintArray(tail);
    // cout << "Tail -> " << tail->data << endl;
    // cout << "Length : " << GetLength(tail) << endl;
    // cout<<endl;

    // InsertAtTail(tail, 30);
    // PrintArray(tail);
    // cout << "Tail -> " << tail->data << endl;
    // cout << "Length : " << GetLength(tail) << endl;
    // cout<<endl;

    // InsertAtIndex(tail, 0 , 1);
    // PrintArray(tail);
    // cout << "Tail -> " << tail->data << endl;
    // cout << "Length : " << GetLength(tail) << endl;
    // cout<<endl;

    // InsertAtIndex(tail, 1, 5);
    // PrintArray(tail);
    // cout << "Tail -> " << tail->data << endl;
    // cout << "Length : " << GetLength(tail) << endl<<endl;
    
    DeleteByValue(tail, 10);
    PrintArray(tail);
    cout << "Tail -> " << tail->data << endl;
    cout << "Length : " << GetLength(tail) << endl<<endl;
    
    return 0;
}