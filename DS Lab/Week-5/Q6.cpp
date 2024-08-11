#include<iostream>
#include<unordered_map>
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
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }cout<<"NULL";
    cout<<endl;
}
int main(){
    Node* node1 = new Node(4);
    Node* head =node1;
    Node* tail = node1;
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    insertAtTail(tail,7);
    insertAtTail(tail,8);
    insertAtTail(tail,9);
    insertAtTail(tail,10);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    Node* node2 = new Node(4);
    Node* head2 =node2;
    Node* tail2 = node2;
    insertAtTail(tail2,15);
    insertAtTail(tail2,16);
    insertAtTail(tail2,17);
    insertAtTail(tail2,18);
    insertAtTail(tail2,19);
    insertAtTail(tail2,20);
    insertAtHead(head2,13);
    insertAtHead(head2,12);
    insertAtHead(head2,11);
    print(head2);
    unordered_map<int,int>mp;
    Node* temp =head;
    while(temp!=NULL){
        mp[temp->data]++;
        temp=temp->next;
    }
    temp = head2;
    while(temp!=NULL){
        if(mp[temp->data]>0){
            break;
        }
        else{
        temp= temp->next;
        }
    }
   if(temp != NULL) {
        cout << "Above two linked lists intersect at: " << temp->data <<endl;
    } else {
        cout << "The two linked lists do not intersect";
    }
}