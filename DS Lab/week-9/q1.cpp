#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node * left, *right;
    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
void inorder(node * head){
    if(head == NULL)return;
    inorder(head->left);
    cout<<head->data;
    inorder(head->right);
}
void preorder(node * head){
    if(head == NULL)return;

    cout<<head->data;
    preorder(head->left);
    preorder(head->right);
}
void postorder(node * head){
    if(head == NULL)return;
    postorder(head->left);
    postorder(head->right);
    cout<<head->data;
}
int main(){
    node * head = new node(5);
    head->left = new node(7);
    head->right = new node(0);
    head->left->left = new node(3);
    head->left->right = new node(12);
    inorder(head);
    cout<<endl;
    preorder(head);
    cout<<endl;
    postorder(head);
    cout<<endl;
}