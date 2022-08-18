#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


void InsertAtHead(Node *&head, Node * &tail,  int d)
{   
    // If Empty List
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }

    // New Node Creation
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// void InsertAtTail(Node * &head, int d)
// {
//     //New Node Creation
//     Node * NewNode = new Node (d);
//     Node * tail = head;
//     while(tail->next != NULL)
//     {
//         tail = tail->next;
//     }
//     tail->next = NewNode;

// }

void InsertAtTail(Node *&head, Node *&tail, int d)
{   
    // If Empty List
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }

    // New Node Creation
    Node *NewNode = new Node(d);
    tail->next = NewNode;
    tail = NewNode;
}

void InsertAtIndex(Node *&head,Node * &tail, int index, int d)
{
    if (index < 0)
    {
        cout << "Invalid Index can't insert "<<d << endl;
        return;
    }
    if (index == 0)
    {
        InsertAtHead(head, tail, d);
        return;
    }
    Node * temp = head;
    for (int i = 0; i < index - 1 && temp != tail ; i++)
    {
        temp = temp->next;
    }
    if(temp == tail)
    {
        InsertAtTail(head , tail, d);
        return;
    }
    //New Node Creation 
    Node * NewNode  = new Node(d);
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void LinkedListTraversal(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// Getting length Of Linked List
int GetLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

int main()
{
   
    Node *head = NULL;
    Node *tail = NULL;

    LinkedListTraversal(head);

    InsertAtHead(head, tail, 11);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl<<endl;

    InsertAtHead(head, tail, 13);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl<<endl;

    InsertAtHead(head, tail, 8);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl<<endl;

    InsertAtTail(tail, tail, 25);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl<<endl;

    InsertAtIndex(head, tail, 1, 100);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl<<endl;

    InsertAtIndex(head, tail, 0, 101);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl<<endl;

    InsertAtIndex(head, tail, 8, 102);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl<<endl;

    cout << GetLength(head) << endl;
    return 0;
}