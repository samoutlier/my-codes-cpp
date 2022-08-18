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

void DeleteNode(Node *&head, Node *&tail, int index)
{
    if (index < 0 || index >= GetLength(head))
        cout << "Invalid Index " << endl;

    // Deletion At Head
    else if (index == 0)
    {
        Node *temp = head;

        if (tail == head)
        {
            tail = tail->next;
        }
        head = head->next;

        delete (temp);
        return;
    }

    else
    {
        Node *prev = NULL;
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;

        delete (current);

        if (prev->next == NULL)
            tail = prev;
    }
}

void Reverse(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Reverse(head, curr->next, curr);
    curr->next = prev;
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

void ReverseLinkedList(Node *&head, Node *&tail)
{
    Node *curr = head;
    Node *prev = NULL;
    Reverse(head, curr, prev);
}

Node *AddingTwoList(Node *&head1, Node *&head2, Node *&tail1, Node *&tail2)
{
    ReverseLinkedList(head1, tail1);
    ReverseLinkedList(head2, tail2);

    Node *MasterHead = NULL;
    Node *MasterTail = NULL;
    int carry = 0;
    int sum = 0;
    while (head1 != NULL && head2 != NULL)
    {
        sum = (head1->data + head2->data + carry) % 10;
        carry = (head1->data + head2->data + carry) / 10;
        InsertAtHead(MasterHead, MasterTail, sum);
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != NULL)
    {
        sum = (head1->data + carry) % 10;
        carry = (head1->data + carry) / 10;
        InsertAtHead(MasterHead, MasterTail, sum);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        sum = (head2->data + carry) % 10;
        carry = (head2->data + carry) / 10;
        InsertAtHead(MasterHead, MasterTail, sum);
        head2 = head2->next;
    }
    if (carry != 0)
        InsertAtHead(MasterHead, MasterTail, carry);

    return MasterHead;
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    InsertAtTail(head1, tail1, 3);
    InsertAtTail(head1, tail1, 4);
    InsertAtTail(head1, tail1, 5);

    cout<<"First List : ";
    LinkedListTraversal(head1);

    Node *head2 = NULL;
    Node *tail2 = NULL;

    // InsertAtTail(head2, tail2, 4);
    // InsertAtTail(head2, tail2, 5);
    // InsertAtTail(head2, tail2, 5);

    cout<<"Second List : ";
    LinkedListTraversal(head2);

    Node *ans = AddingTwoList(head1, head2, tail1, tail2);
    cout<<"Sum Of Both List : ";
    LinkedListTraversal(ans);

    return 0;
}