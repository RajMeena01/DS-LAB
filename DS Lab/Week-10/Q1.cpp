#include <iostream> 
#include<queue>
using namespace std;
struct Tree
{
    int val;
    Tree *left;
    Tree *right;
    Tree(int x) : val(x), left(NULL), right(NULL) {}
};
Tree *insertval(Tree *root, int val)
{
    if (!root)
    {
        root = new Tree(val);
    }
    else if (val <= root->val)
    {
        root->left = insertval(root->left, val);
    }
    else
    {
        root->right = insertval(root->right, val);
    }
    return root;
}
void preorder(Tree *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}
void display(Tree *root)
{   // level order 
    if (root == NULL) return; queue<Tree*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Tree *current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
        cout << endl;
    }
}
int main()
{
    int elements[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(elements) / sizeof(elements[0]);
    Tree *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insertval(root, elements[i]);
    }
    cout << "BST :" << endl;
    display(root);
    cout << "\nPreorder traversal:" << endl;
    preorder(root);
    cout << "\nPostorder traversal:" << endl;
    postorder(root);
    cout<<endl;
    return 0;

}
