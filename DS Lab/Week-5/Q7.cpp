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
bool isPallindrome(Node* head){
    if(head == NULL && head->next == NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* curr = slow;
    Node* prev = NULL;
    while(curr){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    slow = head;
    fast = prev;
    while(fast){
        if(slow->data != fast->data){
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
int main(){
    Node* head;
    cout<<"Enter number of elements : ";
    int n;
    cin>>n;
    cout<<"Enter elements: ";
    createLinkedList(head, n);
    if(isPallindrome(head)){
        cout<<"List is Pallindrome"<<endl;
    }else{
        cout<<"List is not Pallindrome"<<endl;
    }
}