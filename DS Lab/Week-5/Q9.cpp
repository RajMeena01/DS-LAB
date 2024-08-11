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
bool isNonDecreasing(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* prev = head;
    Node* curr = head->next;
    while(curr){
        if(prev->data > curr->data){
            return false;
        }
        prev = curr;
        curr = curr->next;
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
    if(isNonDecreasing(head)){
        cout<<"List is non decreasing order";
    }else{
        cout<<"List is in decreasing order";
    }
    cout<<endl;
}