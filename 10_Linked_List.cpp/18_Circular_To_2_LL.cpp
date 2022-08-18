#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "Deleted Node : " << value << endl;
    }
};

void InsertAtTail(Node *&tail, int d)
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

// Getting length Of Linked List
int GetLength(Node *tail)
{
    if (tail == NULL)
        return 0;
    else if (tail->next == NULL)
        return 1;
    else
    {
        Node *temp = tail;
        int len = 0;

        do
        {
            temp = temp->next;
            len++;
        } while (temp != tail);
        return len;
    }
}

void InsertAtIndex(Node *&tail, int index, int d)
{
    if (index < 0 || index > GetLength(tail))
    {
        cout << "Invalid Index can't insert " << d << endl;
        return;
    }
    else if (index == GetLength(tail))
    {
        InsertAtTail(tail, d);
        return;
    }
    else
    {
        Node *current = tail;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        Node *NewNode = new Node(d);
        NewNode->next = current->next;
        current->next = NewNode;
    }
}

void DeleteByValue(Node *&tail, int value)
{

    // Empty list check
    if (tail == NULL)
        cout << "List is Empty can't delete " << value << endl;
    else if (tail->next == tail)
    {
        if (tail->data == value)
        {
            Node *temp = tail;
            temp->next = NULL;
            tail = NULL;
            delete temp;
        }
        else
        {
            cout << "Value Not present " << endl;
        }
    }
    else
    {
        // Assuming Value is present
        Node *prev = tail;
        Node *current = prev->next;
        while (current->data != value)
        {
            prev = current;
            current = current->next;
        }
        if (current == tail)
        {
            tail = prev;
        }
        prev->next = current->next;
        current->next = NULL;
        delete (current);
    }
}

void PrintArray(Node *tail)
{
    if (tail == NULL)
    {
        cout << "Circular list Is Empty " << endl;
    }

    if (tail->next == tail)
    {
        cout << tail->data << " " << endl;
        return;
    }

    Node *temp = tail;
    do
    {
        temp = temp->next;
        cout << temp->data << " ";
    } while (temp != tail);
    cout << endl;
};

void LinkedListTraversal(Node *&head)
{
    if (head == NULL)
        cout << "List Is Empty .";
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

pair<Node *, Node *> CircularToLL(Node *&tail)
{
    if (tail == NULL)
        return {NULL, NULL};

    else if (tail->next == tail)
    {
        tail->next = NULL;
        return {tail, NULL};
    }

    // 1 2 3 4 5 6 7 8 9 10
    else
    {
        Node *head = tail->next;
        tail->next = NULL;
        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node *ans1 = head;
        Node *ans2 = slow->next;
        slow->next = NULL;
        // //cout << "Inside" << endl;
        // LinkedListTraversal(ans1);
        // cout << "Inside" << endl;
        // LinkedListTraversal(ans2);
        return {ans1, ans2};
    }
}

int main()
{
    Node *tail = NULL;

    // InsertAtTail(tail, 10);
    // InsertAtTail(tail, 20);
    // InsertAtTail(tail, 30);
    // InsertAtTail(tail, 40);
    // InsertAtTail(tail, 50);
    // InsertAtTail(tail, 60);
    // InsertAtTail(tail, 70);
    // InsertAtTail(tail, 80);
    // InsertAtTail(tail, 90);
    // InsertAtTail(tail, 100);

    PrintArray(tail);

    // cout<<tail->next->data<<endl;

    pair<Node *, Node *> ans = CircularToLL(tail);
    LinkedListTraversal(ans.first);
    LinkedListTraversal(ans.second);

    return 0;
}