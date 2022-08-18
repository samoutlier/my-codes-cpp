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

Node* oddEvenList(Node* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        
        Node * e = head->next;
        Node * odd = head;
        Node * even = head->next;
        vector<Node * > v;
         
        while(odd && odd->next )
        {   
            v.push_back(odd->next);
            odd->next = odd->next->next;
            if( odd->next )
            odd = odd->next;
        }
        for(int i = 1 ; i<v.size() ; i++)
        {
            even->next = v[i];
            even = v[i];
            even->next = NULL;
        }
        
       
        odd->next = e;
        return head;
        
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
    
    
    LinkedListTraversal(head1);
    
    Node * ans =oddEvenList(head1);
    LinkedListTraversal(ans);

    return 0;
}