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
void leafnodes(node * head, int &c){
    if(head == NULL)return ;
    if(head->left == NULL and head->right == NULL)c++;
    leafnodes(head->left,c);
    leafnodes(head->right,c);
}
int main(){
    node * head = new node(5);
    head->left = new node(7);
    head->right = new node(0);
    head->left->left = new node(3);
    head->left->right = new node(12);
    head->right->left = new node(13);
    head->right->right = new node(43);
    int c = 0;
    leafnodes(head,c);
    cout<<c<<endl;
}