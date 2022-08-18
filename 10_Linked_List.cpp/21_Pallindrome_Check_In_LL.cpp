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

Node *MiddleOfNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast->next != NULL)
            fast = fast->next;
    }
    return slow;
}



bool IsPallindrome(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return true;
    else
    {
        // Finding Middle Of Node 
        Node *middle = MiddleOfNode(head);

        //Reversing The List After OF Middle

        Node *prev = NULL;
        Node *curr = middle->next;
        Node *forward = NULL ;

        while (curr != NULL)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }

        middle->next = prev;
        curr = prev;
        prev = head;

        while (curr != NULL)
        {
            if (prev->data != curr->data)
            {
                cout << "False Returned" << endl;
                return false;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return true;
    }
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

    InsertAtTail(head, tail, 0);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 1);

    if (IsPallindrome(head))
        cout << "It is a Pallindrome . " << endl;
    else
        cout << "It is NOT a Pallindrome . " << endl;

    return 0;
}