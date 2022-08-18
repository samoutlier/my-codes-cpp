#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
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
     //cout << "Deleted Node : " << value << endl;
    }
};

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

void InsertChildATLast(Node *&head, Node *&tail,  int value)
{

    Node *temp = new Node(value);
    Node *ptr = tail;

    while (ptr->child != NULL)
    {
        ptr = ptr->child;
    }

    ptr->child = temp;
}

Node *Merge(Node *&down, Node *&right)
{
    if (down == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return down;
    }

    Node *MasterHead = new Node(-1);
    Node *temp = MasterHead;
    while (down != NULL && right != NULL)
    {
        if (down->data <= right->data)
        {
            temp->child = down;
            temp = down;
            down = down->child;
            temp->child = NULL;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
            temp->child = NULL;
        }
    }
    while (down != NULL)
    {
        temp->child = down;
        temp = down;
        down = down->child;
        temp->child = NULL;
    }

    while (right != NULL)
    {
        temp->child = right;
        temp = right;
        right = right->child;
        temp->child = NULL;
    }

    if(MasterHead->child!= NULL)
    {
        temp = MasterHead;
        MasterHead = MasterHead->child;
        temp->child = NULL;
        delete temp;
    }
    return MasterHead;
}

Node *Flatten(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *down = head;
    Node *right = head->next;
    head->next = NULL;

    right = Flatten(right);

    Node *result = Merge(down, right);

    return result;
}

void LinkedListTraversal(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl;
}

void LinkedListTraversalWithChild(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        Node *down = temp;

        while (down != NULL)
        {
            cout << down->data << " ";
            down = down->child;
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    InsertAtTail(head1, tail1, 5);
    InsertChildATLast(head1, tail1, 10);
    InsertChildATLast(head1, tail1, 108);
    InsertChildATLast(head1, tail1, 160);

    InsertAtTail(head1, tail1, -16);
    InsertChildATLast(head1, tail1, 22);
    InsertChildATLast(head1, tail1, 42);

    InsertAtTail(head1, tail1, 100);
    InsertChildATLast(head1, tail1, 200);

    InsertAtTail(head1, tail1, -10);
    InsertChildATLast(head1, tail1, 120);

    InsertAtTail(head1, tail1, 51);

    LinkedListTraversalWithChild(head1);

    Node *ans = Flatten(head1);
    LinkedListTraversal(ans);

    return 0;
}