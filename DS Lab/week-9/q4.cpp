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

int height(node* root) {
    if (root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(node* root) {
    if (root == NULL)
        return true;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if (abs(leftHeight - rightHeight) <= 1 and isBalanced(root->left) and isBalanced(root->right))
        return true;
    
    return false;
}

int main(){
    node * head = new node(5);
    head->left = new node(7);
    // head->right = new node(0);
    head->left->left = new node(3);
    head->left->right = new node(12);
    // head->right->left = new node(13);
    // head->right->right = new node(43);
    cout<<isBalanced(head)<<endl;
}