#include <iostream>
#include <vector>
#include <queue>
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

class compare
{

   public :

   bool operator() (Node * a ,Node * b)
   {
        return a->data > b->data;
   }
};

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



Node *MergeKSortedLL(vector<Node *> &input)
{

    priority_queue<Node *, vector<Node *>, compare> minheap;
    
    int k = input.size();

    for (int i = 0; i < k; i++)
    {   
        if(input[i])
        minheap.push(input[i]);
    }

    Node * head = new Node(-1);
    Node * tail = head;

    while(!minheap.empty())
    {
         tail->next = minheap.top();
         tail = tail->next;
         minheap.pop();
         if(tail->next)
         minheap.push(tail->next);
    }

    Node *todel = head;
    head = head->next;
    delete todel;
    return head;
    
}

// TC : n*k(Log(k))
// SC : k

int main()
{

    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;
    Node *tail3 = NULL;

    InsertAtTail(head1, tail1, 4);
    InsertAtTail(head1, tail1, 6);
    InsertAtTail(head1, tail1, 8);

    InsertAtTail(head2, tail2, 2);
    InsertAtTail(head2, tail2, 5);
    InsertAtTail(head2, tail2, 7);

    InsertAtTail(head3, tail3, 1);
    InsertAtTail(head3, tail3, 3);
    InsertAtTail(head3, tail3, 9);
    InsertAtTail(head3, tail3, 10);


    vector<Node *> input;
    input.push_back(head1);
    input.push_back(head2);
    input.push_back(head3);



    cout<<"Linked List Traversal Of 1 : ";
    LinkedListTraversal(head1);
    cout<<"Linked List Traversal Of 2 : ";
    LinkedListTraversal(head2);
    cout<<"Linked List Traversal Of 3 : ";
    LinkedListTraversal(head3);

    Node *ans = MergeKSortedLL(input);
    cout<<"Linked List Traversal Of Ans : ";
    LinkedListTraversal(ans);

    return 0;
}