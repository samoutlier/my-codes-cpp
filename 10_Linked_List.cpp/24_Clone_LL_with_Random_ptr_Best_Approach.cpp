#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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

Node *Clone(Node *head)
{
   //If Head isNULL
    if (!head)
        return NULL;
    Node *CloneHead = NULL;
    Node *CloneTail = NULL;

    Node *temp = head;
   
   //Creating Clone Node and adding next to its original node
    while (temp)
    {
        int d = temp->data;
        if (!CloneHead)
        {
            CloneHead = new Node(d);
            CloneTail = CloneHead;
            Node *fwd = temp->next;
            temp->next = CloneTail;
            CloneTail->next = fwd;
            temp = fwd;
        }
        else
        {
            CloneTail = new Node(d);
            Node *fwd = temp->next;
            temp->next = CloneTail;
            CloneTail->next = fwd;
            temp = fwd;
        }
    }

    temp = head;
   
   //Storing random Pointer of clone list
    while (temp)
    {
        if (temp->random)
            temp->next->random = temp->random->next;
        else
            temp->next->random = NULL;
        temp = temp->next->next;
    }

    temp = head;
   
   //Separating  clone list from original list
    while (temp->next)
    {
        Node *xyz = temp->next;
        temp->next = xyz->next;
        temp = xyz;
    }

   //returniung clone list
    return CloneHead;
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
    Node *head1 = NULL;
    Node *tail1 = NULL;

    InsertAtTail(head1, tail1, 1);
    InsertAtTail(head1, tail1, 2);
    InsertAtTail(head1, tail1, 3);
    InsertAtTail(head1, tail1, 4);
    InsertAtTail(head1, tail1, 5);

    Node *temp = head1;

    temp->random = head1->next->next;

    temp = temp->next;

    temp->random = head1;

    temp = temp->next;

    temp->random = temp->next->next;

    temp = temp->next;

    temp->random = head1->random;

    temp = temp->next;

    temp->random = head1->next;

    Node *CloneHead = Clone(head1);

    LinkedListTraversal(head1);
    LinkedListTraversal(CloneHead);

    Node *x = head1, *y = CloneHead;

    while (x != NULL && y != NULL)
    {
        if (x->random != NULL && x->random != NULL)
        {
            cout << "Random Of OG LL with data " << x->data << " is " << x->random->data << endl;
            cout << "Random Of Clone LL with data " << y->data << " is " << y->random->data << endl;
        }
        else
        {
            cout << "Random Of OG LL with data " << x->data << " is NULL" << endl;
            cout << "Random Of Clone LL with data " << y->data << " is NULL" << endl;
        }
        x = x->next;
        y = y->next;
    }

    // This was done in T.C. = O(1);
    // This was done in S.C. = O(n);

    return 0;
}