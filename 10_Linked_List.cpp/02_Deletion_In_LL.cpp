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

void DeleteByNode(Node *&head, Node *&tail, int index)
{
    if (index < 0 || index >= GetLength(head))
        cout << "Invalid Index "<<endl;
        

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

void InsertAtTail(Node *&tail, int d)
{
    // New Node Creation
    Node *NewNode = new Node(d);
    tail->next = NewNode;
    tail = NewNode;
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
    Node *n1 = new Node(10);

    // Head Pointing to Node n1
    Node *head = n1;

    // Tail Pointing to Node n1
    Node *tail = n1;
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 50);
    LinkedListTraversal(head);
    DeleteByNode(head, tail, -3);
    LinkedListTraversal(head);
    cout << head->data << endl;
    cout << tail->data << endl;

    return 0;
}