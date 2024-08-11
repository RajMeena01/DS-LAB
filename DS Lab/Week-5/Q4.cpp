#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}
void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;

    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    Node *newnode = new Node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);
    insertAtTail(tail, 15);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    print(head);
    cout << "Enter the nth position from last to delete Node:" << endl;
    int n;
    cin >> n;
    Node *start = new Node(-1);
    start->next = head;
    Node *slow = start;
    Node *fast = start;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    start = start->next;
    print(start);
}