#include <iostream>
#include <vector>
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

node * buildTree(vector<int> arr, int n, int i){
    if(n == 0)return NULL;
    if(i >= n)return NULL;
    node * temp = new node(arr[i]);
    temp->left = buildTree(arr,n,2*i+1);
    temp->right = buildTree(arr,n,2*i+2);
    return temp;
}
 void print(node * head){
    if(head == NULL)return;

    cout<<head->data<<" ";
    print(head->left);
    print(head->right);
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(12);
    arr.push_back(42);
    

    int s = arr.size();
    node * head = buildTree(arr,s,0);
    print(head);
    cout<<endl;
}