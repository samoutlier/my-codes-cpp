#include <iostream>
#include <vector>
#include <map>

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

Node *GetMiddle(Node *head)
{
    if (head == NULL)
    {

        return NULL;
    }
    else if (head->next == NULL)
    {

        return head;
    }
    else
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL && slow != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != NULL)
                fast = fast->next;
        }
        return slow;
    }
}

Node *Merge(Node *left, Node *right)
{
    Node *HeadOfResult = new Node(-1);
    Node *temp = HeadOfResult;
    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    if (HeadOfResult->next != NULL)
    {
        temp = HeadOfResult;
        HeadOfResult = HeadOfResult->next;
        temp->next = NULL;
        delete temp;
        return HeadOfResult;
    }
    else
    {
        return NULL;
    }
}

Node *MergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = GetMiddle(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);

    // Merging Them
    Node *result = Merge(left, right);

    return result;
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

    InsertAtTail(head1, tail1, 2);
    InsertAtTail(head1, tail1, 126);
    InsertAtTail(head1, tail1, 10);
    InsertAtTail(head1, tail1, 100);
    InsertAtTail(head1, tail1, 151);
    InsertAtTail(head1, tail1, -5);
    InsertAtTail(head1, tail1, 0);
    InsertAtTail(head1, tail1, -94);
    InsertAtTail(head1, tail1, 3);
    InsertAtTail(head1, tail1, 55);

    LinkedListTraversal(head1);

    Node *ans = MergeSort(head1);
    LinkedListTraversal(ans);

    return 0;
}