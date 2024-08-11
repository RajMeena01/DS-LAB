#include <iostream>
#include <climits>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isBSThelper(TreeNode *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if (root->val < minValue || root->val > maxValue)
        return false;
    return isBSThelper(root->left, minValue, root->val - 1) && isBSThelper(root->right, root->val + 1, maxValue);
}
bool isBST(TreeNode *root)
{
    return isBSThelper(root, INT_MIN, INT_MAX);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(4);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(13);
    if (isBST(root))
    {
        cout << "The binary tree is a Binary Search Tree (BST)." << endl;
    }
    else
    {
        cout << "The binary tree is not a Binary Search Tree (BST)." << endl;
    }
    return 0;
}
