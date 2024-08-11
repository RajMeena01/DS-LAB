#include<iostream>
#include <utility> 
#include <algorithm>
using namespace std;
class BST {
public:
    int data;
    BST* left;
    BST* right;
    BST(int val): data(val), left(NULL), right(NULL) {}
};
pair<bool, int> checkBST(BST* root){
    if(root == NULL){
        return make_pair(true, 0);
    }
    pair<bool, int> left = checkBST(root->left);
    pair<bool, int> right = checkBST(root->right);

    if(left.first && right.first && abs(left.second - right.second) <= 1){
        return make_pair(true, max(left.second, right.second) + 1);
    }else{
        return make_pair(false, max(left.second, right.second) + 1);
    }
}
BST* buildTree(BST* root, int data) {
    if(root == NULL){
        BST* newNode = new BST(data);
        return newNode;
    }

    if(data < root->data){
        root->left = buildTree(root->left, data);
    }else{
        root->right = buildTree(root->right, data);
    }
    return root;
}

void insert(BST* &root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    while(data != -1){
        root = buildTree(root, data);
        cin>>data;
    }
}
int main(){
    BST* root = NULL;
    insert(root);
    pair<bool, int> result = checkBST(root);
    if(result.first){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}