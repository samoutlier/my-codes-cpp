// Removing a Loop in LL using Floyds Cycle Algorithm

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
    ~Node()
    {
        int value = this->data;
        // Memory Free
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "Deleted Node : " << value << endl;
    }
};

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
void InsertAtTail(Node *&head, Node *&tail, int d)
{
    // If List Is EMpty
    if (head == NULL)
    {
        Node *NewNode = new Node(d);
        tail = NewNode;
        head = NewNode;
        return;
    }

    // New Node Creation
    Node *NewNode = new Node(d);
    tail->next = NewNode;
    tail = NewNode;
}

void InsertAtHead(Node *&head, Node *&tail, int d)
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
    Node *NewNode = new Node(d);
    NewNode->next = head;
    head = NewNode;
}

void InsertAtIndex(Node *&head, Node *&tail, int index, int d)
{
    if (index < 0)
    {
        cout << "Invalid Index can't insert " << d << endl;
        return;
    }
    if (index == 0 || head == NULL)
    {
        InsertAtHead(head, tail, d);
        return;
    }
    Node *temp = head;
    for (int i = 0; i < index - 1 && temp != tail; i++)
    {
        temp = temp->next;
    }
    if (temp == tail)
    {
        InsertAtTail(head, tail, d);
        return;
    }
    // New Node Creation
    Node *NewNode = new Node(d);
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void RemoveDuplicates(Node *&head, Node *&tail)
{

    Node *curr = head;
    while (curr != tail)
    {
        if (curr->data == curr->next->data && curr->next != tail)
        {
            Node *ToDelete = curr->next;
            curr->next = ToDelete->next;
            delete ToDelete;
        }
        else if (curr->data == curr->next->data && curr->next == tail)
        {
            Node * ToDelete = tail;
            tail = curr;
            tail->next = NULL;
            delete ToDelete;
        }
        else
        curr = curr->next;
    }
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

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *tail_Circular = NULL;

    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 4);
    
    cout<<"Before Removing Duplicates : ";
    LinkedListTraversal(head);

    RemoveDuplicates(head, tail);
    
    cout<<"After Removing Duplicates : ";
    LinkedListTraversal(head);
    return 0;
}