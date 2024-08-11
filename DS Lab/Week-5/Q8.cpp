#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(){}
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void createLinkedList(Node*& head, int size) {
    Node* temp = nullptr;
    for(int i = 0; i < size; i++) {
        int d;
        cin >> d;
        if(i == 0) {
            head = new Node(d);
            temp = head;
        } else {
            temp->next = new Node(d);
            temp = temp->next;
        }
    }
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void moveToFront(Node* &head){
    if(head==NULL || head->next==NULL){
        cout<<"NOT POSSIBLE"<<endl;
        return;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    Node* lastNode = temp->next;
    temp->next=NULL;
    lastNode->next = head;
    head= lastNode;
}
int main(){
    Node* head;
    cout<<"Enter number of elements : ";
    int n;
    cin>>n;
    cout<<"Enter elements: ";
    createLinkedList(head, n);
    moveToFront(head);
    print(head);
    cout<<endl;
}