#include<iostream>
using namespace std;
 class Node{
    public :
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
 };
  void insertAtHead(Node* &head , int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head =newNode;
 }
  void insertAtTail(Node* &tail , int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
 }
 void insertAtPosition(Node* &head ,Node* &tail, int data,int pos){
    if(pos==1){
        insertAtHead(head,data);
        return ;
    }
    Node* temp = head;
    int count =1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(tail , data);
        return;
    }
     Node* newnode = new Node(data);
    newnode->next = temp->next;
    temp->next =newnode;

}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }cout<<"NULL";
    cout<<endl;
}
int main(){
    Node * node1 = new Node(1);
    Node* head1 =node1;
    Node* tail1 = node1;
    insertAtTail(tail1,2);
    insertAtTail(tail1,3);
    insertAtTail(tail1,4);
    insertAtTail(tail1,5);
    insertAtTail(tail1,6);
    print(head1);
    Node * node2 = new Node(7);
    Node* head2 =node2;
    Node* tail2 = node2;
    insertAtTail(tail2,8);
    insertAtTail(tail2,9);
    insertAtTail(tail2,15);
    insertAtTail(tail2,11);
    insertAtTail(tail2,12);
    print(head2);
    Node* newhead = head1;
    Node* newTail = newhead;
    while(newTail->next!=NULL){
        newTail= newTail->next;
    }
    newTail->next = head2;
    newTail=tail2;
    print(newhead);
}