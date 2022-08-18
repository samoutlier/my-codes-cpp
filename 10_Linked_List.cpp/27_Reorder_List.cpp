#include <iostream>
#include <vector>
#include<stack>
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

 Node * Middle(Node * head)
    {
        if(!head|| !head->next )
        {
            return head;
        }
        
        Node * slow = head;
        Node * fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    void Solve(Node * &head, stack<Node * > &store)
    {    
        if(!head)
            return ;
        
        Node * curr = head;
        Node * xyz = head->next;
        if(!store.empty())
        {
         curr->next = store.top();
         store.pop();   
         
         curr->next->next = xyz;
         curr = xyz;
            Solve(curr, store);
        }
        else
        {
            curr->next = NULL; 
            return ;
        }
    }
    
    void reorderList(Node* head) {
        if(!head || !head->next || !head->next->next)
            return ;
        Node * mid = Middle(head);
        Node * curr = head;
        Node * midnext = mid->next;
        mid->next = NULL;
        
         
        stack<Node * > store;
        while(midnext)
        {
            store.push(midnext);
           midnext = midnext->next;
        }
        Solve(head, store);
        
    }

int main()
{
   
    Node *head = NULL;
    Node *tail = NULL;


    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 5);
    
    cout<<"Before Reorder : ";
    LinkedListTraversal(head);
    reorderList(head);
    cout<<"After Reorder : ";
    LinkedListTraversal(head);

    
    return 0;
}