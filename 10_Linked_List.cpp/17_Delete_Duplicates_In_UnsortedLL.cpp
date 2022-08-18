// Removing a Loop in LL using Floyds Cycle Algorithm

#include <iostream>
#include <vector>
#include <map>
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
        //  cout << "Deleted Node : " << value << endl;
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

void RemoveDuplicatesFromUnsortedApproach1(Node *&head, Node *&tail)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *sub_curr = curr->next;
        Node *sub_prev = curr;

        while (sub_curr != NULL)
        {
            if (sub_curr->data == curr->data && sub_curr->next != NULL)
            {
                Node *todelete = sub_curr;
                sub_curr = sub_curr->next;
                sub_prev->next = sub_curr;
                delete todelete;
            }
            else if (sub_curr->data == curr->data && sub_curr->next == NULL)
            {
                Node *todelete = sub_curr;
                sub_prev->next = NULL;
                tail = sub_prev;
                sub_curr = NULL;
                delete todelete;
            }
            else
            {
                sub_prev = sub_curr;
                sub_curr = sub_curr->next;
            }
        }

        LinkedListTraversal(head);
        curr = curr->next;
    }
}

void RemoveDuplicatesFromUnsortedApproach2(Node *&head, Node *&tail)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *curr = head;
    map<int, bool> visited;
    visited[curr->data] = true;

    Node *prev = curr;
    curr = curr->next;

    while (curr != NULL)
    {
        if (visited[curr->data])
        {
            Node *todelete = curr;
            curr = curr->next;
            prev->next = curr;
            delete todelete;
        }
        else
        {
            visited[curr->data] = true;
            curr = curr->next;
            prev = prev->next;
            if (prev->next == NULL)
                tail = prev;
        }
        //   LinkedListTraversal(head);
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *tail_Circular = NULL;

    InsertAtTail(head, tail, 9);
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 9);
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 5);
    InsertAtTail(head, tail, 6);
    InsertAtTail(head, tail, 6);
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 0);
    InsertAtTail(head, tail, 8);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 7);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 8);
    InsertAtTail(head, tail, 6);

    cout << "Before Removing Duplicates : ";
    LinkedListTraversal(head);

    RemoveDuplicatesFromUnsortedApproach2(head, tail);

    cout << "After Removing Duplicates : ";
    LinkedListTraversal(head);
    return 0;
}