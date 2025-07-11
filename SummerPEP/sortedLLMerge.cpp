#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
Node *addANode(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}
void sortedLL(Node *&head1, Node *&head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *tracker1 = head1;
    Node *tracker2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (tracker1->data < tracker2->data)
        {
            temp1 = temp1->next;
        }
        else
        {
            tracker2= tracker2->next;
            temp2->next = temp1;
            tracker1->next = temp2;
            tracker1 = temp1;
            temp2 = tracker2;
        }
    }
}

void traversal(Node *&head)
{

    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL";
}
int main()
{
    // Node* newNode = new Node(10);
    // Node* head = newNode;
    Node *head = NULL;
    addANode(head, 20);
    addANode(head, 30);
    traversal(head);
    return 0;
}