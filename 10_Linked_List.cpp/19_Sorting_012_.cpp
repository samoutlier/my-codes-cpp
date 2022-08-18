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

void Approach1_Sorting(Node *&head, Node *&tail)
{   
    if(head == NULL)
    return ;

    Node *head_0 = NULL;
    Node *head_1 = NULL;
    Node *head_2 = NULL;

    Node *tail_0 = NULL;
    Node *tail_1 = NULL;
    Node *tail_2 = NULL;

    InsertAtHead(head_0, tail_0, -1);
    InsertAtHead(head_1, tail_1, -1);
    InsertAtHead(head_2, tail_2, -1);

    // Creating Separate LL
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        if (temp->data == 0)
        {
            tail_0->next = temp;
            tail_0 = temp;
        }
        else if (temp->data == 1)
        {
            tail_1->next = temp;
            tail_1 = temp;
        }
        else
        {
            tail_2->next = temp;
            tail_2 = temp;
        }
    }
    
    if(head_0->next!= NULL)
    head = head_0->next;
    else if(head_1->next != NULL)
    head = head_1->next;
    else 
    head = head_2->next;


    if(tail_2->data != -1)
    tail = tail_2;
    else if(tail_1->data != -1)
    tail = tail_1;
    else
    tail = tail_0;

    // Merging The List

    if (head_1->next != NULL)
    {
        tail_0->next = head_1->next;
    }
    else
    {
        tail_0->next = head_2->next;
    }

    
    tail_1->next = head_2->next;
    
    delete head_0;
    delete head_1;
    delete head_2;
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

    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 0);
    InsertAtHead(head, tail, 1);

    LinkedListTraversal(head);

    Approach1_Sorting(head, tail);

    LinkedListTraversal(head);
    return 0;
}