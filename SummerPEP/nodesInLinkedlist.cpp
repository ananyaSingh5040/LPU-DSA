#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

};
Node* addANode (Node* &head, int val)
{
     Node* newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        return head;
    }
    Node* curr = head;
    while(curr->next!=NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}
int numberOfNodes (Node* &head)
{
    Node* temp = head;
    if(head == NULL)
       return 0 ;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
bool NodeSearch(Node* &head, int val)
{
    if(head == NULL) return false;
    Node* temp = head;
    while(temp->data != val && temp!=NULL)
    {
        temp = temp->next;
    }
    if(temp!= NULL)
    return true;
    return false;
}
int middleNode(Node* &head)
{
    Node* slow = head;
    Node* fast = head->next;
    while(fast!= NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;

}
int main()
{
    Node* head = NULL;
    addANode(head,  20);
    addANode(head,  30);
    addANode(head,  40);
    addANode(head,  50);
    addANode(head,  60);
    addANode(head,  10);
    addANode(head,  80);
    cout<<"Number of nodes: "<<numberOfNodes(head)<<endl;
    int val = 10;
    NodeSearch(head, val) ? cout<<"The node was found"<<endl : cout<<"The node was not present"<<endl;
    cout<<"The middle node is: "<<middleNode(head);
    
    return 0;
}