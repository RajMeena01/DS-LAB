#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* constructAVL(const vector<int>& nums, int left, int right) {
    if (left > right){
        return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = constructAVL(nums, left, mid - 1);
    root->right = constructAVL(nums, mid + 1, right);
    return root;
}
void print(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->val <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main() {
    vector<int> nums;
    int n;
    cout<<"Enter Number of Nodes: ";
    cin>>n;
    cout<<"Enter Nodes: ";
    for(int i = 0; i < n; i++){
        int data;
        cin>> data;
        nums.push_back(data);
    }
    TreeNode* root = constructAVL(nums, 0, n-1);
    cout << "Inorder Traversal of constructed AVL tree: "<<endl;
    print(root);
    return 0;
}
