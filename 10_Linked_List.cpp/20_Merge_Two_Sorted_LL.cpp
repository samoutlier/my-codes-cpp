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
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

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

void InsertAtIndex(Node *&head, Node *&tail, int index, int d)
{
    if (index < 0)
    {
        cout << "Invalid Index can't insert " << d << endl;
        return;
    }
    if (index == 0)
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

Node *MergeLL(Node *&head1, Node *&head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, -1);

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            Node *temp = head1;
            head1 = head1->next;
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
        else
        {
            Node *temp = head2;
            head2 = head2->next;
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
    }
    while (head1 != NULL)
    {
        Node *temp = head1;
        head1 = head1->next;
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
    while (head2 != NULL)
    {
        Node *temp = head2;
        head2 = head2->next;
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
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

    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    InsertAtTail(head1, tail1, 12);
    InsertAtTail(head1, tail1, 35);
    InsertAtTail(head1, tail1, 63);
    InsertAtTail(head1, tail1, 69);
    InsertAtTail(head1, tail1, 85);

    InsertAtHead(head2, tail2, 10);
    InsertAtTail(head2, tail2, 16);
    InsertAtTail(head2, tail2, 34);
    InsertAtTail(head2, tail2, 58);
    InsertAtTail(head2, tail2, 72);
    InsertAtTail(head2, tail2, 100);

    LinkedListTraversal(head1);
    LinkedListTraversal(head2);

    Node *ans = MergeLL(head1, head2);
    LinkedListTraversal(ans);

    return 0;
}