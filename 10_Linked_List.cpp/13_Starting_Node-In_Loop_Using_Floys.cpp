// Detecting a Loop in LL using Floyds Cycle Algorithm

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

Node *StartingNodeInLoop(Node *&head)
{

    // Assuming There is A Loop
    if (head == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
    {
        return NULL;
    }

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
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

void InsertAtTailCircular(Node *&tail, int d)
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

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *tail_Circular = NULL;

    InsertAtTail(head, tail, 20);
    InsertAtTail(head, tail, 30);
    InsertAtTail(head, tail, 40);
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 5);
    InsertAtHead(head, tail, 1);
    InsertAtIndex(head, tail, 4, 25);
    InsertAtIndex(head, tail, 6, 35);
    InsertAtTail(head, tail, 50);
    LinkedListTraversal(head);

    InsertAtTailCircular(tail_Circular, 1);
    InsertAtTailCircular(tail_Circular, 2);
    InsertAtTailCircular(tail_Circular, 3);
    InsertAtTailCircular(tail_Circular, 4);

    // LinkedListTraversal(tail_Circular);

    tail->next = head->next->next;
    
    cout << StartingNodeInLoop(tail_Circular->next)->data << endl;
    cout << (StartingNodeInLoop(head))->data << endl;
    return 0;
}