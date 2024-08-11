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
        return;
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
    while(temp->next!=NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }cout<<"NULL";
    cout<<endl;
}
void deletenode(Node* &head, int pos ){
    if(pos==1){
        Node* temp = head;
        head= head->next;
        temp->next = NULL;
        delete temp;
    }
    Node* prev = NULL;
    Node* curr = head;
    int count =1;
    while(count < pos){
        prev =curr;
        curr= curr->next;
        count++;
    }
    prev->next = curr->next;
    curr->next= NULL;
    delete curr;
}
 bool searchElement(Node* head, int target){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==target){
         
            return true ;
        }
        temp = temp->next;
    }
    return false;
 }
int main(){
    Node * node1 = new Node(10);
    Node* head =node1;
    Node* tail = node1;
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    insertAtTail(tail,15);
    print(head);
    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtHead(head,7);
    print(head);
    deletenode(head,3);
    print(head);
    int k ;
    cout<<"Enter the element to be found: ";
    cin>>k;
    cout<<k<<" is Present: "<<searchElement(head,k)<<endl;
    return 0;
}