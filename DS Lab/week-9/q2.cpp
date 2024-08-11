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
int height(node * head){
    if(head == NULL)return 0;

    int lh = height(head->left);
    int rh = height(head->right);
    return max(lh,rh)+1;
}
int main(){
    node * head = new node(5);
    head->left = new node(7);
    head->right = new node(0);
    head->left->left = new node(3);
    head->left->right = new node(12);
    cout<<height(head)<<endl;
}