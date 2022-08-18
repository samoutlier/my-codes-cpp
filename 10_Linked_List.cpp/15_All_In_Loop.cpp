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


bool LoopCheck(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

       if(slow == fast)
       break;
    }
    if(slow == fast)
    return 1;
    else
    return 0;
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

void RemoveLoop(Node *&head)
{

    if (head == NULL || head->next == NULL)
        return ;

    else if(head->next == head)
    {
        head->next = NULL;
        return;
    }

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
        return ;
    }

    slow = head;
    Node * prev = fast;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    Node * temp = slow;
    while(temp->next != slow)
    {
        temp = temp->next;
    }
    temp->next = NULL;

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
    InsertAtTail(head, tail, 50);

    tail->next = head->next;
    
    
    cout<<LoopCheck(head)<<endl;
    cout<<StartingNodeInLoop(head)->data<<endl;
    RemoveLoop(head);
    cout<<LoopCheck(head)<<endl;
    
   
    return 0;
}