#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node *prev = NULL;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        this->next = NULL;
        this->prev = NULL;
        delete next;
        delete prev;
        cout << "Deleted Node : " << value << endl;
    }
};

// Linked List Traversal
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

// Insertion At Head
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

    // Create A New Node
    Node *NewNode = new Node(d);

    NewNode->next = head;
    head->prev = NewNode;
    head = NewNode;
}

// Insertion AT Tail
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
    // Create A New Node
    Node *NewNode = new Node(d);

    NewNode->prev = tail;
    tail->next = NewNode;
    tail = NewNode;
}

// Insertion AT Index
void InsertAtIndex(Node *&head, Node *&tail, int index, int d)
{
    if (index < 0)
    {
        cout << "Invalid Index can't insert " << d << endl;
        return;
    }
    if (index == 0)
        InsertAtHead(head, tail, d);

    else if (index >= GetLength(head))
        InsertAtTail(head, tail, d);

    else
    {
        // Create A New Node
        Node *NewNode = new Node(d);
        Node *temp = head;

        for (int i = 0; i < index - 1; i++)
        {

            temp = temp->next;
        }

        NewNode->next = temp->next;
        temp->next->prev = NewNode;
        temp->next = NewNode;
        NewNode->prev = temp;
    }
}

void DeleteAtIndex(Node *&head, Node *&tail, int index)
{
    // Invalid Index
    if (index < 0 || index >= GetLength(head))
        cout << "Invalid Index !! " << endl;

    // Deletion At Head
    else if (index == 0)
    {
        Node *temp = head;
        if (tail == head)
        {
            tail = NULL;
            head = NULL;
        }
        else
        {

            head = head->next;
            head->prev = NULL;
        }
        delete (temp);
    }

    // Deletion At Tail
    else if (index == GetLength(head) - 1)
    {
        Node *temp = tail;
        if (tail == head)
        {
            tail = NULL;
            head = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete (temp);
    }

    // Deletion In Middle
    else
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete (temp);
    }
};

void Reverse(Node *&head, Node *&tail)
{
    if (head == tail)
        return;

    Node *current = head;
    Node *before = NULL;
    Node *forward = NULL;

    while (current != NULL)
    {
        forward = current->next;
        current->next = before;
        current->prev = forward;
        before = current;
        current = forward;
    }
    Node *temp = head;
    head = tail;
    tail = temp;
}


void Rev_Recusrsion(Node * &current , Node *&Before)
{
    if(current == NULL)
    {
        return ;
    }
    Rev_Recusrsion(current->next, current);
    current->prev = current->next;
    current->next = Before;
}


void Reverse_Recursion(Node *&head, Node *&tail)
{
    if (head == tail)
        return;
    Node * current = head;
    Node * Before = NULL;
    Rev_Recusrsion(current, Before);
    Node  * temp = head;
    head = tail;
    tail = temp;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    LinkedListTraversal(head);

    InsertAtHead(head, tail, 11);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl
         << endl;

    InsertAtHead(head, tail, 13);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl
         << endl;

    InsertAtHead(head, tail, 8);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl
         << endl;

    InsertAtTail(tail, tail, 25);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl
         << endl;

    InsertAtIndex(head, tail, 1, 100);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl
         << endl;

    InsertAtIndex(head, tail, 0, 101);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl
         << endl;

    InsertAtIndex(head, tail, 8, 102);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl
         << endl;

    cout << GetLength(head) << endl;

    DeleteAtIndex(head, tail, 2);
    LinkedListTraversal(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl
         << endl;

    cout << GetLength(head) << endl;
    
    Reverse(head, tail);
    LinkedListTraversal(head);


    return 0;
}